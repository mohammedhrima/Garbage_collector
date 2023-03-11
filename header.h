/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_malloc_free.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhrima <mhrima@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 19:27:00 by mhrima            #+#    #+#             */
/*   Updated: 2023/01/13 20:34:06 by mhrima           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "limits.h"
# include "unistd.h"
# include <stdlib.h>

typedef struct s_mal
{
	int				index;
	uintptr_t		ptr;
	struct s_mal	*next;
}					t_mal;

uintptr_t			my_malloc(size_t size);
void				my_free(uintptr_t address);
void				my_free_all(void);

#endif