// Final Project Milestone 2
// Menu Module
// File	Menu.cpp
// Version 1.0
// Author	Fardad Soleimanloo
// Revision History
// -----------------------------------------------------------
// Name Jiaheng Wang  Date  July 12  Reason
/////////////////////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Menu.h"
#include "Utils.h"
#include <iomanip>
using namespace std;
namespace sdds {
	MenuItem::MenuItem() {
		m_menuItem = nullptr;
	}
	MenuItem::MenuItem(const char* item) {
		delete[] m_menuItem;
		m_menuItem = new char[strlen(item) + 1];
		strcpy(m_menuItem, item);
	}
	MenuItem::~MenuItem() {
		delete[] m_menuItem;
	}
	MenuItem::operator bool() const {
		if (m_menuItem != nullptr) {
			return true;
		}
		return false;
	}
	void MenuItem::display() {
		std::cout << m_menuItem;
	}
	Menu::Menu() {
		m_menuTitle = nullptr;
		m_numMenu = 0;
	}
	Menu::Menu(const char* title) {
		delete[] m_menuTitle;
		m_menuTitle = new char[strlen(title) + 1];
		strcpy(m_menuTitle, title);
	}
	Menu::~Menu() {
		delete[] m_menuTitle;
		for (int i = 0; i < m_numMenu; i++) {
			delete m_items[i];
		}
	}
	void Menu::display() {
		if (m_menuTitle != nullptr) {
			cout << m_menuTitle << endl;
		}
		for (int i = 0; i < m_numMenu; i++) {
			cout << " " << i + 1 << "- " << m_items[i]->m_menuItem << endl;
		}
		cout << " 0- Exit\n> ";
	}

	int Menu::run() {
		display();
		char selection;
		cin >> selection;
		int unsign = selection - '0';
		while (unsign < 0 || unsign > m_numMenu) {
			foolproof(80);
			cin >> selection;
			unsign = selection - '0';
		}
		cin.ignore();
		return unsign;
	}
	int Menu::operator~() {
		return run();
	}
	Menu& Menu::operator<<(const char* menuitemConent) {
		m_items[m_numMenu++] = new MenuItem(menuitemConent);
		return *this;
	}
	Menu::operator int() const {
		return m_numMenu;
	}
	Menu::operator unsigned int() const {
		return m_numMenu;
	}
	Menu::operator bool() const {
		if (m_menuTitle == nullptr) {
			return false;
		}
		return true;
	}
	std::ostream& Menu::insert(std::ostream& os)const {
		if (m_menuTitle != nullptr)
			os << m_menuTitle;
		return os;
	}
	std::ostream& operator<<(std::ostream& os, const Menu& m) {
		return m.insert(os);
	}
	char* Menu::operator[](int i) const {
		return m_items[i]->m_menuItem;
	}
}