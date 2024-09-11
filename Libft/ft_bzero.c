/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosas-n <drosas-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 19:34:34 by drosas-n          #+#    #+#             */
/*   Updated: 2023/04/27 17:35:21 by drosas-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_bzero(void *s, size_t n)
{
	size_t	x;
	char	*s1;

	s1 = (char *)s;
	x = 0;
	while (x < n)
	{
		s1[x] = '\0';
		x++;
	}
}
