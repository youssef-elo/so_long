/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_2_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-ouaz <yel-ouaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 19:29:23 by yel-ouaz          #+#    #+#             */
/*   Updated: 2024/06/06 17:30:43 by yel-ouaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_counter(int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		count++;
		n *= -1;
	}
	while (n)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*r;

	len = ft_counter(n);
	r = (char *)malloc((len + 1) * sizeof(char));
	if (r == NULL)
		return (NULL);
	r[len] = '\0';
	len--;
	if (n == 0)
		r[0] = '0';
	if (n < 0)
	{
		n *= -1;
		r[0] = '-';
	}
	while (n)
	{
		r[len] = (n % 10) + 48;
		len--;
		n /= 10;
	}
	return (r);
}
