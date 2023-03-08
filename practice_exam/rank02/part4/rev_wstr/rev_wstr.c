#include <unistd.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	int	start;
	int	end;
	int	i;
	int n;

	if (argc != 2)
		return (write(1, "\n", 1), 0);
	i = 0;
	n = 0;
	while (argv[1][i++])
		;
	start = i - 1;
	end = i - 1;
	while (start > 0)
	{
		while (argv[1][end] == ' ' || argv[1][end] == '\t')
			end--;
		start = end;
		while (start > 0 && (argv[1][start - 1] != ' ' && argv[1][start - 1] != '\t'))
			start--;
		i = start;
		printf(">s: %d e: %d<", start, end);
		if (n && argv[1][start - 1] != ' ' && (i - 1))
			write (1, "A", 1);
		while (i <= end)
		{
			n++;
			write(1, &argv[1][i], 1);
			i++;
		}
		end = start - 1;
	}
	return (0);
}
