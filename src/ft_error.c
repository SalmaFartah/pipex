/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfartah <sfartah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 15:23:06 by sfartah           #+#    #+#             */
/*   Updated: 2025/03/25 15:01:35 by sfartah          ###   ########.fr       */
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
	ft_putstr_fd(str, 2);
	closet(fa, fb, -1);
}
