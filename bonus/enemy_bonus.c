/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-ouaz <yel-ouaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 16:48:32 by yel-ouaz          #+#    #+#             */
/*   Updated: 2024/07/19 21:13:55 by yel-ouaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

//allocate an array of struct based on how many enemies there is 
//each element holds the position of each enemy
//and their direction based on the order they are found in the map 
void	initialize_enemies(t_data *d)
{
	int	a;
	int	b;
	int	num_enemies;

	a = 0;
	num_enemies = 0;
	d->opp = malloc(d->num_enemies * sizeof(t_enemy));
	if (!d->opp)
		ft_exit(d);
	while (a < d->map_size)
	{
		b = 0;
		while (b < d->map_w)
		{
			if (d->map[a][b] == 'G')
			{
				(d->opp)[num_enemies].x = b;
				(d->opp)[num_enemies].y = a;
				(d->opp)[num_enemies].dir = 1;
				num_enemies++;
			}
			b++;
		}
		a++;
	}
}

int	move_enemy(t_data *d)
{
	int	a;

	if (d->cooldown == 0)
	{
		a = 0;
		while (a < d->num_enemies)
		{
			if (d->map[d->opp[a].y][d->opp[a].x + d->opp[a].dir] != '0')
				d->opp[a].dir = -d->opp[a].dir;
			if (d->map[d->opp[a].y][d->opp[a].x + d->opp[a].dir] == '0')
			{
				d->map[d->opp[a].y][d->opp[a].x + d->opp[a].dir] = 'G';
				d->map[d->opp[a].y][d->opp[a].x] = '0';
				d->opp[a].x += d->opp[a].dir;
			}
			a++;
		}
		d->cooldown = 4000;
		draw_map(d);
		coin_exit(d);
	}
	d->cooldown--;
	return (1);
}
