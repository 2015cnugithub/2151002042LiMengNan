#include <iostream>
#include "Menu.h"
#include "Mvc_book.h"
#include "Reader.h"
#include "Readerdata.h"
using namespace std;

int main()
{
  int option = 100;//给一个无用值
  char systemAdministratorNum[11] = "0";
  char systemAdministratorNum_cin[11];
  char sPassword[11] = "0";
  char sPassword_cin[11];
  int num;
  char password[11];
  Menu  menu;
  float menuPage = 0;

  Book book;
  BookController bookController(&book);
  BookDB bookDB;
  book.addObserver(&bookDB);
  Readerdata readerdata;

  while(1)
  {
	menu.mainPage();//首页
    cin >> option;
	switch (option)
	{
	case 1://登录
		menuPage = 1;
		while(menuPage == 1)
		{
			menu.whoYouAre();//选择使用者界面
			cin >> option;
			switch (option)
			{
			case 1://系统管理员
				menuPage = 11;
				while(menuPage == 11)
				{
					menu.login1();
					cin >> systemAdministratorNum_cin;
					menu.login2();
					cin >> sPassword_cin;
					if(!strcmp(systemAdministratorNum_cin,systemAdministratorNum) && !strcmp(sPassword_cin,sPassword) )
					{
                      menuPage = 110;
                      while(menuPage == 110)
                      {
						  menu.systemAdministratorPage();//系统管理员操作界面
						  cin >> option;
						  switch (option)
						  {
						  case 1://维护图书
							  menuPage = 111;
							  while(menuPage == 111)
							  {
								menu.maintainBook();
								cin >> option;
								switch (option)
								{
								case 1://增
									bookController.addButton();									
									break;
								case 2://删
                                    bookController.delBook(&bookDB);
                                    break;
								case 3://改
                                    bookController.modifyBook(&bookDB);
									break;
								case 4://查
                                    bookDB.search_bname();
									break;
								case 5://返
                                    menuPage = 110;
									break;
								case 0://退
								  return 0;
								}
							  }
                              break;
                          case 2://维护借阅者
							  menuPage = 112;
							  while(menuPage == 112)
							  {
                                  menuPage= menu.maintainBorrowActorCase(&readerdata);
                                  if (menuPage == 0)
                                      return 0;
							  }
                              break;
						  case 3://维护图书管理员
                              menuPage = 113;
                              while(menuPage == 113)
                              {
                                  menuPage= menu.maintainLibrarianCase(&readerdata);
                              }
                              break;
						  case 4://返回上一级
							  menuPage = 1;
							  break;
						  case 0://退出系统
							  return 0;
						  }
						}
					  }
					else
					{
						menu.loginError();
					}
				}
                break;
			case 2://图书管理员
                menuPage = 12;
                while(menuPage == 12)
                {
                    Reader *r;
                    menu.login1();
                    cin >> num;
                    menu.login2();
                    cin >> password;
                    r = readerdata.search_rnum(num);
                    if (r == NULL)
                    {
                        cout<<"用户名不对，Sorry"<<endl;
                        menuPage = 1;
                        break;
                    }
                    if(!strcmp(r->getrpassword(),password))
                    {
                      menuPage = 120;
                      while(menuPage == 120)
                      {
                          menu.librarianPage();//图书管理员操作界面
                          cin >> option;
                          switch (option)
                          {
                          case 1://借书给借阅者
                                menu.borrowPage(&readerdata,&bookDB);
                             break;
                          case 2://还书
                              menu.returnPage(&readerdata,&bookDB);
                              break;
                          case 3://检索书目
                              bookDB.search_bname();
                              break;
                          case 4://返回上一级
                              menuPage = 1;
                              break;
                          case 0://退出系统
                              return 0;
                          }
                       }
                    }
                   else
                   {
                       menu.loginError();
                   }
                }
                break;
            case 3://借阅者
                menuPage = 13;
                while(menuPage == 13)
                {
                    Reader *r;
                    menu.login1();
                    cin >> num;
                    menu.login2();
                    cin >> password;
                    r = readerdata.search_rnum(num);
                    if (r == NULL)
                    {
                        cout<<"用户名不对，Sorry"<<endl;
                        menuPage = 1;
                        break;
                    }
                    if(!strcmp(r->getrpassword(),password))
                    {
                      menuPage = 130;
                      while(menuPage == 130)
                      {
                          menu.readerPage();//借阅者操作界面
                          cin >> option;
                          switch (option)
                          {
                          case 1://预定图书
                             menu.reservePage(&bookDB);
                             break;
                          case 2://查看个人信息
                              Reader *r;
                              r=readerdata.search_rnum(num);
                              if (r==NULL)
                              {
                                  cout <<"对不起，你的账户失效!"<< endl;
                                  break;
                              }
                              else
                              {
                                  r->readerShow();
                              }
                              break;
                          case 3://检索书目
                              bookDB.search_bname();
                              break;
                          case 4://返回上一级
                              menuPage = 1;
                              break;
                          case 0://退出系统
                              return 0;
                          }
                       }
                    }
                   else
                   {
                       menu.loginError();
                   }
                }
                break;
            case 4://返回上一级
				menuPage = 0;
				break;
			case 0://退出系统
				return 0;
			}
		}
		break;
	case 2://搜索图书
        bookDB.search_bname();
		break;
	case 0://退出系统
		return 0;
	}
  }
  return 0;
}
