/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-ouaz <yel-ouaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 11:06:50 by yel-ouaz          #+#    #+#             */
/*   Updated: 2024/05/25 15:41:15 by yel-ouaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

char	*get_next_line(int fd);
void	*ft_memset(void *b, int c, size_t len);
size_t	ft_strlen(char *s);
char	*ft_strjoin(char *s1, char *s2, size_t len2, int f);
char	*ft_s_d(char *s, unsigned int start, size_t len, int sw);
void	ft_strlcpy(char *dst, char *src, size_t dstsize);
int		ft_check_buffer(char **rstring, char *buffer, int rr);
int		ft_check_remaining(char **rstring, char *buffer);
#endif