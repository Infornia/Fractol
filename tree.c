/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/10 18:30:04 by mwilk             #+#    #+#             */
/*   Updated: 2015/11/12 17:21:55 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


void	fractree(t_data *d, t_coor c, double a, int i)
{
	t_coor	e;
	double	dx;
	double	dy;
	double	dd;
	double	color;

	if (i > 0)
	{
		printf("OUI Le x: %i, Le y: %i\n", c.x, c.y);
		e.x = c.x + (cos(a) * i * 6) * d->zoom;
		e.y = c.y + (sin(a) * i * 9) * d->zoom;
		dx = e.x - c.x;
		dy = e.y - c.y;
		dd = sqrt(dx * dx + dy * dy);
		dx /= dd;
		dy /= dd;
		printf("pre While, The dx: %f, The dy: %f The dd %f\n", dx, dy, dd);
		while (dd-- >= 0)
		{
			color = i + 1 - log(log(e.x + e.y) / log(2));
			color_pixel(&d->screen, RED, c.x, c.y);
			c.x += dx;
			c.y += dy;
		}
		fractree(d, e, a - (M_PI / 8 * 4), i - 1);
		fractree(d, e, a + (M_PI / 8 * 6), i - 1);
	}
}
