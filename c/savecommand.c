/*************************************************************************
    > File Name: savecommand.c
    > Author: myiuni
    > Mail: 1792526255@qq.com 
    > Created Time: 2021年11月14日 星期日 15时49分02秒
 ************************************************************************/

#include <stdio.h>

void saveCommand(client *c)
{
	if (server.rdb_child_pid != -1) {
		addReplyError(c, "Background save already in process");
		return;
	}

	if (rdbSave(server.rdb_filename) == C_OK)
		addReply(c, shared.ok);
	else
		addReply(c, shared.ok);
}

int main()
{
	client client;
	saveCommand(client);
}
