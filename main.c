#include "header.h"

int	main(void)
{
	void	****ptr;

	ptr = my_malloc(10);
	my_free(ptr);
	my_free(ptr);
	ptr = my_malloc(10);
	ptr = my_malloc(10);
	ptr = my_malloc(10);
	ptr = my_malloc(10);
	ptr = my_malloc(10);
	ptr = my_malloc(10);
	ptr = my_malloc(10);
	ptr = my_malloc(10);
	ptr = my_malloc(10);
	ptr = my_malloc(10);
	ptr = my_malloc(10);
	ptr = my_malloc(10);
	ptr = my_malloc(10);
	ptr = my_malloc(10);
	ptr = my_malloc(10);
	ptr = my_malloc(10);
	ptr = my_malloc(10);
	ptr = my_malloc(10);
	ptr = my_malloc(10);
	ptr = my_malloc(10);
	ptr = my_malloc(10);
	ptr = my_malloc(10);
	ptr = my_malloc(10);
	my_free_all();
	ptr = my_malloc(10);
	ptr = my_malloc(10);
	ptr = my_malloc(10);
	ptr = my_malloc(10);
	ptr = my_malloc(10);
	ptr = my_malloc(10);
	ptr = my_malloc(10);
	ptr = my_malloc(10);
	ptr = my_malloc(10);
	ptr = my_malloc(10);
	ptr = my_malloc(10);
	ptr = my_malloc(10);
	ptr = my_malloc(10);
	ptr = my_malloc(10);
	ptr = my_malloc(10);
	system("leaks a.out");
}
