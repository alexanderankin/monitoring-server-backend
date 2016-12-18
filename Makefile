CFLAGS += -g
.PHONY : all run child_handle

all : run

run : m_server
	./m_server

m_server : m_server_helpers.o \
	m_server_signals.o \
	child_handle/m_server_child_handle.o \
	m_server.c

m_server_helpers.o : m_server_helpers.c

m_server_signals.o : m_server_signals.c

child_handle.o :
	$(MAKE) -C child_handle

clean :
	find . -type f -executable -exec rm '{}' \;
	find . -type f -iname "*.o" -exec rm '{}' \;

test : 
	python test.py
