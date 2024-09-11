/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prtstring.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosas-n <drosas-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 18:48:25 by drosas-n          #+#    #+#             */
/*   Updated: 2023/09/04 19:40:45 by drosas-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_prtstring(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (ft_prtstring("(null)"));
	while (s[i])
	{
		write (1, &s[i], 1);
		i++;
	}
	return (i);
}
