/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/29 15:37:13 by byoung-w          #+#    #+#             */
/*   Updated: 2015/04/29 20:13:08 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void			set_minimum_maximum(t_window *data)
{
	int				value;
	size_t			horizontal;
	size_t			vertical;
	t_list			*coordinates;

	vertical = 0;
	coordinates = (data)->coordinates;
	while (vertical < (data)->def_height)
	{
		horizontal = 0;
		while (horizontal < (data)->def_width)
		{
			value = ((t_pixel *)coordinates->content)->h;
			if (value < (data)->min)
				(data)->min = value;
			else if (value > (data)->max)
				(data)->max = value;
			horizontal++;
			coordinates = coordinates->next;
		}
		vertical++;
	}
}

static int			setup_environment(t_window *data)
{
	if (((data)->mlx_ptr = mlx_init()) == NULL)
		return (EXIT_FAILURE);
	if (((data)->mlx_win = mlx_new_window((data)->mlx_ptr, WINDOW_W, WINDOW_H
								, (data)->title)) == NULL)
		return (EXIT_FAILURE);
	set_minimum_maximum(data);
	return (EXIT_SUCCESS);
}

void				fdf(t_window data)
{
	setup_environment(&data);
	mlx_expose_hook((data).mlx_win, expose_hook, &data);
	mlx_key_hook((data).mlx_win, key_hook, &data);
	mlx_mouse_hook ((data).mlx_win, mouse_hook, &data);
	mlx_loop((data).mlx_ptr);
}
