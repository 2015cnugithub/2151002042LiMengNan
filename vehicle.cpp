#include<iostream.h>
#include <graphics.h>
#include<conio.h>
#include"math.h"
class Figure{
public:
	int linestyle;
	int thickness;
	int linecolor;
	virtual void hidden()=0;
	virtual void draw()=0;
	virtual void move(int x,int y)=0;
	virtual int judje(int x){           //循环终止条件
		return 1;
	}


};
class Circle:public Figure{
private:
	int radius;
	int x1,y1;
public:
    Circle(){}
//	void operator()(int lines,int thickn,int linec,int r,int x,int y)
	Circle(int lines,int thickn,int linec,int r,int x,int y)
	{
		linestyle=lines;
        thickness=thickn;
        linecolor=linec;
		radius=r;
        x1=x;
	    y1=y;
	}
	virtual void draw(){
	setlinecolor(linecolor);
	setlinestyle(linestyle,thickness);
	circle(x1,y1,radius);

	}
	virtual void hidden(){
	setlinecolor(BLACK);
	setlinestyle(linestyle,thickness);
	circle(x1,y1,radius);
	
	}
	virtual void move(int x,int y){
	x1=x1+x;
    y1=y1+y;
	
	}

};
class Triangle:public Figure{
private:
	int x0[3];
	int y0[3];
public:
	//void operator()(int lines,int thickn,int linec,int x1[3],int y1[3])
Triangle(int lines,int thickn,int linec,int x1[3],int y1[3])
	{	
		linestyle=lines;
        thickness=thickn;
        linecolor=linec;
		for(int i=0;i<3;i++){
		x0[i]=x1[i];
		y0[i]=y1[i];
		}
	}
virtual void draw(){
	setlinecolor(linecolor);
	setlinestyle(linestyle,thickness);
	line(x0[0],y0[0],x0[1],y0[1]);
    line(x0[0],y0[0],x0[2],y0[2]); 
    line(x0[1],y0[1],x0[2],y0[2]);
}
virtual void hidden(){
   setlinecolor(BLACK);
   setlinestyle(linestyle,thickness);
   line(x0[0],y0[0],x0[1],y0[1]);
   line(x0[0],y0[0],x0[2],y0[2]); 
   line(x0[1],y0[1],x0[2],y0[2]);
}
virtual void move(int x,int y){
	for(int i=0;i<3;i++){
       x0[i]=x0[i]+x;
	   y0[i]=y0[i]+y;
	}
}
};
class R:public Figure{
private:
int x1,y1,x2,y2,x3,y3,x4,y4;
public:
	R(){}
	R(int lines,int thickn,int linec,int x5,int y5,int x6,int y6,int x7,int y7,int x8,int y8){
	    linestyle=lines;
        thickness=thickn;
        linecolor=linec;
        x1=x5;
	    y1=y5;
		x2=x6;
		y2=y6;
		x3=x7;
		y3=y7;
		x4=x8;
		y4=y8;
	
	}
	virtual void draw(){
	setlinecolor(linecolor);
	setlinestyle(linestyle,thickness);
	line(x1,y1,x2,y2);
    line(x1,y1,x3,y3); 
    line(x2,y2,x4,y4);
    line(x3,y3,x4,y4);

}
virtual void hidden(){
   setlinecolor(BLACK);
   setlinestyle(linestyle,thickness);
   line(x1,y1,x2,y2);
   line(x1,y1,x3,y3);
   line(x2,y2,x4,y4);
   line(x3,y3,x4,y4);
}
virtual void move(int x,int y){
	x1=x1+x;
    y1=y1+y;
	x2=x2+x;
    y2=y2+y;
	x3=x3+x;
    y3=y3+y;
	x4=x4+x;
    y4=y4+y;
	}
 virtual int judje(int x){//循环终止条件
	int y=690-(x1+x);
		if(y>=160)
		{
		    return 1;}
		else
			return 0;

	}
};

class FigureLink{
public:
	Figure *data;            //定义数据域
    FigureLink *next;        //定义指针域
	FigureLink(){
	}
	void setdata(Figure *f){
	data=f;
	}
	void setnext(FigureLink *t){
	next=t;
	
	}
	FigureLink *getnext(){
	return next;
	}
    Figure *getdata(){
		return data;
	}

};
class Vehicle{   
public:
	FigureLink contents;
	virtual void draw()=0;
	virtual void hidden()=0;
	virtual void move(int x,int y)=0;

};

class Car:public Vehicle{
public:
	 Car(Figure *f[6]){
     FigureLink *p=&contents;
	 FigureLink * t;
   for(int i=0;i<6;i++)
	{                             //生成链表
	   t=new FigureLink;
	   t->setdata(f[i]);  //第一个结点的数据域为空
       p->setnext(t);
	   p=t;
	}
	}
   virtual void draw(){
   FigureLink *p=contents.getnext();
   Figure *t;
   for(int i=0;i<6;i++)
   {
	   t=p->getdata();       //循环遍历链表
	   t->draw();
	   p=p->getnext();
   }
	
	}
   virtual void hidden(){
   FigureLink *p=contents.getnext();
   Figure *t;
   for(int i=0;i<6;i++)
   {
	   t=p->getdata();       //循环遍历链表
	   t->hidden();
	   p=p->getnext();
   }
	
	}
   virtual void move(int x,int y){
    FigureLink *p=contents.getnext();
    Figure *t;
   for(int i=0;i<6;i++)
   {
	   t=p->getdata();       //循环遍历链表
	   t->move(x,y);
	   p=p->getnext();
   }

   }
   virtual int judje(int x){   //循环终止条件
	    FigureLink *p=contents.getnext();
    Figure *t;
   for(int i=0;i<2;i++)
	   p=p->getnext();
       t=p->getdata();
	   return t->judje(x);
   }  
};
class Truck:public Vehicle{
public:
	 Truck(Figure *f[7]){
     FigureLink *p=&contents;
	 FigureLink * t;
   for(int i=0;i<7;i++)
	{                             //生成链表
	   t=new FigureLink;
	   t->setdata(f[i]);  //第一个结点的数据域为空
       p->setnext(t);
	   p=t;
	}
	}
   virtual void draw(){
   FigureLink *p=contents.getnext();
   Figure *t;
   for(int i=0;i<7;i++)
   {
	   t=p->getdata();       //循环遍历链表
	   t->draw();
	   p=p->getnext();
   }
	
	}
   virtual void hidden(){
   FigureLink *p=contents.getnext();
   Figure *t;
   for(int i=0;i<7;i++)
   {
	   t=p->getdata();       //循环遍历链表
	   t->hidden();
	   p=p->getnext();
   }
	
	}
   virtual void move(int x,int y){
    FigureLink *p=contents.getnext();
    Figure *t;
   for(int i=0;i<7;i++)
   {
	   t=p->getdata();       //循环遍历链表
	   t->move(x,y);
	   p=p->getnext();
   }

   }
  /* virtual int judje(int x){   //循环终止条件
	    FigureLink *p=contents.getnext();
    Figure *t;
   for(int i=0;i<2;i++)
	   p=p->getnext();
       t=p->getdata();
	   return t->judje(x);
   }  */
};
void main(){
	initgraph(700,500);

    Circle c1(PS_SOLID,1,WHITE,10,35,390);
    Circle c2(PS_SOLID,1,WHITE,10,125,390);
	R r1(PS_SOLID,1,WHITE,0,380,0,360,160,380,160,360);
	R r2(PS_SOLID,1,WHITE,45,360,45,340,115,360,115,340);
	int x[3]={25,45,45};
	int y[3]={360,340,360};
	int x1[3]={115,115,135};
	int y1[3]={360,340,360};
	Triangle t1(PS_SOLID,1,WHITE,x,y);
	Triangle t2(PS_SOLID,1,WHITE,x1,y1);
	R r3(PS_SOLID,1,WHITE,0,380,0,300,180,380,180,300);
	R r4(PS_SOLID,1,WHITE,182,380,182,320,222,380,222,320);
	Figure *f1[7];
    Circle c3(PS_SOLID,1,WHITE,10,20,390);
    Circle c4(PS_SOLID,1,WHITE,10,45,390);
	Circle c5(PS_SOLID,1,WHITE,10,135,390);
    Circle c6(PS_SOLID,1,WHITE,10,160,390);
	Circle c7(PS_SOLID,1,WHITE,10,202,390);
	f1[0]=&r3;
	f1[1]=&r4;
	f1[2]=&c3;
	f1[3]=&c4;
	f1[4]=&c5;
	f1[5]=&c6;
    f1[6]=&c7;
    Figure *f[6];
	f[0]=&c1;
	f[1]=&c2;
	f[2]=&r1;
	f[3]=&r2;
	f[4]=&t1;
	f[5]=&t2;
	int v=12;
	int flag=1;
	outtextxy(0,0,"请输入您要进行的操作：1---————小车，2---————卡车");
		char c;
		cin>>c;
	switch(c)
	{
	case '1':{
		       Car car(f);
		       car.draw();
			   outtextxy(0,20,"请选择您要进行的操作：Press <S> key to start moving");
			   outtextxy(0,40,"请选择您要进行的操作：Press <P> key to pause/continue moving");
			   outtextxy(0,60,"请选择您要进行的操作：Press <E> key to end moving");
			   outtextxy(0,80,"请选择您要进行的操作：Press <+> key to speed up");
               outtextxy(0,100,"请选择您要进行的操作：Press <-> key to speed down");
			   while(1)
			   {
				   if(kbhit()){
					   c=getch();
					   if(c=='s')
					   {
						   while(car.judje(v)){
						   if(kbhit()){
							   c=getch();
							   if(c=='+'){flag=1;v=v+10;}
							   else if(c=='-'){
								   flag=1;
							      if(v>=10)
								   v=v-10;
							   
							   }else if(c=='p'){
								  if(flag==1){
									   flag=0;
									   v=0;
								  }
								   else{
									   flag=1;
								       v=12;//恢复时假设为初始速度
								   }
							   }else if(c=='e')
									   break;
								else{}
							   
							   }
						   car.hidden();
						   car.move(v,0);
						   car.draw();
						   Sleep(150);
						   }//while
						   break;
					   }//if
				
					   if(c=='e')
					   {
						   break;
					   }
					   }

				   }//while
		       break;
			 }
	  case '2':
               {
		       Truck truck(f1);
		       truck.draw();
			   outtextxy(0,20,"请选择您要进行的操作：Press <S> key to start moving");
			   outtextxy(0,40,"请选择您要进行的操作：Press <P> key to pause/continue moving");
			   outtextxy(0,60,"请选择您要进行的操作：Press <E> key to end moving");
			   outtextxy(0,80,"请选择您要进行的操作：Press <+> key to speed up");
               outtextxy(0,100,"请选择您要进行的操作：Press <-> key to speed down");
			   while(1)
			   {
				   if(kbhit()){
					   c=getch();
					   if(c=='s')
					   {
						   while(1){
						   if(kbhit()){
							   c=getch();
							   if(c=='+'){flag=1;v=v+10;}
							   else if(c=='-'){
								   flag=1;
							      if(v>=10)
								   v=v-10;
							   
							   }else if(c=='p'){
								  if(flag==1){
									   flag=0;
									   v=0;
								  }
								   else{
									   flag=1;
								       v=12;//恢复时假设为初始速度
								   }
							   }else if(c=='e')
									   break;
								else{}
							   
							   }
						   truck.hidden();
						   truck.move(v,0);
						   truck.draw();
						   Sleep(150);
						   }//while
						   break;
					   }//if
				
					   if(c=='e')
					   {
						   break;
					   }
					   }

				   }//while
		       break;
			 }
	}

}







    







