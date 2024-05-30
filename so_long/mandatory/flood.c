/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-ouaz <yel-ouaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 11:57:19 by yel-ouaz          #+#    #+#             */
/*   Updated: 2024/05/24 14:15:53 by yel-ouaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// check the path to all collectibles and exit
void	check_path(char **map, t_data *data)
{
	char	**dup_map;
	int		i;

	dup_map = malloc(sizeof(char *) * data->map_size);
	data->map_w = length(map[0], 0, 0);
	i = 0;
	while (i < data->map_size)
	{
		dup_map[i] = ft_s_d(map[i], 0, 0, 1);
		i++;
	}
	flood_fill(dup_map, data, data->p_x, data->p_y);
	check_flood_fill(dup_map, data);
}

// flood fill to check if the map is valid
void	flood_fill(char **map, t_data *data, int x, int y)
{
	if (x > data->map_w || x < 0 || y > data->map_size || y < 0)
		return ;
	if (map[y][x] == '1' || map[y][x] == '+')
		return ;
	map[y][x] = '+';
	flood_fill(map, data, x - 1, y);
	flood_fill(map, data, x + 1, y);
	flood_fill(map, data, x, y - 1);
	flood_fill(map, data, x, y + 1);
}

// check if the flood fill was successeful
void	check_flood_fill(char **dup_map, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map_size)
	{
		j = 0;
		while (j < data->map_w)
		{
			if (ft_strchr("PCE", dup_map[i][j]))
			{
				ft_free(data->map, data->map_size);
				ft_free(dup_map, data->map_size);
				data->map = NULL;
				ft_putstr("Error\nInvalid path.\n");
				return ;
			}
			j++;
		}
		i++;
	}
	ft_free(dup_map, data->map_size);
}
