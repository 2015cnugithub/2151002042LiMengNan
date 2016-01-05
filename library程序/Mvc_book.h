// Mvc_book.h: interface for the Mvc_book class.

#ifndef _MVC_BOOK_H_
#define _MVC_BOOK_H_

#include <iostream>
#include <string.h>
#include <fstream>
#include<vector>
#include<algorithm>
using namespace std;

const int Max_book=250;               //可保存图书数量的上限

class Observable;// declare the Observable class,because Observer use it.

class Observer//Define the Observer class, in the project, the TextView and GraphView belong to it.
{
public:
 virtual void update(Observable *o)=0;//Virtual function, achieve polymorphic.
};

class Observable//Define the Observable 
{
private:
	vector<Observer*> obs;//container for Observer class.
    vector<Observer*>::iterator it;
public:
	void notifyObservers()
	{
		for(it=obs.begin();it!=obs.end();it++)
        (*it)->update(this);
	}

	void addObserver(Observer *o) 
	{
       it=find(obs.begin(),obs.end(),o);
	   if (it==obs.end())
	   {
		   obs.push_back(o);
	   }	
    }
	void deleteObserver(Observer *o)
	{
        it=find(obs.begin(),obs.end(),o);
        if (it!=obs.end())
	    obs.erase(it);
    }

	 int countObservers() 
	 {
        return obs.size();
	 }
};

class BookDB;

class Book:public Observable
{
public:
	int num;                           //设置图书条形码
    int flag;                          //设置删除标记     1：已经删除  0：还未删除
	int onshelf;                       //判断图书是否再架 1: 再架可借  0: 本馆借出
	int pub_time;                      //设置出版年月
	char bname[50];                    //设置图书书名
	char pub_name[50];                 //设置出版社名称
	char w_name[10];                   //设置作者姓名

	int getnum(){ return num; }            //获取图书编号
	int getflag(){ return flag; }          //获取删除标记
	int getpub_time(){ return pub_time;}   //获取出版年月
	char *getbname() { return bname; }     //获取图书书名
	char *getpub_name(){ return pub_name;} //获取出版社名
	char *getw_name(){ return w_name;}     //获取作者姓名
	void setbname(char na[]){strcpy(bname,na);} //设置书名
	void setwname(char na[]){strcpy(w_name,na);}//设置作者名字
	void setpubtime(int number){num=number;}    //设置图书新的出版年月
	void setpubname(char na[]){strcpy(pub_name,na);}//设置图书新的出版年月
	void delbook(){ flag=1;}  //删除图书信息
	void show();              //输出图书信息  
    int borrowbook()          //借阅图书
    {
            if (onshelf==1)
            {
                onshelf=0;
                return 1;
            }
            return 0;
    }
    int returnbook()          //归还图书
    {
        if (onshelf==0)
        {
            onshelf=1;
            return 0;
        }
        return 1;
    }
    void addbook(int n,char *na,char *wname,char *pubname,int pubtime)//新增图书信息
    {
        flag=0;
        num=n;
        strcpy(bname,na);
        strcpy(w_name,wname);
        strcpy(pub_name,pubname);
        pub_time=pubtime;
        onshelf=1;
        notifyObservers();
    }
};

class BookDB:public Observer
{
private:
    int book_total;          //图书总共数目
	Book book[Max_book];     //图书记录数组
public:
	BookDB()
	{
        Book b;
		book_total=-1;
/*        //char a;
       fstream file("book.txt",ios::in);
		while (1)
		{
            file.read((char *)&b,sizeof(b));
			if (!file) break;
			book_total++;
            //cin>>a;
            //cout<<sizeof(c);
            //cout<<sizeof(b);
            //cout<<sizeof(book[0]);
            //cin>>a;
            book[book_total]=b;
            //cin>>a;
		}
        file.close();*/
	}

    ~BookDB() //析构函数，其作用是将book[]写到book.txt文件中
	{
		fstream file("book.txt",ios::out);
		for (int i=0;i<=book_total;i++)
			if (book[i].getflag()==0)
                file.write((char *)&book[i],sizeof(book[i]));
			file.close();
	}

	Book *search_bnum(int book_num)    //按图书编号查找图书
	{
        //cout<<book_total<<endl;
		for (int i=0;i<=book_total;i++)
		{
         //   cout<<i<<endl;
			if (book[i].getnum()==book_num && book[i].getflag()==0)
			{	
				return &book[i];
			}
		}
        //cout<<"error"<<endl;
		return NULL;
	}
	
	void update(Observable *o)
	{
           //  cout<<"update:book_total="<<book_total<<endl;
      book[++book_total] = *((Book *)o);
         //   cout<<"update:book_total="<<book_total<<endl;
	}		
	
	void search_bname()//按图书书名查找图书
	{
		int num=0;//if num=0 -->not find
		char bname[50];
		cout << "请输入需要查找的图书的名字:"<<endl;
		cin >> bname;
		for(int i=0;i<=book_total;i++)
		{
			if(strcmp(book[i].getbname(),bname)==0 && book[i].getflag()==0)
			{
				num++;
				show(&book[i]);
				break;
			}
		}
        if(num==0)
		{
			cout <<"对不起，该图书不存在!"<< endl;
		}
	}
	  void show(Book *book)  //输出图书详细信息
	  {
    	cout <<"图书状态："<<(book->onshelf==1? "在架可借":"本馆借出")<<"   "<<"作者姓名："<<book->w_name<<"   "<<"书 名 :"<<"《"<< book->bname<<"》"<<"   "<<endl;
    	cout <<"图书编号: "<<book->num<<"   "<<"出版时间: "<<book->pub_time<<"   "<<"出版社: "<< book->pub_name<<endl; 
	  }
		  		
};

class BookController
{
  Book *book;
public:
      BookController(Book *b)
	  {
        book=b;
	  }


	  void addButton()
	  {
		char wname[10];
        char bname[50];
        char pubname[50];
        int book_num;
        int pubtime;
		cout << "请输入新增图书的书名:"<<endl;
		cin >> bname;
		cout << "请输入新增图书作者姓名:"<<endl;
		cin >> wname;
		cout << "请输入新增图书的编号:"<<endl;
		cin >> book_num;
        cout << "请输入新增图书的出版社名称:" << endl;
		cin >> pubname;
		cout << "请输入新增图书出版年月:" << endl;
		cin >> pubtime;
        (*book).addbook(book_num,bname,wname,pubname,pubtime);
	  }

    void modifyBook(BookDB *bookDB )
	{
		char wname[10];
		char bname[50];
		char pubname[50];
		int book_num;
		int pubtime;
	//	Book *b;
        //BookDB bookDB; only one bookDB
		cout << "请输入需要修改的图书的编号:"<<endl;
		cin >> book_num;
        book=bookDB->search_bnum(book_num);
		if (book==NULL)
		{
			cout << "对不起，该图书不存在!  "<<endl;
		}
		else
		{
			cout << "请输入新的书名:"<<endl;
			cin >> bname;
			book->setbname(bname);
			cout << "请输入图书作者新的名字:"<<endl;
			cin >>wname;
			book->setwname(wname);
			cout <<"请输入图书新的出版年月:"<<endl;
			cin >>pubtime;
			book->setpubtime(pubtime);
			cout <<"请输入图书新的出版社名字:"<<endl;
			cin >>pubname;
			book->setpubname(pubname);
		}
	}
    void delBook(BookDB *bookDB)
    {
        int book_num;
        cout <<"请输入需要删除的图书的编号:"<<endl;
        cin >> book_num;
        book=bookDB->search_bnum(book_num);
        if (book==NULL)
        {
            cout <<"对不起，该图书不存在!" << endl;
        }
        else
        {
            book->delbook();
        }
    }

};

#endif
