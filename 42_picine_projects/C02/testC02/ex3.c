/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex3.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omontero <omontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 17:46:49 by omontero          #+#    #+#             */
/*   Updated: 2022/03/24 17:03:47 by omontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_numeric(char *str);

int	main(void)
{
	char num[] = "17235673450";

	char especial[] = "4524 hbwb 734 h?¿ 5435";

	char vacio[] = "";

	printf("-----\n1 = La string solo contiene caracteres numericos\n0 = La string no contiene solo caracteres numericos\n\n");
	printf("%s = %d\n", num, ft_str_is_numeric(num));
	printf("%s = %d\n", especial, ft_str_is_numeric(especial));
	printf("String vacia = %d\n-----\n", ft_str_is_numeric(vacio));

	return (0);
}