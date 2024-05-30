/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-ouaz <yel-ouaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 11:22:29 by yel-ouaz          #+#    #+#             */
/*   Updated: 2024/05/25 16:18:04 by yel-ouaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_nline(char *s)
{
	int	a;

	a = 0;
	if (s == NULL)
		return (0);
	while (s[a])
	{
		if (s[a] == '\n')
			return (a);
		a++;
	}
	return (-1);
}

int	ft_check_remaining(char **rstring, char *buffer)
{
	size_t	blen;
	int		j;

	j = ft_nline(buffer);
	blen = ft_strlen(buffer);
	if (j >= 0)
	{
		*rstring = ft_s_d(buffer, 0, j + 1, 0);
		if (!rstring)
			return (1);
		ft_strlcpy(buffer, buffer + j + 1, blen - j);
		return (1);
	}
	else if (j == -1 && blen > 0)
	{
		*rstring = ft_s_d(buffer, 0, 0, 1);
		if (!(*rstring))
			return (1);
	}
	return (0);
}

int	ft_check_buffer(char **rstring, char *buffer, int rr)
{
	int	i;

	i = ft_nline(buffer);
	if (i >= 0)
	{
		*rstring = ft_strjoin(*rstring, ft_s_d(buffer, 0, i + 1, 0), i + 1, 1);
		if (!(*rstring))
			return (1);
		ft_strlcpy(buffer, buffer + i + 1, rr - i + 1);
		return (1);
	}
	if (rr == 0 && i == -1)
		return (1);
	else if (i == -1 && rr > 0)
	{
		*rstring = ft_strjoin(*rstring, buffer, rr, 0);
		if (!(*rstring))
			return (1);
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static char	buffer[(unsigned int)BUFFER_SIZE + 1];
	char		*rstring;
	int			rr;

	rr = 1;
	rstring = NULL;
	if (BUFFER_SIZE <= 0)
		return (NULL);
	if (read(fd, 0, 0) == -1)
	{
		ft_memset(buffer, 0, (unsigned int)BUFFER_SIZE + 1);
		return (NULL);
	}
	if (ft_check_remaining(&rstring, buffer) == 1)
		return (rstring);
	while (rr > 0)
	{
		rr = read(fd, buffer, BUFFER_SIZE);
		if (rr >= 0)
			buffer[rr] = '\0';
		if (ft_check_buffer(&rstring, buffer, rr) == 1)
			return (rstring);
	}
	free(rstring);
	return (NULL);
}
