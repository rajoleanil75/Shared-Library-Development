using namespace std;
#include"sharedfile.h"
#include<stdio.h>

DoublyLL::DoublyLL()
{
	head = NULL;
}

DoublyLL::~DoublyLL()
{
	if(head == NULL)
		return;
	else
	{
		DNODE temp = head;
		while(head != NULL)
		{
			head = head->next;
			delete temp;
			temp=head;
		}
	}
}

void DoublyLL::insertFirst(int no)
{
	DNODE temp = new NODE;
	temp->data = no;
	if(head == NULL)
	{
		head = temp;
		head->next = NULL;
		head->prev = NULL;
	}
	else
	{
		temp->prev = NULL;
		temp->next = head;
		head->prev = temp;
		head = temp;
	}
}

void DoublyLL::insertLast(int no)
{
	if(head == NULL)
		insertFirst(no);
	else
	{
		DNODE temp = head;
		while(temp->next != NULL)
			temp = temp->next;
		DNODE nn = new NODE;
		nn->data = no;
		nn->next = NULL;
		nn->prev = temp;
		temp->next = nn;
	}
}

void DoublyLL::insertAtPosition(int no, int pos)
{
	if(pos <= 0 || pos > count()+1)
		return;
	else if(pos == 1)
		insertFirst(no);
	else if(pos == count()+1)
		insertLast(no);
	else
	{
		DNODE temp = head;
		while(pos-2 != 0)
		{
			temp = temp->next;
			pos--;
		}
		DNODE temp1 = temp->next;
		DNODE nn = new NODE;
		nn->data = no;
		nn->next = temp1;
		nn->prev = temp;
		temp->next = nn;
		temp1->prev = nn;
	}
}

void DoublyLL::deleteFirst()
{
	if(head == NULL)
		return;
	DNODE temp = head;
	head = head->next;
	head->prev = NULL;
	delete temp;
}

void DoublyLL::deleteLast()
{
	if(head == NULL)
		return;
	DNODE temp = head;
	while(temp->next->next != NULL)
		temp = temp->next;
	DNODE temp1 = temp->next;
	temp->next = NULL;
	delete temp1;
}

void DoublyLL::deleteAtPosition(int pos)
{
	if(pos <= 0 || pos > count())
		return;
	else if(pos ==1)
		deleteFirst();
	else if(pos == count())
		deleteLast();
	else
	{
		DNODE temp = head;
		while(pos-2 != 0)
		{
			temp = temp->next;
			pos--;
		}
		DNODE temp1 = temp->next;
		temp->next=temp1->next;
		temp1->next->prev=temp;
		delete temp1;
	}
}

void DoublyLL::display()
{
	DNODE temp = head;
	while(temp != NULL)
	{
		printf("| %d |->",temp->data);
		temp = temp->next;
	}
	printf("NULL\n");
}

int DoublyLL::count()
{
	int cnt = 0;
	DNODE temp = head;
	while(temp != NULL)
	{
		cnt++;
		temp = temp->next;
	}
	return cnt;
}

extern "C"
{
	DoublyLL* create()
	{
		return new DoublyLL;
	}
	void destroy(DoublyLL* obj)
	{
		delete obj;
	}
}