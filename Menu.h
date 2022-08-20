// Final Project Milestone  2
// Menu Module
// File	Menu.h
// Version 1.0
// Author	Fardad Soleimanloo
// Revision History
// -----------------------------------------------------------
// Name Jiaheng Wang  Date  July 12  Reason
/////////////////////////////////////////////////////////////////
#ifndef SDDS_MENU_H
#define SDDS_MENU_H
#include <iostream>
namespace sdds {
	int const MAX_MENU_ITEMS = 20;
	class MenuItem {
		char* m_menuItem{};
		MenuItem();
		MenuItem(const char* item);
		~MenuItem();
		operator bool() const;
		void display();
		friend class Menu;
	};
	class Menu {
		char* m_menuTitle{};
		MenuItem* m_items[MAX_MENU_ITEMS];
		int m_numMenu = 0;
	public:
		Menu();
		Menu(const char* title);
		~Menu();
		void display();
		int run();
		int operator~();
		Menu& operator<<(const char* menuitemConent);
		operator int() const;
		operator unsigned int() const;
		operator bool() const;
		std::ostream& insert(std::ostream& os = std::cout)const;
		char* operator[](int i) const;
	};
	std::ostream& operator<<(std::ostream& os, const Menu& m);
}
#endif