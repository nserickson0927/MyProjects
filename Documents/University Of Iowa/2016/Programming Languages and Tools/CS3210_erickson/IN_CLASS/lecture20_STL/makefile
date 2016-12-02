CC = g++
CFLAGS = -Wall -c
LFLAGS = -Wall
OBJS = main.o creature.o

main: $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o main
	rm *.o

main.o: creature.h formatter.h
	$(CC) $(CFLAGS) main.cpp

creature.o: creature.h
	$(CC) $(CFLAGS) creature.cpp

clean:
	rm *.o main