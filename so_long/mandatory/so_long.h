/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-ouaz <yel-ouaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:48:28 by yel-ouaz          #+#    #+#             */
/*   Updated: 2024/05/27 13:49:03 by yel-ouaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "get_next_line.h"


typedef struct s_data
{
	char	**map;
	int		map_size;
	int		map_w;
	void	*con;
	void	*win;
	void	*w;
	void	*bg;
	void	*p;
	void	*c;
	void	*e1;
	void	*e2;
	int		p_x;
	int		p_y;
	int		coins;
	int		moves;
}	t_data;

# define DOWN 125
# define UP   126
# define LEFT 123
# define RIGHT 124

# define W 13
# define A 0
# define S 1
# define D 2

# define ESC 53

char	*ft_strchr(const char *s, int c);
int		ft_strcmp(char *s1, char *s2);
void	ft_putstr(char *s);
void	ft_error(char **map, int map_size, int flag, char *err_mess);
int		length(char *s, int *pce, int flag);
void	check_map(char **map, int line_count);
void	count_lines(char *file, int *line_count);
int		check_input(int argc, char *file);
void	get_map(char *file, int map_size, t_data *data);
void	initialize_struct(t_data *d, int map_size, char **map);
void	check_struct(t_data *d, int map_size, char **map);
void	draw_map(char **map, t_data *data);
int		key(int keycode, t_data *data);
void	ft_exit(t_data *data);
void	check_path(char **map, t_data *data);
void	check_flood_fill(char **dup_map, t_data *data);
void	flood_fill(char **map, t_data *data, int x, int y);
void	ft_move(int keycode, t_data *data, char **map);
int		ft_destroy(t_data *data);
void	ft_zero(t_data *data);
void	ft_free(char **map, int map_size);
void	ft_putchar(char c);
void	ft_putnbr(int a);

#endif
/*
    TASKS
    flood fill DONE
    destroy images in a way that no mlx destroy is given a null  DONE
    split the up down right left movements into another func norm DONE
	check the code thoroughly
*/