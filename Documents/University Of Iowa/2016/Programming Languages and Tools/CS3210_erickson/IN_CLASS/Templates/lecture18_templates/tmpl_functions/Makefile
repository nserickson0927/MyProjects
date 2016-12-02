CC = g++
CFLAGS = -c
LFLAGS = 
OBJS = main.o

main: $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o main
	rm *.o

main.o: formatter.h
	$(CC) $(CFLAGS) main.cpp

clean:
	rm *.o main