/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/10 18:30:04 by mwilk             #+#    #+#             */
/*   Updated: 2015/11/20 21:20:16 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int tree_color(t_data *d, int opt, t_coor s, int i)
{
	int color;

//	printf("The option: %i\n", opt);
	if (opt == 0)
		color = 16777215;
	if (opt == 1)
		color = get_r_color(d->rainbow * 0.09);
	if (opt == 2)
		color = RED;
	if (opt == 3)
		color = i - log(log(s.x + s.y) / log(2));
	if (opt == 4)
		printf("%i, %i\n", WHITE, BLACK);
	if (opt == 5)
		color = get_r_color(RED / Y_WIN * d->rainbow * s.y);
	printf("%i, %i\n", d->rainbow, color);
	return (color);
}

static void	put_line(t_data *d, t_coor s, t_coor e, int color)
{
	double	dx;
	double	dy;
	double	dd;
	double	x;
	double	y;

	x = s.x;
	y = s.y;
	dx = e.x - s.x;
	dy = e.y - s.y;
	dd = sqrt(dx * dx + dy * dy);
	dx = dx / dd;
	dy = dy / dd;
	while (dd-- >= 0)
	{
		color_pixel(&d->screen, color, x, y);
		x += dx;
		y += dy;
	}

}

void	fractree(t_data *d, t_coor s, double a, int i)
{
	t_coor	e;

	if (i > 0)
	{
		e.x = s.x + (cos(a) * i * 6) * d->zoom;
		e.y = s.y + (sin(a) * i * 9) * d->zoom;
		put_line(d, s, e, tree_color(d, d->tree_color_opt, s, i));
		fractree(d, e, a - (M_PI / 8 * d->mouse_y * 2), i - 1);
		fractree(d, e, a + (M_PI / 8 * d->mouse_x * 2), i - 1);
	}
}
