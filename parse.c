/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/29 15:36:12 by byoung-w          #+#    #+#             */
/*   Updated: 2015/04/29 16:14:38 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			validatewidth(t_window **data, char **currow)
{
	if ((*data)->def_width == 0)
		(*data)->def_width = ft_arrlen(currow);
	else if ((*data)->def_width != ft_arrlen(currow))
		ft_putendl_exit("Invalid File: Width Consistency");
	return (1);
}

t_list		*appendtolist(t_list *coordinates, char **currow, int y)
{
	t_pixel		*data;
	int			x;

	x = 0;
	while (currow[x])
	{
		data = (t_pixel *)malloc(sizeof(t_pixel));
		data->x = x;
		data->y = y;
		data->h = ft_atoi(currow[x]);
		ft_list_push_back(&coordinates, data, sizeof(t_pixel));
		x++;
	}
	return (coordinates);
}

void		readfile(t_window *data)
{
	char	*line;
	char	**currow;
	t_list	*coordinates;

	line = NULL;
	coordinates = NULL;
	data->def_height = 0;
	while ((data->status = get_next_line(data->pfd, &line)) > 0)
	{
		currow = ft_split(line);
		if (validatewidth(&data, currow))
			coordinates = appendtolist(coordinates, currow, data->def_height);
		data->def_height++;
	}
	if (data->status < 0)
		ft_putendl_exit("ERROR Reading File. Qutting Now.");
	if (close(data->pfd) == -1)
		ft_putendl_exit("close() error\n");
	data->coordinates = coordinates;
}
