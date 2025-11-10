#include <logger.h>
#include <channel.h>
#include <cstring>

#include <message.h>

#include <arpa/inet.h>
#include <logger.h>
#include <netinet/in.h>
#include <string.h>
#include <sys/socket.h>
#include <tx.h>
#include <unistd.h> 

jinfra::logger::LOG jlog;

class Client {
private:
	int sockfd_;
	sockaddr_in server_;

public:
	Client(const char* ip, int port);
  ~Client();

	ssize_t send(char* buffer, size_t buf_len);
};

Client::Client(const char* ip, int  port) {
	sockfd_ = socket(AF_INET, SOCK_DGRAM, 0);
	if (sockfd_ == -1) {
		jlog("socket error");		
	}

	server_.sin_family = AF_INET;
	server_.sin_port = htons(port); // Server port
	inet_pton(AF_INET, ip, &server_.sin_addr); // Server IP
}

Client::~Client() {
	close(sockfd_);
}

ssize_t Client::send(char* buffer, size_t buf_size) {
	jlog("sending...");
	ssize_t n = sendto(sockfd_, (const char *)buffer, buf_size, MSG_CONFIRM,
			(const struct sockaddr *) &server_, sizeof(server_)); 

	n = recvfrom(sockfd_, buffer, buf_size, MSG_WAITALL, NULL, NULL);

	return n;
}

using jnet::message::Message;

int main(int argc [[maybe_unused]], char* argv[] [[maybe_unused]]) {

  jlog("client");

	// jserver::Buffer buffer;	
	Client client("10.0.0.57", 12345);
	while (true) {
		std::string cmdline;
		std::cout << "jsk >> ";
		int len = std::getline(std::cin, cmdline, '\n');
		jnet::message::Message msg(Message::MsgType::ECHO, cmdline.c_str(), cmdline.size());
		// buffer.id = jserver::ChannelID::CH_SYSTEM;
		// strncpy(buffer.data, "Hello PiOne", sizeof(buffer.data));
		// client.send(buffer.data, sizeof(buffer.data));
		client.send(msg.GetMsg(), msg.GetMsgLen());
		jlog(msg.GetMsg());
	}

	return 0;
}
