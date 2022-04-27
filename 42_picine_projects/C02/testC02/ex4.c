/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex4.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omontero <omontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 18:26:25 by omontero          #+#    #+#             */
/*   Updated: 2022/03/24 17:03:28 by omontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_lowercase(char *str);

int	main(void)
{
	char alfa[] = "abdcefghxyz";

	char especial[] = "ABC áéí !?@#$&* xyz XYZ";

	char vacio[] = "";

	printf("-----\n1 = La string solo contiene caracteres alfabeticos en minuscula\n0 = La string no contiene solo caracteres alfabeticos en minuscula\n\n");
	printf("%s = %d\n", alfa, ft_str_is_lowercase(alfa));
	printf("%s = %d\n", especial, ft_str_is_lowercase(especial));
	printf("String vacia = %d\n-----\n", ft_str_is_lowercase(vacio));

	return (0);
}
