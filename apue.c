#include "/home/zhangjin/projects/apue/src/include/apue.h"
#include <locale.h>

void temp(void);

int main(int argc, char *argv[])
{

    // 如果用 zh_CN.UTF-8 编码
    // 宽字符（固定字符就无法输出了）
    // setlocale(LC_ALL, "zh_CN.UTF-8");
    setlocale(LC_ALL, "");

    // 参数个数至少位 1
    // printf("%d\n", argc);

    // 第一个参数总是程序名
    // /home/zhangjin/projects/apue/apue
    // printf("%s\n", argv[0]);
    printf("Compiled on: %s %s\n", __DATE__, __TIME__);
    printf("------ Start ------\n");
    temp();
    printf("------  End  ------\n");

    return 0;
}

void temp(void)
{
}
