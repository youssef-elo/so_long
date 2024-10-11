/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-ouaz <yel-ouaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 11:45:15 by yel-ouaz          #+#    #+#             */
/*   Updated: 2024/07/17 22:47:29 by yel-ouaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// exits the program in a clean way
void	ft_exit(t_data *data)
{
	int	i;

	i = 0;
	if (data->w)
		mlx_destroy_image(data->con, data->w);
	if (data->bg)
		mlx_destroy_image(data->con, data->bg);
	if (data->p)
		mlx_destroy_image(data->con, data->p);
	if (data->c)
		mlx_destroy_image(data->con, data->c);
	if (data->e1)
		mlx_destroy_image(data->con, data->e1);
	if (data->e2)
		mlx_destroy_image(data->con, data->e2);
	if (data->win)
		mlx_destroy_window(data->con, data->win);
	while (i < data->map_size)
		free((data->map)[i++]);
	free(data->map);
	exit(1);
}

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
void	ft_error(char **map, int map_size, int flag)
{
	int	i;

	i = 0;
	if (flag == 1)
	{
		while (i < map_size)
			free(map[i++]);
		free(map);
	}
	write(2, "Error\nInvalid map.\n", 18);
	exit(1);
}
