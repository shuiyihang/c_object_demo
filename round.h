#ifndef __round_h__
#define __round_h__

struct Round{
    struct shape base;
    int radius;
};
struct Round* Round_creat(int x,int y,int radius);
float round_area(void* self);

#endif