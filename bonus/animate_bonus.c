/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-ouaz <yel-ouaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 19:19:25 by yel-ouaz          #+#    #+#             */
/*   Updated: 2024/06/08 00:08:24 by yel-ouaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	coin_exit(t_data *data)
{
	if (data->map[data->p_y / 60][data->p_x / 60] == 'C')
	{
		data->coins--;
		data->map[data->p_y / 60][data->p_x / 60] = '0';
	}
	if (data->map[data->p_y / 60][data->p_x / 60] == 'E' && data->coins == 0)
	{
		ft_putstr("You Won!!!\n");
		ft_exit(data);
	}
	if (data->map[data->p_y / 60][data->p_x / 60] == 'G')
	{
		dead(data);
		ft_exit(data);
	}
}

void	up_down(int keycode, t_data *d)
{
	if (keycode == UP && d->map[(d->p_y / 60) - 1][d->p_x / 60] != '1')
	{
		ft_animate_u_d(keycode, d);
		draw_map(d);
		ft_animate_u_d(keycode, d);
		draw_map(d);
		ft_animate_u_d(keycode, d);
		draw_map(d);
		d->moves++;
		d->last = d->p;
		move_enemy(d);
	}
	if (keycode == DOWN && d->map[(d->p_y / 60) + 1][d->p_x / 60] != '1')
	{
		ft_animate_u_d(keycode, d);
		draw_map(d);
		ft_animate_u_d(keycode, d);
		draw_map(d);
		ft_animate_u_d(keycode, d);
		draw_map(d);
		d->moves++;
		d->last = d->p;
		move_enemy(d);
	}
}

void	right_left(int k, t_data *d)
{
	if (k == RIGHT && d->map[d->p_y / 60][(d->p_x / 60) + 1] != '1')
	{
		ft_animate_r_l(k, d);
		draw_map(d);
		ft_animate_r_l(k, d);
		draw_map(d);
		ft_animate_r_l(k, d);
		draw_map(d);
		d->moves++;
		d->last = d->r;
		move_enemy(d);
	}
	if (k == LEFT && d->map[d->p_y / 60][(d->p_x / 60) - 1] != '1')
	{
		ft_animate_r_l(k, d);
		draw_map(d);
		ft_animate_r_l(k, d);
		draw_map(d);
		ft_animate_r_l(k, d);
		draw_map(d);
		d->moves++;
		d->last = d->l;
		move_enemy(d);
	}
}

void	ft_animate_r_l(int k, t_data *d)
{
	if (k == RIGHT)
	{
		mlx_put_image_to_window(d->con, d->win, d->pad, d->p_x, d->p_y);
		d->p_x += 10;
		mlx_put_image_to_window(d->con, d->win, d->r1, d->p_x, d->p_y);
		mlx_do_sync(d->con);
		mlx_put_image_to_window(d->con, d->win, d->pad, d->p_x, d->p_y);
		d->p_x += 10;
		mlx_put_image_to_window(d->con, d->win, d->r2, d->p_x, d->p_y);
		mlx_do_sync(d->con);
	}
	if (k == LEFT)
	{
		mlx_put_image_to_window(d->con, d->win, d->pad, d->p_x, d->p_y);
		d->p_x -= 10;
		mlx_put_image_to_window(d->con, d->win, d->l1, d->p_x, d->p_y);
		mlx_do_sync(d->con);
		mlx_put_image_to_window(d->con, d->win, d->pad, d->p_x, d->p_y);
		d->p_x -= 10;
		mlx_put_image_to_window(d->con, d->win, d->l2, d->p_x, d->p_y);
		mlx_do_sync(d->con);
	}
}

void	ft_animate_u_d(int k, t_data *data)
{
	int	m;

	m = 10;
	if (k == UP)
		m = -10;
	mlx_put_image_to_window(data->con, data->win, data->pad,
		data->p_x, data->p_y);
	data->p_y += m;
	mlx_put_image_to_window(data->con, data->win, data->p,
		data->p_x, data->p_y);
	mlx_do_sync(data->con);
	mlx_put_image_to_window(data->con, data->win, data->pad,
		data->p_x, data->p_y);
	data->p_y += m;
	mlx_put_image_to_window(data->con, data->win, data->p,
		data->p_x, data->p_y);
	mlx_do_sync(data->con);
}
