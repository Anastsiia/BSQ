/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctifany <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 17:52:28 by ctifany           #+#    #+#             */
/*   Updated: 2021/02/10 22:56:27 by ctifany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_file_size(char *map_file)
{
	int		fd;
	char	buff;
	int		size;

	fd = open(map_file, O_RDONLY);
	size = 0;
	if (fd >= 0)
	{
		while (read(fd, &buff, 1))
			size++;
		close(fd);
		return (size);
	}
	else
	{
		return (0);
	}
}

int	ft_size_1stline(char *map_file)
{
	int		fd;
	char	buff;
	int		size;

	fd = open(map_file, O_RDONLY);
	size = 0;
	if (fd >= 0)
	{
		while (read(fd, &buff, 1) && buff != '\n')
			size++;
		close(fd);
		if (size < 4)
			return (0);
		return (size);
	}
	else
	{
		return (0);
	}
}

int	ft_size_map(char *map_file)
{
	int size;

	size = 0;
	size = ft_file_size(map_file) - ft_size_1stline(map_file);
	return (size);
}

int	ft_size_stdin(void)
{
	char	buff;
	int		size;

	size = 0;
	while (read(0, &buff, 1))
		size++;
	return (size);
}

int	ft_size_stdin_1stline(void)
{
	char	buff;
	int		size;

	size = 0;
	read(0, &buff, 1);
	while (read(0, &buff, 1) && buff != '\n')
	{
		size++;
	}
	return (size);
}
