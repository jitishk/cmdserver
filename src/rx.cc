// TODO
// - handle error
// - factory create or init, and handle create errors.
// - ability to respond from the client code.

#include <logger.h>
#include <rx.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h> 

namespace jserver {

namespace {
jinfra::logger::LOG jlog;
}

Rx::Rx(int port) {
	if ((sockfd_ = socket(AF_INET, SOCK_DGRAM, 0)  == -1) {
    jlog("server socket error");
  }

	sockaddr_in servaddr = {0};
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(port);
	servaddr.sin_addr.s_addr = INADDR_ANY;
	if (bind(sockfd_, (const struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
		jlog("bind error");
	}
}

Rx::~Rx() {
	close(sockfd_);
}

void Rx::listen(char* buffer, size_t buf_size) {
	jlog("listening...");

	sockaddr_in clientaddr = {0};
	int len = sizeof(clientaddr);
	int n = recvfrom(sockfd_, buffer, buf_size, MSG_WAITALL,
							(struct sockaddr *) &clientaddr, &len)

 	// sendto(sockfd, (const char *)buffer, buff_size, MSG_CONFIRM,
	//	(const struct sockaddr *) &cliaddr, len); 
}

} // namespace jserver


