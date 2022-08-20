// Final Project Milestone 4
// Date Module
// File  Book.h
// Version 1.0
// Author   Fardad Soleimanloo
// Revision History
// -----------------------------------------------------------
// Name Jiaheng Wang  Date  July 26  Reason
/////////////////////////////////////////////////////////////////

#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H

#include"Publication.h"

namespace sdds {
	class Book : public Publication {
		char* m_authorName;
		void set(const char* authorname);
	public:
		Book();

		// RULE OF THREE
		Book(const Book& book);
		Book& operator=(const Book& book);
		~Book();

		char type()const;
		std::ostream& write(std::ostream& os) const;
		std::istream& read(std::istream& istr);
		void set(int member_id);
		operator bool()const;
	};
	std::ostream& operator<<(std::ostream& os, const Book& obj);
	std::istream& operator>>(std::istream& is, Book& obj);
}


#endif