#include <iostream>
#include <string>
using namespace::std;
//声明Worker基类
class Worker{
public:
	void setValues(string,int,string,double);
	virtual void comput_pay(double hours){};
	friend ostream &operator << (ostream &out, Worker &worker){
		out << "Name:" << worker.name << " Age:" << worker.age <<
		" Sex:" << worker.sex <<  " Pay per hour:" << worker.pay_per_hour << endl;
		return out;
}
	void show_name(){
		cout << name << endl;
	}
protected:
	string name;
	int age;
	string sex;
	double pay_per_hour;
};
//设置数据成员值
void Worker::setValues(string n,int a,string x,double pay){
	name = n;
	age = a;
	sex = x;
	pay_per_hour = pay;
}
//重载运算符<<
/*ostream& operator<<(ostream& out, Worker& worker){
		out << "Name:" << worker.name << " Age:" << worker.age <<
		" Sex:" << worker.sex <<  " Pay per hour:" << worker.pay_per_hour << endl;
		return out;
}*/

//声明Worker的派生类HourlyWorker
class HourlyWorker : public Worker{
public:
	void comput_pay(double hours){
		double pay;
		if(hours < 40){
			pay = pay_per_hour*hours;
		}
		else{
			pay = pay_per_hour*40+1.5*pay_per_hour*(hours-40);
		}
		cout << "The worker shoud be paied " << pay << endl;
	}
};
//声明Worker的派生类SalariedWorker
class SalariedWorker : public Worker{
public:
	void Comput_pay(double hours){
		double pay;
		if (hours < 35){
			pay = pay_per_hour*hours + 0.5*pay_per_hour*(35 - hours);
		}
		else{
			pay = pay_per_hour * 40;
		}
		cout << "The worker shoud be paied " << pay << endl;
	}
};
void main()
{
	Worker * p_worker[5];//指针数组，存放动态生成的worker对象地址
	int i = 0;//循环用
	int num = 0;//选择菜单选项时用
	double h;//一周工作小时数
	/*存放键盘输入值*/
	string name;
	int age;
	string sex;
	double per_pay;
	/*创建五个对象，并赋值*/
	for(i=0; i<5; i++){

		cout << "input name,age,sex,per_pay:";
		cin >> name >> age >> sex >> per_pay;
		if(per_pay == 10 || per_pay == 20 || per_pay == 40){
			p_worker[i] = new HourlyWorker;
		}
		else if(per_pay == 30 || per_pay ==50){
			p_worker[i] = new SalariedWorker;
		}
		else{
			cout << "the per_pay is invalid" << endl;
			return;
		}
		p_worker[i]->setValues(name,age,sex,per_pay);
	}
	/*显示菜单*/
	for (i = 0; i < 5; i++){
		cout << i + 1 << " ";
		p_worker[i]->show_name();
	}
	cout << "choose a number:";
	cin >> num;
	cout << *p_worker[num-1];//显示该工人基本信息
	cout << "input the working hours:";
	cin >> h;
	p_worker[num-1]->comput_pay(h);
	/*释放动态生成的对象所占的内存*/
	for(i = 0; i<5; i++){
		delete p_worker[i];
	}
}