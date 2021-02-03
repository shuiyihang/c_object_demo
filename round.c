#include "c_object.h"
#include "round.h"

struct shape_vtbl round_model={
    .area=round_area,
};
struct Round* Round_creat(int x,int y,int radius)
{
    pool_register(Round_TYPE,&round_model);
    struct Round* r=malloc(sizeof(struct Round));
    shape_init((struct shape*)r,x,y,Round_TYPE);
    r->radius=radius;
    return r;
}


float round_area(void* self)
{
    struct Round* this=(struct Round*)self;
    printf("round area:point(%d,%d),radius:%d\n",this->base.x,this->base.y,this->radius);
    return 0;
}