#include "fractol.h"
#include "minilibx-linux/mlx.h"
#include <X11/X.h>
#include <stdio.h>
#include <stdlib.h>

int	close_handler(t_fractal *fractal)
{
	mlx_destroy_image(fractal-> x_connection ->mlx_connection,
					fractal->img->img);
	mlx_destroy_window(fractal->x_connection->mlx_connection,
						fractal-> x_connection->mlx_window);
	mlx_destroy_display(fractal-> x_connection->mlx_connection);
	free(fractal-> x_connection->mlx_connection);
	exit(EXIT_SUCCESS);
}

int	key_handler(int keysym, t_fractal *fractal)
{
	if (keysym == XK_Escape)
		close_handler(fractal);
	if (keysym == XK_Left)
		fractal->shift_x += (0.5 * fractal->zoom);	
	else if (keysym == XK_Right)
		fractal->shift_x -= (0.5 * fractal->zoom);	
	else if (keysym == XK_Up)
		fractal->shift_y -= (0.5 * fractal->zoom);	
	else if (keysym == XK_Down)
		fractal->shift_y += (0.5 * fractal->zoom);	
	else if (keysym == XK_plus)
		fractal->iterations_defintion += 10;
	else if (keysym == XK_minus)	
		fractal->iterations_defintion -= 10;
	fractal_render(fractal);
	return 0;
}

int	mouse_handler(int button, int x, int y, t_fractal *fractal)
{
	//Zoom in
	if (button == Button4)
	{
		fractal->zoom *= 0.95;
		if (fractal->mouse_real > 0)
		{
			if (fractal->mouse_imag > 0)
			{
				fractal->shift_x = (1 - fractal->zoom) * fractal->mouse_real * -1;
				fractal->shift_y = (1 - fractal->zoom) * fractal->mouse_imag * -1;
			}
			else
			{
				fractal->shift_x = (1 - fractal->zoom) * fractal->mouse_real * -1;
				fractal->shift_y = (1 - fractal->zoom) * fractal->mouse_imag;
			}
		}
		else
		{
			if (fractal->mouse_imag > 0)
			{
				fractal->shift_x = (1 - fractal->zoom) * fractal->mouse_real;
				fractal->shift_y = (1 - fractal->zoom) * fractal->mouse_imag * -1;
			}
			else
			{
				fractal->shift_x = (1 - fractal->zoom) * fractal->mouse_real;
				fractal->shift_y = (1 - fractal->zoom) * fractal->mouse_imag;
			}
		}
	}
	//Zoom out
	else if (button == Button5)
	{
		fractal->zoom *= 1.05;
		if (fractal->mouse_real > 0)
		{
			if (fractal->mouse_imag > 0)
			{
				fractal->shift_x = (fractal->zoom - 1) * fractal->mouse_real;
				fractal->shift_y = (fractal->zoom - 1) * fractal->mouse_imag;
			}
			else
			{
				fractal->shift_x = (fractal->zoom - 1) * fractal->mouse_real;
				fractal->shift_y = (fractal->zoom - 1) * fractal->mouse_imag * -1;
			}
		}
		else
		{
			if (fractal->mouse_imag > 0)
			{
				fractal->shift_x = (fractal->zoom - 1) * fractal->mouse_real * -1;
				fractal->shift_y = (fractal->zoom - 1) * fractal->mouse_imag;
			}
			else
			{
				fractal->shift_x = (fractal->zoom - 1) * fractal->mouse_real * -1;
				fractal->shift_y = (fractal->zoom - 1) * fractal->mouse_imag * -1;
			}
		}
	}
	fractal_render(fractal);
	return (0);
}

int	julia_track(int x, int y, t_fractal *fractal)
{
	if (!ft_strncmp(fractal->name, "julia", 5))
	{
		fractal->julia_x = (scaling(x, -2, +2, 0, WIDTH) * fractal->zoom) + fractal->shift_x;
		fractal->julia_y = (scaling(y, +2, -2, 0, HEIGHT) * fractal->zoom) + fractal->shift_y;
		fractal_render(fractal);
	}
	//salvo le coordinate mouse in una variabile e al momento dello zoom le uso per ricentrare l'immagine
	// fractal-> mouse_real = (scaling(x, -2, +2, 0, WIDTH) * fractal->zoom) + fractal->shift_x;  //TODO
	// fractal-> mouse_imag = (scaling(y, +2, -2, 0, HEIGHT)* fractal->zoom) + fractal->shift_y;  //TODO
	return 0;
}
