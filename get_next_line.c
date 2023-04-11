/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 12:57:29 by njantsch          #+#    #+#             */
/*   Updated: 2023/04/11 17:59:38 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*buff_max(char *buffer, char *n_line, char *n_buff, int line_len)
{
	n_buff = ft_realloc(buffer, line_len + BUFFER_SIZE);
	if (!n_buff)
		return (NULL);
	buffer = n_buff;
	n_line = buffer + BUFFER_SIZE;
	return (n_line);
}

char	*read_loop(char *buffer, char *n_line, char *n_buff, int line_len)
{
	int			buffer_index;
	static int	bytes_read;

	line_len = 0;
	buffer_index = 0;
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	while (buffer_index < bytes_read && buffer[buffer_index] != '\n')
	{
		line_len++;
		buffer_index++;
	}
	if (buffer[buffer_index] == '\n')
	{

	}
	n_line = buff_max(buffer, n_line, n_buff, line_len);


}

char	*get_next_line(int fd)
{
	static int	line_len;
	static char	*buffer;
	char		*n_line;
	char		*n_buff;

	n_buff = NULL;
	line_len = 0;
	buffer = ft_calloc(BUFFER_SIZE, sizeof(char));
	n_line = buffer;
	while (1)
	{
		n_buff = read_loop(buffer, n_line, n_buff, line_len);
		if (!n_buff)
			return (NULL);
		else if ()

	}
	*buffer = '\0';
	if (i == 0)
		return (NULL);
	return (ft_strdup(buffer));
}
