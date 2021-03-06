/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/03 09:50:50 by byoung-w          #+#    #+#             */
/*   Updated: 2014/11/06 22:47:08 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int			neg;
	const char	*s;
	long		val;

	s = str;
	neg = 1;
	val = 0;
	while ((*s == ' ' || *s == '\t' || *s == '\n'
	|| *s == '\r' || *s == '\v' || *s == '\f' || *s == '\12'))
		s++;
	if (*s == '+' || *s == '-')
	{
		if (*s == '-')
			neg = -1;
		s++;
	}
	while (*s >= '0' && *s <= '9')
	{
		val *= 10;
		val += (long)(*s - '0');
		s++;
	}
	if (((int)(val * neg) == 0 && val != 0) || (val < 0))
		val = (neg < 0) ? 0 : -1;
	return ((int)(val * neg));
}
