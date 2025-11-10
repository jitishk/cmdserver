#ifndef __MESSAGE_H__
#define __NESSAGE_H_

#include <cstdint>
#include <cstddef>

namespace jnet::message {

class Message {
public:
	using MsgTypeEnumSize = uint8_t;
	enum class MsgType : MsgTypeEnumSize {
		ECHO,
	};

	Message(MsgType type, const char* buffer, size_t buflen);

	const char* GetMsg() const;	
	size_t GetMsgLen() const;

private:
	MsgType type_;
	static const size_t MAX_MSG_SIZE = 4096;
	static const size_t MSG_HDR_SIZE = sizeof(MsgTypeEnumSize);
	static const size_t MAX_BUFFER_SIZE = MAX_MSG_SIZE - MSG_HDR_SIZE;
	char msg_[MAX_MSG_SIZE];
	size_t msglen_;
};

}

#endif // __MESSAGE_H__
