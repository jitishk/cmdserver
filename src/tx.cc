// TODO
// - handle error

#include <arpa/inet.h>
#include <logger.h>
#include <netinet/in.h>
#include <string.h>
#include <sys/socket.h>
#include <tx.h>
#include <unistd.h> 


namespace jserver {

namespace {
jinfra::logger::LOG jlog;
}

int Tx::send(const char* buffer, size_t buf_size) const {

	int clientSocket = socket(AF_INET, SOCK_STREAM, 0); // For TCP/IPv4
	if (clientSocket == -1) {
		jlog("socket error");		
	}

	sockaddr_in serverAddress;
	serverAddress.sin_family = AF_INET;
	serverAddress.sin_port = htons(12345); // Server port
	inet_pton(AF_INET, "10.0.0.57", &serverAddress.sin_addr); // Server IP

	if (connect(clientSocket, (sockaddr*)&serverAddress, sizeof(serverAddress)) == -1) {
		jlog("connect error");
	}

	ssize_t bytesSent = ::send(clientSocket, buffer, buf_size, 0);
	if (bytesSent == -1) {
		jlog("send error");
	}

	close(clientSocket);

	return bytesSent;
}

} // namespace jserver
