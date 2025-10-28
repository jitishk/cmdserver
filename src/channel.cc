// TODO
// - ensure buffer sizes do not overflow
// - handle error

#include <channel.h>
#include <cstring>

namespace jserver {

using jinfra::status::Status;

Status Channel::init() {
	return Status::OK;
}

Status Channel::send(const Buffer& buffer) const {
	char buf[1024] = {0};
	buf[0] = static_cast<char>(buffer.id);
	memcpy(buf+1, buffer.data, sizeof(buf)-1);
	(void) tx_.send(buf, sizeof(buf));	
	return Status::OK;
}

Status Channel::recv(Buffer& buffer) {
	char buf[1024] = {0};
	(void) rx_.listen(buf, sizeof(buf));
	buffer.id = static_cast<jserver::ChannelID>(buf[0]);
	memcpy(buffer.data, buf+1, sizeof(buf)-1);
	return Status::OK;
}

} // namespace jserver

