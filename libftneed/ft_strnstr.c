/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfartah <sfartah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 14:14:45 by sfartah           #+#    #+#             */
/*   Updated: 2025/03/19 13:59:25 by sfartah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	u;
	size_t	v;

	if (!haystack && !len && needle)
		return (NULL);
	if (!(*needle))
		return ((char *)haystack);
	u = 0;
	while (haystack[u] && u < len)
	{
		v = 0;
		while ((needle[v] == haystack[u + v]) && u + v < len)
		{
			if (!needle[v + 1])
				return ((char *)haystack + u);
			v++;
		}
		u++;
	}
	return (NULL);
}
