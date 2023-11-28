/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhrima <mhrima@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 21:02:32 by mhrima            #+#    #+#             */
/*   Updated: 2023/11/28 21:05:29 by mhrima           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void func()
{
	char *ptr;

	ptr = allocate(100);
	ptr = allocate(100);
	ptr = allocate(100);
	ptr = allocate(100);
	ptr = allocate(100);
	ptr = allocate(100);
	ptr = allocate(100);
	ptr = allocate(100);
}

int main(void)
{
	func();
	free_memory();
}
