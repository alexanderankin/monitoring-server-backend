#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

extern int g_server_socket_handle;
void sighandler(int);

/**
 *
 */
void
m_server_attatch_sigint (void)
{
  signal(SIGINT, sighandler);
}

void sighandler(int signum)
{
  printf("\nCaught signal %d, coming out...\n", signum);
  printf("Closing sock: %d, and force_exiting.\n", g_server_socket_handle);
  close(g_server_socket_handle);
  exit(0);
}
