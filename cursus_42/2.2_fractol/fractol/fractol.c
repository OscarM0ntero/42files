/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omontero <omontero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 16:27:53 by omontero          #+#    #+#             */
/*   Updated: 2022/12/19 13:40:45 by omontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <memory.h>
#define WIDTH 1280
#define HEIGHT 768
#define IMG_WIDTH 64
#define IMG_HEIGHT 64

mlx_image_t	*g_img;

void	hook(void *param)
{
	mlx_t	*mlx;

	mlx = param;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_S))
		g_img->instances[0].y -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_W))
		g_img->instances[0].y += 5;
	if (mlx_is_key_down(mlx, MLX_KEY_D))
		g_img->instances[0].x -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_A))
		g_img->instances[0].x += 5;
}

int	main(void)
{
	mlx_t	*mlx;

	mlx = mlx_init(WIDTH, HEIGHT, "Fract'ol", true);
	if (!mlx)
		exit(EXIT_FAILURE);
	g_img = mlx_new_image(mlx, IMG_WIDTH, IMG_HEIGHT);
	memset(g_img->pixels, 255, g_img->width * g_img->height * sizeof(int));
	mlx_image_to_window(mlx, g_img, (WIDTH - IMG_WIDTH) / 2, (HEIGHT - IMG_HEIGHT) / 2);
	mlx_loop_hook(mlx, &hook, mlx);
	mlx_put_pixel(g_img, 10, 10, 0x00FF0000);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}

/*
int	main(int argc, char **argv)
{
	void	*mlx;

	mlx = mlx_init();
	if (!mlx)
		return (1);
	mlx_new_w
}
*/
