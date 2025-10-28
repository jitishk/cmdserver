#ifndef __RX_H__
#define __RX_H__

#include <cstddef>

namespace jserver {

class Rx {
public:
	Rx(int port);
	~Rx();
	void listen(char* buffer, size_t buf_size);
private:
	int sockfd_;
	
};

} // namespace jserver

#endif // _RX_H_
