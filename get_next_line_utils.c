/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 14:33:32 by njantsch          #+#    #+#             */
/*   Updated: 2023/04/06 18:40:41 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc(count * size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, size * count);
	return (ptr);
}

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	i = 0;
	ptr = (unsigned char *) s;
	while (i < n)
	{
		ptr[i] = '\0';
		i++;
	}
}
char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*dest;

	len = ft_strlen(s1) + 1;
	dest = malloc(len);
	if (dest == NULL)
		return (NULL);
	ft_memcpy(dest, s1, len);
	return (dest);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dest;
	unsigned char	*source;

	i = 0;
	dest = (unsigned char *) dst;
	source = (unsigned char *) src;
	if (dest == 0 && src == 0)
		return (0);
	while (i < n)
	{
		dest[i] = source[i];
		i++;
	}
	return (dest);
}

void	*ft_realloc(void *ptr, size_t size)
{
	void *new_ptr;
	size_t *size_ptr;
	size_t old_size;

	size_ptr = (size_t *)ptr;
	if (!size)
	{
		free(ptr);
		return (NULL);
	}
	if (size <= size_ptr)
		return (ptr);
	new_ptr = malloc(size);
	if (!ptr)
		return (new_ptr);
	old_size = size_ptr;
	ft_memcpy(new_ptr, ptr, old_size);
	free(ptr);
	return (new_ptr);
}
