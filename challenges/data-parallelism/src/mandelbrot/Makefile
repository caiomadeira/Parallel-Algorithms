CPP=g++
DEFS =-O3 -std=c++11

all: mandelbrot 

mandelbrot: mandelbrot.cpp
	$(CPP) $(DEFS) $< -o $@ -fopenmp

clean:
	rm -rf mandelbrot output.bmp