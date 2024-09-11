/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosas-n <drosas-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 20:57:15 by drosas-n          #+#    #+#             */
/*   Updated: 2023/05/11 21:24:14 by drosas-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	size_t	x;

	ptr = (char *)malloc(ft_strlen(s1)+1);
	x = 0;
	if (!ptr)
		return (0);
	while (x <= (ft_strlen(s1)))
	{
		ptr[x] = s1[x];
		x++;
	}
	return (ptr);
}
