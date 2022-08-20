// Final Project Milestone 4
// Date Module
// File  Streamable.h
// Version 1.0
// Author   Fardad Soleimanloo
// Revision History
// -----------------------------------------------------------
// Name Jiaheng Wang  Date  July 26  Reason
/////////////////////////////////////////////////////////////////

#ifndef SDDS_STREAMABLE_H
#define SDDS_STREAMABLE_H

namespace sdds {
	class Streamable {
	public:
		virtual std::ostream& write(std::ostream& os)const = 0;
		virtual std::istream& read(std::istream& istr) = 0;
		virtual bool conIO(std::ios& io)const = 0;
		virtual operator bool()const = 0;
		virtual ~Streamable();
	};
	std::ostream& operator<<(std::ostream& os, const Streamable& obj);
	std::istream& operator>>(std::istream& is, Streamable& obj);
}

#endif
