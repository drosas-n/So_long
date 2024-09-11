/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosas-n <drosas-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 20:24:28 by drosas-n          #+#    #+#             */
/*   Updated: 2023/05/11 21:01:12 by drosas-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;
	size_t	x;

	ptr = (char *)malloc(count * size);
	if (!ptr)
		return (0);
	x = 0;
	while (x < count * size)
	{
		ptr[x] = '\0';
		x++;
	}
	return (ptr);
}
