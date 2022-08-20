// Final Project Milestone 4
// Date Module
// File  Book.cpp
// Version 1.0
// Author   Fardad Soleimanloo
// Revision History
// -----------------------------------------------------------
// Name Jiaheng Wang  Date  July 26  Reason
/////////////////////////////////////////////////////////////////

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<iomanip>
#include <string>
#include <cstring>

#include"Book.h"

using namespace std;

namespace sdds {
	Book::Book() : Publication() {
		m_authorName = nullptr;
	}

	void Book::set(const char* authorname) {
		if (m_authorName != nullptr) {
			delete[] m_authorName;
		}
		m_authorName = nullptr;
		if (authorname != nullptr && authorname[0] != '\0') {
			m_authorName = new char[strlen(authorname) + 1];
			strcpy(m_authorName, authorname);
		}
	}

	Book::Book(const Book& book) : Publication(book) {
		if (book.operator bool()) {
			set(book.m_authorName);
		}
	}

	Book& Book::operator=(const Book& book) {
		if (this != &book) {
			Publication::operator=(book);
			set(book.m_authorName);
		}
		return *this;
	}

	Book::~Book() {
		delete[] m_authorName;
	}

	char Book::type()const {
		return 'B';
	}

	std::ostream& Book::write(std::ostream& os) const {
		Publication::write(os);
		if (conIO(os))
		{
			char author[SDDS_AUTHOR_WIDTH + 1] = { 0 }; 
			strncpy(author, m_authorName, SDDS_AUTHOR_WIDTH);
			os << " "; 
			os << setw(SDDS_AUTHOR_WIDTH) << left << setfill(' ') << author << " |";
		}
		else {
			os << '\t' << m_authorName;
		}
		return os;
	}
	

	std::istream& Book::read(std::istream& is) {
		char authName[256] = { 0 };
		Publication::read(is);
		if (m_authorName) {
			delete[] m_authorName;
			m_authorName = nullptr;
		}
		if (conIO(is)) {
			is.ignore();
			std::cout << "Author: ";
		}
		else {
			is.ignore(1000, '\t');
		}
		is.get(authName, 256);
		if (is) {
			m_authorName = new char[strlen(authName) + 1];
			strcpy(m_authorName, authName);
		}
		return is;
	}

	void Book::set(int member_id) {
		Publication::set(member_id);
		Publication::resetDate();
	}

	Book::operator bool()const {
		return m_authorName != nullptr && m_authorName[0] != '\0'
			&& Publication::operator bool();
	}

	ostream& operator<<(ostream& os, const Book& obj) {
		obj.write(os);
		return os;
	}

	istream& operator>>(istream& is, Book& obj) {
		obj.read(is);
		return is;
	}
}