/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 12:38:18 by sleonia           #+#    #+#             */
/*   Updated: 2020/02/12 18:53:29 by raskar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void				zoom(int keycode, t_fractol *fractol)
{
	double			min_x;
	double			max_x;
	double			min_y;

	min_x = fractol->crdn->min_x;
	max_x = fractol->crdn->max_x;
	min_y = fractol->crdn->min_y;
	if (keycode == MINUS)
		fill_crdn(min_x - 0.1, max_x + 0.1, min_y - 0.1, fractol);
	if (keycode == PLUS)
		fill_crdn(min_x + 0.1, max_x - 0.1, min_y + 0.1, fractol);
}

static void			recolor(int keycode, t_fractol *fractol)
{
	if (keycode == 82)
		fractol->color_flag = 1;
	else if (keycode == 83)
		fractol->color_flag = 2;
	else if (keycode == 84)
		fractol->color_flag = 3;
	else if (keycode == 85)
		fractol->color_flag = 4;
	else if (keycode == 86)
		fractol->color_flag = 5;
	else if (keycode == 87)
		fractol->color_flag = 6;
}

int					key_event(int keycode, t_fractol *fractol)
{
	if (keycode == EXIT)
		exit(0);
	if ((keycode >= 82 && keycode <= 89) || keycode == 91)
		recolor(keycode, fractol);
	if (keycode == 34)
		fractol->crdn->repeats++;
	if (keycode == PLUS || keycode == MINUS)
		zoom(keycode, fractol);
	mlx_clear_window(fractol->mlx->ptr, fractol->mlx->win);
	change_fractol(fractol);
	fill_backgound(0, fractol);
	return (0);
}
