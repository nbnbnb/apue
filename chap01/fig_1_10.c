#include "/home/zhangjin/projects/apue/src/include/apue.h"

#include <sys/wait.h>

/* our signal-catching function */
static void sig_int(int);

int main(void)
{
    char buf[MAXLINE];
    pid_t pid;
    int status;

    // 在 Linux Shell 中测试

    // 输入 Ctrl+C，发送 SIGINT 信号
    // 然后执行 sig_int 处理程序

    // 注册信号处理程序
    if (signal(SIGINT, sig_int) == SIG_ERR)
    {
        err_sys("signal error");
    }

    /* print prompt (printf requires %% to print %) */
    // 输出一个 %（转义）
    printf("%% ");

    while (fgets(buf, MAXLINE, stdin) != NULL)
    {
        // 输入了回车
        if (buf[strlen(buf) - 1] == '\n')
        {
            // 设置终止符
            /* replace newline with null */
            buf[strlen(buf) - 1] = 0;
        }

        // 创建子进程
        if ((pid = fork()) < 0)
        {
            err_sys("fork error");
        }
        else if (pid == 0)
        {
            /* child */
            // 子进程执行命令
            execlp(buf, buf, (char *)0);

            // 如果失败了，才会走此段代码
            // 否则，上面的进程执行后退出

            err_ret("couldn't execute: %s", buf);
            exit(127);
        }

        /* parent */
        if ((pid = waitpid(pid, &status, 0)) < 0)
        {
            err_sys("waitpid error");
        }

        printf("%% ");
    }

    exit(0);
}

void sig_int(int signo)
{
    printf("interrupt\n%% ");
}
