#include "my_malloc_free.h"

typedef struct s_mal
{
	uintptr_t address;
	struct s_mal *next;
	int is_free;
} t_mal;

void *ft_calloc(size_t count, size_t size)
{
	void *arr;
	unsigned char *ptr;
	size_t i;

	if (count && size > SIZE_MAX / count)
		return (NULL);
	arr = (void *)malloc(count * size);
	if (!arr)
		return (NULL);
	i = 0;
	ptr = (unsigned char *)arr;
	while (i < count * size)
	{
		ptr[i] = 0;
		i++;
	}
	return (arr);
}

//new_var function to allocate t_mal varibale and return it
t_mal *new_var(uintptr_t address)
{
	t_mal *var;

	var = ft_calloc(1, sizeof(t_mal));
	var->address = address;
	var->next = NULL;
	var->is_free = 0;
	return (var);
}

t_mal *last_var(t_mal *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

// add_back function look for the last element in the node and add the new node to it
void add_back(t_mal **var, t_mal *new_var)
{
	t_mal *ptr;

	if (!var)
		return;
	ptr = last_var(*var);
	if (!ptr)
		*var = new_var;
	else
		ptr->next = new_var;
}

// to be used as global varibales
t_mal **my_allocated_list(void)
{
	static t_mal *list; // declare the head of the linked list , when declaring pointer as static it automatically takes NULL as value
	if (!list) // first time I call "my_allocate_list", 'list' varibale will be intialized to null
		list = new_var(0);//that's why I set it here
	return (&list); // then I return it's pointer
}

void *my_malloc(size_t size)
{
	void *ptr;
	// Allocate the needed size and feed it with 0
	ptr = ft_calloc(1, size);
	// then add it to end of the linked list
	//"my_allocated_list()"  function is used like a global variable
	//"new_var" is a function that allocate t_mal data type in the heap and return its value
	add_back(my_allocated_list(), new_var((uintptr_t)ptr));
	return (ptr);
}

// my_free_all loop in the linked list check if the address savd in node is freed
// if not it frees it
// it work's like ft_lstmap in Libft
void my_free_all(void)
{
	t_mal *var;
	void *ptr;

	var = *my_allocated_list();
	while (var) // keep tracking the element of nodes and free them it they aren't freed
	{			// then set them as freed
		if (!var->is_free)
		{
			free((void *)(var->address));
			ptr = (void *)(var->address);
			ptr = NULL;
			var->is_free = 1;
			return;
		}
		var = var->next;
	}
}

// is like my_free_all but it only free the selected pointer
void my_free(void *ptr)
{
	t_mal *var;
	uintptr_t address;

	address = (uintptr_t)ptr;
	var = *my_allocated_list();
	while (var)
	{
		if (var->address == address && !var->is_free)
		{
			free((void *)(var->address));
			ptr = (void *)(var->address);
			ptr = NULL;
			var->is_free = 1;
			return;
		}
		var = var->next;
	}
}
