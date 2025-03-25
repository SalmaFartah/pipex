/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sp_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfartah <sfartah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 17:08:07 by sfartah           #+#    #+#             */
/*   Updated: 2025/03/24 15:42:48 by sfartah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

char	**to_cmd(char **s, char *str)
{
	char	**ret;
	int		cnt;

	cnt = 0;
	while (s[cnt])
		cnt++;
	if (str)
		cnt++;
	ret = ft_calloc(cnt + 1, sizeof(char *));
	if (!ret)
		return (NULL);
	cnt = -1;
	while (s[++cnt])
	{
		ret[cnt] = ft_strdup(s[cnt]);
		if (!ret[cnt])
			return (free_array(ret), NULL);
	}
	if (str)
	{
		ret[cnt] = ft_strdup(str);
		if (!ret[cnt])
			return (free_array(ret), NULL);
	}
	return (ret);
}

size_t	wherisquote(const char *s)
{
	size_t	cnt;

	cnt = 0;
	while (s[cnt] && s[cnt] != 39)
		cnt++;
	return (cnt);
}

char	*check_quote(char *s, int *checker)
{
	int		i;
	char	*ls;

	i = 0;
	while (s[i])
	{
		if (s[i] == 39)
		{
			ls = ft_substr(s, i + 1, wherisquote(s + i + 1));
			if (!ls)
				return (*checker = 2, NULL);
			return (ls);
		}
		i++;
	}
	return (NULL);
}

char	**split_cmd(char *cmdarg)
{
	char	*fr;
	char	*ls;
	char	**sp;
	char	**ret;
	int		checker;

	checker = 0;
	ls = check_quote(cmdarg, &checker);
	if (!ls && checker == 2)
		return (NULL);
	fr = ft_substr(cmdarg, 0, wherisquote(cmdarg));
	if (!fr)
		return (free(ls), NULL);
	sp = ft_split(fr, 32);
	if (!sp)
		return (free(ls), free(fr), NULL);
	ret = to_cmd(sp, ls);
	if (!ret)
		return (free(fr), free_array(sp), free(ls), NULL);
	return (free(fr), free_array(sp), free(ls), ret);
}
