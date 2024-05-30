/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-ouaz <yel-ouaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 10:12:52 by yel-ouaz          #+#    #+#             */
/*   Updated: 2024/05/29 11:31:42 by yel-ouaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void ft_zero(t_data *data)
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
	data->coins = 0;
	data->enr = 0;
	data->enl = 0;
	data->moves = 0;
	data->last = 0;
}

void	initialize_struct(t_data *d, int map_size, char **map)
{
	int w;

	d->con = mlx_init();
	if(!d->con)
	{
		ft_putstr("Error\nConnection to server x failed\n");
		system("leaks a.out");
		ft_exit(d);
	}
	d->w = mlx_xpm_file_to_image(d->con, "textures/w.xpm", &w, &w);
	d->bg = mlx_xpm_file_to_image(d->con, "textures/b.xpm", &w, &w);
	d->p = mlx_xpm_file_to_image(d->con, "textures/p.xpm", &w, &w);
	d->c = mlx_xpm_file_to_image(d->con, "textures/c.xpm", &w, &w);
	d->e = mlx_xpm_file_to_image(d->con, "textures/ec.xpm", &w, &w);
	d->e1 = mlx_xpm_file_to_image(d->con, "textures/o2.xpm", &w, &w);
	d->r = mlx_xpm_file_to_image(d->con, "textures/1r.xpm", &w, &w);
	d->r1 = mlx_xpm_file_to_image(d->con, "textures/3r.xpm", &w, &w);
	d->r2 = mlx_xpm_file_to_image(d->con, "textures/6r.xpm", &w, &w);
	d->l = mlx_xpm_file_to_image(d->con, "textures/1l.xpm", &w, &w);
	d->l1 = mlx_xpm_file_to_image(d->con, "textures/3l.xpm", &w, &w);
	d->l2 = mlx_xpm_file_to_image(d->con, "textures/6l.xpm", &w, &w);
	d->pad = mlx_xpm_file_to_image(d->con,"textures/pading.xpm",&w,&w);
	d->enr = mlx_xpm_file_to_image(d->con,"textures/enr.xpm",&w,&w);
	d->enl = mlx_xpm_file_to_image(d->con,"textures/enl.xpm",&w,&w);
	d->enl = mlx_xpm_file_to_image(d->con,"textures/enl.xpm",&w,&w);
	d->game_o = mlx_xpm_file_to_image(d->con,"textures/gameover.xpm",&w,&w);
	d->ghost = mlx_xpm_file_to_image(d->con,"textures/ghost.xpm",&w,&w);
	d->last = d->p;
	d->win = mlx_new_window(d->con, d->map_w * 60, d->map_size * 60, "so_long");
	check_struct(d,map_size,map);
}

// check if the struct initialazationwas successeful and count coins
void	check_struct(t_data *d, int map_size, char **map)
{
	int	i;
	int	j;

	if (!d->w || !d->bg || !d->p || !d->c || !d->e || !d->e1 || !d->r || !d->r1
		|| !d->r2 || !d->l || !d->l1 || !d->l2 || !d->pad || !d->win || !d->enr 
		|| !d->enl || !d->game_o || !d->ghost)
	{
		ft_putstr("Error\nCant open image(s)\n");
		system("leaks so_long_bonus");
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
			else if(map[i][j] == 'G')
			{
				d->e_x= j;
				d->e_y= i;
			}
			j++;
		}
		i++;
	}
}
