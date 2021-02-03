#include "c_object.h"
#include "Rect.h"

struct shape_vtbl rect_model={
    .area=rect_area,
};
struct Rect* Rect_creat(int x,int y,int width,int height)
{
    pool_register(Rect_TYPE,&rect_model);//先注册，再使用
    struct Rect* r=malloc(sizeof(struct Rect));
    shape_init((struct shape*)r,x,y,Rect_TYPE);//继承
    r->width=width;
    r->height=height;
    return r;
}
float rect_area(void* self)
{
    struct Rect* this=(struct Rect*)self;
    printf("rect area:point(%d,%d),width:%d,height:%d\n",this->base.x,this->base.y,this->width,this->height);
    return 0;
}