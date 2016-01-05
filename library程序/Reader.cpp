// Reader.cpp: implementation of the Reader class.

#include "Reader.h"
#include <string.h>
#include <iostream>
using namespace std;


void Reader::setname(char na[])             //设置姓名
{ 
		   strcpy(rname,na);
}
void Reader::addreader(int n,char *na,char *password)      //新增读者
{ 
		flag=0;
		num=n;
		strcpy(rname,na);
        strcpy(rpassword,password);
		for(int i=0;i<Max_bor_book;i++)
			borbook[i]=0;
}
void Reader::borrowbook(int book_num)        //借阅图书
{
	for(int i=0;i<Max_bor_book;i++)
	{ 
		if (borbook[i]==0)
		{
			borbook[i]=book_num;
			return;
		}
	}
}
int Reader::returnbook(int book_num)            //归还图书
{ 
	for(int i=0;i<Max_bor_book;i++)
	{ 
		if(borbook[i]==book_num)
		{
			borbook[i]=0;
			return 1;
		}
	}
	return 0;
}
void Reader::readerShow()
{
	cout << "读者编号："<< num <<"   "<< "读者姓名: "<<rname<<endl;
    cout<<"该借阅者所借图书编号有：";
	for(int i=0;i<Max_bor_book;i++)
    {
        if(borbook[i]!=0)
            cout <<"<"<<borbook[i] <<">";
    }
    cout<<endl;
}
void Reader::librarianShow()
{
    cout << "图书管理员编号："<< num <<"   "<< "图书管理员姓名: "<<rname<<endl;
}
