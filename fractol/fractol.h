#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h> 
# include <stdlib.h> 
# include <unistd.h> 
# include <math.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "minilibx-linux/mlx.h"

#define WIDTH	800
#define	HEIGHT	800

#define BLACK       0x000000  // RGB(0, 0, 0)
#define WHITE       0xFFFFFF  // RGB(255, 255, 255)

typedef struct	s_complex
{
	double	x;
	double	y;
}				t_complex;

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
    int		line_length;
	int		endian;
}				t_data;

typedef struct	s_mlx_data
{
	void	*mlx_connection; 
	void	*mlx_window; 	 
} t_mlx_data

typedef struct	s_fractal
{
	char	*name;
	t_mlx_data x_connection;
	t_data	img;

	double	escape_value;
	int		iterations_defintion;
	double	shift_x;
	double	shift_y;
	double	zoom;
	double	julia_x;
	double	julia_y;
	//double	mouse_real;
	//double	mouse_imag;
}				t_fractal;


int		ft_strncmp(char *s1, char *s2, int n);
double  atodbl(char *s);
void    fractal_init(t_fractal *fractal);
void	events(t_fractal *fractal);
void	data(t_fractal *fractal);
void    fractal_render(t_fractal *fractal);
void	frac_pixel(int x, int y, t_fractal *fractal);
void	mandel_vs_julia(t_complex *z, t_complex *c, t_fractal *fractal);
void	my_pixel_put(int x, int y, t_img *img, int color);
double		scaling(double unscaled_num, double new_min, double new_max, double old_min, double old_max);
t_complex   sum_complex(t_complex z1, t_complex z2);
t_complex   square_complex(t_complex z);
int			key_handler(int keysym, t_fractal *fractal);
int    	close_handler(t_fractal *fractal);
int		mouse_handler(int button, int x, int y, t_fractal *fractal);
int		julia_track(int x, int y, t_fractal *fractal);

#endif
