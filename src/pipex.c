/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfartah <sfartah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 12:39:12 by sfartah           #+#    #+#             */
/*   Updated: 2025/03/24 23:13:08 by sfartah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	main(int ac, char *av[], char *env[])
{
	t_h	data;

	if (ac != 5)
		return (write(2, "pipex: bad arguments\n", 22), 1);
	if (pipe(data.pfs) < 0)
		exit(1);
	data.pid_f = fork();
	if (data.pid_f < 0)
		return (ft_error("cant create first child\n", \
		data.pfs[0], data.pfs[1]), 1);
	if (data.pid_f == 0)
		child(data, av, env);
	data.pid_s = fork();
	if (data.pid_s < 0)
		return (ft_error("cant create scnd child\n", \
		data.pfs[0], data.pfs[1]), 1);
	if (data.pid_s == 0)
		sec_child(data, av, env);
	closet(data.pfs[0], data.pfs[1], -1);
	waitpid(data.pid_f, &data.fstatus, 0);
	waitpid(data.pid_s, &data.sstatus, 0);
	if (WEXITSTATUS(data.fstatus) || WEXITSTATUS(data.sstatus))
		return (1);
}
