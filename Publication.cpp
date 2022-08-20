// Final Project Milestone 4
// Date Module
// File  Publication.cpp
// Version 1.0
// Author   Fardad Soleimanloo
// Revision History
// -----------------------------------------------------------
// Name Jiaheng Wang  Date  July 26  Reason
/////////////////////////////////////////////////////////////////

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<iomanip>
#include <cstring>

#include"Publication.h"
#include"Streamable.h"
#include"Lib.h"
#include"Date.h"

using namespace std;

namespace sdds {
	void Publication::set(int member_id) { 
		if (member_id > 9999 && member_id < 100000) {
			m_membership = member_id;
		}
		else {
			m_membership = 0;
		}
	}

	void Publication::setRef(int value) { 
		m_libRef = value;
	}

	void Publication::resetDate() { 
		m_date.setToToday(); 
	}

	char Publication::type()const { 
		return 'P';
	}

	bool Publication::onLoan()const { 
		return m_membership != 0; 
	}

	Date Publication::checkoutDate()const {
		return m_date;
	}

	bool Publication::operator==(const char* title)const { 
		if (strstr(m_title, title) != NULL) { 
			return true;
		}
		return false; 
	}

	Publication::operator const char* () const {
		return m_title; 
	}

	int Publication::getRef()const { 
		return m_libRef;
	}

	bool Publication::conIO(ios& io) const {
		return &io == &cin || &io == &cout;
	}

	std::ostream& Publication::write(std::ostream& os) const {
		if (bool(*this)) {
			char title[SDDS_TITLE_WIDTH + 1] = { 0 };
			strncpy(title, m_title, SDDS_TITLE_WIDTH);
			if (conIO(os)) {
				os << "| " << m_shelfId << " | "
					<< setw(30) << left << setfill('.') << title << " | ";
				m_membership != 0 ? os << m_membership : os << " N/A ";
				os << " | " << m_date << " |";
			}
			else {
				os << type() << "\t" << m_libRef << "\t" << m_shelfId 
					<< "\t" << m_title << "\t" << m_membership;
				os << "\t" << m_date;
			}
		}
		return os;
	}
	
	istream& Publication::read(istream& istr) {
		if (m_title != nullptr) {
			delete[] m_title;
		}
		m_title = nullptr;
		m_shelfId[0] = '\0';
		m_membership = 0;
		m_libRef = -1;
		m_date.setToToday();

		char* title = nullptr;
		title = new char[100];
		char shelfId[SDDS_SHELF_ID_LEN + 1]{};
		int membership = 0;
		int libRef = -1;
		Date date;

		if (conIO(istr)) {
			cout << "Shelf No: ";
			istr.getline(shelfId, SDDS_SHELF_ID_LEN + 1, '\n');
			if (strlen(shelfId) != SDDS_SHELF_ID_LEN) { 
				istr.setstate(ios::failbit);
			}
			cout << "Title: ";
			istr.getline(title, 100, '\n');
			cout << "Date: ";
			istr >> date;
		}
		else {
			istr >> libRef;
			istr.ignore();
			istr.getline(shelfId, 5, '\t');
			istr.getline(title, 200, '\t');
			istr >> membership;
			istr.ignore();
			istr >> date;
		}
		if (!date)
			istr.setstate(ios::failbit);

		if (istr.rdstate() == 0) { 
			m_title = new char[strlen(title) + 1]; 
			strcpy(m_title, title); 
			strcpy(m_shelfId, shelfId);
			m_membership = membership;
			m_date = date;
			m_libRef = libRef;
		}
		delete[] title;
		return istr;
	}
	
	Publication::Publication() { 
		m_title = nullptr;
		m_shelfId[0] = '\0';
		m_membership = 0;
		m_libRef = -1; 
		m_date.setToToday();
	}

	Publication::operator bool() const { 
		return m_title != nullptr || m_shelfId[0] != '\0';
	}

	ostream& operator<<(ostream& os, const Publication& obj) {
		obj.write(os);
		return os; 
	}
	
	istream& operator>>(istream& is, Publication& obj) { 
		obj.read(is);
		return is;
	}

	Publication::Publication(const Publication& pub) { 
		if (pub.operator bool()) { 
			set(pub.m_title, pub.m_shelfId, pub.m_membership, pub.m_libRef, pub.m_date);
		} 
	}

	Publication& Publication::operator=(const Publication& pub) {
		if (this != &pub) { 
			set(pub.m_title, pub.m_shelfId, pub.m_membership, pub.m_libRef, pub.m_date);
		}
		return *this;
	}

	Publication::~Publication() { 
		delete[] m_title;
	}

	void Publication::set(const char* title, const char* shelfId, int membership, int libRef, Date date) {
		if (m_title != nullptr)
			delete[] m_title; 
		m_title = nullptr;
		if (title != nullptr) {
			m_title = new char[strlen(title) + 1];
			strcpy(m_title, title); strcpy(m_shelfId, shelfId);
			m_membership = membership;
			m_libRef = libRef;
			m_date = date; 
		}
		else {
			m_shelfId[0] = '\0';
			m_membership = 0;
			m_libRef = -1;
			m_date.setToToday();
		}
	}
}