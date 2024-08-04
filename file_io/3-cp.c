#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>

#define BUFFER_SIZE 1024

/**
 * handle_error - Print an error message and exit with a code.
 * @exit_code: The exit code to return.
 * @message: The error message format string.
 * @file_name: The name of the file associated with the error.
 */
void handle_error(int exit_code, const char *message, const char *file_name)
{
    if (file_name)
        dprintf(STDERR_FILENO, message, file_name);
    else
        dprintf(STDERR_FILENO, "%s\n", message);
    exit(exit_code);
}

/**
 * handle_fd_error - Print an error message for file descriptor errors.
 * @exit_code: The exit code to return.
 * @message: The error message format string.
 * @fd_value: The file descriptor value associated with the error.
 */
void handle_fd_error(int exit_code, const char *message, int fd_value)
{
    dprintf(STDERR_FILENO, message, fd_value);
    exit(exit_code);
}

/**
 * main - Copies the content of one file to another.
 * @argc: The number of command-line arguments.
 * @argv: The command-line arguments.
 *
 * Return: 0 on success, or an error code on failure.
 */
int main(int argc, char *argv[])
{
    int fd_from, fd_to, bytes_read, bytes_written;
    char buffer[BUFFER_SIZE];
    struct stat file_stat;

    if (argc != 3)
        handle_error(97, "Usage: cp %s\n", NULL);

    fd_from = open(argv[1], O_RDONLY);
    if (fd_from == -1)
        handle_error(98, "Error: Can't read from file %s\n", argv[1]);

    if (fstat(fd_from, &file_stat) == -1)
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
        handle_fd_error(100, "Error: Can't close fd %d\n", fd_from);

    if (close(fd_to) == -1)
        handle_fd_error(100, "Error: Can't close fd %d\n", fd_to);

    return (0);
}
