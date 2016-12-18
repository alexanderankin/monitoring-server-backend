CFLAGS += -g
.PHONY: run_test test

m_server_child_handle.o : m_server_child_handle.c

test : test_runner run_test
test_runner : test_runner.c
run_test :
	./test_runner

