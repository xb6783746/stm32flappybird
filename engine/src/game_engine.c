

#include <game_engine.h>
#include <timer_service.h>
#include <physics_engine.h>
#include <internal/physics_internal.h>
#include <internal/graphics_internal.h>
#include <graphics_engine.h>

gn_ph_settings_t settings;

void game_engine_init(gn_ph_settings_t *arg){

    settings = *arg;

    gn_physics_init();
    gn_graphics_init();
}

void game_engine_start(void){

    timer_service_call_periodically(gn_physics_next, PHYSICS_CYCLE_TICKS);
    timer_service_call_periodically(gn_graphics_next, GRAPHICS_CYCLE_TICKS);
}
void game_engine_stop(void){

    timer_service_delete(gn_physics_next);
    timer_service_delete(gn_graphics_next);
}
void game_engine_restart(void){

    gn_physics_init();
    gn_graphics_init();
}