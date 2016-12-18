#ifndef m_server_helpers_h
#define m_server_helpers_h

#include <sys/types.h> 
#include <sys/socket.h>
#include <arpa/inet.h>

/**
 * Opens a socket and returns the file descriptor.
 */
int m_server_open_socket(void);

/**
 * Initializes the socket listening address structure.
 */
void m_server_initialize_listen_address (struct sockaddr_in *, int);

/**
 * Now bind the host address using bind() call.
 */
void m_server_bind (int, const struct sockaddr*);

#endif
