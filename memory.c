/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhrima <mhrima@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 21:02:29 by mhrima            #+#    #+#             */
/*   Updated: 2023/12/03 01:32:53 by mhrima           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

List **head()
{
    static List *curr;

    if (curr == NULL)
        curr = calloc(1, sizeof(List));
    return &curr;
}

void *allocate(size_t size)
{
    void *ptr;
    List *curr;

    ptr = calloc(size, 1);
    curr = calloc(1, sizeof(List));
    curr->size = size;
    curr->ptr = (uintptr_t)ptr;
    curr->next = *head();
    *head() = curr;
    return ptr;
}

void free_memory()
{
    List *node;
    List *tmp;

    node = *head();
    while (node)
    {
        tmp = node->next;
        free((void*)node->ptr);
        free(node);
        node = tmp;
    }
}

List *free_node(List *node, uintptr_t ptr)
{
    List *tmp;

    if (node && node->ptr == ptr)
    {
        tmp = node->next;
        free((void *)node->ptr);
        free(node);
        return tmp;
    }
    if (node)
        node->next = free_node(node->next, ptr);
    return node;
}

void free_address(void *ptr)
{
    *head() = free_node(*head(), (uintptr_t)ptr);
}
