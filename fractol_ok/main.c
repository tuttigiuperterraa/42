/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosenza <gcosenza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 19:15:46 by gcosenza          #+#    #+#             */
/*   Updated: 2024/03/01 08:05:24 by gcosenza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_fractal	fractal;

	if ((2 == argc && !ft_strncmp(argv[1], "mandelbrot", 11)
			|| 4 == argc && !ft_strncmp(argv[1], "julia", 6))
		|| (2 == argc && !ft_strncmp(argv[1], "bonus", 6)))
	{
		fractal.name = argv[1];
		if (!ft_strncmp(fractal.name, "julia", 5))
		{
			fractal.julia_x = atod(argv[2]);
			fractal.julia_y = atod(argv[3]);
		}
		fractal_init(&fractal);
		fractal_render(&fractal);
		mlx_loop(fractal.mlx_connection);
	}
	else
		ft_putstr(ERROR_MESSAGE);
}
