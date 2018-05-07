
#ifndef FLAPPYBIRD_PHYSICS_ENGINE_H
#define FLAPPYBIRD_PHYSICS_ENGINE_H

#include <game_structs.h>
#include <timer_service.h>

#define OBJECTS_BUFFER_CAPACITY 15
#define BIRDS_BUFFER_CAPACITY 3
#define PHYSICS_CYCLE_TICKS 30

#define PHYSICS_TIME_STEP PHYSICS_CYCLE_TICKS * TIMER_PERIOD_SEC

void gn_phys_add_object(gn_game_object *obj);
void gn_phys_set_gravity(fb_float32_t gravity);

#endif //FLAPPYBIRD_PHYSICS_ENGINE_H
