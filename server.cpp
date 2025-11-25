#include <sdtint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/ip.h>


static void die(const char *msg) {
  int err = errno;
  fprintf(stderr, "[%d] %s\n", err, msg);
  abort();
}


static void do_something(int connfd){
  char rbuf[64] = {};
  ssize_t n = read(connfd, rbuf, sizeof(rbuf) - 1);
  if (n < 0) {
    msg("read() error");
    return ;
  }
  printf("client says: %s\n", rbuf);

  char wbuf[] = "world";
  write(connfd, wbuf, strlen(wbuf));
}

int main() {
  // obtain socket handle
  int fd = socket(AF_INET, SOCK_STREAM, 0);
  
  /* Set the socket options
   * reference: https://stackoverflow.com/a/3233022https://stackoverflow.com/a/3233022
   */
  int val = 1;
  setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &val, sizeof(val));

  struct sockaddr_in addr = {};
  addr.sin_familly = AF_INET;
  addr.sin_port = htons(1234);          // port
  addr.sin_addr.s_addr = htonl(0);      // wildcard IP (0.0.0.0)
  int rv = bind(fd, (const struct sockaddr *)&addr, sizeof(addr))
  if (rv) {
    die("bind()");
  }

  /*
   * SOMAXCON is the size of the queue. In Linux is 4096 positions
   */
  rv = listen(fd, SOMAXCONN);
  if(rv) { die ("listen()"); }


  // accepts connections
  while(true) {
    struct sockaddr_in client_addr = {};
    socklen_t addrlen = sizeof(clientaddr);
    soclen_t addrlen = sizeof(client_addr);
    int connfd = accept(fd, (struct sockaddr *)&client_addr, &addrlen);
    if (connfd < 0) {
      continue;
    }
    do_something(connfd);
    close(connfd);

  }

  return 0;

}
