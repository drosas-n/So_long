/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosas-n <drosas-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 19:28:03 by drosas-n          #+#    #+#             */
/*   Updated: 2023/07/06 17:15:18 by drosas-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		x;
	char	caracter;

	caracter = (char)c;
	x = ft_strlen(s);
	while (x > 0)
	{
		if (caracter == s[x])
			return ((char *)&s[x]);
		x--;
	}
	if (caracter == s[x])
		return ((char *)&s[x]);
	return (0);
}
