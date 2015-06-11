/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/29 17:03:10 by byoung-w          #+#    #+#             */
/*   Updated: 2015/04/29 17:03:12 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void			init(t_render *render, t_pixel *start, t_pixel *end)
{
	render->x_start = start->x;
	render->y_start = start->y;
	render->x_end = end->x;
	render->y_end = end->y;
	render->x_slope = abs(render->x_end - render->x_start);
	render->y_slope = abs(render->y_end - render->y_start);
	render->error = (render->x_slope > render->y_slope ?
						render->x_slope : -render->y_slope) / 2;
}

static void			x_move(t_render *render)
{
	render->error -= render->y_slope;
	render->x_start += render->x_start < render->x_end ? 1 : -1;
}

static void			y_move(t_render *render)
{
	render->error += render->x_slope;
	render->y_start += render->y_start < render->y_end ? 1 : -1;
}

int					rgb_to_color(int red, int green, int blue)
{
	return (red * 256 * 256 + green * 256 + blue);
}

void				render_line(t_window *data
										, t_pixel *start, t_pixel *end)
{
	t_render render;

	init(&render, start, end);
	while (1)
	{
		mlx_pixel_put(data->mlx_ptr, data->mlx_win,
		render.x_start, render.y_start, rgb_to_color(255, 255, 255));
		if (render.x_start == render.x_end && render.y_start == render.y_end)
			break ;
		if (render.error > -render.x_slope)
			x_move(&render);
		if (render.error < render.y_slope)
			y_move(&render);
	}
}
