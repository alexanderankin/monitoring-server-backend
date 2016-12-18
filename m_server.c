#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include <assert.h>

#include "m_server.h"

#ifndef MAX_QUEUED_CONS
#define MAX_QUEUED_CONS 5
#endif

int g_server_socket_handle; // global

int main( int argc, char *argv[] ) {
  int server_socket_handle, accepted_socket_handle, portno;
  struct sockaddr_in serv_addr;
  int pid;
  
  server_socket_handle = m_server_open_socket();
  m_server_initialize_listen_address(&serv_addr, 5001);

  assert((*((struct sockaddr *) &serv_addr)).sa_family == 2 );
  assert((*((struct sockaddr *) &serv_addr)).sa_data[0] == 19 );
  assert((*((struct sockaddr *) &serv_addr)).sa_data[1] == -119 );

  /* bind */
  if (bind(server_socket_handle, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
    perror("ERROR on binding");
    exit(1);
  }
  
  /* listen */
  listen(server_socket_handle, MAX_QUEUED_CONS);
  g_server_socket_handle = server_socket_handle;
  m_server_attatch_sigint();
  
  while (1) {
    accepted_socket_handle = accept(server_socket_handle, NULL, NULL);

    if (accepted_socket_handle < 0) {
      perror("ERROR on accept");
      exit(1);
    }
    
    /* Create child process */
    pid = fork();
    
    if (pid < 0) {
      perror("ERROR on fork");
      exit(1);
    }
    
    if (pid == 0) {
      /* This is the client process */
      close(server_socket_handle);
      m_server_child_handle(accepted_socket_handle);
      exit(0);
    }
    else {
      close(accepted_socket_handle);
    }
    
  }
}
