#ifndef __CHANNEL_H__
#define __CHANNEL_H__

#include <tx.h>
#include <rx.h>
#include <status.h>

namespace jserver {

class Channel {
	private:
		Tx tx;
		Rx rx;
	public:
		jinfra::status::Status init();
		jinfra::status::Status send();
		jinfra::status::Status listen();
};

} // namespace jserver

#endif // __CHANNEL_H__
