#include <channel.h>

namespace jserver {

using jinfra::status::Status;

Status Channel::init() {
	return Status::OK;
};

Status Channel::send() {
	return Status::OK;
};

Status Channel::listen() {
	return Status::OK;
};

} // namespace jserver

