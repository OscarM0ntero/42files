#include <iostream>

void	PrintUppercase(char *str)
{
	char	c;

	while (*str)
	{
		c = *str;
		if (c >= 97 && c <= 122)
			c -= 32;
		std::cout << c;
		str++;
	}
}

int main(int argc, char **argv) {
	int	i;

	(void)argc;
	i = 1;
	if (argv[1])
	{
		while (argv[i])
		{
			PrintUppercase(argv[i]);
			i++;
		}
	}
	else
   		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	std::cout << "\n";
    return (0);
}
