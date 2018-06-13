#include<stdio.h>
#include<stdlib.h>
#include<dlfcn.h>
#include"sharedfile.h"

int main(int argc, char const *argv[])
{

	///////////////////////////For Doubly Link list Shared Library//////////////////////////
	void* sobj = NULL;
	DoublyLL *ptr = NULL;
	DoublyLL* (*fp1)() = NULL;
	void (*fp2)(DoublyLL*) = NULL;
	sobj = dlopen("/mnt/f/C Project/Shared-library-development/Data-Structures/Doubly-link-list/DoublyLLClass.so",RTLD_LAZY);
	if(!sobj)
	{
		fprintf(stderr, "%s\n", dlerror());
		exit(1);
	}
	else
	{
		fp1 = (DoublyLL*(*)())dlsym(sobj,"create");
		fp2 = (void(*)(DoublyLL*))dlsym(sobj,"destroy");

		ptr =fp1();

		ptr->insertFirst(10);
		ptr->insertLast(50);
		ptr->display();
		ptr->insertAtPosition(20,2);
		ptr->insertAtPosition(30,3);
		ptr->insertAtPosition(40,4);
		ptr->display();
		ptr->deleteFirst();
		ptr->deleteLast();
		ptr->display();
		ptr->deleteAtPosition(2);
		ptr->display();
		int cnt = ptr->count();
		printf("Total Element: %d",cnt);

		fp2(ptr);
		dlclose(sobj);
	}
	/////////////////////////////////////////////////////////////////////
	return 0;
}