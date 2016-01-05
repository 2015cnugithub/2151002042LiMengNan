/*******************************************************
mvc:
   V:Observer      M:Observable
     textView          sphere
     graphView   
   C:textController   graphcontroller


********************************************************/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Observable;// declare the Observable class,because Observer use it.

class Observer//Define the Observer class, in the project, the TextView and GraphView belong to it.
{
public:
 virtual void update(Observable *o)=0;//Virtual function, achieve polymorphic.
};

class Observable//Define the Observable 
{
public:

	vector<Observer*> obs;//container for Observer class.
    vector<Observer*>::iterator it;

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


class Sphere:public Observable
{
 double radius;
public:
	Sphere(double r)
	{
       radius=r;
	}
	double getradius()
	{
		return radius;
	}
	void setRadius(double r)
	{
		radius=r;

        notifyObservers();
	}
	double volume()
	{
        return 4/3*3.14*radius*radius*radius;
    }
    double surfaceArea() 
	{
        return 4*3.14*radius*radius;
    }

};
class GraphController
{
    Sphere *sphere;
	
public:
	GraphController(Sphere *sph) 
	{
		sphere=sph;
	}
	void mouseDragg(double x,double y)
	{
		x>y ? (*sphere).setRadius(x/2) : (*sphere).setRadius(y/2);
	}

};
class GraphView:public Observer
{
public:
      GraphView()
	  {
         cout<<"graph view window!!!"<<endl;
	  }
	  void update(Observable *o)
	  {
		  Sphere *sphere=(Sphere *)o;
		  cout<<"GraphView:"<<endl;
		  cout<<"This is a sphere which radious is "<<(*sphere).getradius()<<endl;    
	  }

};
class TextController
{
  Sphere *sphere;
public:
      TextController(Sphere *a)
	  {
         sphere=a;
	  }
	  void textAction(double r)
	  {
         (*sphere).setRadius(r);
	  }
};
class TextView:public Observer
{
public:
	TextView()
	{
		cout<<"text view !!!!"<<endl;
	}
    void update(Observable *o)
	{
	  Sphere *sphere=(Sphere *)o;
	  cout<<"TextView£º"<<endl;
      cout<<"radius is£º"<<(*sphere).getradius()<<endl;
	  cout<<"volume is£º"<<(*sphere).volume()<<endl;
	  cout<<"surfaceArea is:"<<(*sphere).surfaceArea()<<endl;
	}
};

int main()
{
  Sphere sphere(1);
  TextView textView;
  GraphView graphView;
  GraphController graphController(&sphere);
  TextController textController(&sphere);
  sphere.addObserver(&textView);
  sphere.addObserver(&graphView);
  textView.update(&sphere);
  graphView.update(&sphere);
  
  char option='Z';
  double r,x,y;

  while(option != 'q')
  {
	  cout<<"a.Input sphere radious in textview !!!"<<endl;
      cout<<"b.Drag mouse change the sphere radious in Graphview !!!"<<endl;
	  cout<<"q.Quit !!!"<<endl;
	  scanf(" %c",&option);
		  if(option=='a')
		  {
			  cout<<"Please input the radious of sphere:"<<endl;
			  cin>>r;
              textController.textAction(r);
		  }
		  if(option=='b')
		  {
			  cout<<"Please input x,y:"<<endl;
			  cin>>x>>y;
              graphController.mouseDragg(x,y) ;
		  }
  }
  return 0;
}