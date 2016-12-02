CC = g++
CFLAGS = -Wall -c
LFLAGS = -Wall
OBJS = main.o image.o ppm.o

main: $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o main
	rm *.o

main.o: pixel.h image.h
	$(CC) $(CFLAGS) main.cpp

ppm.o: ppm.h
	$(CC) $(CFLAGS) ppm.cpp

image.o: image.h
	$(CC) $(CFLAGS) image.cpp

clean:
	rm *.o main