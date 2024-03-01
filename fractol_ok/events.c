/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosenza <gcosenza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 18:39:56 by gcosenza          #+#    #+#             */
/*   Updated: 2024/03/01 07:42:07 by gcosenza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "minilibx-linux/mlx.h"
#include <X11/X.h>
#include <stdio.h>
#include <stdlib.h>

int	close_handler(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx_connection, fractal->img.img_ptr);
	mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
	mlx_destroy_display(fractal->mlx_connection);
	free(fractal->mlx_connection);
	exit(EXIT_SUCCESS);
}

int	julia_mode(int keysym, t_fractal *fractal)
{
	if (keysym == 119)
		fractal->julia_x -= (0.09 * fractal->zoom);
	else if (keysym == 101)
		fractal->julia_x += (0.25 * fractal->zoom);
	else if (keysym == 97)
		fractal->julia_y -= (0.09 * fractal->zoom);
	else if (keysym == 113)
		fractal->julia_y += (0.09 * fractal->zoom);
	return (0);
}

int	key_handler(int keysym, t_fractal *fractal)
{
	if (keysym == J_KEY)
	{
		fractal->julia_x = 0;
		fractal->julia_y = 0;
		fractal->name = "julia";
	}
	if (keysym == M_KEY)
		fractal->name = "mandelbrot";
	if (keysym == B_KEY)
		fractal->name = "bonus";
	if ((!ft_strncmp (fractal->name, "julia", 6))
		&& (keysym == 119 || keysym == 101 || keysym == 97 || keysym == 113))
		julia_mode(keysym, fractal);
	if (keysym == XK_Left || keysym == XK_Right || keysym == XK_Up
		|| keysym == XK_Down)
		arrow(keysym, fractal);
	if (keysym == 65307)
		close_handler(fractal);
	else if (keysym == 112)
		fractal->iterations_defintion += 10;
	else if (keysym == 111)
		fractal->iterations_defintion -= 10;
	mlx_clear_window (fractal->mlx_connection, fractal->mlx_window);
	fractal_render(fractal);
	return (0);
}

int	mouse_handler(int button, int x, int y, t_fractal *fractal)
{
	double	mouse_real;
	double	mouse_imag;
	double	n_mouse_real;
	double	n_mouse_imag;

	mouse_real = map (x, -2, 2, WDT) * fractal->zoom + fractal->shift_x;
	mouse_imag = map (y, 2, -2, HGT) * fractal->zoom + fractal->shift_y;
	if (button == Button4)
		fractal->zoom *= 0.95;
	else if (button == Button5)
		fractal->zoom *= 1.05;
	n_mouse_real = map (x, -2, 2, WDT) * fractal->zoom + fractal->shift_x;
	n_mouse_imag = map (y, 2, -2, HGT) * fractal->zoom + fractal->shift_y;
	fractal->shift_x += mouse_real - n_mouse_real;
	fractal->shift_y += mouse_imag - n_mouse_imag;
	fractal_render (fractal);
	return (0);
}

int	mouse_track(int x, int y, t_fractal *fractal)
{
	fractal->mouse_imag = y;
	fractal->mouse_real = x;
	return (0);
}
