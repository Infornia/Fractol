/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 13:16:03 by mwilk             #+#    #+#             */
/*   Updated: 2015/11/28 20:43:20 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_coor	option_tri(t_data *d, t_coor c)
{
	if (d->tri_opt == 0)
	{
		c.x = X_HALF;
		c.y = Y_HALF / 6;
	}
	else if (d->tri_opt == 1)
	{
		c.x = cos(X_HALF);
		c.y = sin(Y_HALF / 6);
	}
	else if (d->tri_opt == 2)
	{
		c.x = X_HALF + cos(M_PI / 8 * d->mouse_x * 2);
		c.y = Y_HALF / 6 + sin( M_PI / 8 * d->mouse_y * 2);
	}
	return(c);
}

static int tri_color(t_data *d, int opt, t_coor s, int i)
{
	int color;

	if (opt == 0)
		color = RGB(d->r, d->g, d->b);
	if (opt == 1)
		color = get_r_color((d-> count + d->rainbow) * 0.09);
	if (opt == 2)
		color = RGB(233 + i * 7, 105 + i * 7, 244 - i * 7);
	if (opt == 3)
		color = i - log(log(s.x + s.y) / log(2));
	if (opt == 4)
		color = RGB(50 + d->r + i * 7, d->g + i * 7, d->b + 150 - i * 7);
	if (opt == 5)
		color = get_r_color(RED / Y_WIN * (d->count + d->rainbow) * s.y);
	if (opt == 6)
		color = RGB(22 + d->r + i * 2, d->g + i * 2, d->b + 22 - i * 2);
	return (color);
}

void		fractriangle(t_data *d, t_coor c, double h, int max_i)
{
	int x;
	int y;
	double cx;
	int color;

	y = 0;
	if (max_i == 1)
	{
		color = tri_color(d, d->tri_color_opt, c, max_i);
		while (y < h && y < Y_WIN)
		{
			x = x < 0 ? 0 : -y / sqrt(3);
			while(x <= y / sqrt(3) && x < X_WIN)
			{
				color_pixel(&d->screen, color, d->os_x * 22 + c.x + x * cos(d->mouse_x * 6), d->os_y * 22 + c.y + y * sin(d->mouse_y * 9));
//				color_pixel(&d->screen, color, d->os_x * 22 + c.x + x, d->os_y * 22 + c.y + y);
				x++;
			}
			y++;
		}
	}
	else if (max_i > 1 && c.x < X_WIN && c.y < Y_WIN)
	{
		color = tri_color(d, d->tri_color_opt, c, max_i);
		if (d->tri_opt == 3)
		{
			while (y < h && y < Y_WIN)
			{
				color_pixel(&d->screen, color, -y / sqrt(3) + c.x, y + c.y);
				color_pixel(&d->screen, color * 11, y / sqrt(3) + c.x, y + c.y);
				y++;
			}
			x = -y / sqrt(3);
			while (x < y / sqrt(3) && x < X_WIN)
			{
				color_pixel(&d->screen, color * 22, x + c.x, y + c.y);
				x++;
			}
		}
		h = h / 2;
		fractriangle(d, c, h, max_i - 1);
		cx = c.x + h / sqrt(3);
		c.x = c.x - h / sqrt(3);
		c.y = c.y + h;
		fractriangle(d, c, h, max_i - 1);
		c.x = cx;
		fractriangle(d, c, h, max_i - 1);
	}
}
