#include "c_object.h"

struct shape_poll pool[MAX_POOL];

int pool_register(int type,struct shape_vtbl* module)
{
    int i;
    for(i=0;i<MAX_POOL;i++)
    {
        if(pool[i].shape_type==0)
        {
            pool[i].shape_type=type;
            pool[i].module=module;
            break;
        }
    }
    if(i==MAX_POOL)
        return -1;
    return 0;
}
void pool_init()
{
    memset(pool,0,sizeof(pool[MAX_POOL]));
}
struct shape* shape_creat(int x,int y)
{
    struct shape* s=malloc(sizeof(struct shape));
    s->x=x;
    s->y=y;
    
    return s;
}
int shape_init(struct shape* self,int x,int y,int type)
{
    int i=0;
    for(;i<MAX_POOL;i++)
    {
        if(pool[i].shape_type==type)
        {
            self->vptr=pool[i].module;
            break;
        }
    }
    if(i==MAX_POOL)
        return -1;
    self->x=x;
    self->y=y;
    return 0;
}