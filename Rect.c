#include "c_object.h"
#include "malloc.h"
#include "Rect.h"
struct Rect* Rect_creat(int x,int y,int width,int height,int type)
{
    struct Rect* r=malloc(sizeof(struct Rect));
    shape_init((struct shape*)r,x,y,type);
    r->width=width;
    r->height=height;
    return r;
}