/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfartah <sfartah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 15:07:49 by sfartah           #+#    #+#             */
/*   Updated: 2025/03/18 15:40:11 by sfartah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	putadrs(void *p, char c)
{
	int	t;

	t = 0;
	t += write(1, "0x", 2);
	t += puthex((unsigned long)p, c);
	return (t);
}

int	putch(char c)
{
	write(1, &c, 1);
	return (1);
}

static int	cnt(unsigned int nbr)
{
	int	sz;

	if (nbr == 0)
		return (1);
	sz = 0;
	while (nbr > 0)
	{
		sz++;
		nbr /= 10;
	}
	return (sz);
}

int	putunb(unsigned int nb)
{
	if (nb < 10)
		putch(nb + '0');
	else
	{
		putunb(nb / 10);
		putunb(nb % 10);
	}
	return (cnt(nb));
}

