CC = g++
CFLAGS = -Wall -c
LFLAGS = -Wall
OBJS = main.o

main: $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o main
	rm *.o

main.o:
	$(CC) $(CFLAGS) main.cpp

clean:
	rm *.o main