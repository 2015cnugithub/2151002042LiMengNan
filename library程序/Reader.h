// Reader.h: interface for the Reader class.

#ifndef _READER_H_
#define _READER_H_

const int Max_bor_book=5;  //读者借阅图书本数上限

class Reader//读者类
{   
private:
	int num;                                //读者借阅证编号
	char rname[10];                         //读者姓名
    char rpassword[11];
	int borbook[Max_bor_book];              //读者借阅的图书
	int flag;                               //删除标记 1:已经删除 0:还未删除
public:
	Reader() {}
	int getnum() {return num;}              //获取读者借阅证编号
    int returnbook(int bookid);             //归还图书
    char *getrname() {return rname;}        //获取读者姓名
    char *getrpassword(){return rpassword;} //获取密码
	int getflag() {return flag;}            //获取删除标记
	void setname(char na[]);                //设置姓名
	void delbook(){  flag=1;  };            //设置删除标记 1:已经删除 0:还未删除
    void addreader(int n,char *na,char *password);  //增加读者
    void borrowbook(int bookid);                    //借阅图书
    void readerShow();                              //输出读者详细信息
    void librarianShow();
};

#endif
