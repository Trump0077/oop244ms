/************************************************************************
// Final Project Milestone 2
// OOP244 Utils Module:
// File  utils.cpp
// Version
// Date
// Author
// Description
//
// Revision History
// -----------------------------------------------------------
// Name Jiaheng Wang  Date  July 12  Reason
/////////////////////////////////////////////////////////////////
***********************************************************************/
#include <iostream>
using namespace std;
#include "Utils.h"
namespace sdds {
	void foolproof(int limit) {
		cin.clear();
		cin.ignore(limit, '\n');
		cout << "Invalid Selection, try again: ";
	}
}