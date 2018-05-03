

#include <game_engine.h>
#include <timer_service.h>
#include <physics_engine.h>
#include <internal/physics_internal.h>
#include <internal/graphics_internal.h>
#include <graphics_engine.h>

gn_ph_settings_t settings;

void gn_engine_init(gn_ph_settings_t *arg){

    settings = *arg;

    gn_phys_init();
    gn_graphics_init();
}

void gn_engine_start(void){

    timer_service_call_periodically(gn_phys_next, PHYSICS_CYCLE_TICKS);
    timer_service_call_periodically(gn_graphics_next, GRAPHICS_CYCLE_TICKS);
}
void gn_engine_stop(void){

    timer_service_delete(gn_phys_next);
    timer_service_delete(gn_graphics_next);
}
void gn_engine_restart(void){

    gn_phys_init();
    gn_graphics_init();
}