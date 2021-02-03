#ifndef __c_object_h__
#define __c_object_h__

#include "malloc.h"
#include "string.h"
struct shape_poll{
    int shape_type;
    struct shape_vtbl* module;
};

struct shape_vtbl
{
    float (*area)(void* self);
    void (*draw)(void* self);
};

struct shape
{
    struct shape_vtbl* vptr;
    int x;
    int y;
};

enum{
    Rect_TYPE=1,
    Round_TYPE,
    triangle_TYPE,
};

#define MAX_POOL 10

extern struct shape_poll pool[MAX_POOL];
int pool_register(int type,struct shape_vtbl* module);
int shape_init(struct shape* self,int x,int y,int type);
void shape_move(struct shape* self,int dx,int dy);
struct shape* shape_creat(int x,int y);
void pool_init();
#endif