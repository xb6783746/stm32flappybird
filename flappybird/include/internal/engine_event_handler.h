

#ifndef FLAPPYBIRD_ENGINE_EVENT_HANDLER_H
#define FLAPPYBIRD_ENGINE_EVENT_HANDLER_H

#include <game_structs.h>

void fb_on_object_deleted(pe_game_object *go);
void fb_on_collision(pe_game_object *go1, pe_game_object *go2);

#endif //FLAPPYBIRD_ENGINE_EVENT_HANDLER_H
