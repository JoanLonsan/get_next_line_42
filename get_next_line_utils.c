/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:40:06 by marvin            #+#    #+#             */
/*   Updated: 2022/10/10 15:40:06 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != (unsigned char)c)
		if (!*s++)
			return (0);
	return ((char *)s);
}

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
		*(char *)(b + i++) = (unsigned char)c;
	return (b);
}

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, '\0', n);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*a;

	if (count == 0 || size == 0)
	{
		count = 1;
		size = 1;
	}
	a = (void *)malloc(count * size);
	if (!a)
		return (NULL);
	ft_bzero(a, count * size);
	return (a);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*sj;

	sj = (char *)malloc(sizeof(*s1) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!sj)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
		sj[j++] = s1[i++];
	i = 0;
	while (s2[i])
		sj[j++] = s2[i++];
	sj[j] = '\0';
	return (sj);
}
