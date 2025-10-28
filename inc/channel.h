#ifndef __CHANNEL_H__
#define __CHANNEL_H__

#include <tx.h>
#include <rx.h>
#include <status.h>

namespace jserver {

using jinfra::status::Status;

enum class ChannelID : char {
	CH_INVALID = 0,
	CH_SYSTEM
};

struct Buffer {
	ChannelID id;
	char data[1024];
};

class Channel {
	private:
		Tx tx_;
		Rx rx_;
	public:
		Status init();
		Status send(const Buffer& buffer) const;
		Status recv(Buffer& buffer);
};

} // namespace jserver

#endif // __CHANNEL_H__
