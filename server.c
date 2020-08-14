#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <event2/event.h>
#include <event2/bufferevent.h>
#include <event2/listener.h>

void read_cb(struct bufferevent *bev, void *arg)
{
	char buf[1024] = {0};
	bufferevent_read(bev, buf, sizeof(buf));
	printf("recv buf: %s\n", buf);

	char *pt = "The data you sent to me i have received.....";

	bufferevent_write(bev, pt, strlen(pt)+1);
	printf("I have sent the data, to client.....\n");
}

void write_cb(struct bufferevent *bev, void *arg)
{
	printf("sent data has been sent\n");
}

void event_cb(struct bufferevent *bev, short events, void *arg)
{
	if (events & BEV_EVENT_EOF)
	{
		printf("connection closed\n");
	}

	else if (events & BEV_EVENT_ERROR)
	{
		printf("some other error\n");
	}
}

void listen_cb(
		struct evconnlistener *listener,
		evutil_socket_t fd,
		struct sockaddr *addr,
		int len,
		void *ptr)
{
	struct event_base* base = (struct event_base*)ptr;
	struct bufferevent* bev = NULL;

	bev = bufferevent_socket_new(base, fd, BEV_OPT_CLOSE_ON_FREE);
	bufferevent_setcb(bev, read_cb, write_cb, event_cb, NULL);

	bufferevent_enable(bev, EV_READ);
}

int main()
{
	struct sockaddr_in serv;
	serv.sin_family = AF_INET;
	serv.sin_port = htons(8765);
	serv.sin_addr.s_addr = htonl(INADDR_ANY);

	struct event_base* base = event_base_new();
	struct evconnlistener* listen = NULL;

	listen = evconnlistener_new_bind(base, listen_cb, base,
									 LEV_OPT_CLOSE_ON_FREE | LEV_OPT_REUSEABLE, -1, (struct sockaddr *)&serv, sizeof(serv));

	event_base_dispatch(base);

	evconnlistener_free(listen);
	event_base_free(base);
	return 0;
}
