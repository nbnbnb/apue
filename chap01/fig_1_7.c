#include "/home/zhangjin/projects/apue/src/include/apue.h"
#include <sys/wait.h>

int main(void)
{
    /* from apue.h */
    char buf[MAXLINE];

    pid_t pid;
    int status;

    /* print prompt (printf requires %% to print %) */
    printf("%% ");

    while (fgets(buf, MAXLINE, stdin) != NULL)
    {
        if (buf[strlen(buf) - 1] == '\n')
        {
            /* replace newline with null */
            buf[strlen(buf) - 1] = 0;
        }

        if ((pid = fork()) < 0)
        {
            err_sys("fork error");
        }
        else if (pid == 0)
        {
            /* child */
            // 调用 execlp 以执行从标准输入读入的命令
            // 这就用新的程序文件替换了子进程原先执行的程序文件
            execlp(buf, buf, (char *)0);
            err_ret("couldn't execute: %s", buf);
            exit(127);
        }

        /* parent */
        // 等待子进程终止
        if ((pid = waitpid(pid, &status, 0)) < 0)
        {
            err_sys("waitpid error");
        }

        printf("%% ");
    }

    exit(0);
}
