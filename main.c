#include "my_malloc_free.h"

void func(void)
{
	char **x = my_malloc(500);
	//x = NULL;
	char *str = my_malloc(1000);
	int i = 0;
	while (i < 20)
		str[i++] = 'c';
	str = (char *)my_malloc(1000);
	i = 0;
	while (i < 20)
		str[i++] = 'c';
	str = (char *)my_malloc(1000);
	i = 0;
	while (i < 20)
		str[i++] = 'c';
	str = (char *)my_malloc(1000);
	while (i < 20)
		str[i++] = 'c';
	str = (char *)my_malloc(1000);
}

/*
	to check the program:
		run make
	
	my_malloc: is like malloc you give it the size you want to allocate
	my_free: is like default free
	my_free_all: function that free all not freed allocated spaces
*/

int main()
{
	func();
	//system("leaks a.out");
	//while(1);
	return (0);
}
