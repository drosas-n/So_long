/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosas-n <drosas-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 19:20:35 by drosas-n          #+#    #+#             */
/*   Updated: 2024/07/01 19:06:19 by drosas-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*get_cleaner(char *stat_str)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	while (stat_str[i] != '\0' && stat_str[i] != '\n')
		i++;
	if (stat_str[i] == '\0')
	{
		free(stat_str);
		return (NULL);
	}
	temp = ft_calloc_gnl((ft_strlen_gnl(stat_str) - i + 1), sizeof(char));
	i++;
	j = 0;
	while (stat_str[i] != '\0')
		temp[j++] = stat_str[i++];
	free(stat_str);
	if (temp[0] == '\0')
	{
		free(temp);
		return (NULL);
	}
	return (temp);
}

static char	*get_good_line(char *stat_str)
{
	char	*temp;
	int		i;

	i = 0;
	if (stat_str[i] == '\0')
		return (NULL);
	while (stat_str[i] != '\0' && stat_str[i] != '\n')
		i++;
	temp = ft_calloc_gnl((i + 1 + ft_strchr_gnl(stat_str, '\n')), sizeof(char));
	i = 0;
	while (stat_str[i] != '\0' && stat_str[i] != '\n')
	{
		temp[i] = stat_str[i];
		i++;
	}
	if (stat_str[i] != '\0' && stat_str[i] == '\n')
		temp[i++] = '\n';
	return (temp);
}

static char	*get_strjoin2(char *stat_str, char *temp)
{
	char	*newline;

	newline = ft_strjoin_gnl(stat_str, temp);
	free(stat_str);
	return (newline);
}

static char	*get_all(int fd, char *stat_str)
{
	char	*temp;
	int		reader;

	if (!stat_str)
		stat_str = ft_calloc_gnl(1, sizeof(char));
	temp = ft_calloc_gnl((BUFFER_SIZE + 1), sizeof(char));
	reader = 1;
	while (reader > 0)
	{
		reader = read(fd, temp, BUFFER_SIZE);
		if (reader < 0)
		{
			free(temp);
			return (NULL);
		}
		temp[reader] = '\0';
		stat_str = get_strjoin2(stat_str, temp);
		if (ft_strchr_gnl(temp, '\n'))
			break ;
	}
	free(temp);
	return (stat_str);
}

char	*get_next_line(int fd)
{
	static char	*stat_str[1024];
	char		*good_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (read(fd, 0, 0) < 0)
	{
		if (stat_str[fd] != NULL)
		{
			free(stat_str[fd]);
			stat_str[fd] = NULL;
		}
		return (NULL);
	}
	stat_str[fd] = get_all(fd, stat_str[fd]);
	if (stat_str[fd] == NULL)
		return (free(stat_str[fd]), stat_str[fd] = NULL, NULL);
	good_line = get_good_line(stat_str[fd]);
	if (good_line == NULL)
		return (free(stat_str[fd]), stat_str[fd] = NULL, NULL);
	stat_str[fd] = get_cleaner(stat_str[fd]);
	if (stat_str[fd] == NULL)
		return (free(stat_str[fd]), stat_str[fd] = NULL, good_line);
	return (good_line);
}

/* int	main(void)
{
	int		fichero1;
	int		fichero2;
	int		fichero3;
	char	*line;

	fichero1 = open("archivo.txt", 0);
	fichero2 = open("archivo2.txt", O_RDONLY);
	fichero3 = open("archivo3.txt", O_RDONLY);
	line = get_next_line(fichero1);
	while (line != NULL)
	{
		printf("%s", line);
		line = get_next_line(fichero1);
	}
	printf("\n\n");
	line = get_next_line(fichero2);
	while (line != NULL)
	{
		printf("%s", line);
		line = get_next_line(fichero2);
	}
	printf("\n\n");
	line = get_next_line(fichero3);
	while (line != NULL)
	{
		printf("%s", line);
		line = get_next_line(fichero3);
	}
	printf("\n\n");
	close(fichero1);
	close(fichero2);
	close(fichero3);
	free(line);
} */
