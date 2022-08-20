// Final Project Milestone 5
// LibApp Module
// File	LibApp.h
// Version 1.0
// Author	Fardad Soleimanloo
// Revision History
// -----------------------------------------------------------
// Name Jiaheng Wang   Date July 30, 2022  Reason
/////////////////////////////////////////////////////////////////

#ifndef SDDS_LIBAPP_H
#define SDDS_LIBAPP_H
#include "Menu.h"
#include "Publication.h"
#include "Lib.h"
namespace sdds {
    class LibApp {
        char m_fileName[256];
        Publication* PPA[SDDS_LIBRARY_CAPACITY]{}; //Publication Pointers Array
        int NOLP; //Number Of Loaded Publications
        int LLRN; //Last Library Reference Number
        bool m_changed = false;
        Menu m_publicationMenu{ "Choose the type of publication:" };
        Menu m_mainMenu{ "Seneca Library Application" };
        Menu m_exitMenu{ "Changes have been made to the data, what would you like to do?" };
        bool confirm(const char* message);
        void load();  
        void save();
        int search(int option, char type); 
        Publication* getPub(int libRef);
        void newPublication();
        void removePublication();
        void checkOutPub();
        void returnPub();

    public:
        LibApp();
        LibApp(const char filename[256]);
        ~LibApp();
        void run();
    };
}
#endif 
