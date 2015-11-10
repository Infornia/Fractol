/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/11 15:48:12 by mwilk             #+#    #+#             */
/*   Updated: 2015/11/10 15:43:44 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		main(int ac, char **av)
{
	t_data	*d;

	(void)av;
	print_usage(ac);
	if (ac == 1)
	{
		if(!(d = main_frac()))
			return (1);
		mlx_hook(d->win, 2, 1, key_hook, d);
		mlx_hook(d->win, 4, 4, mouse_hook, d);
		mlx_hook(d->win, 6, 16, mouse_hook_move, d);
		mlx_expose_hook(d->win, expose_hook, d);
		mlx_loop(d->mlx);
	}
	return (0);
}
