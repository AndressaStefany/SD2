CC = g++
CXX = g++
CPPFLAGS = -Wall -O2
CFLAGS =
LDFLAGS = -O2 

#Use essa opcao para compilar o sistema real e o simulado
LDLIBS = 

#Use essa opcao para compilar somente o sistema simulado
#LDLIBS = -lmatrix -lpthread -lssocket

FILES = Socket.o ClientSocket.o ServerSocket.o

all: simple_server_main simple_client_main

simple_server_main: ${FILES}
simple_client_main: ${FILES}

Socket.o: Socket.h Socket.cpp

ClientSocket.o: ClientSocket.h ClientSocket.cpp

ServerSocket.o: ServerSocket.h ServerSocket.cpp

##### SPECIAL TARGETS ######

.PHONY: clean realclean 

clean:
	-rm -f *.o *~ 

