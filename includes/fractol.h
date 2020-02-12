/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raskar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 18:04:34 by raskar            #+#    #+#             */
/*   Updated: 2020/02/12 18:46:21 by raskar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

/*
** Map size
*/
# define WIDTH		1920
# define HEIGHT		1080

/*
** Event`s
*/
# define EXIT  		53
# define PLUS  		69
# define MINUS		78

/*
** List of fractol`s
*/
# define MANDELBROT 		"mandelbrot"
# define JULIA     			"julia"
# define BURNING_SHIP		"burning_ship"
# define MANDELBAR 			"mandelbar"
# define CELTIC_MANDELBAR   "celtic_mandelbar"

/*
** Key of fractol`s
*/
# define MANDELBROT_KEY				1
# define JULIA_KEY 					2
# define BURNING_SHIP_KEY 			3
# define MANDELBAR_KEY 				4
# define CELTIC_MANDELBAR_KEY 		5

/*
** Colors
*/
# define WHITE 		0xFFFFFF
# define BLOOD 		0x630101
# define YELLOW		0xA18B28
# define PURPLE 	0x9303A7
# define BLUE 		0x0B61A4
# define GREEN 		0x58E000

/*
** Library`s
*/
# include <time.h>
# include <stdbool.h>
# include <math.h>
# include "./libft/libft.h"
# include "./mlx/mlx.h"

/*
** Struct`s
*/
typedef struct		s_crdn
{
	double			max_x;
	double			min_x;
	double			max_y;
	double			min_y;
	double			shift_x;
	double			shift_y;
	double			move_x;
	double			move_y;
	int				repeats;
	double			rotation_x;
	double			rotation_y;
}					t_crdn;

typedef struct		s_mlx
{
	void			*ptr;
	void			*win;
	void			*img;
	int				*data;
	int				bpp;
	int				size_l;
	int				endn;
}					t_mlx;

typedef struct		s_cmplx
{
	int				key;
	double			c_x;
	double			c_y;
	double			z_x;
	double			z_y;
	double			sqr_z_x;
	double			sqr_z_y;
}					t_cmplx;

typedef struct		s_fractol
{
	int				key;
	int				color_flag;
	t_crdn			*crdn;
	t_mlx			*mlx;
	t_cmplx			*cmplx;
}					t_fractol;

/*
** Function`s
*/

/*
** burning_ship.c
*/
void				burning_ship(t_fractol *fractol);

/*
** mandelbar.c
*/
void				mandelbar(t_fractol *fractol);

/*
** celtic_mandelbar.c
*/
void				celtic_mandelbar(t_fractol *fractol);

/*
**	julia.c
*/
void				julia(t_fractol *fractol);

/*
** window.c
*/
int					set_window(t_fractol *fractol);

/*
** list.c
*/
int					delete_struct(int key, t_fractol *fractol);
void				fill_crdn(double min_x, double max_x, \
						double min_y, t_fractol *fractol);
t_fractol			*create_struct(void);

/*
** key_event.c
*/
void				zoom(int keycode, t_fractol *fractol);
int					key_event(int keycode, t_fractol *fractol);

/*
** mandelbrot.c
*/
void				mandelbrot(t_fractol *fractol);

/*
** draw.c
*/
void				put_pixel(int x, int y, int color, t_fractol *fractol);
void				fill_backgound(int color, t_fractol *fractol);
void				main_draw(int x, int y, int i, t_fractol *fractol);

/*
** change_fractol.c
*/
void				change_fractol(t_fractol *fractol);

/*
** mouse_event.c
*/
int					mouse_move(int x, int y, t_fractol *fractol);
int					mouse_event(int keycode, int x, int y, t_fractol *fractol);

#endif
