/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_utils1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfartah <sfartah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 15:10:18 by sfartah           #+#    #+#             */
/*   Updated: 2025/03/18 15:40:30 by sfartah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	putst(char *str)
{
	int	kt;
	int	i;

	kt = 0;
	if (!str)
		kt += putst("(null)");
	i = 0;
	while (str && str[i])
	{
		kt += putch(str[i]);
		i++;
	}
	return (kt);
}

int	puthex(unsigned long nb, char c)
{
	int	t;

	t = 0;
	if (nb <= 15)
	{
		if (nb < 10)
			t += putch(nb + '0');
		else if (c == 'p' || c == 'x')
			t += putch(nb + 87);
		else if (c == 'X')
			t += putch(nb + 55);
	}
	else
	{
		t += puthex(nb / 16, c);
		t += puthex(nb % 16, c);
	}
	return (t);
}

static int	cnt(long nbr)
{
	int	sz;

	if (nbr == 0)
		return (1);
	sz = 0;
	(nbr < 0) && (nbr *= -1) && (sz++);
	while (nbr > 0)
	{
		sz++;
		nbr /= 10;
	}
	return (sz);
}

int	putnb(int nb)
{
	int	kt;

	kt = cnt(nb);
	if (nb == -2147483648)
		write(1, "-2147483648", 11);
	else if (nb < 0)
	{
		putch('-');
		nb *= -1;
		putnb(nb);
	}
	else if (nb >= 0 && nb < 10)
		putch (nb + '0');
	else
	{
		putnb(nb / 10);
		putnb(nb % 10);
	}
	return (kt);
}
