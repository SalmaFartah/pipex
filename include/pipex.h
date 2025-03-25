/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfartah <sfartah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 12:40:00 by sfartah           #+#    #+#             */
/*   Updated: 2025/03/25 01:21:00 by sfartah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>

typedef struct s_h
{
	int		pfs[2];
	char	**paths;
	int		in;
	int		out;
	char	**cmd;
	char	*cmd_path;
	int		pid_f;
	int		pid_s;
	int		fstatus;
	int		sstatus;
}				t_h;

char	**ft_split(char const *s, char c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(const char *s1);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
size_t	ft_strlen(const char *s);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	ft_putstr_fd(char *s, int fd);

void	free_array(char **a);
char	**to_cmd(char **s, char *str);
char	**split_cmd(char *cmdarg);

int		checkinfile(char *file, int fds[2]);
int		checkoutfile(char *file, int fds[2]);
char	*chek_access(char **paths, char *cmd, char *carg);
char	**get_path(char **env);

void	child(t_h data, char *av[], char *env[]);
void	sec_child(t_h data, char *av[], char *env[]);

void	closet(int fa, int fb, int fc);
void	ft_error(char *str, int fa, int fb);

#endif