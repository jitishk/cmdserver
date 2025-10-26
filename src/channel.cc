#include <channel.h>

namespace jserver {

using jinfra::status::Status;

Status Channel::init() {
	return Status::OK;
}

Status Channel::send(const Buffer& buffer) const {
	(void) tx_.send(buffer);	
	return Status::OK;

}

Status Channel::recv(Buffer& buffer) {
	(void) rx_.listen();
	return Status::OK;
}

} // namespace jserver

