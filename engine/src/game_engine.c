

#include <game_engine.h>
#include <internal/physics_internal.h>

gn_ph_settings_t settings;

void gn_engine_init(gn_ph_settings_t *arg){

    settings = *arg;

    gn_phys_init();
}

void gn_engine_reset(void){

    gn_phys_init();
}