/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrik-sa <abrik-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 12:49:59 by abrik-sa          #+#    #+#             */
/*   Updated: 2022/04/04 09:53:44 by abrik-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>

int	ft_strlen(char *str);

int	main(void)
{
	int	result;

	char str[] = "Hola";
	result = ft_strlen(str);
	printf("%i", result);
}
