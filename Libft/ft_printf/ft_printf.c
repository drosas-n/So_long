/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosas-n <drosas-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 18:48:19 by drosas-n          #+#    #+#             */
/*   Updated: 2023/09/04 20:02:13 by drosas-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_type(char const *str, int i, va_list args)
{
	int	x;

	x = 0;
	if (str[i] == 'c')
		x += ft_putchar(va_arg(args, int));
	else if (str[i] == 's')
		x += ft_prtstring(va_arg(args, char *));
	else if (str[i] == 'p')
		x += ft_ptr(va_arg(args, unsigned long long));
	else if (str[i] == 'd')
		x += ft_decsig(va_arg(args, int));
	else if (str[i] == 'i')
		x += ft_decsig(va_arg(args, int));
	else if (str[i] == 'u')
		x += ft_decnosig(va_arg(args, unsigned int));
	else if (str[i] == 'x')
		x += ft_hexadec(va_arg(args, unsigned int), 'x');
	else if (str[i] == 'X')
		x += ft_hexadec(va_arg(args, unsigned int), 'X');
	else if (str[i] == '%')
		x += ft_putchar('%');
	return (x);
}

int	ft_printf(char const *str, ...)
{
	va_list	args;
	int		i;
	int		x;

	i = 0;
	x = 0;
	va_start (args, str);
	while (str[i])
	{
		if (str[i] != '%')
			x += ft_putchar(str[i]);
		else
		{
			i++;
			x += ft_type(str, i, args);
		}
		i++;
	}
	va_end(args);
	return (x);
}
/* 
int	main(void)
{
	int	x;

	x = 285;
	ft_printf("Dirección de memoria es: %p, y en hexadecimal es: %x", x, x);
} */
