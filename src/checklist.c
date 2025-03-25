/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checklist.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfartah <sfartah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 15:21:36 by sfartah           #+#    #+#             */
/*   Updated: 2025/03/25 16:21:13 by sfartah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	checkinfile(char *file, int fds[2])
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (access(file, F_OK) < 0)
	{
		ft_putstr_fd("pipex: no such file or directory : ", 2);
		ft_putstr_fd(file, 2);
		write(2, "\n", 1);
		close_exit(fds, -1, 0);
	}
	if (access(file, R_OK) < 0)
	{
		ft_putstr_fd("pipex: permission denied: ", 2);
		ft_putstr_fd(file, 2);
		write(2, "\n", 1);
		close_exit(fds, -1, 0);
	}
	if (fd < 0)
	{
		perror("pipex: ");
		close_exit(fds, -1, 0);
	}
	return (fd);
}

int	checkoutfile(char *file, int fds[2])
{
	int	fd;

	fd = open(file, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (access(file, W_OK) < 0)
	{
		ft_putstr_fd("pipex: permission denied: ", 2);
		ft_putstr_fd(file, 2);
		write(2, "\n", 1);
		close_exit(fds, -1, 1);
	}
	if (fd < 0)
	{
		perror("pipex: ");
		close_exit(fds, -1, 0);
	}
	return (fd);
}

char	*chek_access(char **paths, char *cmd, char *carg)
{
	int		i;
	char	*cmd_path;

	i = 0;
	if (!access(carg, F_OK & X_OK))
		return (free_array(paths), ft_strdup(carg));
	while (paths[i])
	{
		cmd_path = ft_strjoin(paths[i], cmd);
		if (!cmd_path)
			return (free_array(paths), NULL);
		if (!access(cmd_path, F_OK & X_OK))
			return (free_array(paths), cmd_path);
		free(cmd_path);
		i++;
	}
	free_array(paths);
	return (NULL);
}

char	**get_path(char **env)
{
	int		i;
	char	**paths;

	i = 0;
	while (env[i])
	{
		if (ft_strnstr(env[i], "PATH", 4))
		{
			paths = ft_split(env[i] + 5, ':');
			if (!paths)
				return (NULL);
			return (paths);
		}
		i++;
	}
	return (NULL);
}
