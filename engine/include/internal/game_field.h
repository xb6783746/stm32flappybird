
#ifndef FLAPPYBIRD_PHYSICS_INTERNAL_H
#define FLAPPYBIRD_PHYSICS_INTERNAL_H

#include <physics_engine.h>
#include <game_engine.h>

extern gn_ph_settings_t settings;
extern gn_solid_body_t bodies[SOLID_BODIES_BUFFER_CAPACITY];
extern gn_bird_t birds[BIRDS_BUFFER_CAPACITY];

void gn_phys_add_body_to_field(gn_solid_body_t *obj);
void gn_phys_add_bird_to_field(gn_bird_t *obj);

void gn_phys_reset_field(void);

#endif //FLAPPYBIRD_PHYSICS_INTERNAL_H
