CFLAGS += -g
# .PHONY : all

all : server run

run : m_server
	./m_server

server : m_server.c

clean :
	find . -type f -executable -exec rm '{}' \;

test : 
	python test.py
