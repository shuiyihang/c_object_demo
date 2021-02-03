/**
 * 测试结构体中存放函数指针，并使用
*/
#include <stdio.h>
typedef int (*fun1)(int a,int b);
typedef void (*fun2)(void);
typedef void (*fun3)(void *data);

int fun1_model(int par1,int par2)
{
    printf("fun1_model");
}
void fun2_model(void)
{
    printf("fun2_model");
}
void fun3_model(void *dat)
{
    char *str=(char*)dat;
    printf("fun3_model:%s",str);
}

struct start_cb
{
    fun1 fun1_api;
    fun2 fun2_api;
    fun3 fun3_api;
}test={
    .fun1_api=fun1_model,
    .fun2_api=fun2_model,
    .fun3_api=fun3_model,
};
void fin_api(struct start_cb* api)
{
    fun3 use=*((fun3*)(&(api->fun1_api)+2));
    use("useless people\n");
    printf("addr:%p//%p///%p///%p\n",&test,&(api->fun1_api),&(api->fun2_api)+1,&(api->fun3_api));
}
int main()
{
    int *p;
    printf("p:%ld\n",sizeof(p));
    fin_api(&test);
}