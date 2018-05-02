

#include <gtk_graphics.h>
#include <graphics.h>
#include <math.h>

cairo_surface_t *surface = NULL;
GtkWidget *widget;

static gboolean draw_cb(GtkWidget *widget, cairo_t *cr, gpointer data);
static gboolean configure_event_cb(GtkWidget *widget, GdkEventConfigure *event, gpointer data);

void gtk_graphics_init(GtkWidget *wdg){

    widget = wdg;

    g_signal_connect (wdg, "draw",
                      G_CALLBACK(draw_cb), NULL);
    g_signal_connect (wdg, "configure-event",
                      G_CALLBACK(configure_event_cb), NULL);
}

void graphics_clear(gl_color_t color){

    cairo_t *cr;

    cr = cairo_create(surface);

    cairo_set_source_rgb(cr, color.red, color.green, color.blue);
    cairo_paint(cr);

    cairo_destroy(cr);

    gtk_widget_queue_draw_area(widget, 0, 0, 500, 100);
}

void graphics_draw_rect(gl_rectangle_t *obj){

    cairo_t *cr;

    cr = cairo_create(surface);

    cairo_rectangle(cr, obj->point.x, obj->point.y, obj->width, obj->height);
    cairo_set_source_rgb(cr, obj->color.red, obj->color.green, obj->color.blue);
    cairo_set_line_width(cr, obj->border_size);
    cairo_stroke(cr);
    cairo_fill(cr);

    cairo_destroy(cr);

    gtk_widget_queue_draw_area(widget, (gint) obj->point.x, (gint) obj->point.y, obj->width, obj->height);
}

void graphics_draw_frect(gl_filled_rectangle_t *obj){

    cairo_t *cr;

    cr = cairo_create(surface);

    cairo_rectangle(cr, obj->point.x, obj->point.y, obj->width, obj->height);
    cairo_set_source_rgb(cr, obj->color.red, obj->color.green, obj->color.blue);
    cairo_fill(cr);

    cairo_destroy(cr);

    gtk_widget_queue_draw_area(widget, (gint) obj->point.x, (gint) obj->point.y, obj->width, obj->height);

}
void graphics_draw_circle(gl_circle_t *obj){

    cairo_t *cr;

    cr = cairo_create(surface);

    cairo_arc(cr, obj->point.x, obj->point.y, obj->radius, 0, 2*M_PI);
    cairo_set_source_rgb(cr, obj->color.red, obj->color.green, obj->color.blue);
    cairo_set_line_width(cr, obj->border_size);
    cairo_stroke(cr);
    cairo_fill(cr);

    cairo_destroy(cr);

    gtk_widget_queue_draw_area(widget, (gint) (obj->point.x - obj->radius), (gint) (obj->point.y - obj->radius), 2*obj->radius, 2*obj->radius);
}
void graphics_draw_fcircle(gl_filled_circle_t *obj){

    cairo_t *cr;

    cr = cairo_create(surface);

    cairo_arc(cr, obj->point.x, obj->point.y, obj->radius, 0, 2*M_PI);
    cairo_set_source_rgb(cr, obj->color.red, obj->color.green, obj->color.blue);
    cairo_fill(cr);

    cairo_destroy(cr);

    gtk_widget_queue_draw_area(widget, (gint) (obj->point.x - obj->radius), (gint) (obj->point.y - obj->radius), 2*obj->radius, 2*obj->radius);
}

static gboolean draw_cb(GtkWidget *widget, cairo_t *cr, gpointer data) {

    cairo_set_source_surface(cr, surface, 0, 0);
    cairo_paint(cr);

    return FALSE;
}


static gboolean configure_event_cb(GtkWidget *widget, GdkEventConfigure *event, gpointer data) {

    if (surface)
        cairo_surface_destroy(surface);

    surface = gdk_window_create_similar_surface(gtk_widget_get_window(widget),
                                                CAIRO_CONTENT_COLOR,
                                                gtk_widget_get_allocated_width(widget),
                                                gtk_widget_get_allocated_height(widget));


    gl_color_t color;

    color.red = color.green = color.blue = 255;

    graphics_clear(color);

    return TRUE;
}