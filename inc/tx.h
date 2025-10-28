#ifndef __TX_H__
#define __TX_H__

#include <cstddef>

namespace jserver {

class Tx {
public:
	int send(const char* buffer, size_t buf_size) const;
};

} // namespace jserver

#endif // __TX_H__
