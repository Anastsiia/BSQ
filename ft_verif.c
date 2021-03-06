/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctifany <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 18:01:33 by ctifany           #+#    #+#             */
/*   Updated: 2021/02/10 21:41:24 by ctifany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_verif_map(void)
{
	if (ft_check_min() == 0 || ft_check_breakline() == 0
			|| ft_check_chars() == 0)
	{
		return (0);
	}
	else
		return (1);
}

int	ft_check_min(void)
{
	if (map[0].col < 1 || map[0].row < 1)
		return (0);
	return (1);
}

int	ft_check_breakline(void)
{
	int	i;
	int	qty;

	i = 0;
	qty = 0;
	while (map[0].map[i] != '\0')
	{
		if (map[0].map[i] == '\n')
			qty++;
		i++;
	}
	if (qty == map[0].row)
		return (1);
	else
		return (0);
}

int	ft_check_chars(void)
{
	int	i;

	i = 0;
	while (map[0].map[i] != '\0')
	{
		if (map[0].map[i] == map[0].full)
			return (0);
		if (!(map[0].map[i] == map[0].empty || map[0].map[i] == map[0].obstacle
					|| map[0].map[i] == '\n'))
			return (0);
		i++;
	}
	if (i % (map[0].col + 1) != 0)
		return (0);
	return (1);
}
