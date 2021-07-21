/*************************************************************************
    > File Name: epollmyself.cpp
    > Author: myiuni
    > Mail: 1792526255@qq.com 
    > Created Time: 2021年07月21日 星期三 20时17分51秒
 ************************************************************************/

#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/epoll.h>
#include<poll.h>
#include<iostream>
#include<string.h>
#include<vector>
#include<errno.h>
#include<iostream>

int main()
{
	int listenfd = socket(AF_INET, SOCK_STREAM, 0);
	int on = 1;
	setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, (char *)&on, sizeof(on));
	setsockopt(listenfd, SOL_SOCKET, SO_REUSEPORT, (char *)&on, sizeof(on));

	struct sockaddr_in bindaddr;
	bindaddr.sin_family = AF_INET;
	bindaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	bindaddr.sin_port = htons(6666);
	bind(listenfd, (struct sockaddr*)&bindaddr, sizeof(bindaddr));

	listen(listenfd, 5);

	int epollfd = epoll_create(1);
	epoll_event listen_fd_event;
	listen_fd_event.data.fd = listenfd;
	listen_fd_event.events = EPOLLIN;

	epoll_ctl(epollfd, EPOLL_CTL_ADD, listenfd, &listen_fd_event);
	
	int n;
	while (1) {
		epoll_event epoll_events[1024];
		n = epoll_wait(epollfd, epoll_events, 1024, 1000);
		for (int i = 0; i < n; ++i) {
			if (epoll_events[i].events & EPOLLIN) {
				if (epoll_events[i].data.fd == listenfd) {
					struct sockaddr_in clieaddr;
					socklen_t len = sizeof(clieaddr);
					int cliefd = accept(listenfd, (struct sockaddr *)&clieaddr, &len);
					epoll_event client_fd_event;
					client_fd_event.data.fd = cliefd;
					client_fd_event.events = EPOLLIN;
					epoll_ctl(epollfd, EPOLL_CTL_ADD, cliefd, &client_fd_event);
				} else {
					char ch;
					int m = recv(epoll_events[i].data.fd, &ch, 1, 0);
					std::cout << "recv from:" << epoll_events[i].data.fd << "--->" << ch << std::endl;
				}

			}

		}
	}
	close(listenfd);
	return 0;
}
