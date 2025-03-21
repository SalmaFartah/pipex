/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfartah <sfartah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 12:33:00 by sfartah           #+#    #+#             */
/*   Updated: 2024/12/01 22:37:22 by sfartah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	putch(char c);
int	putst(char *str);
int	putnb(int nb);
int	putunb(unsigned int nb);
int	putadrs(void *p, char c);
int	puthex(unsigned long nb, char c);

#endif