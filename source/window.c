/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 12:34:25 by sleonia           #+#    #+#             */
/*   Updated: 2020/02/12 18:57:32 by raskar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int			close_window(void *param)
{
	(void)param;
	exit(0);
}

static void			init_mlx(t_fractol *fractol)
{
	if (!(fractol->mlx = (t_mlx *)malloc(sizeof(t_mlx))))
		exit(1);
	if (!(fractol->mlx->ptr = mlx_init()))
		exit(1);
	if (!(fractol->mlx->win = mlx_new_window(fractol->mlx->ptr, \
						WIDTH, HEIGHT, "Raskar")))
		exit(1);
	if (!(fractol->mlx->img = mlx_new_image(fractol->mlx->ptr, WIDTH, HEIGHT)))
		exit(1);
	if (!(fractol->mlx->data = (int *)mlx_get_data_addr(fractol->mlx->img, \
		&(fractol->mlx->bpp), &(fractol->mlx->size_l), &(fractol->mlx->endn))))
		exit(1);
}

int					set_window(t_fractol *fractol)
{
	init_mlx(fractol);
	change_fractol(fractol);
	mlx_hook(fractol->mlx->win, 17, 0, close_window, fractol);
	mlx_hook(fractol->mlx->win, 2, 0, key_event, fractol);
	mlx_hook(fractol->mlx->win, 4, 0, mouse_event, fractol);
	mlx_hook(fractol->mlx->win, 6, 0, mouse_move, fractol);
	mlx_loop(fractol->mlx->ptr);
	return (0);
}
