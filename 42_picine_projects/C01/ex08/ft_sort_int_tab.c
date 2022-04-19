/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: omontero <omontero@student.42.fr>          +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2022/03/23 09:30:56 by omontero          #+#    #+#             */
/*   Updated: 2022/03/23 09:30:56 by omontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	es_menor(int a, int b)
{
	int	x;

	if (a < b)
		x = 1;
	else
		x = 0;
	return (x);
}

int	pos(int n, int *tab)
{
	int	i;

	i = 0;
	while (tab[i] != n)
		i++;
	return (i);
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (es_menor(tab[j], tab[i]) && pos(tab[i], tab) < pos(tab[j],
					tab))
			{
				k = tab[i];
				tab[i] = tab[j];
				tab[j] = k;
			}
			j++;
		}
		i++;
	}
}
