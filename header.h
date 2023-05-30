#ifndef HEADER_H
# define HEADER_H

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
void			ft_memset(void *pointer, int c, size_t len);
void			*ft_memcpy(void *destination, void *source, size_t len);

#endif