/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 11:55:26 by sleonia           #+#    #+#             */
/*   Updated: 2020/02/12 18:54:06 by raskar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void				fill_crdn(double min_x, double max_x, \
						double min_y, t_fractol *fractol)
{
	fractol->crdn->min_x = min_x;
	fractol->crdn->max_x = max_x;
	fractol->crdn->min_y = min_y;
	fractol->crdn->max_y = fractol->crdn->min_y + \
		(fractol->crdn->max_x - fractol->crdn->min_x) * HEIGHT / WIDTH;
	fractol->crdn->shift_x = (fractol->crdn->max_x - \
			fractol->crdn->min_x) / (WIDTH - 1);
	fractol->crdn->shift_y = (fractol->crdn->max_y - \
			fractol->crdn->min_y) / (HEIGHT - 1);
	fractol->crdn->move_x = 0.0;
	fractol->crdn->move_y = 0.0;
	fractol->crdn->repeats = 30;
	fractol->crdn->rotation_x = 0;
	fractol->crdn->rotation_y = 0;
}

t_fractol			*create_struct(void)
{
	t_fractol		*fractol;

	if (!(fractol = (t_fractol *)malloc(sizeof(t_fractol))))
		exit(1);
	if (!(fractol->crdn = (t_crdn *)malloc(sizeof(t_crdn))))
		exit(1);
	fill_crdn(-2.0, 1.0, -1.0, fractol);
	if (!(fractol->cmplx = (t_cmplx *)malloc(sizeof(t_cmplx))))
		exit(1);
	fractol->color_flag = 1;
	return (fractol);
}
