/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/08 17:13:30 by mwilk             #+#    #+#             */
/*   Updated: 2015/05/08 19:57:00 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		expose_hook(t_data *d)
{
	draw(e);
	mlx_put_image_to_window(e->mlx, e->win, e->screen.ptr, 0, 0);
	return (0);
}

int		key_hook(int keycode, t_data *d)
{
	if (keycode == ESC)
		ft_envdel(e);
	else if (keycode == LEFT)
		e->offset_x -= 0.1f / e->zoom;
	else if (keycode == RIGHT)
		e->offset_x += 0.1f / e->zoom;
	else if (keycode == UP)
		e->offset_y -= 0.1f / e->zoom;
	else if (keycode == DOWN)
		e->offset_y += 0.1f / e->zoom;
	else if (keycode == KEY_R)
		init_var(e);
	else if (keycode == TAB)
		e->current_fractal = (e->current_fractal + 1) % NB_FRACTAL;
	//key_press_color_fractal(keycode, e);
	expose_hook(e);
	return (0);
}

int		mouse_hook(int button, int x, int y, t_data *d)
{
	if (button == 1)
	{
		d->pos_x = x;
		d->pos_y = y;
	}
	else if (button == 5)
		e->zoom += e->zoom * 0.1f;
	else if (button == 4)
		e->zoom -= e->zoom * 0.1f;
	update_zoom(e);
	expose_hook(e);
	return (0);
}

int			mouse_hook_move(int x, int y, t_env *e)
{
	e->move_pos_x = x;
	e->move_pos_y = y;
	e->mouse_x = x / (double)WIN_X;
	e->mouse_y = y / (double)WIN_Y;
	e->julia_cx = -0.8 + e->mouse_x * 1.1;
	e->julia_cy = 0.3 - e->mouse_y * 0.32;
	if (x % 5 == 0 || y % 5 == 0)
		expose_hook(e);
	return (0);
}
