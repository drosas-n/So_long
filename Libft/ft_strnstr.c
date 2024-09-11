/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosas-n <drosas-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 19:29:30 by drosas-n          #+#    #+#             */
/*   Updated: 2024/07/01 19:05:41 by drosas-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	x;
	size_t	y;

	x = 0;
	if (ft_strlen(needle) == 0)
		return ((char *)haystack);
	while (haystack[x] != '\0' && x < len)
	{
		y = 0;
		while (haystack[x + y] == needle[y] && (x + y) < len)
		{
			y++;
			if (needle[y] == '\0')
				return ((char *)&haystack[x]);
		}
		x++;
	}
	return (0);
}

/* int	main(void)
{
	const char	s[] = "abcdef";
	const char	c[] = "abc";
	int			x;

	x = 3;
	ft_strnstr(s, c, x);
} */
