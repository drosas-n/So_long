/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosas-n <drosas-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 19:27:47 by drosas-n          #+#    #+#             */
/*   Updated: 2023/04/28 19:06:50 by drosas-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	char	caracter;
	int		x;

	caracter = (char)c;
	x = 0;
	while (s[x] != '\0')
	{
		if (s[x] == caracter)
			return ((char *)&s[x]);
		x++;
	}
	if (s[x] == caracter)
		return ((char *)&s[x]);
	return (0);
}
