
#include <internal/game_field.h>
#include <memory.h>

gn_solid_body_t *bodies[SOLID_BODIES_BUFFER_CAPACITY];
gn_bird_t *birds[BIRDS_BUFFER_CAPACITY];

void gn_phys_add_body_to_field(gn_solid_body_t *obj){

    int i;
    for(i = 0; i < SOLID_BODIES_BUFFER_CAPACITY; i++){

        if(bodies[i] == NULL){

            bodies[i] = obj;
            break;
        }
    }
}
void gn_phys_add_bird_to_field(gn_bird_t *obj){

    int i;
    for(i = 0; i < BIRDS_BUFFER_CAPACITY; i++){

        if(birds[i] == NULL){

            birds[i] = obj;
            break;
        }
    }
}

void gn_phys_reset_field(void){

    memset(bodies, NULL, sizeof(bodies));
    memset(birds, NULL, sizeof(bodies));
}
