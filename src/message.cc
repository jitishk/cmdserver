#include <message.h>
#include <status.h>
#include <logger.h>
#include <cstdint>
#include <cstddef>
#include <cstring>

namespace jnet::message {

jinfra::logger::LOG jlog;
using jinfra::status::Status;

Message::Message(MsgType type, const char* buffer, size_t buflen) {
	if (buffer == nullptr) {
		jlog("null buffer");
	}
	if (buflen > MAX_BUFFER_SIZE) {
		jlog("buffer size exceeded");
		return;
	}
	msg_[0] = static_cast<uint8_t>(type);
	memcpy(msg_+1, buffer, buflen);
	msglen_ = buflen + MSG_HDR_SIZE;
}

const char* Message::GetMsg() const {
	return msg_;
}

size_t Message::GetMsgLen() const {
	return msglen_;
}

} // jnet::message
