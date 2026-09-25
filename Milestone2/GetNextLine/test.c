#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

#define BUFFER_SIZE 4

int	main(void)
{
	int fd;
	char buffer[BUFFER_SIZE + 1];
	ssize_t bytes_read;

	fd = open("example.txt", O_RDONLY);
	if (fd < 0)
		return (1);

	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
		printf("Buffer: %s\n", buffer);
	}

	close(fd);
	return (0);
}