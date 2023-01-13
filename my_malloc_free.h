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

void* my_malloc(size_t size);
void my_free(void *ptr, int free_all);

#endif
