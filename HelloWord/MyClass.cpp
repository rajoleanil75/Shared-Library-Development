using namespace std;
#include<iostream>
#include"sharedfile.h"
#include<stdio.h>

Hello::Hello()
{
	i=0;
	cout<<"\n In Constructor of Hello";
}

Hello::~Hello()
{
	cout<<"\n In Destructor of Hello";
}

void Hello::accept(int a)
{
	i=a;
	cout<<"\n In Accept function of Hello";
}

void Hello::display()
{
	cout<<"\n In Display function of Hello";
	cout<<"\n Value of i: "<<i;
}

extern "C"
{
	Hello* create()
	{
		return new Hello;
	}
	void destroy(Hello* p)
	{
		delete p;
	}
}