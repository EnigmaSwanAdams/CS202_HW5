
/*
* CS 202 homework 5
* 4/27/2022
*
* file containing main for the
* Main Program 3: contains tests/proof of functionality 
* for all three functions in main program 3 (MP3)
*/



#include <iostream>
#include <vector>
#include "fibs.h"
#include "ack.h"
#include "StopWatch.h"
using std::cout;
using std::endl;
using std::vector;

int main() {
	
	// demonstration of fib and fib_loop 
	const int MAX_NUM_FIBS = 10000;
	cout << "Printing fibbonacci demonstration. Note the format is index: fib result, fib_loop result\n";
	cout << "An error should be printed out if an overflow occurs, or the function outputs aren't equal\n";
	for(int i=0; i<MAX_NUM_FIBS; i++){
		cout << i << ": ";
		cout << fib(i) << ", " << fib_loop(i) << endl;
		if (fib(i) != fib_loop(i)) { cout << "ERROR THEY ARE NOT EQUAL\N"; }
		if ((fib(i) < 0) || (fib_loop(i) < 0)) { 
			cout << "OVERFLOW OCCURED STOPPING CALCULATION\n";
			break;
		}
	}
	cout << "Finished printing fibbonacci results\n" << endl;
	
	
	// demonstration of ack function 
	const int MAX_NUM_ACK = 10;
	int currentAck = -1;
	StopWatch sw;
	double timeTaken;
	
	cout << "Printing ack demonstration.\n";
	for (int i = 0; i < MAX_NUM_ACK; i++) {
		for(int j = 0; j < MAX_NUM_ACK; j++){
			sw.Start();
			currentAck = ack(i, j);
			sw.Stop();
			timeTaken = sw.TimeMilliSec();
			cout << "A(" << i << ", " << j << "): " << currentAck << " (took " << timeTaken << " to complete)\n";
			
			if (i == 4 && j >= 0) {
				cout << "previouse testing shows the function will throw an error after this point\n";
				cout << "returning..." << endl;
				return 1;
			}
		}
	}

	//note that we don't actually get here 
	cout << "Finished printing Ackermann's numbers\n";
	return 0;
	
}



