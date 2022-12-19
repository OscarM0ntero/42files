/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omontero <omontero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 16:27:58 by omontero          #+#    #+#             */
/*   Updated: 2022/12/19 14:15:49 by omontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "MLX42/include/MLX42/MLX42.h"
# include "get_next_line/get_next_line.h"
//# include "MLX42/include/MLX42/MLX42.h"

/**
 * @brief Esta estructura guarda toda la informacion del mapa
 * Siendo path la ruta, structure el mapa en forma de array, 
 * n_chars y n_lines el numero de caracteres por linea y numero de lineas
 * y error una booleana, 0 si es correcto el mapa, 1 si es erroneo
 */
typedef struct s_map
{
	char	*path;
	char	**structure;
	size_t	n_chars;
	size_t	n_lines;
	int		error;
}			t_map;
#endif