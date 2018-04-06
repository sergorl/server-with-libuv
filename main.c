#include <stdio.h>
#include <unistd.h>
#include "server.h"

int main() {
    run_tcp_server("127.0.0.1");
    return 0;
}
