/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_help.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/08 19:03:53 by mwilk             #+#    #+#             */
/*   Updated: 2015/12/11 22:52:05 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	update_zoom(t_data *d)
{
	double c0x;
	double c0y;

	c0x = (d->c0x + d->os_x) / d->zoom;
	c0y = (d->c0y + d->os_y) / d->zoom;
	d->os_zoom_x += c0x - d->mouse_x * c0x * 2.0;
	d->os_zoom_y += c0y - d->mouse_y * c0y * 2.0;
	d->zoom_w = d->zoom * (double)X_HALF;
	d->zoom_h = d->zoom * (double)Y_HALF;
}

void	hook_key_moves(t_data *d, int keycode)
{
	if (keycode == LEFT)
		d->os_x -= 0.1f / d->zoom;
	else if (keycode == RIGHT)
		d->os_x += 0.1f / d->zoom;
	else if (keycode == UP)
		d->os_y -= 0.1f / d->zoom;
	else if (keycode == DOWN)
		d->os_y += 0.1f / d->zoom;
}

void	hook_key_colors(t_data *d, int keycode)
{
	if (keycode == NUM1)
		d->r = d->r <= 0 ? 255 : d->r - 2;
	else if (keycode == NUM2)
		d->g = d->g <= 0 ? 255 : d->g - 2;
	else if (keycode == NUM3)
		d->b = d->b <= 0 ? 255 : d->b - 2;
	else if (keycode == NUM4)
		d->r = d->r >= 255 ? 0 : d->r + 2;
	else if (keycode == NUM5)
		d->g = d->g >= 255 ? 0 : d->g + 2;
	else if (keycode == NUM6)
		d->b = d->b >= 255 ? 0 : d->b + 2;
	else if (keycode == KEY2)
		d->cur_pal = (d->cur_pal + 1) % NB_PAL;
	else if (keycode == KEY1)
	{
		d->cur_pal--;
		if (d->cur_pal < 0)
			d->cur_pal = NB_PAL - 1;
	}
	if (keycode == KEYR)
		d->rainbow = d->rainbow % 70 + 1;
}

void	hook_key_fractal(t_data *d, int keycode)
{
	if (keycode == IT_UP)
		d->it += 1;
	else if (keycode == IT_DOWN)
		d->it -= 1;
	else if (keycode == OPT_UP)
		d->tri_opt = (d->tri_opt + 1) % NB_TRI_OPT;
	else if (keycode == OPT_DOWN)
		d->tri_opt = d->tri_opt < 1 ? NB_TRI_OPT : d->tri_opt - 1;
	else if (keycode == TAB)
		d->cur_frac = (d->cur_frac + 1) % NB_FRACTAL;
	else if (keycode == SHIFT)
		d->cur_frac = d->cur_frac < 1 ? NB_FRACTAL : d->cur_frac - 1;
	else if (keycode == ZOOM_IN)
	{
		d->zoom += d->zoom * 0.1f;
		d->count += 1;
		update_zoom(d);
	}
	else if (keycode == ZOOM_OUT)
	{
		d->zoom -= d->zoom * 0.1f;
		d->count -= 1;
		update_zoom(d);
	}
}
