using namespace std;
#include"sharedfile.h"
#include<stdio.h>

SinglyCLL::SinglyCLL()
{
	head = NULL;
}
SinglyCLL::~SinglyCLL()
{
	if(head == NULL)
		return;
	SCNODE temp;
	while(head != NULL)
	{
		temp = head;
		head = head->next;
		delete temp;
	}
}

void SinglyCLL::insertFirst(int no)
{
	SCNODE nn = new NODE;
	nn->data = no;
	if(head == NULL)
	{
		head = nn;
		head->next = head;
	}
	else
	{
		SCNODE temp = head;
		while(temp->next != head)
			temp = temp->next;
		temp->next = nn;
		nn->next = head;
	}
}
void SinglyCLL::insertLast(int no)
{
	SCNODE nn = new NODE;
	nn->data = no;
	if(head == NULL)
	{
		head = nn;
		head->next = head;
	}
	else
	{
		SCNODE temp = head;
		while(temp->next != head)
			temp = temp->next;
		temp->next = nn;
		nn->next = head;
	}
}
void SinglyCLL::insertAtPosition(int no, int pos)
{
	if(pos <= 0 || pos > count()+1)
		return;
	if(pos == 1)
		insertFirst(no);
	else if(pos == count()+1)
		insertLast(no);
	else
	{
		SCNODE temp =head;
		while(pos-2 != 0)
		{
			temp = temp->next;
			pos--;
		}
		SCNODE nn = new NODE;
		nn->data = no;
		nn->next = temp->next;
		temp->next = nn;
	}
}

void SinglyCLL::deleteFirst()
{
	if(head == NULL)
		return;
	else if(head->next == head)
	{
		delete head;
		head = NULL;
	}
	else
	{
		SCNODE temp = head;
		while(temp->next != head)
			temp = temp->next;
		temp->next = head->next;
		temp = head;
		head = head->next;
		delete temp;
	}
}

void SinglyCLL::deleteLast()
{
	if(head == NULL)
		return;
	else if(head->next == head)
	{
		delete head;
		head = NULL;
	}
	else
	{
		SCNODE temp = head;
		while(temp->next->next != head)
			temp = temp->next;
		SCNODE temp1 = temp->next;
		temp->next = head;
		delete temp1;
	}
}

void SinglyCLL::deleteAtPosition(int pos)
{
	if(pos <= 0 || pos > count())
		return;
	if(pos == 1)
		deleteFirst();
	if(pos == count())
		deleteLast();
	else
	{
		SCNODE temp = head;
		while(pos-2 != 0)
		{
			temp = temp->next;
			pos--;
		}
		SCNODE temp1 = temp->next;
		temp->next = temp1->next;
		delete temp1;
	}
}

void SinglyCLL::display()
{
	SCNODE temp = head;
	printf("\n <--> ");
	while(temp->next != head)
	{
		printf("| %d | <--> ",temp->data);
		temp = temp->next;
	}
	printf("| %d | <--> ",temp->data);
}

int SinglyCLL::count()
{
	SCNODE temp = head->next;
	if(head == NULL)
		return 0;
	int cnt = 1;
	while(temp != head)
	{
		cnt++;
		temp = temp->next;
	}
	return cnt;
}

extern "C"
{
	SinglyCLL* create()
	{
		return new SinglyCLL;
	}
	void destroy(SinglyCLL *obj)
	{
		delete obj;
	}
}