#ifndef __TX_H__
#define __TX_H__

#include <buffer.h>

namespace jserver::tx {

class Tx {
public:
	int send(const jinfra::buffer::Buffer& buffer) const;
};

} // namespace jserver::tx

#endif // __TX_H__
