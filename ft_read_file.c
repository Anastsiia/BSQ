/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctifany <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 16:36:59 by ctifany           #+#    #+#             */
/*   Updated: 2021/02/10 23:00:44 by ctifany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_read_file(int argc, char *map_file)
{
	int res;
	int **matrix;

	if (argc == 1)
		ft_get_map_stdin();
	else
		ft_get_map(map_file);
	if (ft_verif_map() == 0)
		return (0);
	matrix = ft_map_to_int();
	res = ft_largest_square(map[0].row, map[0].col, matrix);
	map[0].pos_x = map[0].row;
	map[0].pos_y = map[0].col;
	ft_search_square(res, &map[0].pos_x, &map[0].pos_y, matrix);
	ft_inverse_array(res, map[0].row, map[0].col, matrix);
	write(1, "\n", 1);
	return (1);
}

int		ft_get_map(char *map_file)
{
	int		fd;
	char	first_l[64];
	int		i;
	int		a;

	map[0].map = (char*)malloc(sizeof(char) * ft_size_map(map_file));
	a = 0;
	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		return (0);
	while (read(fd, &first_l[a], 1) && first_l[a] != '\n')
		a++;
	first_l[a] = '\0';
	i = 0;
	while (read(fd, &map[0].map[i], 1) && map[0].map[i] != '\0')
		i++;
	map[0].map[i] = '\0';
	close(fd);
	ft_get_info_map(first_l, a);
	if (a < 4)
		return (0);
	map[0].col = (((ft_size_map(map_file) - 1) / map[0].row) - 1);
	return (1);
}

void	ft_get_map_stdin(void)
{
	int		i;
	int		j;
	char	first_l[64];

	map[0].map = (char*)malloc(sizeof(char) * 4096);
	i = 0;
	while (read(0, &first_l[i], 1) && first_l[i] != '\n')
		i++;
	first_l[i] = '\0';
	ft_get_info_map(first_l, i);
	j = 0;
	while (read(0, &map[0].map[j], 1) && map[0].map[j] != '\0')
		j++;
	map[0].map[j] = '\0';
	if (i > 3)
		map[0].col = ((j / map[0].row) - 1);
}

void	ft_get_info_map(char *buff, int len)
{
	int i;
	int l;

	i = 0;
	l = 0;
	map[0].full = buff[len - 1];
	map[0].obstacle = buff[len - 2];
	map[0].empty = buff[len - 3];
	while (i < (len - 3))
	{
		map[0].nb_line[l] = buff[i];
		i++;
		l++;
	}
	map[0].nb_line[l] = '\0';
	map[0].row = ft_atoi(map[0].nb_line);
}

int		**ft_map_to_int(void)
{
	int **matrix;
	int i;
	int x;
	int y;

	i = 0;
	y = 0;
	matrix = ft_allocate_mem_2d(map[0].row, map[0].col);
	while (map[0].map[i] != '\0')
	{
		x = 0;
		while (map[0].map[i] != '\n')
		{
			if (map[0].map[i] == map[0].empty)
				matrix[y][x] = 1;
			else if (map[0].map[i] == map[0].obstacle)
				matrix[y][x] = 0;
			i++;
			x++;
		}
		y++;
		i++;
	}
	return (matrix);
}
