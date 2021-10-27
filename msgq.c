/*************************************************************************
    > File Name: msgq.c
    > Author: myiuni
    > Mail: 1792526255@qq.com 
    > Created Time: 2021年10月27日 星期三 21时32分15秒
 ************************************************************************/
#include <sys/msg.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int qid;

	if (argc != 2) {
		puts("USAGE: del_msgq.c <queue ID >");
		exit(1);
	}

	qid = atoi(argv[1]);
	system("ipcs -q");

	if ((msgctl(qid, IPC_RMID, NULL)) < 0) {
		perror("msgctl");
		exit(1);
	}

	system("ipcs -q");
	printf("successfully removed %d queue\n", qid);

	exit(0);

}
