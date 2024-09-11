/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosas-n <drosas-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 17:24:28 by drosas-n          #+#    #+#             */
/*   Updated: 2023/06/30 20:19:21 by drosas-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_operation(long int n)
{
	int	x;

	x = 0;
	while (n > 9)
	{
		n /= 10;
		x++;
	}
	return (x + 1);
}

char	*ft_itoa(int n)
{
	char		*ptr;
	int			count;
	long int	n2;

	n2 = n;
	if (n < 0)
		n2 *= -1;
	count = ft_operation(n2);
	if (n < 0)
		count += 1;
	ptr = (char *)malloc((count + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	ptr[count--] = '\0';
	while (count >= 0)
	{
		ptr[count--] = (n2 % 10) + '0';
		n2 /= 10;
	}
	if (n < 0)
		ptr[0] = '-';
	return (ptr);
}

/* int	main(void)
{
	int	n;

	n = -9;
	ft_itoa(n);
} */
