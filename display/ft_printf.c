/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfartah <sfartah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 12:32:09 by sfartah           #+#    #+#             */
/*   Updated: 2025/03/18 15:38:15 by sfartah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	next(const char *s, int i, va_list arg)
{
	int	kt;

	kt = 0;
	if (s[i] == 'c')
		kt = putch(va_arg(arg, int));
	else if (s[i] == 's')
		kt = putst(va_arg(arg, char *));
	else if (s[i] == 'd' || s[i] == 'i')
		kt = putnb(va_arg(arg, int));
	else if (s[i] == 'u')
		kt = putunb(va_arg(arg, unsigned int));
	else if (s[i] == 'p')
		kt = putadrs(va_arg(arg, void *), s[i]);
	else if (s[i] == 'x' || s[i] == 'X')
		kt = puthex(va_arg(arg, unsigned int), s[i]);
	else if (s[i] == '%')
		kt = putch('%');
	else
		kt = putch(s[i]);
	return (kt);
}

int	ft_printf(const char *s, ...)
{
	va_list	arg;
	int		i;
	int		kt;

	va_start(arg, s);
	i = 0;
	kt = 0;
	while (s[i])
	{
		if (s[i] == '%' && s[i + 1] != '\0')
			kt += next(s, ++i, arg);
		else if (s[i] != '%')
			kt += putch(s[i]);
		i++;
	}
	va_end (arg);
	return (kt);
}
