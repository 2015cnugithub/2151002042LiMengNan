// Menu.cpp: implementation of the Menu class.

#include "Menu.h"
#include <iostream>
#include "Reader.h"
#include "Readerdata.h"
#include "Mvc_book.h"
using namespace std;

Menu::Menu()
{

}

Menu::~Menu()
{

}

void Menu::mainPage()
{
    cout <<  "***************************************************" << endl;
	cout <<  "          欢 迎 使 用 图 书 管 理 系 统 ! " <<endl;
    cout <<  "                  1  登录" << endl;
  	cout <<  "                  2  搜索图书" << endl;
   	cout <<  "                  0  退出系统" << endl;
   	cout <<  "***************************************************" << endl;
}

void Menu::whoYouAre()
{
	cout <<  "***************************************************" << endl;	    
    cout <<  "                  1  系统管理员" << endl;
  	cout <<  "                  2  图书管理员" << endl;
    cout <<  "                  3  借阅者" << endl;
    cout <<  "                  4  返回上一级" << endl;
   	cout <<  "                  0  退出系统" << endl;
   	cout <<  "***************************************************" << endl;  
}

void Menu::login1()
{
	cout <<  "***************************************************" << endl;	    
    cout <<  "                  编号：" ;
}
void Menu::login2()
{
	cout <<  "***************************************************" << endl;	    
  	cout <<  "                  密码：" ;
}
void Menu::systemAdministratorPage()
{
	cout <<  "***************************************************" << endl;	    
    cout <<  "                  1  维护图书" << endl;
  	cout <<  "                  2  维护借阅者" << endl;
    cout <<  "                  3  维护图书管理员" << endl;
    cout <<  "                  4  返回上一级" << endl;
   	cout <<  "                  0  退出系统" << endl;
   	cout <<  "***************************************************" << endl;  
}
void Menu::loginError()
{
	cout <<  "***************************************************" << endl;	    
  	cout <<  "                  用户名或密码错误，请重新输入：" <<endl;
}
void Menu::maintainBook()
{
	cout <<  "***************************************************" << endl;	    
    cout <<  "                  1  添加图书" << endl;
  	cout <<  "                  2  删除图书" << endl;
    cout <<  "                  3  修改图书" << endl;
    cout <<  "                  4  搜索图书" << endl;
    cout <<  "                  5  返回上级" << endl;
   	cout <<  "                  0  退出系统" << endl;
   	cout <<  "***************************************************" << endl;  
}
void Menu::maintainBorrowActor()
{
	cout <<  "***************************************************" << endl;	    
    cout <<  "                  1  添加借阅者" << endl;
  	cout <<  "                  2  删除借阅者" << endl;
    cout <<  "                  3  修改借阅者" << endl;
    cout <<  "                  4  查询借阅者" << endl;
    cout <<  "                  5  返回上级" << endl;
   	cout <<  "                  0  退出系统" << endl;
   	cout <<  "***************************************************" << endl;  
}
void Menu::maintainLibrarian()
{
    cout <<  "***************************************************" << endl;
    cout <<  "                  1  添加图书管理员" << endl;
    cout <<  "                  2  删除图书管理员" << endl;
    cout <<  "                  3  修改图书管理员" << endl;
    cout <<  "                  4  查询图书管理员" << endl;
    cout <<  "                  5  返回上级" << endl;
    cout <<  "                  0  退出系统" << endl;
    cout <<  "***************************************************" << endl;
}
void Menu::librarianPage()
{
    cout <<  "***************************************************" << endl;
    cout <<  "                  1  借书-->借阅者" << endl;  
    cout <<  "                  2  借阅者-->还书" << endl;
    cout <<  "                  3  搜索书目" << endl;
    cout <<  "                  4  返回上一级" << endl;
    cout <<  "                  0  退出系统" << endl;
    cout <<  "***************************************************" << endl;
}
float Menu::maintainBorrowActorCase(Readerdata * readerdata)
{
    int option;
    float menuPage;
    char reader_name[20];
    char reader_password[11];
    int reader_num;
    Reader *r;
    maintainBorrowActor();
    cin >> option;
    switch (option)
    {
    case 1://增
        cout << "请输入读者编号:";
        cin >> reader_num;
        cout << "请输入读者姓名:";
        cin >> reader_name;
        cout << "请输入密码:";
        cin >> reader_password;
        readerdata->addreader (reader_num,reader_name,reader_password);
        break;
    case 2://删
        cout << "请输入读者编号:";
        cin >> reader_num;
        r=readerdata->search_rnum(reader_num);
        if (r==NULL)
        {
            cout <<"对不起，该读者不存在!" << endl;
            break;
        }
        r->delbook();
        break;
    case 3://改
        cout << "请输入读者编号:";
        cin >> reader_num;
        r=readerdata->search_rnum(reader_num);
        if (r==NULL)
        {
            cout << "对不起，该读者不存在! "<<endl;
            break;
        }
        cout << "请输入新的姓名:";
        cin >> reader_name;
        r->setname(reader_name);
        break;
    case 4://查
        cout << "请输入读者编号:";
        cin >> reader_num;
        r=readerdata->search_rnum(reader_num);
        if (r==NULL)
        {
            cout <<"对不起，该读者不存在!"<< endl;
            break;
        }
        else
        {
            r->readerShow();
        //    r->showReader();
        }
        break;
    case 5://返
        menuPage = 110;
        return menuPage;
    case 0:
        return 0;
    }
    menuPage = 112;
    return menuPage;
}
float Menu::maintainLibrarianCase(Readerdata * readerdata)
{
    int option;
    float menuPage;
    char reader_name[20];
    int reader_num;
    char reader_password[11];
    Reader *r;
    maintainLibrarian();
    cin >> option;
    switch (option)
    {
    case 1://增
        cout << "请输入图书管理员编号:";
        cin >> reader_num;
        cout << "请输入图书管理员姓名:";
        cin >> reader_name;
        cout << "请输入密码:";
        cin >> reader_password;
        readerdata->addreader (reader_num,reader_name,reader_password);
        break;
    case 2://删
        cout << "请输入图书管理员编号:";
        cin >> reader_num;
        r=readerdata->search_rnum(reader_num);
        if (r==NULL)
        {
            cout <<"对不起，该图书管理员不存在!" << endl;
            break;
        }
        r->delbook();
        break;
    case 3://改
        cout << "请输入图书管理员编号:";
        cin >> reader_num;
        r=readerdata->search_rnum(reader_num);
        if (r==NULL)
        {
            cout << "对不起，该图书管理员不存在! "<<endl;
            break;
        }
        cout << "请输入新的姓名:";
        cin >> reader_name;
        r->setname(reader_name);
        break;
    case 4://查
        cout << "请输入图书管理员编号:";
        cin >> reader_num;
        r=readerdata->search_rnum(reader_num);
        if (r==NULL)
        {
            cout <<"对不起，该图书管理员不存在!"<< endl;
            break;
        }
        else
        {
            r->librarianShow();
        }
        break;
    case 5://返
        menuPage = 110;
        return menuPage;
    case 0:
        return 0;
    }
    menuPage = 113;
    return menuPage;
}
void Menu::borrowPage(Readerdata *readerdata,BookDB *bookdb)
{
    int reader_num;
    int book_num;
    Reader *r;
    Book *b;
    cout <<  "***************************************************" << endl;
    cout <<  "                  借阅者编号：" ;
    cin >> reader_num;
    r = readerdata->search_rnum(reader_num);
    if (r == NULL)
    {
        cout<<"Sorry, 该借阅者不存在！"<<endl;
    }
    else
    {
        cout <<  "                  请输入所借图书编号：" ;
        cin >> book_num;
        b = bookdb->search_bnum(book_num);
        if (b == NULL)
        {
              cout<<"Sorry, 该图书不存在！"<<endl;
        }
        else
        {
            if (b->borrowbook()==0)//onshelf标志量
            {
                cout << "对不起，该图书已借出，不能借书!"<< endl;
            }
            else
            {
                r->borrowbook(book_num);
                cout << r->getrname()<<"借阅"<<"《"<<b->getbname()<<"》"<<"成功"<<endl;
            }
        }
    }
}
void Menu::returnPage(Readerdata *readerdata,BookDB *bookdb)
{
    int reader_num;
    int book_num;
    Reader *r;
    Book *b;
    cout <<  "***************************************************" << endl;
    cout <<  "                  借阅者编号：" ;
    cin >> reader_num;
    r = readerdata->search_rnum(reader_num);
    if (r == NULL)
    {
        cout<<"Sorry, 该借阅者不存在！"<<endl;
    }
    else
    {
        cout <<  "                  请输入所还图书编号：" ;
        cin >> book_num;
        b = bookdb->search_bnum(book_num);
        if (b == NULL)
        {
              cout<<"Sorry, 该图书不存在！"<<endl;
        }
        else
        {
            if (b->returnbook()==1)//onshelf标志量
            {
                cout << "对不起，该图书没有借出!"<< endl;
            }
            else
            {
                r->returnbook(book_num);
                cout << r->getrname()<<"返还"<<"《"<<b->getbname()<<"》"<<"成功"<<endl;
            }
        }
    }
}
void Menu::reservePage(BookDB *bookdb)
{
    int book_num;
    Book *b;
    cout <<  "***************************************************" << endl;
    cout <<  "                  请输入所还图书编号：" ;
    cin >> book_num;
    b = bookdb->search_bnum(book_num);
    if (b == NULL)
    {
          cout<<"Sorry, 该图书不存在！"<<endl;
    }
    else
    {
        cout<<"预定"<<"《"<<b->getbname()<<"》"<<"成功"<<endl;
    }
}
void Menu::readerPage()
{
    cout <<  "***************************************************" << endl;
    cout <<  "                  1  预定图书" << endl;
    cout <<  "                  2  查看个人信息" << endl;
    cout <<  "                  3  搜索书目" << endl;
    cout <<  "                  4  返回上一级" << endl;
    cout <<  "                  0  退出系统" << endl;
    cout <<  "***************************************************" << endl;
}






