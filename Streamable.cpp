// Final Project Milestone 4
// Date Module
// File  Streamable.cpp
// Version 1.0
// Author   Fardad Soleimanloo
// Revision History
// -----------------------------------------------------------
// Name Jiaheng Wang  Date  July 26  Reason
/////////////////////////////////////////////////////////////////

#include<iostream>
#include"Streamable.h"

using namespace std;

namespace sdds {
	Streamable::~Streamable() {

	}

	ostream& operator<<(ostream& os, const Streamable& obj) {
		obj.write(os);
		return os;
	}

	istream& operator>>(istream& is, Streamable& obj) {
		obj.read(is);
		return is;
	}
}