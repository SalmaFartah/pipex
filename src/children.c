/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   children.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfartah <sfartah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 15:20:30 by sfartah           #+#    #+#             */
/*   Updated: 2025/03/25 01:22:30 by sfartah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	check_cmd(char *cmd_path, int pfs[2], char **cmd, int fd)
{
	if (!cmd_path)
	{
		closet(pfs[0], pfs[1], fd);
		ft_putstr_fd("pipex: command not found : ", 2);
		ft_putstr_fd(*cmd, 2);
		write(2, "\n", 1);
		free_array(cmd);
		exit(0);
	}
}

void	scheck_cmd(char *cmd_path, int pfs[2], char **cmd, int fd)
{
	if (!cmd_path)
	{
		closet(pfs[0], pfs[1], fd);
		ft_putstr_fd("pipex: command not found : ", 2);
		ft_putstr_fd(*cmd, 2);
		write(2, "\n", 1);
		free_array(cmd);
		exit(1);
	}
}

void	child(t_h data, char *av[], char *env[])
{
	data.in = checkinfile(av[1], data.pfs);
	data.paths = get_path(env);
	if (!data.paths)
	{
		closet(data.pfs[0], data.pfs[1], data.in);
		exit(1);
	}
	data.cmd = split_cmd(av[2]);
	if (!data.cmd)
	{
		closet(data.pfs[0], data.pfs[1], data.in);
		free_array(data.paths);
		exit(1);
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
	data.paths = get_path(env);
	if (!data.paths)
	{
		closet(data.pfs[0], data.pfs[1], data.out);
		exit(1);
	}
	data.out = checkoutfile(av[4], data.pfs);
	data.cmd = split_cmd(av[3]);
	if (!data.cmd)
	{
		closet(data.pfs[0], data.pfs[1], data.out);
		free_array(data.paths);
		exit(1);
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
