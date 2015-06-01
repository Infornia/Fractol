/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/08 17:12:22 by mwilk             #+#    #+#             */
/*   Updated: 2015/05/13 20:00:36 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_frac(t_data *d)
{
	int		i;

	i = 0;
	d->color_mode = 0;
	d->lr = X_WIN * 2 / 5;
	d->ud = 200 + Y_WIN / 1000;
	d->mlx = mlx_init();
	d->win = mlx_new_window (d->mlx, X_WIN, Y_WIN, "Fract'ol");
}

void	init_screen(t_img *d, void *mlx)
{
	d->img = mlx_new_image(mlx, X_WIN, Y_WIN);
	d->data_img = mlx_get_data_addr
		(d->img, &(d->bpp), &(d->size), &(d->endian));
	d->bpp /= 8;
	d->max_size = d->size * Y_WIN + d->bpp * X_WIN;
}

void	init_variables(t_data *d)
{
	d->os_zoom_x = 0.f;
	d->os_zoom_y = 0.f;
	d->os_x = 0.f;
	d->os_y = 0.f;
	d->zoom = 0.f;
	d->click_x = 0;
	d->click_y = 0;
	d->mouse_x = 0;
	d->mouse_y = 0;
	d->c0x = 1.5 * (-X_HALF) / (d->zoom * X_HALF);
	d->c0y = (-Y_HALF) / (d->zoom * Y_HALF);
	d->zoom_w = d->zoom * (double)X_HALF;
	d->zoom_h = d->zoom * (double)Y_HALF;
	d->julia_cx = -0.8;
	d->julia_cy = 0.3;
}

void	init_julia(t_data *d, int x, int y)
{
	d->u.cx = d->julia_cx;
	d->u.cy = d->julia_cy;
	d->u.zx = 1.6 * (x - X_HALF) / (d->zoom_w) + d->os_x;
	d->u.zy = 1.2 * (y - Y_HALF) / (d->zoom_h) + d->os_y;
	d->u.i = 1;
	d->u.cld = 4.0;
	d->u.cln = 0;
	d->u.last_iter = 0;
}

void	init_mandelbrot(t_data *d, int x, int y)
{
	d->u.cx = 1.6 * (x - X_HALF) / (d->zoom_w * X_HALF);
	d->u.cx += d->os_x - 0.5 + d->os_zoom_x / 2.0;
	d->u.cx = 1.1 * (y - Y_HALF) / (d->zoom_w * Y_HALF);
	d->u.cy += d->os_y + d->os_zoom_y / 2.0;
	d->u.zx = d->u.cx;
	d->u.zy = d->u.cy;
	d->u.i = 0;
	d->u.cld = 4.0;
	d->u.cln = 0;
	d->u.last_iter = 0;
}
