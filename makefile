CXX = gcc
TARGET = main
SRCS = lang.c
OBJS = lang.o
LIB = liblang.so
LD_PATH = ./
LIBS = -llang -lm

run: lang.o shared
	$(CXX) -o $(TARGET) main.c -L$(LD_PATH) $(LIBS)
	./$(TARGET)

lang.o:
	$(CXX) -c -fPIC $(SRCS)

shared:
	$(CXX) -shared -o $(LIB) $(OBJS)

clear:
	rm $(LIB) $(OBJS)
