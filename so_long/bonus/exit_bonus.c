/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-ouaz <yel-ouaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 10:12:38 by yel-ouaz          #+#    #+#             */
/*   Updated: 2024/05/29 11:32:13 by yel-ouaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

// free array
void	ft_free(char **map, int map_size)
{
	int	i;

	i = 0;
	while (i < map_size)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

// error exit in case of invalid map 
//flag is to decide wether to free the map or not
void	ft_error(char **map, int map_size, int flag, char *err_mess)
{
	int	i;

	i = 0;
	if (flag == 1 || flag == 2)
	{
		while (i < map_size)
			free(map[i++]);
		free(map);
		if (flag == 2)
			ft_putstr(err_mess);
	}
	if (flag == 0 || flag == 1)
		write(1, "Error\nInvalid map\n", 18);
	exit(1);
}

void my_destroy_image(t_data *data,void *img)
{
	if (img)
		mlx_destroy_image(data->con,img);
}

void ft_exit(t_data *data)
{
	my_destroy_image(data,data->w);
	my_destroy_image(data,data->bg);
	my_destroy_image(data,data->r);
	my_destroy_image(data,data->r1);
	my_destroy_image(data,data->r2);
	my_destroy_image(data,data->l);
	my_destroy_image(data,data->l1);
	my_destroy_image(data,data->l2);
	my_destroy_image(data,data->p);
	my_destroy_image(data,data->e);
	my_destroy_image(data,data->e1);
	my_destroy_image(data,data->c);
	my_destroy_image(data,data->pad);
	my_destroy_image(data,data->enr);
	my_destroy_image(data,data->enl);
	my_destroy_image(data,data->game_o);
	my_destroy_image(data,data->ghost);
	if(data->win)
		mlx_destroy_window(data->con,data->win);
	ft_free(data->map,data->map_size);
	exit (1);
}
