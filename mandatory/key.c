/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-ouaz <yel-ouaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 12:06:09 by yel-ouaz          #+#    #+#             */
/*   Updated: 2024/06/05 14:33:25 by yel-ouaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// draws the map
void	draw_map(char **map, t_data *d)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	mlx_clear_window(d->con, d->win);
	mlx_put_image_to_window(d->con, d->win, d->bg, 0, 0);
	while (i < d->map_size)
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '1')
				mlx_put_image_to_window(d->con, d->win, d->w, j * 60, i * 60);
			if (map[i][j] == 'E' && d->coins > 0)
				mlx_put_image_to_window(d->con, d->win, d->e1, j * 60, i * 60);
			if (map[i][j] == 'E' && d->coins == 0)
				mlx_put_image_to_window(d->con, d->win, d->e2, j * 60, i * 60);
			if (map[i][j] == 'C')
				mlx_put_image_to_window(d->con, d->win, d->c, j * 60, i * 60);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(d->con, d->win, d->p, d->p_x * 60, d->p_y * 60);
}

void	ft_putnbrn(int num)
{
	ft_putnbr(num);
	ft_putchar('\n');
}

void	ft_move(int keycode, t_data *data, char **map)
{
	if (keycode == UP && map[data->p_y - 1][data->p_x] != '1')
	{
		data->p_y--;
		data->moves++;
		ft_putnbrn(data->moves);
	}
	if (keycode == DOWN && map[data->p_y + 1][data->p_x] != '1')
	{
		data->p_y++;
		data->moves++;
		ft_putnbrn(data->moves);
	}
	if (keycode == LEFT && map[data->p_y][data->p_x - 1] != '1')
	{
		data->p_x--;
		data->moves++;
		ft_putnbrn(data->moves);
	}
	if (keycode == RIGHT && map[data->p_y][data->p_x + 1] != '1')
	{
		data->p_x++;
		data->moves++;
		ft_putnbrn(data->moves);
	}
}

// handle key events
int	key(int keycode, t_data *data)
{
	if (keycode == ESC)
	{
		ft_putstr("Esc key pressed.\n");
		ft_exit(data);
	}
	ft_move(keycode, data, data->map);
	if (data->map[data->p_y][data->p_x] == 'C')
	{
		data->map[data->p_y][data->p_x] = '0';
		data->coins--;
	}
	if (data->map[data->p_y][data->p_x] == 'E' && data->coins == 0)
	{
		ft_putstr("You won!!\n");
		ft_exit(data);
	}
	draw_map(data->map, data);
	return (1);
}

// close window when cross is clicked
int	ft_destroy(t_data *data)
{
	ft_putstr("Window cross clicked.\n");
	ft_exit(data);
	return (1);
}
