/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/29 19:58:29 by byoung-w          #+#    #+#             */
/*   Updated: 2015/04/29 20:13:10 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		mouse_hook(int button, int x, int y, t_window *win)
{
	(void)win;
	ft_putstr("x = ");
	ft_putnbr(x);
	ft_putstr("\ty = ");
	ft_putnbr(y);
	ft_putstr("\tbutton = ");
	ft_putnbr(button);
	ft_putchar('\n');
	return (0);
}

int		expose_hook(t_window *win)
{
	render(win);
	return (0);
}

int		key_hook(int keycode, t_window *win)
{
	(void)win;
	ft_putstr("key: ");
	ft_putnbr(keycode);
	ft_putstr("\n");
	if (keycode == KEY_ESC)
		exit(0);
	return (0);
}
