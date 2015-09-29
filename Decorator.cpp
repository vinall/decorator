/*
 * Decorator.cpp
 * 
 * Following is the code for decorator pattern example in C++
 * Example has been taken from Head-first design pattern.
 * Decorator pattern provide us an excellent way to add resposibilities to an object
 * at runtime
 */


#include <iostream>
#include <string>
using namespace std;

class Beverage{
	string strDesc;
	
	public:
		Beverage()
		{
			strDesc = "Unknown Beverage";
		}
		Beverage(string strDesc)
		{
			this->strDesc = strDesc;
		}
		
		virtual string getDescription(){return strDesc;}
		
		virtual float getCost()=0;
		virtual ~Beverage(){
			cout<<"Beverage destructor"<<endl;
		}
};

class Mocha : public Beverage
{
	public :
		Mocha():Beverage("Mocha")
		{
			
		}
		float getCost()
		{
			
			return 0.8;
		}
		
		virtual ~Mocha(){
			cout<<"mocha destructor"<<endl;
		}
};
class BeverageDecorator : public Beverage
{
	public:
		virtual string getDescription()=0;
};
class whip : public BeverageDecorator
{
	private:
		Beverage *b;
	public:
		whip(Beverage *b)
		{
			this->b = b;
		}
		float getCost()
		{
			
			return 0.5f + b->getCost();
		}
		string getDescription()
		{
			
			return b->getDescription() + ",Whip";
		}
		~whip()
		{
			delete b;
			cout<<"whip destructor"<<endl;
		}
};
int main(int argc, char **argv)
{
	 
	Beverage *mocha = new Mocha();
	mocha = new whip(mocha);
	
	cout<<"Cost of "<<mocha->getDescription()<<" = "<<mocha->getCost()<<endl;
	
	cout<<"\n\nDestruction of Beverage ----"<<endl;
	delete mocha;
	return 0;
}

