#ifndef __Rect_H__
#define __Rect_H__
#include "c_object.h"
struct Rect{
    struct shape base;
    int width;
    int height;
};
struct Rect* Rect_creat(int x,int y,int width,int height,int type);
#endif