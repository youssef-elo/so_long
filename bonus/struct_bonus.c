/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-ouaz <yel-ouaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 10:12:52 by yel-ouaz          #+#    #+#             */
/*   Updated: 2024/07/19 21:14:06 by yel-ouaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_zero(t_data *data)
{
	data->con = 0;
	data->win = 0;
	data->w = 0;
	data->bg = 0;
	data->r = 0;
	data->r1 = 0;
	data->r2 = 0;
	data->l = 0;
	data->l1 = 0;
	data->l2 = 0;
	data->p = 0;
	data->e = 0;
	data->e1 = 0;
	data->c = 0;
	data->enr = 0;
	data->enl = 0;
	data->moves = 0;
	data->last = 0;
	data->opp = 0;
}

void	initialize_struct(t_data *d, int map_size, char **map)
{
	d->con = mlx_init();
	if (!d->con)
	{
		write(2, "Error\nMlx connection failed.\n", 29);
		ft_exit(d);
	}
	get_images(d);
	d->win = mlx_new_window(d->con, d->map_w * 60, d->map_size * 60, "so_long");
	check_struct(d, map_size, map);
}

void	get_images(t_data *d)
{
	int	w;
	int	h;

	d->w = mlx_xpm_file_to_image(d->con, "textures/w.xpm", &w, &h);
	d->bg = mlx_xpm_file_to_image(d->con, "textures/b.xpm", &w, &h);
	d->p = mlx_xpm_file_to_image(d->con, "textures/p.xpm", &w, &h);
	d->c = mlx_xpm_file_to_image(d->con, "textures/c.xpm", &w, &h);
	d->e = mlx_xpm_file_to_image(d->con, "textures/ec.xpm", &w, &h);
	d->e1 = mlx_xpm_file_to_image(d->con, "textures/o2.xpm", &w, &h);
	d->r = mlx_xpm_file_to_image(d->con, "textures/1r.xpm", &w, &h);
	d->r1 = mlx_xpm_file_to_image(d->con, "textures/3r.xpm", &w, &h);
	d->r2 = mlx_xpm_file_to_image(d->con, "textures/6r.xpm", &w, &h);
	d->l = mlx_xpm_file_to_image(d->con, "textures/1l.xpm", &w, &h);
	d->l1 = mlx_xpm_file_to_image(d->con, "textures/3l.xpm", &w, &h);
	d->l2 = mlx_xpm_file_to_image(d->con, "textures/6l.xpm", &w, &h);
	d->pad = mlx_xpm_file_to_image(d->con, "textures/pading.xpm", &w, &h);
	d->enr = mlx_xpm_file_to_image(d->con, "textures/enr.xpm", &w, &h);
	d->enl = mlx_xpm_file_to_image(d->con, "textures/enl.xpm", &w, &h);
	d->game_o = mlx_xpm_file_to_image(d->con, "textures/gameover.xpm", &w, &h);
	d->ghost = mlx_xpm_file_to_image(d->con, "textures/ghost.xpm", &w, &h);
	d->last = d->p;
}

// check if the struct init successeful and count coins aswell as enemies
void	check_struct(t_data *d, int map_size, char **map)
{
	int	i;
	int	j;

	if (!d->w || !d->bg || !d->p || !d->c || !d->e || !d->e1 || !d->r || !d->r1
		|| !d->r2 || !d->l || !d->l1 || !d->l2 || !d->pad || !d->win || !d->enr
		|| !d->enl || !d->game_o || !d->ghost)
	{
		write(2, "Error\nCant open image(s)\n", 25);
		ft_exit(d);
	}
	i = 0;
	j = 0;
	while (i < map_size)
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				d->coins++;
			if (map[i][j] == 'G')
				d->num_enemies++;
			j++;
		}
		i++;
	}
}
