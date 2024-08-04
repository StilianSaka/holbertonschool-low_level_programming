#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

void handle_error(int exit_code, char *message, char *file_name)
{
	if (file_name)
		dprintf(STDERR_FILENO, message, file_name);
	else
		dprintf(STDERR_FILENO, "%s\n", message);
	exit(exit_code);
}

int main(int argc, char *argv[])
{
	int fd_from, fd_to, bytes_read, bytes_written;
	char buffer[BUFFER_SIZE];

	if (argc != 3)
		handle_error(97, "Usage: cp %s\n", NULL);
	fd_from = open(argv[1], O_RDONLY);
	if (fd_from == -1)
		handle_error(98, "Error: Can't read from file %s\n", argv[1]);
	fd_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (fd_to == -1)
		handle_error(99, "Error: Can't write to %s\n", argv[2]);
	while ((bytes_read = read(fd_from, buffer, BUFFER_SIZE)) > 0)
	{
		bytes_written = write(fd_to, buffer, bytes_read);
		if (bytes_written == -1)
			handle_error(99, "Error: Can't write to %s\n", argv[2]);
	}
	if (bytes_read == -1)
		handle_error(98, "Error: Can't read from file %s\n", argv[1]);
	if (close(fd_from) == -1)
		handle_error(100, "Error: Can't close fd\n", NULL);
	if (close(fd_to) == -1)
		handle_error(100, "Error: Can't close fd\n", NULL);

	return (0);
}
