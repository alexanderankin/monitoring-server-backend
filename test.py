import socket
import sys

# Create a TCP/IP socket
sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# Connect the socket to the port where the server is listening
server_address = ('localhost', 5001)
print 'connecting to %s port %s' % server_address
sock.connect(server_address)

try:
  # Send data
  message = 'This is the message.  It will be repeated.'
  print 'sending "%s"' % message
  sock.sendall(message)

  # Look for the response
  amount_received = 0
  amount_expected = len(message)
  no_data_recv = False
  
  while not no_data_recv:
    data = sock.recv(50)
    amount_received += len(data)
    print 'received "%s"' % data
    if len(data) == 0: no_data_recv = True

  assert(amount_received == 18)

finally:
  print >>sys.stderr, 'closing socket'
  sock.close()
