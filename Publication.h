// Final Project Milestone 4
// Date Module
// File  Publication.h
// Version 1.0
// Author   Fardad Soleimanloo
// Revision History
// -----------------------------------------------------------
// Name Jiaheng Wang  Date  July 26  Reason
/////////////////////////////////////////////////////////////////

#ifndef SDDS_PUBLICATION_H
#define SDDS_PUBLICATION_H

#include "Date.h"
#include "Lib.h"
#include "Streamable.h"

namespace sdds {
	class Publication :Streamable {
		char* m_title{};
		char m_shelfId[SDDS_SHELF_ID_LEN + 1]{};
		int m_membership = 0;
		int m_libRef = -1;
		Date m_date;

		void set(const char* title, const char* shelfId, int membership, int libRef, Date date);
	public:
		Publication();

		// Modifiers
		virtual void set(int member_id);
		// Sets the membership attribute to either zero or a five-digit integer.
		void setRef(int value);
		// Sets the **libRef** attribute value
		void resetDate();
		// Sets the date to the current date of the system
		
		// Queries
		virtual char type()const;
		//Returns the character 'P' to identify this object as a "Publication object"
		bool onLoan()const;
		//Returns true is the publication is checkout (membership is non-zero)
		Date checkoutDate()const;
		//Returns the date attribute
		bool operator==(const char* title)const;
		//Returns true if the argument title appears anywhere in the title of the 
		//publication. Otherwise, it returns false; (use strstr() function in <cstring>)
		operator const char* ()const;
		//Returns the title attribute
		int getRef()const;
		//Returns the libRef attirbute.

		// Streamable pure virtual function implementations
		bool conIO(std::ios& io)const;
		std::ostream& write(std::ostream& os) const;
		std::istream& read(std::istream& istr);

		operator bool() const;

		// The Rule of three
		Publication(const Publication& pub);
		Publication& operator=(const Publication& pub);
		~Publication();
	};
	std::ostream& operator<<(std::ostream& os, const Publication& obj);
	std::istream& operator>>(std::istream& is, Publication& obj);
}


#endif