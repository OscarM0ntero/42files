/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omontero <omontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 16:27:58 by omontero          #+#    #+#             */
/*   Updated: 2023/01/07 21:13:37 by omontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "MLX42/include/MLX42/MLX42.h"
# include "get_next_line/get_next_line.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <memory.h>
# include <time.h>
# define IMG_W 64
# define IMG_H 64
//# include "MLX42/include/MLX42/MLX42.h"

/**
 * @brief Estructura de un enemigo, type 0 para estatico, 1 para V
 * y 2 para H
 * dir 1 para derecha/arriba. 0 para izquierda/abajo
 * 
 */
typedef struct s_enemy
{
	int	type;
	int	dir;
}			t_enemy;

typedef struct s_anim
{
	size_t	frame_flower;
	size_t	frame_enemy;
	size_t	frame_player;
	size_t	frame_water;
	size_t	frame_fade;
}			t_anim;

typedef struct s_coins
{
	size_t		n_coins;
	size_t		c_count;
}			t_coins;

typedef struct s_sprites_grass
{
	xpm_t	*corner_b_l;
	xpm_t	*corner_b_r;
	xpm_t	*corner_t_l;
	xpm_t	*corner_t_r;
	xpm_t	*grass;
	xpm_t	*grass_b;
	xpm_t	*grass_l;
	xpm_t	*grass_r;
	xpm_t	*grass_to;
	xpm_t	*grass_corner_b_l;
	xpm_t	*grass_corner_b_r;
	xpm_t	*grass_corner_t_l;
	xpm_t	*grass_corner_t_r;
	xpm_t	*grass_corridor_r_l;
	xpm_t	*grass_corridor_t_b;
	xpm_t	*grass_end_b;
	xpm_t	*grass_end_l;
	xpm_t	*grass_end_r;
	xpm_t	*grass_end_to;
	xpm_t	*grass_island;
}			t_sprites_grass;

typedef struct s_sprites
{
	t_sprites_grass	grass;
	xpm_t			*player;
	xpm_t			*player_back;
	xpm_t			*enemy1;
	xpm_t			*enemy2;
	xpm_t			*enemy3;
	xpm_t			*floor_1;
	xpm_t			*floor_2;
	xpm_t			*floor_3;
	xpm_t			*floor_4;
	xpm_t			*collect_1;
	xpm_t			*collect_2;
	xpm_t			*exit;
	xpm_t			*fade1;
	xpm_t			*fade2;
	xpm_t			*fade3;
	xpm_t			*fade4;
	xpm_t			*fade5;
}			t_sprites;

typedef struct s_matrix_sq
{
	char		c;
	mlx_image_t	*img;
	size_t		x;
	size_t		y;
}			t_matrix_sq;

/**
 * @brief Esta estructura guarda toda la informacion del mapa
 * Siendo path la ruta, structure el mapa en forma de array, 
 * n_chars y n_lines el numero de caracteres por linea y numero de lineas
 * y error una booleana, 0 si es correcto el mapa, 1 si es erroneo
 */
typedef struct s_map
{
	t_matrix_sq	*mtrx;
	t_matrix_sq	*mx_add;
	clock_t		clock;
	mlx_t		*mlx;
	time_t		time;
	t_sprites	sprites;
	t_anim		anim;
	t_coins		coins;
	t_enemy		**enemy;
	int			img_assigned;
	char		*path;
	char		**str;
	size_t		n_chars;
	size_t		n_lines;
	size_t		n_images;
	size_t		n_total;
	size_t		n_extra;
	size_t		n_enemies;
	int			error;
	size_t		p_x;
	size_t		p_y;
	size_t		p_look;
	int			game_over;
	int			map_finished;
	size_t		mv_count;
	int			move;
	size_t		total_frames;
	mlx_image_t	*end;
	mlx_image_t	**black;
}			t_map;

//	so_long.c
void	delete_map(t_map *map);
void	map_to_window(t_map *map);
void	generate_image(t_map *map, int32_t x, int32_t y);
void	generate_map(t_map *map);

//	so_long_new_itoa.c
char	*new_itoa(int n);

//	so_long_utils.c
void	print_map(t_map *map);
size_t	count_lines(char *p);
int		all_ones(char *line);
void	check_line(char *line, size_t n_lin, t_map *new_map);

//	so_long_start_map.c
void	assign_to_map(t_map *new_map, char *path);
t_map	read_map(char *p);
void	start(t_map *map, char *p);

//	so_long_movement.c
void	move_up(t_map *map);
void	move(int dir, t_map *map);

//	so_long_checkers.c
int		error_handler(int error);
void	check_player_coords(t_map *map);
void	check_exit_and_coin(t_map *map);
void	check_enemies(t_map *map);

//	so_long_textures.c
xpm_t	*enemy_selector(t_map *map);
xpm_t	*floor_select(t_map *map, size_t x, size_t y, size_t frame);
xpm_t	*walls_select(t_map *map, size_t x, size_t y);
xpm_t	*texture(t_map *map, size_t x, size_t y);
xpm_t	*extra_selector(t_map *map, char c);
void	regenerate_water(t_map *map);
void	regenerate_enemies(t_map *map);
#endif
