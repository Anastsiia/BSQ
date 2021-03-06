/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctifany <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 19:27:50 by ctifany           #+#    #+#             */
/*   Updated: 2021/02/10 19:29:06 by ctifany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	**ft_allocate_mem_2d(int n, int m)
{
	int i;
	int **arr;

	i = 0;
	arr = (int**)malloc(n * sizeof(int*));
	while (i < n)
	{
		arr[i] = (int*)malloc(m * sizeof(int));
		i++;
	}
	return (arr);
}
