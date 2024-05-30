/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-ouaz <yel-ouaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 11:22:36 by yel-ouaz          #+#    #+#             */
/*   Updated: 2024/05/24 11:43:12 by yel-ouaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*p;

	p = (unsigned char *)b;
	while (len)
	{
		*p = (unsigned char)c;
		len--;
		p++;
	}
	return (b);
}

char	*ft_s_d(char *s, unsigned int start, size_t len, int sw)
{
	char	*r;

	if (!s)
		return (NULL);
	if (sw == 0)
	{
		r = (char *)malloc(len + 1);
		if (r == NULL)
			return (NULL);
		ft_strlcpy(r, s + start, len + 1);
		return (r);
	}
	if (sw == 1)
	{
		len = ft_strlen(s) + 1;
		r = (char *)malloc(len * sizeof(char));
		if (r == NULL)
			return (NULL);
		ft_strlcpy(r, s, len);
		return (r);
	}
	return (NULL);
}

void	ft_strlcpy(char *dst, char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize == 0)
		return ;
	while (i < (dstsize - 1) && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}

char	*ft_strjoin(char *s1, char *s2, size_t len2, int f)
{
	size_t	len1;
	char	*r;

	if ((!s1 && !s2) || (s1 && !s2))
		return (s1);
	if (!s1 && s2)
	{
		r = ft_s_d(s2, 0, 0, 1);
		if (f == 1)
			free(s2);
		return (r);
	}
	len1 = ft_strlen(s1);
	r = (char *)malloc(len1 + len2 + 1);
	if (r == NULL)
	{
		if (f == 1)
			free(s2);
		return (free(s1), NULL);
	}
	ft_strlcpy(r, s1, len1 + 1);
	ft_strlcpy(r + len1, s2, len2 + 1);
	if (f == 1)
		free(s2);
	return (free(s1), r);
}

size_t	ft_strlen(char *s)
{
	size_t	len;

	len = 0;
	if (!s)
		return (-1);
	while (s[len])
	{
		len++;
	}
	return (len);
}
