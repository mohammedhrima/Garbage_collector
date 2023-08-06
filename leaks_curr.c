#include "header.h"

// first thing to put in mind
// memory leaks means allocating
// space in heap and losing its address

// static varibale are stored in data segment in memory
// data segment is the last space that get freed in memory when main exit

// when main is exiting and find that there is a static variable pointing
// on a memory on the heap, its frees it

t_mal	*head(void)
{
	static t_mal	curr;

	if (curr.ptr == NULL)
	{
		curr.len = 10;
		curr.ptr = malloc(curr.len * sizeof(uintptr_t));
	}
	return (&curr);
}

// in case you freed a pointer before
// I use the same pointer to save the new allocate space
int	get_available_pos(void)
{
	t_mal	*curr;
	int		pos;

	pos = 0;
	curr = head();
	while (pos < curr->pos)
	{
		if (curr->ptr[pos] == 0)
			break ;
		pos++;
	}
	return (pos);
}

void	*my_malloc(size_t size)
{
	t_mal		*curr;
	void		*new;
	uintptr_t	*ptr;
	int			pos;

	new = malloc(size);
	ft_memory_set(new, 0, size);
	pos = get_available_pos();
	curr = head();
	curr->ptr[pos] = (uintptr_t) new;
	if (pos == curr->pos)
		curr->pos++;
	if (curr->pos + 2 >= curr->len)
	{
		ptr = malloc(curr->len * 2 * sizeof(uintptr_t));
		ft_memory_copy(ptr, curr->ptr, curr->len * sizeof(uintptr_t));
		free(curr->ptr);
		curr->ptr = ptr;
		curr->len *= 2;
	}
	return (new);
}

void	my_free(void *address)
{
	t_mal	*curr;
	int		i;

	curr = head();
	i = 0;
	while (i < curr->pos && curr->ptr[i] != (uintptr_t)address)
		i++;
	if (curr->ptr[i] == (uintptr_t)address)
	{
		free((void *)curr->ptr[i]);
		curr->ptr[i] = 0;
	}
}

void	my_free_all(void)
{
	t_mal	*curr;
	int		i;

	curr = head();
	i = 0;
	while (i < curr->pos)
	{
		free((void *)curr->ptr[i]);
		curr->ptr[i] = 0;
		i++;
	}
}
