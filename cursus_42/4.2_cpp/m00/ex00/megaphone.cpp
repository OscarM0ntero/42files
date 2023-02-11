#include <iostream>

void	PrintUppercase(char *str)
{
	while (*str)
	{
		*str = std::toupper(*str);
		std::cout << *str;
		str++;
	}
}

int main(int argc, char **argv) {
	int	i;

	(void)argc;
	i = 1;
	if (argv[i])
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
