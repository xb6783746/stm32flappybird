

#include <gtk/gtk.h>
#include <gtk_graphics.h>
#include <platform.h>
#include <flappybird.h>
#include <timer_service.h>
#include <flappybird_events.h>


extern cairo_surface_t *surface;

/* Handle button press events by either drawing a rectangle
 * or clearing the surface, depending on which button was pressed.
 * The ::button-press signal handler receives a GdkEventButton
 * struct which contains this information.
 */
static gboolean button_press_event_cb(GtkWidget *widget,
                      GdkEventButton *event,
                      gpointer data) {


    if (event->button == GDK_BUTTON_PRIMARY) {

        if(fb_game_is_running()) {

            fb_bird_jump(0);
        } else {

            fb_game_start();
        }
    }

    /* We've handled the event, stop processing */
    return TRUE;
}


static void close_window(void) {

    if (surface)
        cairo_surface_destroy(surface);
}

static void on_game_over(fb_uint8_t bird_num){

    fb_game_stop();
}

static void game_init(){

    fb_game_settings_t settings;

    settings.on_game_over = on_game_over;
    settings.screen_width = 500;
    settings.screen_height = 100;
    settings.birds_count = 1;

    fb_game_init(&settings);

}

static void activate(GtkApplication *app, gpointer user_data) {

    GtkWidget *window;
    GtkWidget *frame;
    GtkWidget *drawing_area;

    window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW (window), "Drawing Area");

    g_signal_connect (window, "destroy", G_CALLBACK(close_window), NULL);

    gtk_container_set_border_width(GTK_CONTAINER (window), 8);

    frame = gtk_frame_new(NULL);
    gtk_frame_set_shadow_type(GTK_FRAME (frame), GTK_SHADOW_IN);
    gtk_container_add(GTK_CONTAINER (window), frame);

    drawing_area = gtk_drawing_area_new();
    /* set a minimum size */
    gtk_widget_set_size_request(drawing_area, 500, 100);

    gtk_container_add(GTK_CONTAINER (frame), drawing_area);

    gtk_graphics_init(drawing_area);


    timer_service_init();
    game_init();

    g_signal_connect (drawing_area, "button-press-event",
                      G_CALLBACK(button_press_event_cb), NULL);

    /* Ask to receive events the drawing area doesn't normally
     * subscribe to. In particular, we need to ask for the
     * button press and motion notify events that want to handle.
     */
    gtk_widget_set_events(drawing_area, gtk_widget_get_events(drawing_area)
                                        | GDK_BUTTON_PRESS_MASK
                                        | GDK_POINTER_MOTION_MASK);

    gtk_widget_show_all(window);
}

int main(int argc, char **argv) {

    GtkApplication *app;
    int status;

    app = gtk_application_new("org.gtk.example", G_APPLICATION_FLAGS_NONE);
    g_signal_connect (app, "activate", G_CALLBACK(activate), NULL);
    status = g_application_run(G_APPLICATION (app), argc, argv);
    g_object_unref(app);

    return status;
}