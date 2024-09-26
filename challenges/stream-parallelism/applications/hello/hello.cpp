#include <iostream>
#include <chrono>
#include <unistd.h>

int main(){

	auto tstart = std::chrono::high_resolution_clock::now();

	for(int i=250; i<750; i+=50){

		// Emitter or Source or Generator
		i++; // Just to simulate an emitter action

		// Worker or Operator or Filter
		usleep(i*1000);

		// Collector or Sink or Join
		std::cout << "Finishing item " << ((i-1)/50)-5 << std::endl;

	}

	auto tend = std::chrono::high_resolution_clock::now();
	double TT = std::chrono::duration<double>(tend-tstart).count();
	std::cout << "Time(seconds): " << TT << std::endl;

}