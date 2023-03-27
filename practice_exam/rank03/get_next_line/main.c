#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main (void)
{
	int fd = open("hola.txt", O_RDONLY);

	char *s;

	s = get_next_line(fd);
	do {
		printf("%s", s);
		s = get_next_line(fd);
	} while (s);
	close(fd);
	return (0);
}
