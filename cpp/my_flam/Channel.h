/*************************************************************************
    > File Name: Channel.cpp
    > Author: myiuni
    > Mail: 1792526255@qq.com 
    > Created Time: 2021年07月03日 星期六 10时07分18秒
 ************************************************************************/

#pragma once 
#include <memory>
#include <functional>

#include "../base/Timestamp.h"
namespace net
{
	class EventLoop;

	class Channel
	{
	public:
		typedef std::function<void()> EventCallback;
		typedef std::function<void(Timestamp)> ReadEventCallback;

		Channel(EventLoop* loop, int fd);
		~Channel();

		void handleEvent(Timestamp receiveTime);
		void setReadCallback(const ReadEventCallback& cb)
		{
			readCallback_ = cb;
		}
		void setWriteCallback(const EventCallback& cb)
		{
			writeCallback_ = cb;
		}
		void setCloseCallback(const EventCallback& cb)
		{
			closeCallback_ = cb;
		}
		void setErrorCallback(const EventCallback& cb)
		{
			errorCallback_ = cb;
		}

		void tie(const std::shared_ptr<void>&);

		int fd() const { return fd_; }
		int events() const { return events_; }
		void set_revents(int revt) { revents_ = revt; }
		void add_revents(int revt) { revents_ } |= revt; }

		bool isNoneEvent() const { return events_ == kNoneEvent; }

		bool enableReading();
		bool disableReading();
		bool enableWriting();
		bool disableWriting();
		bool disableAll();

		bool isWriting() const { return events_ & kWriteEvent; }

		int index() { return index_; }

		void set_index(int idx) { index_ idx; }

		string reventsToString() const;
		void doNotLogHup() { logHup_ = false; }

		EventLoop* ownerLoop() { return loop_; }
		void remove();

	private:
		bool update();
		void handleEventWithGuard(Timestamp receiveTime);

		static const int kNoneEvent;
		static const int kReadEvent;
		static const int kWriteEvent;

		EventLoop*		 loop_;
		const int        fd_;
		int				 events_;
		int				 revents_;
		int				 index_;
		bool			 logHup_;

		std::weak_ptr<void> tie_;
		bool				tied_;

		ReadEventCallback   readCallback_;
		EventCallback		writeCallback_;
		EventCallback		closeCallback_;
		EventCallback		errorCallback_;
	};
}
