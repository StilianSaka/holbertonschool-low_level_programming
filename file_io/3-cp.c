#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define BUFSIZE 1024

/**
 * main - entry point
 * @ac: argument count
 * @av: array of argument tokens
 * Return: 0 on success, exits with error codes otherwise
 */
int main(int ac, char *av[])
{
	int fd_from, fd_to, rd_stat, wr_stat;
	mode_t perm = S_IRUSR | S_IWUSR | S_IWGRP | S_IRGRP | S_IROTH;
	char buffer[BUFSIZE];

	if (ac != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	fd_from = open(av[1], O_RDONLY);
	if (fd_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", av[1]);
		exit(98);
	}

	fd_to = open(av[2], O_CREAT | O_WRONLY | O_TRUNC, perm);
	if (fd_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", av[2]);
		close(fd_from);
		exit(99);
	}

	while ((rd_stat = read(fd_from, buffer, BUFSIZE)) > 0)
	{
		wr_stat = write(fd_to, buffer, rd_stat);
		if (wr_stat != rd_stat)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", av[2]);
			close(fd_from);
			close(fd_to);
			exit(99);
		}
	}

	if (rd_stat == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", av[1]);
		close(fd_from);
		close(fd_to);
		exit(98);
	}

	if (close(fd_from) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_from);
		close(fd_to); /* Ensure fd_to is closed before exiting */
		exit(100);
	}

	if (close(fd_to) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_to);
		exit(100);
	}

	return (0);
}
