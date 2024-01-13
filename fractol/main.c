
#include "fractol.h"
#include "minilibx-linux/mlx.h"

int	main(int argc, char **argv)
{
	t_fractal	frac;

	if ( argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 10)
		||  argc == 4 && !ft_strncmp(argv[1], "julia", 5))
	{
		frac -> name = argv[1];
		if (!ft_strncmp(f_type, "julia", 5))
		{
			fractal.julia_x = atodbl(av[2]);
			fractal.julia_y = atodbl(av[3]);
		}
		fractal_init(&frac);
		fractal_render(&frac);
		mlx_loop(frac -> x_connection -> mlx_connection);
	}
	else
	{
		return (0);
	}
}
