#ifndef LC_HEADER_H
# define LC_HEADER_H

# include <stdint.h>
# include <stdlib.h>

typedef struct s_mal
{
	int			pos;
	uintptr_t	*ptr;
	int			len;
}				t_mal;

void			*my_malloc(size_t size);
void			my_free(void *address);
void			my_free_all(void);
void			ft_memory_set(void *pointer, int c, size_t len);
void			*ft_memory_copy(void *destination, void *source, size_t len);

#endif