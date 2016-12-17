CFLAGS += -g
.PHONY : all

all : run

run : server
	./server

server : server.c

clean :
	find . -type f -executable -exec rm '{}' \;
