/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/10 18:30:04 by mwilk             #+#    #+#             */
/*   Updated: 2015/12/01 16:07:29 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		display_for_tree(t_data *d, int opt)
{
	if (opt == 0 || opt == 4 || opt == 6)
	{
		mlx_string_put(d->mlx, d->win, 50, 10, RED, "+/- NUM 4/1");
		mlx_string_put(d->mlx, d->win, 50, 30, GREEN, "+/- NUM 5/2");
		mlx_string_put(d->mlx, d->win, 50, 50, QUOISE, "+/- NUM 6/3");
		mlx_string_put(d->mlx, d->win, 10, 10, RED, ft_itoa(d->r));
		mlx_string_put(d->mlx, d->win, 10, 30, GREEN, ft_itoa(d->g));
		mlx_string_put(d->mlx, d->win, 10, 50, QUOISE, ft_itoa(d->b));
	}
	else if (opt == 1 || opt == 5)
		mlx_string_put(d->mlx, d->win, 10, 10, PINK, "press R bro !");
}

static int	tree_color(t_data *d, int opt, t_coor s, int i)
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
