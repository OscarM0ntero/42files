/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex6.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omontero <omontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 18:43:34 by omontero          #+#    #+#             */
/*   Updated: 2022/03/28 09:52:59 by omontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_printable(char *str);

int	main(void)
{
	char alfa[] = "ABC abc !?@#$&* xyz XYZ";

	char especial[] = "ABC abc \127 áéí \27 !?@#$&* xyz XYZ";

	char vacio[] = "";

	printf("-----\n1 = La string solo contiene caracteres imprimibles\n0 = La string no contiene solo caracteres imprimibles\n\n");
	printf("%s = %d\n", alfa, ft_str_is_printable(alfa));
	printf("%s = %d\n", especial, ft_str_is_printable(especial));
	printf("String vacia = %d\n-----\n", ft_str_is_printable(vacio));

	return (0);
}
