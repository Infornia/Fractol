/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frac.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/05 16:34:42 by mwilk             #+#    #+#             */
/*   Updated: 2015/11/05 17:27:42 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAC_H
# define FRAC_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <mlx.h>
# include <fcntl.h>
# include <math.h>
# include "libft.h"

/*
**Parameters
*/

# define X_WIN 800
# define Y_WIN 600
# define Y_HALF Y_WIN / 2
# define X_HALF X_WIN / 2

/*
**Colors
*/
# define RED		0xFF0000
# define GREEN		0x00FF00
# define BLUE 		0x0000FF
# define QUOISE		0x74BDF9
# define GREEN 		0x00FF00
# define PINK 		0xFF00FF
# define WHITE 		0xFFFFFF
# define GRAY 		0x0F0F0F
# define BLACK 		0x000000
# define RGB(r, g, b)(256 * 256 * (int)(r) + 256 * (int)(g) + (int)(b))
# define ABS(x)		((x) < 0 ? -(x) : (x))

/*
**keys
*/

# define ESC		53
# define UP			126
# define DOWN		125
# define LEFT		123
# define RIGHT		124
# define TAB		48
# define PLUS		69
# define MINUS		78
# define SHIFT		257
# define ZOOM_IN	24
# define ZOOM_OUT	27
# define PEAK_UP	30
# define PEAK_DOWN	33
# define RESET		29
# define KEY1		18
# define KEY2		19
# define ZOOM_IN_M	5
# define ZOOM_OUT_M	4

/*
**Structures
*/

typedef struct	s_screen
{
	void		*img;
	char		*data_img;	
	int			bpp;
	int			size;
	int			endian;
	int			max_size;
	int			w;
	int			h;
}				t_screen;


typedef struct	s_data
{
	void			*mlx;
	void			*win;
	t_img			s;
	int				click_x;
	int				click_y;
	int				move_x;
	int				move_y;
	double			mouse_x;
	double			mouse_y;
}				t_data;

t_data			*main_frac();
void			fractal_del(t_data *d);

void			init_mlx(t_data *d);
void			init_screen(t_img *d, void * mlx);
int				expose_hook(t_data *d);
int				mouse_hook(int button, int x, int y, t_data *d);
int				mouse_hook_move(int x, int y, t_data *d);
int				key_hook(int keycode, t_data *d);

#endif
