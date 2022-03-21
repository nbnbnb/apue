#include "/home/zhangjin/projects/apue/src/include/apue.h"

#define BUFFSIZE 4096

int main(void)
{
    int n;
    char buf[BUFFSIZE];

    // 若通过 ./fig1_4 <infile> outfile 将会指向文件的复制

    // 控制台通过 Ctrl+D 终止
    while ((n = read(STDIN_FILENO, buf, BUFFSIZE)) > 0)
    {
        if (write(STDOUT_FILENO, buf, n) != n)
        {
            err_sys("write error");
        }
    }

    if (n < 0)
    {
        err_sys("read error");
    }

    exit(0);
}
