/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfartah <sfartah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 15:59:04 by sfartah           #+#    #+#             */
/*   Updated: 2025/03/21 16:02:51 by sfartah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

char *chek_access(char **paths, char *cmd)
{
	int i;
	char *cmd_path;
	
	i = 0;
	while (paths[i])
	{
		
		cmd_path = ft_strjoin(ft_strdup("/"), cmd);
		cmd_path = ft_strjoin(paths[i], cmd_path);
		if (!access(cmd_path, F_OK & X_OK))
			return (cmd_path);
		i++;
	}
	return (free(cmd_path), NULL);
}

void	child(t_h data, char *av[], char *env[])
{
	int i;
	char **cmd;
	char *cmd_path;
	int infd;

	i = 0;
	close(data.pipefds[0]);
	infd = open(av[1], O_RDONLY, 0777);
	if (infd < 0)
	{
		ft_printf("Error: no such file or directory : %s\n", av[1], strerror(1));
		exit(1);
	}
	dup2(infd, 0);
	close(infd);
	dup2(data.pipefds[1], 1);
	close(data.pipefds[1]);
	cmd = ft_split(av[2], 32);
	cmd_path = chek_access(data.paths, *cmd);
	if (!cmd_path)
		ft_printf("Error: command not found : %s\n", av[2]);
	if (cmd_path)
		execve(cmd_path, (char *const *)cmd, env);
}

void	sec_cmd(t_h data, char *av[], char *env[])
{
	char **cmd;
	char *cmd_path;

	close(data.pipefds[1]);
	data.outfd = open(av[4], O_CREAT | O_WRONLY, 0644);
	dup2(data.outfd, 1);
	close(data.outfd);
	dup2(data.pipefds[0], 0);
	close(data.pipefds[0]);
	cmd = ft_split(av[3], 32);
	cmd_path = chek_access(data.paths, *cmd);
	if (!cmd_path)
		ft_printf("Error: command not found : %s\n", av[3]);
	if (cmd_path)
		execve(cmd_path, (char *const *)cmd, env);
}

char *get_path(char **env)
{
	int i;

	i = 0;
	while (env[i])
	{
		if (ft_strnstr(env[i], "PATH", 4))
			return (env[i] + 5);
		i++;
	}
	return (NULL);
}

int	main(int ac, char *av[], char *env[])
{
	t_h	data;
	char *path;
	int first;
	// int sec;
	
	if (ac != 5)
		return (ft_printf("Error : Need four arguments\n", strerror(1)), 1);
	path = get_path(env);
	pipe(data.pipefds);
	data.paths = ft_split(path, ':');
	first = fork();
	if (first == 0)
		child(data, av, env);
	else if (first > 0)
	{
			sec_cmd(data, av, env);
			// wait(NULL);
			// waitpid(first, NULL, 0);
			// waitpid(sec, NULL, 0);
	}
}
