/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/13 18:16:44 by mwilk             #+#    #+#             */
/*   Updated: 2015/11/20 21:08:44 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>

void			draw_tree(t_data *d)
{
	int		max_i;
	t_coor	c;

	ft_bzero(d->screen.data_img, X_WIN * Y_WIN * 4);
	d->it = d->it >= 4 ? 4 : d->it;
	max_i = 11 + d->it;
	c.x = X_HALF - d->zoom / 4.1;
	c.y = Y_WIN - 20 + d->zoom / 1.2;
	d->tree_color_opt = d->current_pal % NB_TREE_COLORS;
	fractree(d, c, -(M_PI / 2), max_i);
}

void			draw(t_data *d)
{
	int		max_i;
	int		color;
	int		x;
	int		y;

	ft_putnbr(ft_strlen(d->screen.data_img));
	max_i = sqrt(ABS(2 * sqrt(ABS(1 - sqrt(5 * d->zoom))))) * 66.5 + d->it;
	d->it = d->it >= max_i ? max_i  : d->it;
//	printf("%i\n", max_i);
	x = 0;
	while (x < X_WIN)
	{
		y = 0;
		while (y < Y_WIN)
		{
			d->u.RZ = 0.0;
			d->u.IZ = 0.0;
			color = d->fractal[d->current_frac](d, x, y, max_i);
			color_pixel(&d->screen, color, x, y);
			y++;
		}
		x++;
	}
}
