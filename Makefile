CFLAGS += -g
.PHONY : all run child_handle

all : run

run : m_server
	./m_server

m_server : child_handle/m_server_child_handle.o m_server.c

child_handle.o :
	$(MAKE) -C child_handle

clean :
	find . -type f -executable -exec rm '{}' \;

test : 
	python test.py
