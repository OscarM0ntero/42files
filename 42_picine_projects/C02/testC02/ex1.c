/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex1.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omontero <omontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 17:09:30 by omontero          #+#    #+#             */
/*   Updated: 2022/03/24 09:38:49 by omontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n);

int	main(void)
{
	char origen[] = "En un lugar de la Mancha";
	char destino[] = "Mario manda, callad Sanic's";

	printf("Origen: %s\nDestino: %s\n", origen, destino);
	ft_strncpy(destino, origen, 15);
	printf("Destino cambiado: %s\n", destino);
}
