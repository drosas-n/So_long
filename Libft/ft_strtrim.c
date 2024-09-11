/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosas-n <drosas-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 19:48:27 by drosas-n          #+#    #+#             */
/*   Updated: 2023/06/30 20:12:39 by drosas-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	ft_strstart(char const *s1, char const *set)
{
	size_t	x;
	size_t	y;

	x = 0;
	while (s1[x] != '\0')
	{
		y = 0;
		while (s1[x] != set[y] && set[y] != '\0')
			y++;
		if (set[y] == '\0')
			return (x);
		x++;
	}
	return (0);
}

static size_t	ft_strfinal(char const *s1, char const *set)
{
	size_t	y;
	size_t	len;

	len = ft_strlen(s1);
	if (len == 0)
		return (0);
	len--;
	while (len > 0)
	{
		y = 0;
		while (s1[len] != set[y] && set[y] != '\0')
			y++;
		if (set[y] == '\0')
			return (len);
		len--;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ptr;
	size_t	start;
	size_t	final;
	size_t	x;

	x = 0;
	start = ft_strstart(s1, set);
	final = ft_strfinal(s1, set);
	if (start == 0 && final == 0)
	{
		ptr = (char *)ft_calloc(1, 1);
		if (!ptr)
			return (0);
		return (ptr);
	}
	ptr = (char *)malloc(final - start + 2);
	if (!ptr)
		return (0);
	while (x <= (final - start))
	{
		ptr[x] = s1[start + x];
		x++;
	}
	ptr[x] = '\0';
	return (ptr);
}

/* int	main(void)
{
	const char	s[] = "";
	const char	set[] = "";

	ft_strtrim(s, set);
} */
