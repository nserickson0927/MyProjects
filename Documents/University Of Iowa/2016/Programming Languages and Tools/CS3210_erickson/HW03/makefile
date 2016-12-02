CC = g++
CFLAGS = -Wall -c -std=c++14
LFLAGS = -Wall
OBJS = main.o complex.o lodepng.o

fractal: $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o fractal
	rm *.o

main.o: lodepng.h complex.h
	$(CC) $(CFLAGS) main.cpp

lodepng.o: lodepng.h
	$(CC) $(CFLAGS) lodepng.cpp

complex.o: complex.h
	$(CC) $(CFLAGS) complex.cpp

clean:
	rm *.o fractal