#include "/home/zhangjin/projects/apue/src/include/apue.h"
#include <errno.h>

int main(int argc, char *argv[])
{
    // 通过 strerror 方法，可以转换为特定错误文本
    fprintf(stderr, "EACCES: %s\n", strerror(EACCES));

    // 设置 errno
    // /* No such file or directory */
    errno = ENOENT;

    // 输出错误信息，然后返回
    // 例如
    // kkking: No such file or directory
    perror("kkking");

    exit(0);
}
