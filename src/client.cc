#include <buffer.h>
#include <logger.h>
#include <tx.h>
#include <cstring>

jinfra::logger::LOG jlog;

int main(int argc [[maybe_unused]], char* argv[] [[maybe_unused]]) {

  jlog("client");
  jserver::Tx tx;
	jinfra::buffer::Buffer buffer;

	strncpy(buffer.data, "Hello PiOne", sizeof(buffer.data));

	tx.send(buffer);

  return 0;
}
