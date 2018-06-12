#include<stdio.h>
#include<stdlib.h>
#include<dlfcn.h>
#include"sharedfile.h"

int main(int argc, char const *argv[])
{
	void *p = NULL;
	Hello *ptr = NULL;
	Hello* (*fp1)() = NULL;
	void (*fp2)(Hello *) = NULL;

	p = dlopen("/mnt/f/C Project/Shared-library-development/HelloWord/MyClass.so",RTLD_LAZY);
	if(!p)
	{
		fprintf(stderr, "%s", dlerror());
		printf("\nUnable to open MyClass.so library...!!!");
		exit(1);
	}
	else
	{
		fp1 = (Hello*(*)()) dlsym(p,"create");
		fp2 = (void(*)(Hello *)) dlsym(p,"destroy");

		ptr = fp1();
		ptr->accept(1);
		ptr->display();
		fp2(ptr);
		dlclose(p);
	}
	return 0;
}