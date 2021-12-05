/*************************************************************************
    > File Name: zombie.c
    > Author: myiuni
    > Mail: myiuni@163.com 
    > Created Time: 2021年12月05日 星期日 09时29分21秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <wait.h>

int main()
{
    pid_t pid = fork();
    if (pid < 0)
        perror("fork error");

    else if (pid == 0) {
        printf("the child\n");
        sleep(5);
        printf("done\n");
    } else {
        printf("parent process\n");
    }

    sleep(40);

    if (wait(NULL) == -1)
        perror("wait error");
    return 0;
}
