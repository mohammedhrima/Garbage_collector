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

List *begin()
{
    static List *head;

    if (head == NULL)
        head = calloc(1, sizeof(List));
    return head;
}

List *end()
{
    static List *curr;

    if (curr == NULL)
        curr = begin();
    else
        curr = curr->next;
    return curr;
}

void *allocate(size_t size)
{
    void *ptr;
    List *curr;

    ptr = calloc(size, 1);
    curr = end();
    curr->ptr = ptr;
    curr->next = calloc(1, sizeof(List));
    return ptr;
}

void free_memory()
{
    List *node;
    List *tmp;

    node = begin();
    while (node)
    {
        tmp = node->next;
        free(node->ptr);
        free(node);
        node = tmp;
    }
}
