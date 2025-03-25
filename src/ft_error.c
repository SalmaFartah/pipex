/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfartah <sfartah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 15:23:06 by sfartah           #+#    #+#             */
/*   Updated: 2025/03/25 16:53:56 by sfartah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	closet(int fa, int fb, int fc)
{
	if (fa >= 0)
		close(fa);
	if (fb >= 0)
		close(fb);
	if (fc >= 0)
		close(fc);
}

void	ft_error(char *str, int fa, int fb)
{
	write(2, "pipex: ", 7);
	ft_putstr_fd(str, 2);
	write(2, "\n", 1);
	closet(fa, fb, -1);
}

void	close_exit(int fds[2], int fd, int err)
{
	closet(fds[0], fds[1], fd);
	exit(err);
}
