/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/08 14:49:06 by byoung-w          #+#    #+#             */
/*   Updated: 2015/05/01 03:46:36 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft.h"
# include "get_next_line.h"
# include "mlx.h"
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <limits.h>
# include <string.h>
# define WINDOW_W 1024
# define WINDOW_H 768
# define WINDOW_LEFT 10
# define WINDOW_RIGHT 10
# define KEY_ESC 53

typedef struct		s_window
{
	void			*mlx_ptr;
	void			*mlx_win;
	char			*title;
	int				pfd;
	int				status;
	int				keycode;
	size_t			def_width;
	size_t			def_height;
	int				min;
	int				max;
	t_list			*coordinates;
}					t_window;

typedef struct		s_pixel
{
	int				h;
	int				x;
	int				y;
}					t_pixel;

typedef struct		s_render
{
	int				x_slope;
	int				y_slope;
	int				x_start;
	int				y_start;
	int				x_end;
	int				y_end;
	int				error;
}					t_render;

char				**ft_split(char *str);
int					mouse_hook(int button, int x, int y, t_window *env);
int					expose_hook(t_window *env);
int					key_hook(int keycode, t_window *param);
void				readfile(t_window *data);
void				ft_putendl_exit(char const *s);
size_t				ft_arrlen(char **array);
void				ft_list_push_back(t_list **begin_list,
void *data, int thesize);
t_list				*ft_create_elem(void *data);
void				render(t_window *win);
void				fdf(t_window data);
void				render_line(t_window *data
										, t_pixel *start, t_pixel *end);
#endif
