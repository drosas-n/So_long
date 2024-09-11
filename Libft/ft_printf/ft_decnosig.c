/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decnosig.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosas-n <drosas-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 19:25:12 by drosas-n          #+#    #+#             */
/*   Updated: 2023/08/31 19:40:56 by drosas-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_decnosig(unsigned int num)
{
	int	x;
	int	a;

	x = 0;
	if (num > 9)
		x += ft_decnosig(num / 10);
	a = num % 10 + '0';
	write (1, &a, 1);
	x++;
	return (x);
}
