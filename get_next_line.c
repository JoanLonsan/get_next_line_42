/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:32:31 by marvin            #+#    #+#             */
/*   Updated: 2022/10/10 15:32:31 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *get_next_line(int fd)
{
    char    *buffer;
    char    *line;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    buffer = read (fd);
    if (!buffer)
        return (NULL);
    line = ft_get_line(buffer);
    buffer = ft_get_next(buffer);
    return (line);
}