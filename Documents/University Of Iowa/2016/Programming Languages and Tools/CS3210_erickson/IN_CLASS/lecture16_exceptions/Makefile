CC = g++
CFLAGS = -Wall -c
LFLAGS = -Wall
SRCS = main.cpp alerts.cpp
OBJS = ${SRCS:.cpp=.o}

#SRC=$(wildcard *.c)

main: $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o main
	rm *.o

main.o: alerts.h
	$(CC) $(CFLAGS) main.cpp

alerts.o: alerts.h
	$(CC) $(CFLAGS) alerts.cpp

clean:
	rm *.o main