/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_help.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/08 19:03:53 by mwilk             #+#    #+#             */
/*   Updated: 2015/11/21 19:13:18 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	update_zoom(t_data *d)
{
	float c0x;
	float c0y;

	c0x = (d->c0x + d->os_x) / d->zoom;
	c0y = (d->c0y + d->os_y) / d->zoom;
	d->os_zoom_x += c0x - d->mouse_x * c0x * 2.0;
	d->os_zoom_y += c0y - d->mouse_y * c0y * 2.0;
	d->zoom_w = d->zoom * (float)X_HALF;
	d->zoom_h = d->zoom * (float)Y_HALF;
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
		d->current_pal = (d->current_pal + 1) % NB_PAL;
	else if (keycode == KEY1)
	{
		d->current_pal--;
		if (d->current_pal < 0)
			d->current_pal = NB_PAL - 1;
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
	else if(keycode == SHIFT)
	{
		d->current_frac--;
		if (d->current_frac < 0)
			d->current_frac = NB_FRACTAL - 1;
	}
	else if (keycode == TAB)
		d->current_frac = (d->current_frac + 1) % NB_FRACTAL;
	else if (keycode == SHIFT)
		d->current_frac = (d->current_frac - 1) % NB_FRACTAL;
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
}
