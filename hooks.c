/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/08 17:13:30 by mwilk             #+#    #+#             */
/*   Updated: 2015/05/13 20:14:09 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		expose_hook(t_data *d)
{
	draw(d);
	mlx_put_image_to_window(d->mlx, d->win, d->screen.img, 0, 0);
	return (0);
}

int		key_hook(int keycode, t_data *d)
{
	if (keycode == ESC)
		fractal_del(d);
	else if (keycode == LEFT)
		d->os_x -= 0.1f / d->zoom;
	else if (keycode == RIGHT)
		d->os_x += 0.1f / d->zoom;
	else if (keycode == UP)
		d->os_y -= 0.1f / d->zoom;
	else if (keycode == DOWN)
		d->os_y += 0.1f / d->zoom;
	else if (keycode == RESET)
		init_variables(d);
	else if (keycode == TAB)
		d->current_frac = (d->current_frac + 1) % NB_FRACTAL;
	//key_press_color_fractal(keycode, e);
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

int			mouse_hook_move(int x, int y, t_data *d)
{
	d->move_x = x;
	d->move_y = y;
	d->mouse_x = x / (double)X_WIN;
	d->mouse_y = y / (double)Y_WIN;
	d->julia_cx = -0.8 + d->mouse_x * 1.1;
	d->julia_cy = 0.3 - d->mouse_y * 0.32;
	if (x % 5 == 0 || y % 5 == 0)
		expose_hook(d);
	return (0);
}
