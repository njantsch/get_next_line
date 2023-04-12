/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 12:57:29 by njantsch          #+#    #+#             */
/*   Updated: 2023/04/12 18:02:30 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>

char	*buff_trim()

char	*get_line(char *buffer)
{
	int		i;
	char	*new;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	new = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		new[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
	{
		new[i] = buffer[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	*check_new_line(char *buffer, char c)
{
	int	i;

	i = 0;
	if (!buffer)
		return (0);
	while (buffer[i] != '\0')
	{
		if (buffer[i] == c)
			return (&buffer[i]);
		i++;
	}
	if (buffer[i] == c)
		return (&buffer[i]);
	return (0);
}

char	*get_next_line(int fd)
{
	int			bytes_read;
	static char	*buffer;
	char		*new_buff;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	new_buff = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!new_buff)
		return (NULL);
	bytes_read = 1;
	while (!check_new_line(buffer, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, new_buff, BUFFER_SIZE);
		new_buff[bytes_read] = '\0';
		buffer = ft_strjoin(buffer, new_buff);
	}
	free(new_buff);
	line = get_line(buffer);
	buffer = buff_trim(buffer)
	return (line);
}

#include <stdio.h>
#include <fcntl.h>
int main(void)
{
	char *line = NULL;
	int fd = open("hello.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("%s", line);
	line = get_next_line(fd);
	printf("%s", line);
	// line = get_next_line(fd);
	// printf("%s", line);
	free(line);
	close(fd);
	return (0);
}
