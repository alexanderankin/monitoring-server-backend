
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include "child_processing.h"

void m_server_child_handle (int sock) {
  int n;
  char buffer[256];
  bzero(buffer,256);
  n = read(sock,buffer,255);
  
  if (n < 0) {
    perror("ERROR reading from socket");
    exit(1);
  }
  
  printf("Here is the message: %s\n",buffer);
  n = write(sock,"I got your message",18);
  
  if (n < 0) {
    perror("ERROR writing to socket");
    exit(1);
  }
  
}
