typedef struct node
{
	int data;
	struct node *prev, *next;
}NODE,*DNODE;

class DoublyLL
{
private:
	DNODE head;
public:
	DoublyLL();
	~DoublyLL();
	virtual void insertFirst(int );
	virtual void insertLast(int );
	virtual void insertAtPosition(int , int );
	virtual void deleteFirst();
	virtual void deleteLast();
	virtual void deleteAtPosition(int );
	virtual void display();
	virtual int count();
};