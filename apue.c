#include "/home/zhangjin/projects/apue/src/include/apue.h"
#include <locale.h>

void temp(void);

int main(int argc, char *argv[])
{

    setlocale(LC_ALL, "");

    // 参数个数至少位 1
    // printf("%d\n", argc);

    // 第一个参数总是程序名
    // /home/zhangjin/projects/apue/apue
    // printf("%s\n", argv[0]);

    printf("------ Start ------\n");
    temp();
    printf("------  End  ------\n");

    return 0;
}

void temp(void)
{

}
