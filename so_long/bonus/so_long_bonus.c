/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-ouaz <yel-ouaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 10:12:47 by yel-ouaz          #+#    #+#             */
/*   Updated: 2024/05/29 12:27:28 by yel-ouaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void print_t_data(t_data data)
{
    printf("map_size: %d\n", data.map_size);
    printf("map_w: %d\n", data.map_w);
    
    // Print the addresses of the void pointers
    printf("con: %p\n", data.con);
    printf("win: %p\n", data.win);
    printf("w: %p\n", data.w);
    printf("bg: %p\n", data.bg);
    printf("r: %p\n", data.r);
    printf("r1: %p\n", data.r1);
    printf("r2: %p\n", data.r2);
    printf("l: %p\n", data.l);
    printf("l1: %p\n", data.l1);
    printf("l2: %p\n", data.l2);
    printf("p: %p\n", data.p);
    printf("e: %p\n", data.e);
    printf("e1: %p\n", data.e1);
    printf("c: %p\n", data.c);
    printf("pad: %p\n", data.pad);
    
    printf("p_x: %d\n", data.p_x);
    printf("p_y: %d\n", data.p_y);
    printf("e_x: %d\n", data.e_x);
    printf("e_y: %d\n", data.e_y);
    printf("coins: %d\n", data.coins);
    printf("moves: %d\n", data.moves);
    // printf("direction: %d\n", data.direction);

    // Assuming map is a 2D array of characters
    printf("map:\n");
    for (int i = 0; i < data.map_size; ++i)
    {
        printf("%s\n", data.map[i]);
    }
}
#define RED "\033[31m"
#define RESET "\033[0m"
void print2DArray(int rows, int cols, char **array) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (array[i][j] == 'G') {
                printf(RED "G" RESET);
            } else {
                printf("%c", array[i][j]);
            }
        }
        printf("\n");
    }
	printf("\n");
}


void initialize_enemies(t_data *d)
{
    int a = 0, b = 0;
    int num_enemies = 0;

    // First, count the number of enemies
    while(a < d->map_size)
    {
        b = 0;
        while(b < d->map_w)
        {
            if(d->map[a][b] == 'G')
                num_enemies++;
            b++;
        }
        a++;
    }

    // Allocate memory for the enemies array
    d->enemies = malloc(num_enemies * sizeof(t_enemy));
    d->num_enemies = num_enemies;
	printf("|%p|\n",d->enemies);
    // Then, initialize the enemies
    a = 0;
    num_enemies = 0;
    while(a < d->map_size)
    {
        b = 0;
        while(b < d->map_w)
        {
            if(d->map[a][b] == 'G')
            {
                (d->enemies)[num_enemies].x = b;
                (d->enemies)[num_enemies].y = a;
                (d->enemies)[num_enemies].dir = 1; // Initial direction is to the right
                num_enemies++;
            }
            b++;
        }
        a++;
    }
}
int move_enemy(t_data *d)
{

    int a = 0;

    if(d->cooldown == 0)
    {
        while(a < d->num_enemies)
        {
            t_enemy *enemy = &((d->enemies)[a]);
            if ((enemy->dir == 1 && d->map[enemy->y][enemy->x + 1] == '1') || (enemy->dir == -1 && d->map[enemy->y][enemy->x - 1] == '1')||
				(enemy->dir == 1 && d->map[enemy->y][enemy->x + 1] == 'C') || (enemy->dir == -1 && d->map[enemy->y][enemy->x - 1] == 'C')
				|| (enemy->dir == 1 && d->map[enemy->y][enemy->x + 1] == 'E') || (enemy->dir == -1 && d->map[enemy->y][enemy->x - 1] == 'E'))
                enemy->dir = -enemy->dir;

            if ((d->map[enemy->y][enemy->x + enemy->dir] != '1' && d->map[enemy->y][enemy->x + enemy->dir] != 'E') && 
				d->map[enemy->y][enemy->x + enemy->dir] != 'C' )
            {
                d->map[enemy->y][enemy->x + enemy->dir] = 'G';
                d->map[enemy->y][enemy->x] = '0';
                enemy->x += enemy->dir;
            }
            a++;
        }
        d->cooldown = 2000;
        draw_map(d->map,d);
        coin_exit(d);
    }
    d->cooldown--;
    return 1;
}

// int move_enemy(t_data *d)
// {
// 	static int j = 1;
// 	static int i = 0;
// 	int a = 0, b = 0;

// 	if (i ==0)
// 	{
// 		while(a < d->map_size)
// 		{
// 			b = 0;
// 			while(b < d->map_w)
// 			{
// 				if(d->map[a][b] == 'G')
// 				{
// 					if (d->map[a][b - 1] == '1' )
// 						j = 1;
// 					else if(d->map[a][b + 1] == '1')
// 						j = -1;

// 					if (d->map[a][b + j] != '1' && d->map[a][b + j] != 'E' )
// 					{
// 						d->map[a][b + j] = 'G';
// 						d->map[a][b] = '0';
// 						draw_map(d->map,d);
// 						coin_exit(d);
// 					}
// 				}
// 				b++;
// 			}
// 			a++;
// 		}
// 		i = 5000;	
// 	}
// 	i--;
// 	return 1;
// }


int main(int argc,char *argv[])
{
	t_data data;

	ft_zero(&data);
	data.map_size = check_input(argc,argv[1]);
	get_map(argv[1], data.map_size, &data);
	if (!data.map)
		return (-1);
	initialize_struct(&data, data.map_size, data.map);
	initialize_enemies(&data);
	print_t_data(data);
	draw_map(data.map, &data);
	mlx_loop_hook(data.con,move_enemy,&data);
	mlx_hook(data.win, 2, 0, key, &data);
	mlx_hook(data.win, 17, 0, ft_destroy, &data);
	mlx_loop(data.con);
}