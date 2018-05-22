

#ifndef FLAPPYBIRD_FLAPPYBIRD_SETTINGS_H
#define FLAPPYBIRD_FLAPPYBIRD_SETTINGS_H


#define PHYSICS_CYCLE_TICKS 30
#define PHYSICS_TIME_STEP PHYSICS_CYCLE_TICKS * TIMER_PERIOD_SEC

#define GRAPHICS_CYCLE_TICKS 30
#define GRAPHICS_TIME_STEP GRAPHICS_CYCLE_TICKS * TIMER_PERIOD_SEC

#define BIRD_WIDTH 5
#define BIRD_HEIGHT 5
#define BIRD_HORIZONTAL_VELOCITY -50

#define BIRD_HP 3

#define BIRD_JUMP -35

#define BIRD_INITIAL_X 10
#define BIRD_INITIAL_Y 10
#define DIST_BETWEEN_BIRDS BIRD_WIDTH*2

#define PIPE_WIDTH 10
#define PIPE_HOLE_SIZE 20

#define GRAVITY 50

#endif //FLAPPYBIRD_FLAPPYBIRD_SETTINGS_H
