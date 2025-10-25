#include <logger.h>
#include <rx.h>

jinfra::logger::LOG jlog;

int main(int argc [[maybe_unused]], char* argv[] [[maybe_unused]]) {

  jlog("server");
  jserver::Rx rx;

  rx.listen();
  return 0;
}
