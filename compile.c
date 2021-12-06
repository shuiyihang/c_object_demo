#include <stdio.h>
#include "Rect.h"
#include "round.h"

int main()
{
    pool_init();
    struct shape* rect=(struct shape*)Rect_creat(5,5,10,10);//对象
    rect->vptr->area(rect);//多态

    struct shape* round=(struct shape*)Round_creat(7,8,5);//对象
    round->vptr->area(round);//多态

    free(rect);
    free(round);
    return 0;
}