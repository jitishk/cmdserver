#include <arpa/inet.h>
#include <buffer.h>
#include <logger.h>
#include <netinet/in.h>
#include <string.h>
#include <sys/socket.h>
#include <tx.h>
#include <unistd.h> 


namespace jserver::tx {

jinfra::logger::LOG jlog;

int Tx::send(const jinfra::buffer::Buffer& buffer) const {
	int clientSocket = socket(AF_INET, SOCK_STREAM, 0); // For TCP/IPv4
	if (clientSocket == -1) {
		jlog("socket error");		
	}

	sockaddr_in serverAddress;
	serverAddress.sin_family = AF_INET;
	serverAddress.sin_port = htons(5665); // Server port
	inet_pton(AF_INET, "10.0.0.57", &serverAddress.sin_addr); // Server IP

	if (connect(clientSocket, (sockaddr*)&serverAddress, sizeof(serverAddress)) == -1) {
		jlog("connect error");
	}


	const char* message = buffer.data;
	ssize_t bytesSent = ::send(clientSocket, message, strlen(message), 0);
	if (bytesSent == -1) {
		jlog("send error");
	}

	close(clientSocket);

	return bytesSent;
}

} // namespace jserver::tx
