/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_help.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/08 19:03:53 by mwilk             #+#    #+#             */
/*   Updated: 2015/05/13 20:03:01 by mwilk            ###   ########.fr       */
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

void	key_press_color_fractal(int	keycode, t_data *d)
{
	if (keycode == SHIFT)
	{
		d->current_frac--;
		if (d->current_frac < 0)
			d->current_frac = NB_FRACTAL - 1;
	}
	else if (keycode == PLUS)
	{
		d->zoom += d->zoom * 0.1f;
		update_zoom(d);
	}
	else if (keycode == MINUS)
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
