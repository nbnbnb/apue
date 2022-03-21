#include "/home/zhangjin/projects/apue/src/include/apue.h"
#include <dirent.h>

int main(int argc, char *argv[])
{
    DIR *dp;
    struct dirent *dirp;

    // 指定一个目录
    char *path = "/home/zhangjin/projects/apue/src/db";

    // 打开目录
    if ((dp = opendir(path)) == NULL)
    {
        err_sys("can't open %s", path);
    }

    // 对目录进行迭代
    // 每次调用 readdir 方法
    while ((dirp = readdir(dp)) != NULL)
    {
        // 输出目录名称
        printf("%s\n", dirp->d_name);
    }

    closedir(dp);
    exit(0);
}
