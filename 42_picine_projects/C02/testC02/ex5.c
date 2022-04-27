/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex5.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omontero <omontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 18:30:49 by omontero          #+#    #+#             */
/*   Updated: 2022/03/28 09:41:44 by omontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_uppercase(char *str);

int	main(void)
{
	char alfa[] = "ABCDEFGH";

	char especial[] = "ABC abc áéí !?@#$&* xyz XYZ";

	char vacio[] = "";

	printf("-----\n1 = La string solo contiene caracteres alfabeticos en mayuscula\n0 = La string no contiene solo caracteres alfabeticos en mayuscula\n\n");
	printf("%s = %d\n", alfa, ft_str_is_uppercase(alfa));
	printf("%s = %d\n", especial, ft_str_is_uppercase(especial));
	printf("String vacia = %d\n-----\n", ft_str_is_uppercase(vacio));

	return (0);
}
