/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/10 18:30:04 by mwilk             #+#    #+#             */
/*   Updated: 2015/11/20 15:10:17 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	put_line(t_data *d, t_coor s, t_coor e, int color)
{
	double	dx;
	double	dy;
	double	dd;
	double	x;
	double	y;

	(void)color;
	x = s.x;
	y = s.y;
	dx = e.x - s.x;
	dy = e.y - s.y;
	dd = sqrt(dx * dx + dy * dy);
	dx = dx / dd;
	dy = dy / dd;
	while (dd-- >= 0)
	{
//		color = i + 1 - log(log(e.x + e.y) / log(2));
		color_pixel(&d->screen, RED, x, y);
		x += dx;
		y += dy;
	}

}

void	fractree(t_data *d, t_coor s, double a, int i)
{
	t_coor	e;

	if (i > 0)
	{
//		printf("OUI Le x: %i, Le y: %i\n", c.x, c.y);
		e.x = s.x + (cos(a) * i * 6) * d->zoom;
		e.y = s.y + (sin(a) * i * 9) * d->zoom;
//		printf("pre While, The dx: %f, The dy: %f The dd %f\n", dx, dy, dd);
		put_line(d, s, e, RED);
		fractree(d, e, a - (M_PI / 8 * d->mouse_y * 2), i - 1);
		fractree(d, e, a + (M_PI / 8 * d->mouse_x * 2), i - 1);
	}
}
