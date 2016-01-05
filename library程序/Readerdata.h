// Readerdata.h: interface for the Readerdata class.

#ifndef _READERDATA_H_
#define _READERDATA_H_
#include "Reader.h"

const int Max_reader=1000;//可保存读者数量的上限

class Readerdata//读者数据类
{
private:
   Reader reader[Max_reader];   //读者信息记录
   int reader_total;            //读者总共数目

public:
    Readerdata();                                 //构造函数，其作用是将reader.txt读到read[]中
    int addreader(int n,char *na,char *password); //新增读者时先检察该读者是否已经存在
    Reader *search_rnum(int reader_num) ;         //按读者借阅证编号查找
    Reader *search_rname(char reader_name[20]);   //按读者姓名查找读者
    void show();                                  //输出所有读者详细信息
    ~Readerdata();                                //析构函数，其作用是将read[]写到reader.txt文件中

};
#endif
