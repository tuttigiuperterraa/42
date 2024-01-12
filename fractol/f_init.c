#include "fractol.h"
#include "minilibx-linux/mlx.h"
#include <stdio.h>
#include <stdlib.h>

void	data(t_fractal *fractal)
{
	fractal->escape_value = 4;
	fractal->iterations_defintion = 42; 
	fractal->shift_x = 0.0;
	fractal->shift_y = 0.0;
	fractal->zoom = 1.0;
}

void	events(t_fractal *fractal)
{
	mlx_hook(fractal-> x_connection ->mlx_window,
			KeyPress,
			KeyPressMask,
			key_handler,
			fractal);
	mlx_hook(fractal-> x_connection ->mlx_window,
			ButtonPress,
			ButtonPressMask,
			mouse_handler,
			fractal);
	mlx_hook(fractal-> x_connection ->mlx_window,
			DestroyNotify,
			StructureNotifyMask,
			close_handler,
			fractal);
	mlx_hook(fractal-> x_connection ->mlx_window,
			MotionNotify,
			PointerMotionMask,
			julia_track,
			fractal);
}

void	fractal_init(t_fractal *fractal)
{
	fractal-> x_connection -> mlx_connection = mlx_init();
	if (NULL == fractal-> x_connection ->mlx_connection)
		malloc_error();
	fractal-> x_connection -> mlx_window = mlx_new_window(fractal-> x_connection ->mlx_connection,
										WIDTH,
										HEIGHT,
										fractal->name);
	if (NULL == fractal-> x_connection ->mlx_window)
	{
		mlx_destroy_display(fractal-> x_connection ->mlx_connection);
		free(fractal-> x_connection ->mlx_connection);
		return (NULL);
	}
	fractal->img ->img = mlx_new_image(fractal-> x_connection ->mlx_connection,
										WIDTH, HEIGHT);
	if (NULL == fractal->img ->img)
	{
		mlx_destroy_window(fractal-> x_connection->mlx_connection, fractal-> x_connection ->mlx_window);
		mlx_destroy_display(fractal-> x_connection ->mlx_connection);
		free(fractal-> x_connection ->mlx_connection);
		malloc_error();
	}
	fractal->img ->addr = mlx_get_data_addr(fractal->img ->img,
												&fractal->img ->bits_per_pixel,
												&fractal->img ->line_length,
												&fractal->img ->endian);
	events(fractal);
	data(fractal);
}