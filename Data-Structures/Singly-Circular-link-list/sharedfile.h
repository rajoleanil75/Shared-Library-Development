typedef struct node
{
	int data;
	struct node *next;
}NODE, *SCNODE;

class SinglyCLL
{
private:
	SCNODE head;
public:
	SinglyCLL();
	~SinglyCLL();
	virtual void insertFirst(int );
	virtual void insertLast(int );
	virtual void insertAtPosition(int ,int );
	virtual void deleteFirst();
	virtual void deleteLast();
	virtual void deleteAtPosition(int );
	virtual void display();
	virtual int count();
};