/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/08 17:13:30 by mwilk             #+#    #+#             */
/*   Updated: 2015/12/01 16:06:13 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		expose_hook(t_data *d)
{
	if (d->cur_frac < 6)
		draw(d);
	else if (d->cur_frac == 6)
		draw_tree(d);
	else if (d->cur_frac == 7)
		draw_triangle(d);
	mlx_do_sync(d->mlx);
	mlx_put_image_to_window(d->mlx, d->win, d->screen.img, 0, 0);
	if (d->cur_frac == 6)
		display_for_tree(d, d->tree_color_opt);
	if (d->cur_frac == 7)
		display_for_tri(d, d->tri_color_opt);
	return (0);
}

int		key_hook(int keycode, t_data *d)
{
	printf("%i\n", keycode);
	if (keycode == ESC)
		fractal_del(d);
	else if (keycode == RESET)
		init_variables(d);
	hook_key_moves(d, keycode);
	hook_key_fractal(d, keycode);
	hook_key_colors(d, keycode);
	expose_hook(d);
	return (0);
}

int		mouse_hook(int button, int x, int y, t_data *d)
{
	if (button == 1)
	{
		d->click_x = x;
		d->click_y = y;
	}
	else if (button == 5)
		d->zoom += d->zoom * 0.1f;
	else if (button == 4)
		d->zoom -= d->zoom * 0.1f;
	update_zoom(d);
	expose_hook(d);
	return (0);
}

int		mouse_hook_move(int x, int y, t_data *d)
{
	d->move_x = x;
	d->move_y = y;
	d->mouse_x = (float)x / X_WIN;
	d->mouse_y = (float)y / Y_WIN;
	d->julia_cx = -0.8 + d->mouse_x * 1.1;
	d->julia_cy = 0.3 - d->mouse_y * 0.32;
	expose_hook(d);
	return (0);
}
