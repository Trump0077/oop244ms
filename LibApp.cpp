// Final Project Milestone 5
// LibApp Module
// File	LibApp.cpp
// Version 1.0
// Author	Fardad Soleimanloo
// Revision History
// -----------------------------------------------------------
// Name Jiaheng Wang   Date July 30, 2022  Reason
/////////////////////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
#include "LibApp.h"
#include "Book.h"
#include "PublicationSelector.h"

using namespace std;

namespace sdds {
    bool LibApp::confirm(const char* message) {
        Menu confirm(message);
        confirm << "Yes";
        int t_return = confirm.run();
        if (t_return) {
            return true;
        }
        return false;
    }
    void LibApp::load() {
        cout << "Loading Data" << endl;
        ifstream infile(m_fileName);
        char type{};
        for (int i = 0; infile; i++) {
            infile >> type;
            infile.ignore();
            if (infile) {
                if (type == 'P')
                    PPA[i] = new Publication;
                else if (type == 'B')
                    PPA[i] = new Book;
                else cout << "no data" << endl;
                if (PPA[i] && i < SDDS_LIBRARY_CAPACITY) {
                    infile >> *PPA[i];
                    LLRN = PPA[i]->getRef();
                    NOLP++;
                }
            }
        }
    }  
    void LibApp::save() {
        cout << "Saving Data" << endl;
        ofstream outfile(m_fileName);
        for (int i = 0; i < NOLP; i++) {
            if (PPA[i]->getRef()) {
                outfile << *PPA[i] << endl;
            }
        }
    }
    void prnPub(Publication* p[], int size, int ref) {
        int i;
        for (i = 0; i < size; i++) {
            if (ref == p[i]->getRef()) {
                cout << *p[i] << endl;
                i = size; // Exit the loop.
            }
        }
    }
    int LibApp::search(int option, char type) {
        PublicationSelector ps("Select one of the following found matches:", 15);
        cout << "Publication Title: ";
        char title[256];
        cin >> title;
        if (option == 1) {
            for (int i = 0; i < NOLP; i++) {
                if (strstr(*PPA[i], title) && PPA[i]->getRef() != 0 && type == PPA[i]->type())
                    ps << PPA[i];
            }
        }       
        else if (option == 2) {
            for (int i = 0; i < NOLP; i++) {
                if (strstr(*PPA[i], title) && !PPA[i]->onLoan() && PPA[i]->getRef() != 0 
                    && type == PPA[i]->type())
                    ps << PPA[i]; 
            }
        }
        else if (option == 3) {
            for (int i = 0; i < NOLP; i++) {
                if (strstr(*PPA[i], title) && PPA[i]->onLoan() && PPA[i]->getRef() != 0 
                    && type == PPA[i]->type())
                    ps << PPA[i]; 
            }
        }
        int ref = 0;
        if (ps) {
            ps.sort(); 
            ref = ps.run(); 
            if (ref) {
                prnPub(PPA, NOLP, ref);
            }
            else {
                cout << "Aborted!" << endl;
            }
        }
        else {
            cout << "No matches found!" << endl;
        }
        return ref;
    }
    Publication* LibApp::getPub(int libRef) {
        for (int i = 0; i < NOLP; i++) {
            if (libRef == PPA[i]->getRef()) 
                return PPA[i];
        }
        return nullptr;
    }
    void LibApp::newPublication() {
        if (NOLP >= SDDS_LIBRARY_CAPACITY) {
            cout << "Library is at its maximum capacity!" << endl;
        }
        else {
            cout << "Adding new publication to the library" << endl;

            int i = m_publicationMenu.run();
            Publication* p = nullptr;
            if (i == 0) {
                cout << "Aborted!" << endl;
                return;
            }
            else if (i == 1) {
                p = new Book;
                cin >> *p;
            }
            else if (i == 2) {
                p = new Publication;
                cin >> *p;
            }
            if (cin.fail()) {
                cin.clear();
                i = 0;
                cout << "\nAborted!\n";
            }
            if (cin && confirm("Add this publication to the library?")) {
                if (*p) {
                    m_changed = true;
                    p->setRef(++LLRN);
                    PPA[NOLP] = p;
                    NOLP++;
                    cout << "Publication added" << endl;
                }
                else
                {
                    cout << "Failed to add publication!" << endl;
                    delete p;
                }
            }
            else {
                cout << "Aborted!" << endl;
            }
        }
    }
    void LibApp::removePublication() {
        cout << "Removing publication from the library" << endl;
        int i = m_publicationMenu.run();
        char type;
        if (i == 1) 
            type = 'B';
        else 
            type = 'P';
        int ref = search(1, type);
        if (ref != 0 && confirm("Remove this publication from the library?")) {
            m_changed = true;
            getPub(ref)->setRef(0);
            cout << "Publication removed" << endl;
        }
    }
    void LibApp::checkOutPub() {
        cout << "Checkout publication from the library" << endl;
        int i = m_publicationMenu.run();
        char type;
        if (i == 1) type = 'B';
        else type = 'P';
        int ref = search(2, type);
        if (ref != 0 && confirm("Check out publication?")) {
            m_changed = true;
            int mn;
            cout << "Enter Membership number: ";
            while (1) {
                cin >> mn;
                if (mn > 9999 && mn <= 99999) break;
                cout << "Invalid membership number, try again: ";
            }
            getPub(ref)->set(mn);
            cout << "Publication checked out" << endl;
        }
    }
    void LibApp::returnPub() {
        cout << "Return publication to the library" << endl;
        int i = m_publicationMenu.run();
        char type;
        if (i == 1) type = 'B';
        else type = 'P';
        int ref = search(3, type);
        if (ref != 0 && confirm("Return Publication?")) {
            Date date = getPub(ref)->checkoutDate();
            Date today;
            int days = today - date;
            days -= 15;
            if (days > 0) {
                cout << fixed << setprecision(2) << "Please pay $" << float(days) * (0.5)
                    << " penalty for being " << days << " days late!" << endl;
            }
            getPub(ref)->set(0);
            cout << "Publication returned" << endl;
            m_changed = true;
        }
    }
    LibApp::LibApp() {
        m_mainMenu << "Add New Publication"
            << "Remove Publication"
            << "Checkout publication from library"
            << "Return publication to library";
        m_exitMenu << "Save changes and exit" << "Cancel and go back to the main menu";
        load();
    }
    LibApp::LibApp(const char filename[256]) {
        m_mainMenu << "Add New Publication"
            << "Remove Publication"
            << "Checkout publication from library"
            << "Return publication to library";
        m_exitMenu << "Save changes and exit" << "Cancel and go back to the main menu";
        m_publicationMenu << "Book" << "Publication";
        strcpy(m_fileName, filename);
        NOLP = 0;
        LLRN = -1;
        load();
    }
    LibApp::~LibApp() {
        for (int i = 0; i < NOLP; i++) {
            delete PPA[i];
        }
    }
    void LibApp::run() {
        while (1) {
            int option = m_mainMenu.run();
            if (option == 1) newPublication();
            else if (option == 2) removePublication();
            else if (option == 3) checkOutPub();
            else if (option == 4) returnPub();
            else if (option == 0) {
                if (m_changed) {
                    int saveOption = m_exitMenu.run();
                    if (saveOption == 1) {
                        save();
                        break;
                    }
                    else if (saveOption == 0) {
                        if (confirm("This will discard all the changes are you sure?"))
                            break;
                    }
                }
                else break;
            }
            cout << endl;
        }
        cout << endl;
        cout << "-------------------------------------------" << endl;
        cout << "Thanks for using Seneca Library Application" << endl;
    }
}
  