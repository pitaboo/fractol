/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_fractol.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 09:09:39 by sleonia           #+#    #+#             */
/*   Updated: 2020/02/12 18:47:41 by raskar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void				change_fractol(t_fractol *fractol)
{
	if (fractol->key == MANDELBROT_KEY)
		mandelbrot(fractol);
	else if (fractol->key == JULIA_KEY)
		julia(fractol);
	else if (fractol->key == BURNING_SHIP_KEY)
		burning_ship(fractol);
	else if (fractol->key == MANDELBAR_KEY)
		mandelbar(fractol);
	else if (fractol->key == CELTIC_MANDELBAR_KEY)
		celtic_mandelbar(fractol);
	mlx_put_image_to_window(fractol->mlx->ptr, fractol->mlx->win, \
										fractol->mlx->img, 0, 0);
	fill_backgound(0, fractol);
}
