/*
* CS 202 homework 5
* 4/25/2022
*
* header for
* Main Program 1: Template read() write()
*
* contains the the templated function defintiions
*/



#ifndef MYREADWRITE_H_
#define MYREADWRITE_H_

#include <fstream>
#include <fstream>
using std::fstream;
#include<iostream>
#include <istream>
#include <sstream>
using std::ofstream;
using std::ifstream;



// writes binary files out
template<typename T, typename S>
S& myWrite(S& stream, T& thing) {
	stream.write(reinterpret_cast<const char*>(&thing), sizeof(thing));
	return stream;
}

// reads in a binary file
template<typename T, typename S>
S& myRead(S& stream, T& thing) {
	stream.read(reinterpret_cast<char*>(&thing), sizeof(thing));
	return stream;
}

#endif /* MYREADWRITE_H_ */