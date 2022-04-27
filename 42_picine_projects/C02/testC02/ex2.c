/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex2.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omontero <omontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 17:26:56 by omontero          #+#    #+#             */
/*   Updated: 2022/03/24 17:04:06 by omontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_alpha(char *str);

int	main(void)
{
	char alfa[] = "ABCabcxyzXYZ";

	char especial[] = "ABC áéí !?@#$&* xyz XYZ";

	char vacio[] = "";
	
	printf("-----\n1 = La string solo contiene caracteres alfabeticos\n0 = La string no contiene solo caracteres alfabeticos\n\n");
	printf("%s = %d\n", alfa, ft_str_is_alpha(alfa));
	printf("%s = %d\n", especial, ft_str_is_alpha(especial));
	printf("String vacia = %d\n-----\n", ft_str_is_alpha(vacio));

	return (0);
}