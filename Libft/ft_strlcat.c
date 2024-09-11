/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosas-n <drosas-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 19:26:54 by drosas-n          #+#    #+#             */
/*   Updated: 2023/05/03 21:29:10 by drosas-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dsize;
	size_t	ssize;
	size_t	x;

	dsize = ft_strlen(dst);
	ssize = ft_strlen(src);
	x = 0;
	if (dsize >= size)
		ssize += size;
	else
		ssize += dsize;
	while (src[x] != '\0' && (dsize + 1) < size)
	{
		dst[dsize] = src[x];
		dsize++;
		x++;
	}
	dst[dsize] = '\0';
	return (ssize);
}
