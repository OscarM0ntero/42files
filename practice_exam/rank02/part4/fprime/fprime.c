#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//	Return 1 if n is prime, 0 if not
int is_prime(int n)
{
	int i = 2;
	int c = 0;

	while (i <= n/2)
	{
		if (n % i == 0)
			c++;
		i++;
	}
	if (!c)
		return (1);
	else
		return (0);
}

int main (int argc, char **argv)
{
	if (argc != 2)
		return(printf("\n"), 0);
	int num = atoi(argv[1]);
	int tmp = num;
	int i = 2;

	if (num == 1)
		return(printf("1\n"), 0);
	else if (is_prime(num))
		return(printf("%d\n", num), 0);

	while (i <= tmp)
	{
		printf("%d", i);
		if (is_prime(i) && tmp % i == 0)
		{
			printf("%d", i);
			tmp /= i;
			if (tmp != 1)
				printf("*");
			i = 1;
		}
			i++;
	}
	printf("\n");
	return 0;
}
