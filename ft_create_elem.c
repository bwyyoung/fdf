/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/10 10:38:25 by byoung-w          #+#    #+#             */
/*   Updated: 2014/09/10 10:38:37 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list		*ft_create_elem(void *data)
{
	t_list		*mlist;

	mlist = (t_list *)malloc(sizeof(t_list));
	mlist->next = NULL;
	mlist->data = data;
	return (mlist);
}
