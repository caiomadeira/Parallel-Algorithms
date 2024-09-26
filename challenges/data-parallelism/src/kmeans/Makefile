CPP=g++
DEFS =-O3 -std=c++11

all: kmeans 
 kmeans: kmeans.cpp
	$(CPP) $(DEFS) $< -o $@

clean:
	rm -rf kmeans result.txt