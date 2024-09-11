/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosas-n <drosas-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 14:21:37 by drosas-n          #+#    #+#             */
/*   Updated: 2023/06/30 20:12:16 by drosas-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	ft_counter(char const *s, char c)
{
	int	x;
	int	count;

	x = 0;
	count = 0;
	while (s[x] != '\0')
	{
		if ((s[x] != c && s[x + 1] == c) || (s[x] != c && s[x + 1] == '\0'))
			count++;
		x++;
	}
	return (count);
}

static char	**ft_freesplit(char **ptr, int words)
{
	while (words > 0)
	{
		words--;
		free(ptr[words]);
	}
	free(ptr);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		x;
	int		letters;
	int		words;
	char	**ptr;

	x = -1;
	letters = 0;
	words = -1;
	ptr = (char **)malloc(sizeof(char *) * (ft_counter(s, c) + 1));
	if (!ptr)
		return (0);
	while (s[++x])
	{
		if (s[x] != c)
			letters++;
		if ((s[x] != c && s[x + 1] == c) || (s[x] != c && s[x + 1] == '\0'))
		{
			ptr[++words] = ft_substr(&s[x - (letters - 1)], 0, letters);
			if (!ptr[words])
				return (ft_freesplit(ptr, words));
			letters = 0;
		}
	}
	ptr[++words] = NULL;
	return (ptr);
}

/* int	main(void)
{
	char const	s[] = "  again";
	char		c;

	c = ' ';
	ft_split(s, c);
}
 */