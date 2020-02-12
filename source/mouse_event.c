/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_event.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 16:19:59 by sleonia           #+#    #+#             */
/*   Updated: 2020/02/12 18:55:43 by raskar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int					mouse_move(int x, int y, t_fractol *fractol)
{
	fractol->crdn->rotation_y = (y + fractol->crdn->shift_y) / (double)HEIGHT;
	fractol->crdn->rotation_x = (x + fractol->crdn->shift_x) / (double)WIDTH;
	change_fractol(fractol);
	return (0);
}

int					mouse_event(int keycode, int x, int y, t_fractol *fractol)
{
	if (keycode == 4)
		zoom(MINUS, fractol);
	if (keycode == 5)
	{
		if (y < HEIGHT / 2)
			fractol->crdn->move_y -= (fractol->crdn->max_y - \
					fractol->crdn->min_y) / 0.1;
		if (y > HEIGHT / 2)
			fractol->crdn->move_y += (fractol->crdn->max_y - \
					fractol->crdn->min_y) / 0.1;
		if (x < WIDTH / 2 + 200)
			fractol->crdn->move_x += (fractol->crdn->max_x - \
					fractol->crdn->min_x) / 0.1;
		if (x > WIDTH / 2 + 200)
			fractol->crdn->move_x -= (fractol->crdn->max_x - \
					fractol->crdn->min_x) / 0.1;
		zoom(PLUS, fractol);
	}
	change_fractol(fractol);
	return (0);
}
