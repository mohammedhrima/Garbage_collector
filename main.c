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
	int *ptr;

	ptr = allocate(10);
	ptr = allocate(20);
	ptr = allocate(30);
	free_address(ptr);
	ptr = allocate(40);
	ptr = allocate(50);
	ptr = allocate(60);
	ptr = allocate(70);
	ptr = allocate(80);
}

int main(void)
{
	func();
	free_memory();
}
