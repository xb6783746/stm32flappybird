
#ifndef FLAPPYBIRD_PHYSICS_INTERNAL_H
#define FLAPPYBIRD_PHYSICS_INTERNAL_H

#include <physics_engine.h>
#include <game_engine.h>


extern gn_ph_settings_t settings;
extern gn_game_object *objects[OBJECTS_BUFFER_CAPACITY];

void gn_phys_add_body_to_field(gn_game_object *obj);

void gn_phys_reset_field(void);

#endif //FLAPPYBIRD_PHYSICS_INTERNAL_H
