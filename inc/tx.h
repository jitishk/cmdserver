#ifndef __TX_H__
#define __TX_H__

#include <buffer.h>

namespace jserver {

using jinfra::buffer::Buffer;

class Tx {
public:
	int send(const Buffer& buffer) const;
};

} // namespace jserver

#endif // __TX_H__
