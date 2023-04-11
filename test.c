#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>


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

// void	*ft_realloc(void *ptr, size_t size)
// {
// 	void	*new_ptr;
// 	size_t	*size_ptr;
// 	size_t	old_size;

// 	if (!ptr)
// 		return (malloc(size));
// 	if (!size)
// 	{
// 		free(ptr);
// 		return (NULL);
// 	}
// 	size_ptr = (size_t *)ptr - 1;
// 	old_size = *size_ptr;
// 	if (size <= old_size)
// 		return (ptr);
// 	new_ptr = malloc(size);
// 	if (!new_ptr)
// 		return (NULL);
// 	ft_memcpy(new_ptr, ptr, old_size);
// 	free(ptr);
// 	return (new_ptr);
// }

// char	*ft_strdup(const char *s1)
// {
// 	char *res;
// 	int i;

// 	while (s1[i])
// 		i++;
// 	res = calloc(sizeof(char), i + 1);
// 	if (!res)
// 		return (NULL);
// 	i = -1;
// 	while (s1[++i])
// 		res[i] = s1[i];
// 	return(res);
// }

// char	*buff_max(char *buffer, char *n_line, char *n_buff)
// {
// 	n_buff = ft_realloc(buffer, BUFFER_SIZE * 2);
// 	if (!n_buff)
// 		return (NULL);
// 	buffer = n_buff + BUFFER_SIZE;
// 	return (buffer);
// }

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	static int	buffer_index;
	static int	bytes_read;
	char		*line;
	int			line_length;

	buffer_index = 0;
	bytes_read = 0;
	line = NULL;
	line_length = 0;
	while (1)
	{
		if (buffer_index == bytes_read)
		{
			bytes_read = read(fd, buffer, BUFFER_SIZE);
			buffer_index = 0;
			if (bytes_read == 0)
				break ;
		}
		while (buffer_index < bytes_read && buffer[buffer_index] != '\n')
		{
			line_length++;
			buffer_index++;
		}
		line = malloc(line_length + 1);
		if (!line)
			break ;
		ft_memcpy(line, buffer, line_length);
		line[line_length] = '\0';
		if (buffer_index == bytes_read)
			break ;
		else
		{
			buffer_index++;
			break ;
		}
	}
	return (line);
}

int main(void)
{
	char *line = NULL;
	int fd = open("hello.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("%s", line);
	// line = get_next_line(fd);
	// printf("%s", line);
	// line = get_next_line(fd);
	// printf("%s", line);
	free(line);
	close(fd);
	return (0);
}
