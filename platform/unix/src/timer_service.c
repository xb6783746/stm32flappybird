

#include <timer_service.h>
#include <gtk/gtk.h>

#define CALLBACK_BUFFER_CAPACITY 10


typedef struct callback_array_entry_s {

    void_callback clb;
    fb_uint32_t ticks;
    fb_uint32_t curr_ticks;
} callback_array_entry_t;

static gint timer = 0;
static callback_array_entry_t callbacks[CALLBACK_BUFFER_CAPACITY];

static gint timer_callback(gpointer data);

void timer_service_init(){

    timer = gdk_threads_add_timeout(TIMER_PERIOD_MSEC, timer_callback, NULL);
}

void timer_service_call_periodically(void_callback clb, fb_uint32_t ticks){

    int i;
    for(i = 0; i < CALLBACK_BUFFER_CAPACITY; i++){

        if(callbacks[i].clb == NULL){

            callbacks[i].clb = clb;
            callbacks[i].ticks = ticks;
            callbacks[i].curr_ticks = 0;
            break;
        }
    }
}

void timer_service_delete(void_callback clb){

    int i;
    for(i = 0; i < CALLBACK_BUFFER_CAPACITY; i++){

        if(callbacks[i].clb == clb){

            callbacks[i].clb = NULL;
            break;
        }
    }
}

static void add(void_callback clb){

    int i;
    for(i = 0; i < CALLBACK_BUFFER_CAPACITY; i++){

        if(callbacks[i].clb == NULL){

            callbacks[i].clb = clb;
            break;
        }
    }
}

gint timer_callback (gpointer data)
{

    int i;
    for(i = 0; i < CALLBACK_BUFFER_CAPACITY; i++){

        if(callbacks[i].clb != NULL){

            callbacks[i].curr_ticks = (fb_uint32_t) ((callbacks[i].curr_ticks + 1) % callbacks[i].ticks);

            if(!callbacks[i].curr_ticks){

                callbacks[i].clb();
            }
        }
    }

    return 1;
}