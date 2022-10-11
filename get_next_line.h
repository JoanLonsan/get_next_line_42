# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Untitled-1                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/10 15:37:33 by marvin            #+#    #+#              #
#    Updated: 2022/10/10 15:37:33 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

char    *get_next_line(int fd);
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *b, int c, size_t len);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
char    *ft_free_gnl(char *ret, char *buffer);
char    *ft_fd_read(int fd, char *buffer);
char    *ft_get_line(char *buffer);
char    *ft_get_next(char *buffer);

# endif