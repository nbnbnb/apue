#include "/home/zhangjin/projects/apue/src/include/apue.h"

int main(void)
{
    // 每次打印
    // 进程 ID 都不一样
    printf("hello world from process ID %ld\n", (long)getpid());
    exit(0);
}
