#include <status.h>
#include <logger.h>
// #include <channel.h>


// #include <rx.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h> 

namespace {
jinfra::logger::LOG jlog;
}

using jinfra::status::Status;


class Server {
public:
	Server(int port);
	~Server();
	ssize_t listen(char* buffer, size_t buf_size, struct sockaddr_in& client, socklen_t* len);
	ssize_t respond(const char* buffer, size_t buf_size, const struct sockaddr_in& client, socklen_t len);
	void respond();
private:
	int sockfd_;

};

Server::Server(int port) {
	if ((sockfd_ = socket(AF_INET, SOCK_DGRAM, 0)) == -1) {
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

Server::~Server() {
	close(sockfd_);
}

ssize_t Server::listen(char* buffer, size_t buf_size, struct sockaddr_in& client, socklen_t* len) {
	jlog("listening...");
	client = {0};
	ssize_t n = recvfrom(sockfd_, buffer, buf_size, MSG_WAITALL,
							(struct sockaddr *) &client, len);
	return n;
}

ssize_t Server::respond(const char* buffer, size_t buf_size, const struct sockaddr_in& client, socklen_t len) {
	jlog("responding...");
	ssize_t n = sendto(sockfd_, (const char *)buffer, buf_size, MSG_CONFIRM,
			(const struct sockaddr *) &client, len); 
	return n;
}

int main(int argc [[maybe_unused]], char* argv[] [[maybe_unused]]) {

	Server server(12345);
	struct sockaddr_in client = {0};
	socklen_t len = sizeof(client);
	char buffer[1024];
	
	while (server.listen(buffer, sizeof(buffer), client, &len) > 0) {
		server.respond(buffer, sizeof(buffer), client, len);
	}
  return 0;
}



