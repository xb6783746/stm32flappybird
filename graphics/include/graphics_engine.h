
#ifndef FLAPPYBIRD_GRAPHICS_ENGINE_H
#define FLAPPYBIRD_GRAPHICS_ENGINE_H

#include <game_structs.h>

void gr_init(void);

void gr_update(void);

void gr_add_bird(pe_game_object *go);
void gr_add_pipe(pe_game_object *go);

void gr_delete(pe_game_object *go);

#endif //FLAPPYBIRD_GRAPHICS_ENGINE_H
