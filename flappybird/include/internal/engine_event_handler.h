

#ifndef FLAPPYBIRD_ENGINE_EVENT_HANDLER_H
#define FLAPPYBIRD_ENGINE_EVENT_HANDLER_H

#include <game_structs.h>

void on_object_deleted(gn_game_object *go);
void on_collision(gn_game_object *go1, gn_game_object *go2);

#endif //FLAPPYBIRD_ENGINE_EVENT_HANDLER_H
