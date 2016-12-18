#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <arpa/inet.h>
#include "m_server_helpers.h"

#include <assert.h>

int
m_server_open_socket (void)
{
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  
  if (sockfd < 0) {
    /* perror is stdio.h function */
    perror("ERROR opening socket");
    exit(1);
  }

  return sockfd;
}

void
m_server_initialize_listen_address (struct sockaddr_in *s, int portno)
{
  /* Initialize socket structure */
  bzero((char *) s, sizeof((*s)));
  
  s->sin_family = AF_INET;
  s->sin_addr.s_addr = INADDR_ANY;
  s->sin_port = htons(portno);
}

/**
 * For some reason this doesnt quite work.
 */
void
m_server_bind (int sockfd, const struct sockaddr *serv_addr)
{
  assert((*serv_addr).sa_family == 2 );
  for (int i = 0; i < 14; ++i)
  {
    printf("%d\n", (*serv_addr).sa_data[i]);
  }

  // size_t size = sizeof(*(struct sockaddr_in*)serv_addr);
  if (bind(sockfd, serv_addr, sizeof(serv_addr)) < 0) {
    perror("ERROR on binding");
    exit(1);
  }

}
