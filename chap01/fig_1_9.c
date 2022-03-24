#include "/home/zhangjin/projects/apue/src/include/apue.h"

int main(void)
{
    // uid = 1000, gid = 1000
    printf("uid = %d, gid = %d\n", getuid(), getgid());
    exit(0);
}
