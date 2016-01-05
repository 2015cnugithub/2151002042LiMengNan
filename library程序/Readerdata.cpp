// Readerdata.cpp: implementation of the Readerdata class.

#include "Readerdata.h"
#include <fstream>
#include <string.h>
#include<iostream>
using namespace std;

Readerdata::Readerdata()                 //构造函数，其作用是将reader.txt读到read[]中
{
	Reader R;
	reader_total=-1;
	fstream file("reader.txt",ios::in); //打开一个输入文件
	while (1)
	{
		file.read((char *)&R,sizeof(R));
		if (!file)break;
		reader_total++;
		reader[reader_total]=R;
	}
	file.close();                      
}
int Readerdata::addreader(int n,char *na,char *password) //新增读者时先检察该读者是否已经存在
{
	Reader *p=search_rnum(n);
	if (p==NULL)
	{
		reader_total++;
        reader[reader_total].addreader(n,na,password);
		return 1;
	}
	return 0;
}
void Readerdata::show()                  //输出所有读者详细信息
{
	for (int i=0;i<=reader_total;i++)
	{
        reader[i].readerShow();
        cout << endl;
	}
}
Reader * Readerdata::search_rnum(int reader_num)     //按读者借阅证编号查找
{
	for (int i=0;i<=reader_total;i++)
		if (reader[i].getnum()==reader_num&&reader[i].getflag()==0)
		{
			return &reader[i];
		}
		return NULL;
}
Reader * Readerdata:: search_rname(char reader_name[20])//按读者姓名查找读者
{
	for (int i=0;i<=reader_total;i++)
		for(int i=0;i<=reader_total;i++)
		if(strcmp(reader[i].getrname(),reader_name)==0&&reader[i].getflag()==0)
		{
			return &reader[i];
		}
		return NULL;
}
Readerdata:: ~Readerdata()                          //析构函数，其作用是将read[]写到reader.txt文件中
{
	fstream file("reader.txt",ios::out);
    for (int i=0;i<=reader_total;i++)
		if (reader[i].getflag()==0)
			file.write((char *)&reader[i],sizeof(reader[i]));
		file.close();

}
