/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 13:16:03 by mwilk             #+#    #+#             */
/*   Updated: 2015/11/28 15:24:54 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int tri_color(t_data *d, int opt, t_coor s, int i)
{
	int color;

	if (opt == 0)
		color = RGB(d->r, d->g, d->b);
	if (opt == 1)
		color = get_r_color(d->rainbow * 0.09);
	if (opt == 2)
		color = RGB(233 + i * 7, 105 + i * 7, 244 - i * 7);
	if (opt == 3)
		color = i - log(log(s.x + s.y) / log(2));
	if (opt == 4)
		color = RGB(50 + d->r + i * 7, d->g + i * 7, d->b + 150 - i * 7);
	if (opt == 5)
		color = get_r_color(RED / Y_WIN * d->rainbow * s.y);
	if (opt == 6)
		color = RGB(22 + d->r + i * 2, d->g + i * 2, d->b + 22 - i * 2);
	return (color);
}

void		fractriangle(t_data *d, t_coor c, float h, int max_i)
{
	int x;
	int y;
	float cx;

	y = 0;
	if (max_i == 1)
	{
		while (y < h && y < Y_WIN)
		{
			x = x < 0 ? 0 : -y / sqrt(3);
			while(x <= y / sqrt(3) && x <= X_WIN)
			{
				color_pixel(&d->screen, tri_color(d, d->tri_color_opt, c, max_i), c.x + x, c.y + y);
				x++;
			}
			y++;
		}
	}
	else if (max_i > 1)
	{
		while (y < h)
		{
			color_pixel(&d->screen, BLUE, -y / sqrt(3) + c.x, y + c.y);
			color_pixel(&d->screen, GREEN, y / sqrt(3) + c.x, y + c.y);
			y++;
		}
		x = -y / sqrt(3);
		while (x < y / sqrt(3))
		{
			color_pixel(&d->screen, WHITE, x + c.x, y + c.y);
			x++;
		}
		if (c.x < X_WIN && c.y < Y_WIN)
		{
			fractriangle(d, c, h / 2, max_i - 1);
			cx = c.x + h / sqrt(3) / 2;
			c.x = c.x - h / sqrt(3) / 2;
			c.y = c.y + h / 2;
			fractriangle(d, c, h / 2, max_i - 1);
			c.x = cx;
			fractriangle(d, c, h / 2, max_i - 1);
		}
	}
}
