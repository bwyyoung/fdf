/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/29 17:03:10 by byoung-w          #+#    #+#             */
/*   Updated: 2015/04/29 17:03:12 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		calculate_points(t_window *data
									, t_pixel points[data->def_height
														* data->def_width])
{
	size_t	row;
	size_t	column;
	int		index;
	double	z_mult;
	t_list	*coordinates;

	z_mult = -1;
	row = 0;
	coordinates = data->coordinates;
	while (row < data->def_height)
	{
		column = 0;
		while (column < data->def_width)
		{
			index = row * data->def_width + column;
			points[index].x = WINDOW_LEFT * column
			- WINDOW_RIGHT * row + (data->def_height - 1) * WINDOW_LEFT;
			points[index].y = z_mult * ((t_pixel *)coordinates->content)->h
			+ WINDOW_LEFT / 2 * column + WINDOW_RIGHT / 2 * row;
			points[index].h = ((t_pixel *)coordinates->content)->h;
			column++;
			coordinates = coordinates->next;
		}
		row++;
	}
}

static void		render_horizontal(t_window *data
								, t_pixel points[data->def_height
													* data->def_width]
								, int y)
{
	size_t	i;

	i = 0;
	while (i < data->def_width - 1)
	{
		render_line(data
						, &(points[y * data->def_width + i])
						, &(points[y * data->def_width + i + 1]));
		i++;
	}
}

static void		render_vertical(t_window *data
								, t_pixel points[data->def_height
													* data->def_width]
								, int x)
{
	size_t	i;

	i = 0;
	while (i < data->def_height - 1)
	{
		render_line(data
						, &(points[i * data->def_width + x])
						, &(points[(i + 1) * data->def_width + x]));
		i++;
	}
}

void			render(t_window *data)
{
	size_t		i;
	t_pixel		points[data->def_height * data->def_width];

	calculate_points(data, points);
	i = 0;
	if (data->def_height == 1 && data->def_width == 1)
		render_line(data, &points[0], &points[0]);
	while (i < data->def_height)
	{
		render_horizontal(data, points, i);
		i++;
	}
	i = 0;
	while (i < data->def_width)
	{
		render_vertical(data, points, i);
		i++;
	}
}
