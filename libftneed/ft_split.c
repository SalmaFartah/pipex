/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfartah <sfartah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:02:22 by sfartah           #+#    #+#             */
/*   Updated: 2025/03/18 17:09:48 by sfartah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static int	cnt_words(char const *s, char c)
{
	int	cnt;
	int	u;

	if (!s)
		return (0);
	u = 0;
	cnt = 0;
	while (s[u])
	{
		if ((s[u] != c) && (u == 0 || s[u - 1] == c))
			cnt++;
		u++;
	}
	return (cnt);
}

static char	*alc_fill(const char *s, int st, int c)
{
	char	*ptrf;
	int		nd;
	int		u;

	nd = st;
	while (s[nd] && s[nd] != c)
		nd++;
	ptrf = ft_calloc((nd - st) + 1, sizeof(char));
	if (!ptrf)
		return (NULL);
	u = 0;
	while (st < nd)
		ptrf[u++] = s[st++];
	return (ptrf);
}

static void	*ft_free(char **p, int u)
{
	int	j;

	j = 0;
	while (j < u)
	{
		free(p[j]);
		j++;
	}
	free(p);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		st;
	int		u;
	char	**ptr;

	if (!s)
		return (NULL);
	st = 0;
	u = 0;
	ptr = ft_calloc((cnt_words(s, c) + 1), sizeof(char *));
	if (!ptr)
		return (NULL);
	while (s[st] && u < cnt_words(s, c))
	{
		if (s[st] != c && (st == 0 || s[st - 1] == c))
		{
			ptr[u] = alc_fill(s, st, c);
			if (!(ptr[u]))
				return (ft_free(ptr, u));
			u++;
		}
		st++;
	}
	return (ptr);
}
