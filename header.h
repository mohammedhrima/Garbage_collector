/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhrima <mhrima@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 20:49:07 by mhrima            #+#    #+#             */
/*   Updated: 2023/11/28 20:49:45 by mhrima           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LC_HEADER_H
#define LC_HEADER_H

#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef struct List_
{
	size_t size;
	uintptr_t ptr;
	struct List_ *next;
} List;

void *allocate(size_t size);
void free_memory();
void free_address(void *ptr);
List **head();

#endif