/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-ouaz <yel-ouaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 10:12:41 by yel-ouaz          #+#    #+#             */
/*   Updated: 2024/07/17 22:50:26 by yel-ouaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	draw_map(t_data *d)
{
	char	*s;

	mlx_clear_window(d->con, d->win);
	mlx_put_image_to_window(d->con, d->win, d->bg, 0, 0);
	put_map(d, 0, 0, 0);
	s = ft_itoa(d->moves);
	if (!s)
	{
		write(2, "Error\nmalloc fail.\n", 19);
		ft_exit(d);
	}
	mlx_string_put(d->con, d->win, 0, 0, 0xff0000, s);
	free(s);
	mlx_put_image_to_window(d->con, d->win, d->last, d->p_x, d->p_y);
}

void	put_map(t_data *d, int i, int j, int e)
{
	while (i < d->map_size)
	{
		j = 0;
		while (d->map[i][j])
		{
			if (d->map[i][j] == '1')
				mlx_put_image_to_window(d->con, d->win, d->w, j * 60, i * 60);
			if (d->map[i][j] == 'E' && d->coins > 0)
				mlx_put_image_to_window(d->con, d->win, d->e, j * 60, i * 60);
			if (d->map[i][j] == 'E' && d->coins == 0)
				mlx_put_image_to_window(d->con, d->win, d->e1, j * 60, i * 60);
			if (d->map[i][j] == 'C')
				mlx_put_image_to_window(d->con, d->win, d->c, j * 60, i * 60);
			if (d->map[i][j] == 'G')
			{
				put_enemy(d, &e, j, i);
			}
			j++;
		}
		i++;
	}
}

void	put_enemy(t_data *d, int *e, int j, int i)
{
	if (((d->opp)[*e]).dir == 1)
		mlx_put_image_to_window(d->con, d->win, d->enr,
			j * 60, i * 60);
	else if (((d->opp)[*e]).dir == -1)
		mlx_put_image_to_window(d->con, d->win, d->enl,
			j * 60, i * 60);
	(*e)++;
}

int	key(int keycode, t_data *data)
{
	int	moves_check;

	moves_check = data->moves;
	if (keycode == ESC)
	{
		ft_putstr("ESC key pressed.\n");
		ft_exit(data);
	}
	if (keycode == LEFT)
		data->last = data->l;
	if (keycode == RIGHT)
		data->last = data->r;
	if (keycode == UP || keycode == DOWN)
		data->last = data->p;
	right_left(keycode, data);
	up_down(keycode, data);
	if (data->moves > moves_check)
	{
		data->cooldown /= 4;
		move_enemy(data);
	}
	coin_exit(data);
	draw_map(data);
	return (1);
}

void	dead(t_data *data)
{
	int	x;
	int	y;
	int	i;

	i = 150000;
	x = (data->map_w * 30) - 90 + 80;
	y = (data->map_size * 30);
	while (y > -100)
	{
		mlx_clear_window(data->con, data->win);
		mlx_put_image_to_window(data->con, data->win, data->game_o,
			(data->map_w * 30) - 90, (data->map_size * 30) - 90);
		mlx_put_image_to_window(data->con, data->win, data->ghost, x, y);
		mlx_do_sync(data->con);
		while (i)
			i--;
		i = 150000;
		y -= 10;
	}
}
