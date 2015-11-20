/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/08 17:13:30 by mwilk             #+#    #+#             */
/*   Updated: 2015/11/20 15:10:32 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		expose_hook(t_data *d)
{
	if (d->current_frac != 6)
		draw(d);
	else
		draw_tree(d);
	mlx_do_sync(d->mlx);
	mlx_put_image_to_window(d->mlx, d->win, d->screen.img, 0, 0);
	return (0);
}

int		key_hook(int keycode, t_data *d)
{
	printf("%i\n", keycode);
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
	else if (keycode == IT_UP)
		d->it += 1;
	else if (keycode == IT_DOWN)
		d->it -= 1;
	else if (keycode == RESET)
		init_variables(d);
	else if (keycode == TAB)
		d->current_frac = (d->current_frac + 1) % NB_FRACTAL;
	key_frac(keycode, d);
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
	d->mouse_x = (float)x / X_WIN;
	d->mouse_y = (float)y / Y_WIN;
	d->julia_cx = -0.8 + d->mouse_x * 1.1;
	d->julia_cy = 0.3 - d->mouse_y * 0.32;
	if (x % 5 == 0 || y % 5 == 0)
		expose_hook(d);
	return (0);
}

void		key_frac(int keycode, t_data *d)
{
	if(keycode == SHIFT)
	{
		d->current_frac--;
		if (d->current_frac < 0)
			d->current_frac = NB_FRACTAL - 1;
	}
	else if (keycode == ZOOM_IN)
	{
		d->zoom += d->zoom * 0.1f;
		update_zoom(d);
	}
	else if (keycode == ZOOM_OUT)
	{
		d->zoom -= d->zoom * 0.1f;
		update_zoom(d);
	}
	else if (keycode == KEY1)
		d->current_pal = (d->current_pal + 1) % NB_PAL;
	else if (keycode == KEY2)
	{
		d->current_pal--;
		if (d->current_pal < 0)
			d->current_pal = NB_PAL - 1;
	}
}
