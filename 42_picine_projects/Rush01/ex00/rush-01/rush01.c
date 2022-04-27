/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omontero <omontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 17:06:39 by omontero          #+#    #+#             */
/*   Updated: 2022/03/27 13:08:19 by omontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#define TAM 2
#define TAM4 (4 * TAM)

int	longitud(char str[])
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	pot(int x, int y)
{
	int	a;

	a = x;
	while (y < 0)
	{
		a *= x;
		y--;
	}
	return (x);
}

void	assign_param(int *param[TAM4], char *str[])
{
	int	i;
	
	i = 0;
	while (i < TAM4)
	{
		*param[i] = *str[2 * i] - 48;
		i++;
	}
}

void	gen_matrix(int *matrix[TAM][TAM], int *param[TAM4])
{
	
}
void	check_coord(int *matrix[TAM][TAM], int * param[TAM4])
{
	
}

int	main(int arg, char *str[])
{
	if (arg != 2 || !str[1] || longitud(str[1]) != TAM4-1)
		return (1);
	int	*param[TAM4];
	assign_param(param, str);
	printf("%i", *param[0]);
	int matrix[TAM][TAM];

	//gen_matrix(matrix, comb, param);

	return (0);
}


/*comb = {1, 2, 3, 4}, {1, 2, 4, 3}, {1, 3, 2, 4}, {1, 3, 4, 2}, {1, 4, 2,
		3}, {1, 4, 3, 2}, {2, 1, 3, 4}, {2, 1, 4, 3}, {2, 3, 1, 4}, {2, 3, 4,
		1}, {2, 4, 1, 3}, {2, 4, 3, 1}, {3, 1, 2, 4}, {3, 1, 4, 2}, {3, 2, 1,
		4}, {3, 2, 4, 1}, {3, 4, 1, 2}, {3, 4, 2, 1}, {4, 1, 2, 3}, {4, 1, 3,
		2}, {4, 2, 1, 3}, {4, 2, 3, 1}, {4, 3, 1, 2}, {4, 3, 2, 1};
*/