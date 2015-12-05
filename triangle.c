/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 13:16:03 by mwilk             #+#    #+#             */
/*   Updated: 2015/12/05 21:52:38 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		display_for_tri(t_data *d, int opt)
{
	if (opt == 0)
	{
		mlx_string_put(d->mlx, d->win, 50, 10, RED, "+/- NUM 4/1");
		mlx_string_put(d->mlx, d->win, 50, 30, GREEN, "+/- NUM 5/2");
		mlx_string_put(d->mlx, d->win, 50, 50, QUOISE, "+/- NUM 6/3");
		mlx_string_put(d->mlx, d->win, 10, 10, RED, ft_itoa(d->r));
		mlx_string_put(d->mlx, d->win, 10, 30, GREEN, ft_itoa(d->g));
		mlx_string_put(d->mlx, d->win, 10, 50, QUOISE, ft_itoa(d->b));
	}
	else if (opt == 1 || opt == 3)
		mlx_string_put(d->mlx, d->win, 10, 10, PINK, "press R bro !");
}

t_coor		option_tri(t_data *d, t_coor c)
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
	return (c);
}

static int	tri_color(t_data *d, int opt, t_coor s, int i)
{
	int color;

	if (opt == 0)
		color = RGB(d->r, d->g, d->b);
	if (opt == 1)
		color = get_r_color((d->count + d->rainbow) * 0.09);
	if (opt == 2)
		color = RGB(233 + i * 7, 105 + i * 7, 244 - i * 7);
	if (opt == 3)
		color = get_r_color(RED / Y_WIN * (d->count + d->rainbow) * s.y);
	return (color);
}

static void	triple_shot(t_data *d, t_coor c, double h, int max_i)
{
	double	cx;

	fractriangle(d, c, h, max_i);
	cx = c.x + h / sqrt(3);
	c.x = c.x - h / sqrt(3);
	c.y = c.y + h;
	fractriangle(d, c, h, max_i);
	c.x = cx;
	fractriangle(d, c, h, max_i);
}

void		fractriangle(t_data *d, t_coor c, double h, int max_i)
{
	int		color;

	c.j = 0;
	if (max_i == 1)
	{
		color = tri_color(d, d->tri_color_opt, c, max_i);
		while (c.j < h && c.j < Y_WIN)
		{
			c.i = c.i < 0 ? 0 : -c.j / sqrt(3);
			while (c.i <= c.j / sqrt(3) && c.i < X_WIN)
			{
				if (d->tri_opt == 2)
					color_pixel(&d->screen, color,
							d->os_x * 22 + c.x + c.i * cos(d->mouse_x * 6),
							d->os_y * 22 + c.y + c.j * sin(d->mouse_y * 9));
				else
					color_pixel(&d->screen, color * max_i,
							d->os_x * 22 + c.x + c.i, d->os_y * 22 + c.y + c.j);
				c.i++;
			}
			c.j++;
		}
	}
	else if (max_i > 1 && c.x < X_WIN && c.y < Y_WIN)
		triple_shot(d, c, h / 2, max_i - 1);
}
