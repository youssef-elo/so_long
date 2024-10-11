/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-ouaz <yel-ouaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 10:12:47 by yel-ouaz          #+#    #+#             */
/*   Updated: 2024/06/26 20:12:02 by yel-ouaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	main(int argc, char *argv[])
{
	t_data	data;

	ft_zero(&data);
	data.map_size = check_input(argc, argv[1]);
	get_map(argv[1], data.map_size, &data);
	if (!data.map)
		return (-1);
	initialize_struct(&data, data.map_size, data.map);
	initialize_enemies(&data);
	draw_map(&data);
	mlx_loop_hook(data.con, move_enemy, &data);
	mlx_hook(data.win, 2, 0, key, &data);
	mlx_hook(data.win, 17, 0, ft_destroy, &data);
	mlx_loop(data.con);
}
