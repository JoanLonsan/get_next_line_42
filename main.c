/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrescen <jcrescen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 19:36:46 by jcrescen          #+#    #+#             */
/*   Updated: 2022/10/16 19:36:55 by jcrescen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>

void	ft_exit(void)
{
	system("leaks -q a.out");
}

int	main(void)
{
	int		fd;
	char	*a;

	atexit(ft_exit);
	fd = open("input.txt", O_RDONLY);
	a = get_next_line(fd);
	while (a != NULL)
	{
		puts (a);
		ft_free(&a, 0, 0);
		a = get_next_line(fd);
	}
	ft_free(&a, 0, 0);
}
