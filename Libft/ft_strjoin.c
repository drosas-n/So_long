/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosas-n <drosas-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 19:30:20 by drosas-n          #+#    #+#             */
/*   Updated: 2023/06/27 19:46:16 by drosas-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	size_t	len;
	size_t	x;
	size_t	y;

	x = 0;
	y = 0;
	len = (ft_strlen(s1) + ft_strlen(s2));
	ptr = (char *)malloc(len + 1);
	if (!ptr)
		return (0);
	while (s1[x])
	{
		ptr[x] = s1[x];
		x++;
	}
	while (s2[y])
	{
		ptr[x + y] = s2[y];
		y++;
	}
	ptr[x + y] = '\0';
	return (ptr);
}
