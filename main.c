/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/29 15:32:52 by byoung-w          #+#    #+#             */
/*   Updated: 2015/05/01 04:44:14 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		errorcheck(char *thefile)
{
	if (errno == EISDIR)
	{
		ft_putstr("cat: ");
		ft_putstr(thefile);
		ft_putstr("Is a directory\n");
		return (0);
	}
	return (1);
}

void	ft_putendl_exit(char const *s)
{
	ft_putendl(s);
	exit(1);
}

int		main(int argc, char **argv)
{
	t_window	data;

	if (argc - 1 == 1)
	{
		data.pfd = open(argv[1], O_RDONLY);
		if (data.pfd < 0)
		{
			ft_putstr(argv[1]);
			ft_putstr(": No such file or directory\n");
			exit(1);
		}
		data.title = argv[1];
		data.def_width = 0;
		if (errorcheck(argv[1]))
		{
			readfile(&data);
			fdf(data);
		}
	}
	else
		ft_putendl("Program must have 1 argument: File Path");
	return (0);
}
