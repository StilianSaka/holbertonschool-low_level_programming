#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

#define BUFFER_SIZE 1024

/**
 * closefd - closes a file descriptor
 * @fd: file descriptor
 */
void closefd(int fd)
{
	if (close(fd) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * main - Entry point
 * @argc: number of arguments supplied to argv
 * @argv: array of arguments
 * Return: 0 on success, or an appropriate error code on failure
 */
int main(int argc, char *argv[])
{
	int fdr, fdw, n, m;
	char buffer[BUFFER_SIZE];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	fdr = open(argv[1], O_RDONLY);
	if (fdr == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}

	fdw = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fdw == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		closefd(fdr);
		exit(99);
	}

	while ((n = read(fdr, buffer, BUFFER_SIZE)) > 0)
	{
		m = write(fdw, buffer, n);
		if (m != n)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
			closefd(fdr);
			closefd(fdw);
			exit(99);
		}
	}

	if (n == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		closefd(fdr);
		closefd(fdw);
		exit(98);
	}

	closefd(fdr);
	closefd(fdw);

	return (0);
}
