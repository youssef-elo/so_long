/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-ouaz <yel-ouaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 10:12:49 by yel-ouaz          #+#    #+#             */
/*   Updated: 2024/06/07 17:43:34 by yel-ouaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "mlx.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "get_next_line_bonus.h"

# define DOWN 125
# define UP   126
# define LEFT 123
# define RIGHT 124

# define W 13
# define A 0
# define S 1
# define D 2

# define ESC 53

typedef struct s_enemy
{
	int	x;
	int	y;
	int	dir;
}	t_enemy;

typedef struct s_data
{
	char	**map;
	int		map_size;
	int		map_w;
	void	*con;
	void	*win;
	void	*w;
	void	*bg;
	void	*r;
	void	*r1;
	void	*r2;
	void	*l;
	void	*l1;
	void	*l2;
	void	*p;
	void	*e;
	void	*e1;
	void	*c;
	void	*pad;
	void	*last;
	void	*enr;
	void	*enl;
	void	*game_o;
	void	*ghost;
	t_enemy	*opp;
	int		p_x;
	int		p_y;
	int		coins;
	int		moves;
	int		num_enemies;
	int		cooldown;
}	t_data;

int		check_input(int argc, char *file);
void	count_lines(int *line_count, int fd);
void	get_map(char *file, int map_size, t_data *data);
void	check_map(char **map, int line_count);
int		length(char *s, int *pce, int flag);
void	ft_free(char **map, int map_size);
void	ft_error(char **map, int map_size, int flag);
void	check_path(char **map, t_data *data);
void	flood_fill(char **map, t_data *data, int x, int y);
void	check_flood_fill(char **dup_map, t_data *data);
void	ft_zero(t_data *data);
char	*ft_strchr(char *s, int c);
int		ft_strcmp(char *s1, char *s2);
void	ft_putstr(char *s);
void	ft_putchar(char c);
void	ft_putnbr(int a);
void	initialize_struct(t_data *d, int map_size, char **map);
void	draw_map(t_data *d);
void	right_left(int keycode, t_data *data);
int		key(int keycode, t_data *data);
void	check_struct(t_data *d, int map_size, char **map);
void	ft_animate_r_l(int k, t_data *data);
int		ft_counter(int n);
char	*ft_itoa(int n);
void	up_down(int keycode, t_data *data);
void	ft_animate_u_d(int k, t_data *data);
void	coin_exit(t_data *data);
void	my_destroy_image(t_data *data, void *img);
void	ft_exit(t_data *data);
int		ft_destroy(t_data *data);
int		move_enemy(t_data *d);
void	initialize_enemies(t_data *d);
void	get_images(t_data *d);
void	put_map(t_data *d, int i, int j, int e);
void	put_enemy(t_data *d, int *e, int j, int i);
void	dead(t_data *data);

#endif