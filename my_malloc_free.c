#include "my_malloc_free.h"

typedef struct s_mal
{
	unsigned long address;
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

t_mal *new_var(unsigned long address)
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
	static t_mal *list;
	if (!list)
		list = new_var(0);
	return (&list);
}

void* my_malloc(size_t size)
{
	void *ptr;

	ptr = ft_calloc(1, size);
	add_back(my_allocated_list(), new_var((unsigned long)ptr));
	return (ptr);
}

void my_free(void *ptr)
{
	t_mal *var;
	unsigned long address;

	address = (unsigned long)ptr;
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

void my_free_all(void)
{
	t_mal *var;
	void *ptr;

	var = *my_allocated_list();
	while (var)
	{
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