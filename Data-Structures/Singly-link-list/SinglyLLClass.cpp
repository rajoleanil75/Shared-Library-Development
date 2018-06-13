using namespace std;
#include"sharedfile.h"
#include<stdio.h>

SinglyLL::SinglyLL()
{
	head = NULL;
}

SinglyLL::~SinglyLL()
{
	if(head == NULL)
		return;
	PNODE temp1,temp2;
	temp1=head;
	while(temp1!=NULL)
	{
		temp2=temp1->next;
		delete temp1;
		temp1=temp2;
	}
}

void SinglyLL::insertFirst(int no)
{
	PNODE temp = new NODE;
	temp->data = no;
	temp->next = head;
	head = temp;
}

void SinglyLL::insertLast(int no)
{
	PNODE temp = new NODE;
	temp->data = no;
	temp->next = NULL;
	if(head == NULL)
		head=temp;
	else
	{
		PNODE temp1 = head;
		while(temp1->next !=NULL)
			temp1 = temp1->next;
		temp1->next=temp;
	}
}

void SinglyLL::insertAtPosition(int no, int pos)
{
	if(pos <=0 || pos > count()+1)
		return;
	if(pos == 1)
		insertFirst(no);
	else if(pos == count()+1)
		insertLast(no);
	else
	{
		PNODE temp = new NODE;
		temp->data = no;
		PNODE temp1 = head;
		while(pos-2 != 0)
		{
			temp1 = temp1->next;
			pos--;
		}
		temp->next = temp1->next;
		temp1->next = temp;
	}
}

void SinglyLL::deleteFirst()
{
	if(head == NULL)
		return;
	else
	{
		PNODE temp = head;
		head = head->next;
		delete temp;
	}
}

void SinglyLL::deleteLast()
{
	if(head == NULL)
		return;
	else
	{
		PNODE temp = head;
		while(temp->next->next != NULL)
			temp = temp->next;

		delete temp->next;
		temp->next = NULL;
	}
}

void SinglyLL::deleteAtPosition(int pos)
{
	if(pos <= 0 || pos > count())
		return;
	else if(pos == 1)
		deleteFirst();
	else if(pos == count())
		deleteLast();
	else
	{
		PNODE temp = head;
		while(pos-2 != 0)
		{
			temp = temp->next;
			pos--;
		}
		PNODE temp1 = temp->next;
		temp->next=temp1->next;
		delete temp1;
	}
}

void SinglyLL::display()
{
	PNODE temp = head;
	while(temp != NULL)
	{
		printf("| %d |->",temp->data);
		temp = temp->next;
	}
	printf("NULL\n");
}

int SinglyLL::count()
{
	PNODE temp = head;
	int cnt = 0;
	while(temp != NULL)
	{
		temp = temp->next;
		cnt++;
	}
	return cnt;
}

extern "C"
{
	SinglyLL* create()
	{
		return new SinglyLL;
	}
	void destroy(SinglyLL* obj)
	{
		delete obj;
	}
}