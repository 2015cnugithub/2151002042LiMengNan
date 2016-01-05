// Menu.h: interface for the Menu class.

#ifndef _MENU_H_
#define _MENU_H_

#include "Readerdata.h"
#include "Mvc_book.h"
class Menu  
{
public:
	Menu();
	void mainPage();
	void whoYouAre();
    void login1();
    void login2();
	void systemAdministratorPage();
	void loginError();
	void maintainBook();
    void maintainBorrowActor();
    void maintainLibrarian();
    float maintainBorrowActorCase(Readerdata *readerdata);
    float maintainLibrarianCase(Readerdata * readerdata);
    void librarianPage();
    void borrowPage(Readerdata *readerdata,BookDB *bookdb);
    void returnPage(Readerdata *readerdata,BookDB *bookdb);
    void reservePage(BookDB *bookdb);
    void readerPage();
	virtual ~Menu();

};

#endif
