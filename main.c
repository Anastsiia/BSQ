/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctifany <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 18:18:20 by ctifany           #+#    #+#             */
/*   Updated: 2021/02/10 19:27:16 by ctifany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	main(int argc, char **argv)
{
	int i;

	i = 1;
	if (argc == 1 && ft_read_file(argc, argv[0]) == 0)
	{
		ft_msg_error();
		return (0);
	}
	else if (argc > 1)
	{
		while (i < argc)
		{
			if (ft_read_file(argc, argv[i]) == 0)
			{
				ft_msg_error();
			}
			i++;
		}
	}
	return (0);
}
