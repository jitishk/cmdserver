#include <logger.h>
#include <listener.h>

jinfra::logger::LOG jlog;

int main(int argc [[maybe_unused]], char* argv[] [[maybe_unused]]) {

  jlog("server");
  jserver::Listener listener;

  listener.listen();
  return 0;
}
