SHELL=/bin/sh
CFLAGS= -c -g -std=c++11 -pedantic
TEST_CFLAGS=  -c -g -std=c++11 -pedantic
OBJECTS= bnn.o bnn_test.o  
LFLAGS=-g -Wl,--copy-dt-needed-entries 
TEST_OBJECTS= bnn.o bnn_test.o  
CC= g++
INCLUDES= -I/usr/include
LIB_INCLUDE=
LIBS=

%.o: %.cpp
	$(CC) $(CFLAGS) $(INCLUDES) $<

bnn_test: $(TEST_OBJECTS)
	$(CC) $(TEST_CFLAGS) $(INCLUDES) $<

all:	bnn

bnn:	$(OBJECTS)
	$(CC) $(LFLAGS) $(OBJECTS) $(LIB_INCLUDE) $(LIBS) -o bnn_test 

test:	$(TEST_OBJECTS)
	$(CC) $(LFLAGS) $(TEST_OBJECTS) $(LIB_INCLUDE) $(LIBS) -o bnn_test 

# --- remove binary and executable files
clean:
	rm -f bnn_test $(OBJECTS) $(TEST_OBJECTS)

	
light_clean:
	rm -f $(OBJECTS) $(TEST_OBJECTS)
	
