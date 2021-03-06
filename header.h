/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctifany <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 20:13:12 by ctifany           #+#    #+#             */
/*   Updated: 2021/02/10 20:19:20 by ctifany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>

struct	s_first_line
{
	char	nb_line[10];
	char	empty;
	char	obstacle;
	char	full;
	int		row;
	int		col;
	char	*map;
	int		pos_x;
	int		pos_y;
};
struct s_first_line map[1];
void	ft_putchar(char c);
void	ft_putstr(char *str);
int		ft_strlen(char *str);
int		ft_atoi(char *str);
void	ft_msg_error(void);
int		ft_read_file(int argc, char *map_file);
int		ft_get_map(char *map_file);
void	ft_get_map_stdin(void);
void	ft_get_info_map(char *buff, int len);
int		**ft_map_to_int(void);
int		ft_largest_square(int nb_x, int nb_y, int **m);
int		ft_min_v(char a, char b, char c);
void	ft_search_square(int res, int *nb_x, int *nb_y, int **matrix);
void	ft_inverse_array(int res, int row, int col, int **matrix);
void	ft_inverse_array_aux(int res, int col, int **matrix, int i);
int		**ft_allocate_mem_2d(int n, int m);
int		ft_verif_map(void);
int		ft_check_min(void);
int		ft_check_breakline(void);
int		ft_check_chars(void);
int		ft_file_size(char *map_file);
int		ft_size_1stline(char *map_file);
int		ft_size_map(char *map_file);
int		ft_size_stdin(void);
int		ft_size_stdin_1stline(void);
int		ft_check_row_size(void);
int		ft_check_row_qty(void);
int		**ft_copy_matrix(int nb_x, int nb_y, int matrix[][nb_y]);

#endif
