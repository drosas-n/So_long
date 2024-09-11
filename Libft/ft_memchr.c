/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosas-n <drosas-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 19:28:47 by drosas-n          #+#    #+#             */
/*   Updated: 2023/05/09 18:41:10 by drosas-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*string;
	char	caracter;
	size_t	x;

	string = (char *)s;
	caracter = (char)c;
	x = 0;
	while (x < n)
	{
		if (string[x] == caracter)
			return ((void *)&string[x]);
		x++;
	}
	return (0);
}
