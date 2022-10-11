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

char    *ft_get_buffer(char *ret, char *buffer)
{
    char    *aux;

    aux = ft_strjoin(ret, buffer);
    free(ret);
    return(aux);
}

char    *ft_fd_read(int fd, char *buffer)
{
    char    *aux;
    int     i;

    if (!buffer)
        buffer = ft_calloc(1, 1);
    buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
    i = 1;
    while (i > 0)
    {
        i = read(fd, aux, BUFFER_SIZE);
        if (i == -1)
        {
            free(aux);
            return (NULL);
        }
        aux[i] = '\0';
        buffer = ft_get_buffer(buffer, aux);
        if (ft_strchr(aux, '\n'))
            break;
    }
    free(aux);
    return (buffer);
}

char    *ft_get_line(char *buffer)
{
    char    *line;
    int     i;

    if (!buffer[i])
        return (NULL);
    while (buffer[i] != '\n' && buffer[i])
        i++;
    line = ft_calloc(i + 2, sizeof(char));
    i = 0;
    while (buffer[i] != '\n' && buffer[i])
    {
        line[i] = buffer[i];
        i++;
    }
    line[i] = '\n';
    return (line);
}

char    *ft_get_next(char *buffer)
{
    char    *line;
    int     i;
    int     j;

    i = 0;
    while (buffer[i] != '\n' && buffer[i])
        i++;
    if (!buffer[i])
        free(buffer);
        return (NULL);
    line = ft_calloc((ft_strlen(buffer) - i + 1), sizeof(char));
    i++;
    j = 0;
    while (buffer[i])
        {
        line[j] = buffer[i];
        i++;
        j++;
        }
    free(buffer);
    return (line);
}

char    *get_next_line(int fd)
{
    static char     *buffer;
    char            *line;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    buffer = ft_fd_read(fd, buffer);
    if (!buffer)
        return (NULL);
    line = ft_get_line(buffer);
    buffer = ft_get_next(buffer);
    return (line);
}
