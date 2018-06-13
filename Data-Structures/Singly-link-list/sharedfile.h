typedef struct node
{
	int data;
	struct node *next;
}NODE,*PNODE;

class SinglyLL
{
private:
	PNODE head;
public:
	SinglyLL();
	~SinglyLL();
	virtual void insertFirst(int);
	virtual void insertLast(int);
	virtual void insertAtPosition(int,int);
	virtual void deleteFirst();
	virtual void deleteLast();
	virtual void deleteAtPosition(int);
	virtual int count();
	virtual void display();
};