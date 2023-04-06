/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 12:57:29 by njantsch          #+#    #+#             */
/*   Updated: 2023/04/06 16:50:59 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#define BUFFER_SIZE

char	search_del(static char *buffer, char c)
{

}

char	*get_next_line(int fd)
{
	int				i;
	char			c;
	static char		*buffer;
	static char		*res;

	if (!BUFFER_SIZE || !fd)
		return (
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	res = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer || !res)
		return (NULL);
	while (1)
	{
		i = 0;
		ft_bzero(buffer, BUFFER_SIZE);


	}
}
