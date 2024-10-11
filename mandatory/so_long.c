/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-ouaz <yel-ouaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:47:14 by yel-ouaz          #+#    #+#             */
/*   Updated: 2024/06/06 18:14:34 by yel-ouaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[ ])
{
	t_data	data;

	ft_zero(&data);
	data.map_size = check_input(argc, argv[1]);
	get_map(argv[1], data.map_size, &data);
	if (!data.map)
		return (-1);
	initialize_struct(&data, data.map_size, data.map);
	draw_map(data.map, &data);
	mlx_hook(data.win, 2, 0, key, &data);
	mlx_hook(data.win, 17, 0, ft_destroy, &data);
	mlx_loop(data.con);
}
