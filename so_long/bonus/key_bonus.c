/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-ouaz <yel-ouaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 10:12:41 by yel-ouaz          #+#    #+#             */
/*   Updated: 2024/05/29 16:39:49 by yel-ouaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	draw_map(char **map, t_data *d)
{
	int	i;
	int	j;
	int e;

	e = 0;
	i = 0;
	mlx_clear_window(d->con,d->win);
	mlx_put_image_to_window(d->con, d->win, d->bg, 0, 0);
	while (i < d->map_size)
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '1')
				mlx_put_image_to_window(d->con, d->win, d->w, j * 60, i * 60);
			if (map[i][j] == 'E' && d->coins > 0)
				mlx_put_image_to_window(d->con, d->win, d->e, j * 60, i * 60);
			if (map[i][j] == 'E' && d->coins == 0)
				mlx_put_image_to_window(d->con, d->win, d->e1, j * 60, i * 60);
			if (map[i][j] == 'C')
				mlx_put_image_to_window(d->con, d->win, d->c, j * 60, i * 60);
			if (map[i][j] == 'G')
			{
				if (((d->enemies)[e]).dir == 1)
					mlx_put_image_to_window(d->con, d->win, d->enr, j * 60, i * 60);
				else if (((d->enemies)[e]).dir == -1)
					mlx_put_image_to_window(d->con, d->win, d->enl, j * 60, i * 60);
				e++;
			}
			j++;
		}
		i++;
	}
	put_moves(d);
}

void put_moves(t_data *d)
{
	char *s;

	s = ft_itoa(d->moves);
	mlx_string_put(d->con, d->win, 0,0,0xff0000,s);
	free(s);
	mlx_put_image_to_window(d->con, d->win, d->last, d->p_x, d->p_y);
}

int	key(int keycode, t_data *data)
{
	if (keycode == ESC)
	{
		ft_putstr("ESC key pressed\n");
		system("leaks so_long_bonus");
		ft_exit (data);
	}
	right_left(keycode, data);
	up_down(keycode, data);
	coin_exit(data);
	draw_map(data->map,data);
	return 1;
}

void dead(t_data *data)
{
	int x;
	int y;
	int	i;
	
	i = 20000000;
	x = (data->map_w * 30) - 90 + 80;
	y = (data->map_size * 30);
	while(y > -100)
	{
		mlx_clear_window(data->con,data->win);
		mlx_put_image_to_window(data->con,data->win,data->game_o,(data->map_w * 30) - 90, (data->map_size * 30) - 90);
		mlx_put_image_to_window(data->con,data->win,data->ghost,x,y);
		mlx_do_sync(data->con);
		while(i)
			i--;
		i =200000000;
		y -=10;
	}
}

void coin_exit(t_data *data)
{
	if (data->map[data->p_y / 60][data->p_x / 60] == 'C')
	{
		data->coins--;
		data->map[data->p_y / 60 ][data->p_x / 60] = '0';
	}
	if (data->map[data->p_y / 60][data->p_x / 60] == 'E' && data->coins == 0)
	{
		ft_putstr("You Won!!!\n");
		system("leaks so_long_bonus");
		ft_exit(data);
	}
	if (data->map[data->p_y / 60][data->p_x / 60] == 'G')
	{
		dead(data);
		system("leaks so_long_bonus");
		ft_exit(data);
	}
}

void up_down(int keycode, t_data * d)
{
	if (keycode == UP && d->map[(d->p_y / 60) - 1][d->p_x / 60] != '1' )
	{
		ft_animate_u_d(keycode, d);
		draw_map(d->map, d);
		ft_animate_u_d(keycode, d);
		draw_map(d->map, d);
		ft_animate_u_d(keycode, d);
		draw_map(d->map, d);
		d->moves++;
		d->last = d->p;
	}
	if (keycode == DOWN && d->map[(d->p_y / 60) + 1][d->p_x / 60] != '1')
	{
		ft_animate_u_d(keycode, d);
		draw_map(d->map, d);
		ft_animate_u_d(keycode, d);
		draw_map(d->map, d);
		ft_animate_u_d(keycode, d);
		draw_map(d->map, d);
		d->moves++;
		d->last = d->p;
	}
}

void right_left(int k,t_data *d)
{
	if (k == RIGHT && d->map[d->p_y / 60][(d->p_x / 60) + 1] != '1')
	{
		ft_animate_r_l(k, d);
		draw_map(d->map, d);
		ft_animate_r_l(k, d);
		draw_map(d->map, d);
		ft_animate_r_l(k, d);
		draw_map(d->map, d);
		d->moves++;
		d->last = d->r;
	}
	if (k == LEFT && d->map[d->p_y / 60][(d->p_x / 60) - 1] != '1')
	{
		ft_animate_r_l(k, d);
		draw_map(d->map, d);
		ft_animate_r_l(k, d);
		draw_map(d->map, d);
		ft_animate_r_l(k, d);
		draw_map(d->map, d);
		d->moves++;
		d->last = d->l;
	}
}

void ft_animate_r_l(int k ,t_data *d)
{
	if (k == RIGHT)
	{
		mlx_put_image_to_window(d->con, d->win, d->pad, d->p_x, d->p_y);
		d->p_x+=10;
        mlx_put_image_to_window(d->con, d->win, d->r1, d->p_x, d->p_y);
        mlx_do_sync(d->con);
		mlx_put_image_to_window(d->con, d->win,d->pad ,d->p_x, d->p_y);
		d->p_x+=10;
        mlx_put_image_to_window(d->con, d->win, d->r2, d->p_x, d->p_y);
        mlx_do_sync(d->con);
	}
	if (k == LEFT)
	{
		mlx_put_image_to_window(d->con, d->win, d->pad, d->p_x, d->p_y);
		d->p_x-=10;
        mlx_put_image_to_window(d->con, d->win, d->l1, d->p_x, d->p_y);
        mlx_do_sync(d->con);
		mlx_put_image_to_window(d->con, d->win,d->pad ,d->p_x, d->p_y);
		d->p_x-=10;
        mlx_put_image_to_window(d->con, d->win, d->l2, d->p_x, d->p_y);
        mlx_do_sync(d->con);
	}
}

void ft_animate_u_d(int k ,t_data *data)
{
	int m;

	m = 10;
	if (k == UP)
		m = -10;
	mlx_put_image_to_window(data->con, data->win, data->pad, data->p_x, data->p_y);
	data->p_y += m;
	mlx_put_image_to_window(data->con, data->win, data->p, data->p_x, data->p_y);
	mlx_do_sync(data->con);
	mlx_put_image_to_window(data->con, data->win,data->pad ,data->p_x, data->p_y);
	data->p_y += m;
	mlx_put_image_to_window(data->con, data->win, data->p, data->p_x, data->p_y);
	mlx_do_sync(data->con);
}

int	ft_destroy(t_data *data)
{
	ft_putstr("Window cross clicked\n");
	system("leaks so_long_bonus");
	ft_exit(data);
	return (1);
}