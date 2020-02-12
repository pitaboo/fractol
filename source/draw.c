/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raskar <raskar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 11:09:30 by raskar            #+#    #+#             */
/*   Updated: 2020/02/12 18:50:14 by raskar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

void				put_pixel(int x, int y, int color, t_fractol *fractol)
{
	fractol->mlx->data[y * WIDTH + x] = color;
}

void				fill_backgound(int color, t_fractol *fractol)
{
	int				x;
	int				y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			put_pixel(x, y, color, fractol);
			x++;
		}
		y++;
	}
}

void				main_draw(int x, int y, int i, t_fractol *fractol)
{
	if (fractol->color_flag == 1)
		put_pixel(x, y, (((i * 255 / fractol->crdn->repeats) << 7) + ((i * 255 / fractol->crdn->repeats) << 7) + i * 255 / fractol->crdn->repeats), fractol);
	if (fractol->color_flag == 2)
		put_pixel(x, y, (((i * 100 / fractol->crdn->repeats) << 8) + ((i / fractol->crdn->repeats) << 1) + i * 1000 / fractol->crdn->repeats), fractol);
	if (fractol->color_flag == 3)
		put_pixel(x, y, (((i * 300 / fractol->crdn->repeats) << 8) + ((i / fractol->crdn->repeats) << 8) + i * 105 / fractol->crdn->repeats), fractol);
	if (fractol->color_flag == 4)
		put_pixel(x, y, (((i * 400 / fractol->crdn->repeats) << 8) + ((i / fractol->crdn->repeats) << 8) + i * 105 / fractol->crdn->repeats), fractol);
	if (fractol->color_flag == 5)
		put_pixel(x, y, (((i * 500 / fractol->crdn->repeats) << 8) + ((i / fractol->crdn->repeats) << 8) + i * 105 / fractol->crdn->repeats), fractol);
	if (fractol->color_flag == 6)
		put_pixel(x, y, (((i * 600 / fractol->crdn->repeats) << 8) + ((i / fractol->crdn->repeats) << 8) + i * 105 / fractol->crdn->repeats), fractol);
}
