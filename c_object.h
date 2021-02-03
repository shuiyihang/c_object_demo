#ifndef __c_object_h__
#define __c_object_h__
struct shape;
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


#define MAX_POOL 10


int pool_register(int type,struct shape_vtbl* module);
int shape_init(struct shape* self,int x,int y,int type);
void shape_move(struct shape* self,int dx,int dy);
struct shape* shape_creat(int x,int y);
#endif