/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex8.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: omontero <omontero@student.42.fr>          +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2022/03/22 18:57:45 by omontero          #+#    #+#             */
/*   Updated: 2022/03/22 19:34:07 by omontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_sort_int_tab(int *tab, int size);

void	putarr(int arr[], int size)
{
	int	i;

	i = 0;
	while (i < (size - 1))
	{
		printf("%d, ", arr[i]);
		i++;
	}
	printf("%d\n", arr[size - 1]);
}

int	main(void)
{
	int	tab[] = {10, 7, 8, 9, 1, 5};
	int	size;

	size = 6;
	printf("Original: ");
	putarr(tab, size);
	ft_sort_int_tab(tab, size);
	printf("Modified: ");
	putarr(tab, size);
}
