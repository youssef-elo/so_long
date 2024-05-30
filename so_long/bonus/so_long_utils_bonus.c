/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-ouaz <yel-ouaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 16:16:49 by yel-ouaz          #+#    #+#             */
/*   Updated: 2024/05/27 16:05:19 by yel-ouaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

int	ft_strcmp(char *s1, char *s2)
{
	int				i;
	unsigned char	*p1;
	unsigned char	*p2;

	p1 = (unsigned char *)s1;
	p2 = (unsigned char *)s2;
	i = 0;
	while (p1[i] || p2[i])
	{
		if (p1[i] != p2[i])
			return (p1[i] - p2[i]);
		i++;
	}
	return (0);
}

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int a)
{
	long	n;

	n = a;
	if (n < 0)
	{
		n *= -1;
		ft_putchar('-');
	}
	if (n <= 9 && n >= 0)
	{
		ft_putchar(n + 48);
		return ;
	}
	ft_putnbr(n / 10);
	ft_putnbr(n % 10);
}

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
