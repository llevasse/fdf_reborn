/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 10:57:39 by llevasse          #+#    #+#             */
/*   Updated: 2023/05/25 20:45:17 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char			buff[BUFFER_SIZE + 1];
	static char		*stach[OPEN_MAX];
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX || read(fd, buff, 0) != 0)
	{
		if (stach[fd])
			return (free(stach[fd]), stach[fd] = NULL, NULL);
		return (NULL);
	}
	buff[0] = 0;
	stach[fd] = stach_empty(stach[fd], fd, buff);
	if (!stach[fd] && buff[0] != 0)
		return (NULL);
	stach[fd] = check_stach_nl(stach[fd], buff, fd);
	if (!stach[fd])
		return (NULL);
	if (stach[fd][0] == '\0')
		return (free(stach[fd]), stach[fd] = NULL, NULL);
	line = return_line(stach, fd);
	if (!line)
		return (free(stach[fd]), stach[fd] = NULL, NULL);
	if (ft_strcmp(line, stach[fd]))
		return (get_left_over(line, stach[fd]), line);
	return (free(stach[fd]), stach[fd] = NULL, line);
}

char	*return_line(char *stach[OPEN_MAX], int fd)
{
	char	*line;
	int		i;

	i = 0;
	while (stach[fd][i] != '\n' && stach[fd][i])
		i++;
	line = malloc((i + is_nl(stach[fd]) + 1) * sizeof(char));
	if (!line)
		return (NULL);
	fill_char(line, stach[fd], is_nl(stach[fd]));
	return (line);
}

char	*stach_empty(char *stach, int fd, char buff[BUFFER_SIZE])
{
	int	count;

	if (stach)
		return (stach);
	count = read(fd, buff, BUFFER_SIZE);
	buff[count] = '\0';
	if (count < 0)
		return (NULL);
	stach = malloc((count + 1) * sizeof(char));
	if (!stach)
		return (NULL);
	stach[count] = '\0';
	fill_char(stach, buff, 0);
	return (stach);
}

char	*check_stach_nl(char *stach, char buff[BUFFER_SIZE + 1], int fd)
{
	int	count;

	if (!stach)
		return (stach);
	if (!is_nl(stach))
	{
		count = read(fd, buff, BUFFER_SIZE);
		buff[count] = '\0';
		while (!is_nl(stach) && count > 0)
		{
			stach = ft_strjoin(stach, buff);
			if (!stach)
				return (NULL);
			if (!is_nl(stach))
				count = read(fd, buff, BUFFER_SIZE);
			buff[count] = '\0';
		}
		if (count <= 0)
			stach = ft_strjoin(stach, "\0");
		if (!stach)
			return (NULL);
	}
	return (stach);
}

void	get_left_over(char *line, char *stach)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (line[i] != '\n' && line[i])
		stach[i++] = 0;
	if (!line[i])
		return (free(stach));
	i++;
	while (stach[i] != '\0')
		stach[j++] = stach[i++];
	stach[j] = 0;
}
