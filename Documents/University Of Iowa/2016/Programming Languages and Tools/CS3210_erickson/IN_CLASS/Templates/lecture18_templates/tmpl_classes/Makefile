CC = g++
CFLAGS = -c
LFLAGS = 
OBJS = main.o treasure.o

main: $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o main
	rm *.o

main.o: formatter.h pair.h stack.h
	$(CC) $(CFLAGS) main.cpp

treasure.o: treasure.h
	$(CC) $(CFLAGS) treasure.cpp

clean:
	rm *.o main