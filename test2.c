#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>

char	*buff_max(char *buffer, char *n_line, char *n_buff)
{
	n_buff = realloc(buffer, BUFFER_SIZE * 2);
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

	buffer = calloc(BUFFER_SIZE, sizeof(char));
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
	return (strdup(buffer));
}

int main(int argc, char *argv[])
{
	char *line = NULL;
	int fd = open("hello.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("%s", line);
	line = get_next_line(fd);
	printf("%s", line);
	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	close(fd);
	return (0);
}
