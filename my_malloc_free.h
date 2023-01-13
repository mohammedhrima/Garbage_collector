/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_malloc_free.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhrima <mhrima@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 19:27:00 by mhrima            #+#    #+#             */
/*   Updated: 2023/01/13 19:46:53 by mhrima           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_MALLOC_H
#define MY_MALLOC_H

#include "unistd.h"
#include "limits.h"
#include "stdlib.h"

typedef struct s_mal
{
	unsigned long address;
	struct s_mal *next;
	int is_free;
} t_mal;

t_mal *new_var(unsigned long address);
t_mal *last_var(t_mal *lst);
void add_back(t_mal **var, t_mal *new_var);
t_mal **my_allocated_list(void);
void* my_malloc(size_t size);
void my_free(void *ptr, int free_all);

#endif