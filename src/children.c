/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   children.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfartah <sfartah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 15:20:30 by sfartah           #+#    #+#             */
/*   Updated: 2025/03/25 15:08:40 by sfartah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	check_cmd(char *cmd_path, int pfs[2], char **cmd, int fd)
{
	if (!cmd_path)
	{
		ft_putstr_fd("pipex: command not found : ", 2);
		ft_putstr_fd(*cmd, 2);
		write(2, "\n", 1);
		free_array(cmd);
		close_exit(pfs, fd, 0);
	}
}

void	scheck_cmd(char *cmd_path, int pfs[2], char **cmd, int fd)
{
	if (!cmd_path)
	{
		ft_putstr_fd("pipex: command not found : ", 2);
		ft_putstr_fd(*cmd, 2);
		write(2, "\n", 1);
		free_array(cmd);
		close_exit(pfs, fd, 1);
	}
}

void	child(t_h data, char *av[], char *env[])
{
	data.in = checkinfile(av[1], data.pfs);
	data.paths = get_path(env);
	if (!data.paths)
		close_exit(data.pfs, data.in, 1);
	data.cmd = split_cmd(av[2]);
	if (!data.cmd)
	{
		free_array(data.paths);
		close_exit(data.pfs, data.in, 1);
	}
	data.cmd_path = chek_access(data.paths, *data.cmd, av[2]);
	check_cmd(data.cmd_path, data.pfs, data.cmd, data.in);
	dup2(data.in, 0);
	dup2(data.pfs[1], 1);
	closet(data.pfs[0], data.pfs[1], data.in);
	execve(data.cmd_path, data.cmd, env);
	free(data.cmd_path);
	free_array(data.cmd);
	exit(1);
}

void	sec_child(t_h data, char *av[], char *env[])
{
	
	data.out = checkoutfile(av[4], data.pfs);
	data.paths = get_path(env);
	if (!data.paths)
		close_exit(data.pfs, data.out, 1);
	data.cmd = split_cmd(av[3]);
	if (!data.cmd)
	{
		free_array(data.paths);
		close_exit(data.pfs, data.out, 1);
	}
	data.cmd_path = chek_access(data.paths, *data.cmd, av[3]);
	scheck_cmd(data.cmd_path, data.pfs, data.cmd, data.out);
	dup2(data.out, 1);
	dup2(data.pfs[0], 0);
	closet(data.pfs[0], data.pfs[1], data.out);
	execve(data.cmd_path, data.cmd, env);
	free(data.cmd_path);
	free_array(data.cmd);
	exit(1);
}
