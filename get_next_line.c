/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 12:57:29 by njantsch          #+#    #+#             */
/*   Updated: 2023/04/06 19:04:26 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#define BUFFER_SIZE

char	*buff_max(char *buffer, char *n_line, char *n_buff)
{
	n_buff = ft_realloc(buffer, BUFFER_SIZE * 2);
	if (!n_buff)
		return (NULL);
	buffer = n_buff;
	n_line = buffer + BUFFER_SIZE;
	return (n_line);
}

char	*get_next_line(int fd)
{
	int			i;
	char		c;
	static char	*buffer;
	static char	*n_line;
	char		*n_buff;

	buffer = ft_calloc(BUFFER_SIZE, sizeof(char));
	n_line = buffer;
	c = '\0';
	i = 0;
	while (c != '\n')
	{
		if (n_line == buffer + BUFFER_SIZE)
			if (buff_max(buffer, n_line, n_buff) == NULL)
				break ;
		read(fd, n_line, 1);
		c = *n_line++;
		buffer[i++] = c;
	}
	buffer[i] = '\0';
	if (i == 0)
		return (NULL);
	return (ft_strdup(buffer));
}
