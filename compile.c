#include "Rect.h"
#include <stdio.h>

float rect_area(struct shape* self)
{
    printf("rect area\n");
    return 0;
}
float round_area(struct shape* self)
{
    printf("round area\n");
    return 0;
}

struct shape_vtbl rect_model={
    .area=rect_area,
};
struct shape_vtbl round_model={
    .area=round_area,
};



float shape_area(void* self)
{   
    struct shape* this=(struct shape*)self;
    return this->vptr->area(self);
}



int main()
{
    struct Rect* r=Rect_creat(5,5,10,10);
    pool_register(1,&rect_model)

}