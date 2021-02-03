#include "c_object.h"
#include "malloc.h"
#include "Rect.h"
struct Rect* Rect_creat(int x,int y,int width,int height)
{
    struct Rect* r=malloc(sizeof(struct Rect));
    shape_init((struct shape*)r,x,y);
    r->width=width;
    r->height=height;
    return r;
}