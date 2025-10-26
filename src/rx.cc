#include <logger.h>
#include <rx.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h> 

namespace jserver {

namespace {
jinfra::logger::LOG jlog;
}

void Rx::listen() {
  jlog("rx");
  int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
  if (serverSocket == -1) {
    jlog("server socket error");
  }

	sockaddr_in serverAddress;
	serverAddress.sin_family = AF_INET;
	serverAddress.sin_port = htons(5665); // Example port
	serverAddress.sin_addr.s_addr = INADDR_ANY; // Listen on all available interfaces
	if (bind(serverSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) == -1) {
    jlog("bind error");
	}

	if (::listen(serverSocket, 5) == -1) { // 5 is the backlog queue size
		jlog("listen error");
	}

	jlog("listening...");

	sockaddr_in clientAddress;
  socklen_t clientLen = sizeof(clientAddress);
  int clientSocket = accept(serverSocket, (struct sockaddr*)&clientAddress, &clientLen);
  if (clientSocket == -1) {
		jlog("accept error");
  }

	char buffer[1024] = {0};
	recv(clientSocket, buffer, sizeof(buffer), 0);
	jlog(buffer);
	close(clientSocket);
}

} // namespace jserver


