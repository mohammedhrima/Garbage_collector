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
	
	my_malloc(site_t size_to_allocate);
	my_free(void *ptr, int free_all)

	my_malloc: is like malloc you give it the size you want to allocate 
	
	my_free:   is like default free but has a second argument,
			   in case you want to free all allocated space once set free_all to 1 else set it to 0
			   		example:
						char ***ptr = my_malloc(1000);
						my_free(ptr, 0)
*/

int main()
{
	func();
	//system("leaks a.out");
	//while(1);
	return (0);
}