#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>

char	*get_next_line(int fd)
{
	int			i;
	char		c;
	static char	*buffer;
	static char	*new_line;
	char		*new_buffer;
	ssize_t		bytes_read;

	buffer = malloc(BUFFER_SIZE);
	new_line = buffer;
	c = '\0';
	i = 0;
	while (c != '\n')
	{
		if (new_line == buffer + BUFFER_SIZE)
		{
			new_buffer = realloc(buffer, BUFFER_SIZE * 2);
			if (!new_buffer)
				break ;
			buffer = new_buffer;
			new_line = buffer + BUFFER_SIZE;
		}
		bytes_read = read(fd, new_line, 1);
		if (bytes_read <= 0)
			break ;
		c = *new_line++;
		buffer[i++] = c;
	}
	buffer[i] = '\0';
	if (i == 0)
		return (NULL);
	return (strdup(buffer));
}

int main(int argc, char *argv[])
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
