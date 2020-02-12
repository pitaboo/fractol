/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 01:17:45 by sleonia           #+#    #+#             */
/*   Updated: 2020/02/12 18:34:27 by raskar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void			calculate_cmplx(int x, int y, t_fractol *fractol)
{
	int				i;
	bool			flag;

	i = -1;
	flag = false;
	fractol->cmplx->z_x = fractol->cmplx->c_x;
	fractol->cmplx->z_y = fractol->cmplx->c_y;
	while (++i < fractol->crdn->repeats)
	{
		fractol->cmplx->sqr_z_x = fractol->cmplx->z_x * fractol->cmplx->z_x;
		fractol->cmplx->sqr_z_y = fractol->cmplx->z_y * fractol->cmplx->z_y;
		if (fractol->cmplx->sqr_z_y + fractol->cmplx->sqr_z_x > 4)
		{
			flag = true;
			break ;
		}
		fractol->cmplx->z_y = 2 * (fractol->cmplx->z_x * \
					fractol->cmplx->z_y) + fractol->cmplx->c_y;
		fractol->cmplx->z_x = (fractol->cmplx->sqr_z_x - \
					fractol->cmplx->sqr_z_y + fractol->cmplx->c_x);
	}
	if (flag)
		main_draw(x, y, i, fractol);
}

void				mandelbrot(t_fractol *fractol)
{
	int		x;
	int		y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		fractol->cmplx->c_y = fractol->crdn->max_x - y * \
			fractol->crdn->shift_x + fractol->crdn->move_y;
		while (++x < WIDTH)
		{
			fractol->cmplx->c_x = fractol->crdn->min_x + x * \
				fractol->crdn->shift_x + fractol->crdn->move_x;
			calculate_cmplx(x, y, fractol);
		}
	}
}
