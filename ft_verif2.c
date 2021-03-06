/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctifany <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 18:05:36 by ctifany           #+#    #+#             */
/*   Updated: 2021/02/10 18:10:39 by ctifany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_check_row_size(void)
{
	int	i;

	i = 0;
	while (map[0].map[i] != '\0')
		i++;
	if ((i - map[0].row) != (map[0].row * map[0].col))
		return (0);
	return (1);
}

int	ft_check_row_qty(void)
{
	int	i;
	int	row_count;

	i = 0;
	row_count = 0;
	while (map[0].map)
	{
		if (map[0].map)
			row_count++;
		i++;
	}
	if (row_count != map[0].row)
		return (0);
	else
		return (1);
}
