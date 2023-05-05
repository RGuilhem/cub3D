/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_val.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:54:28 by graux             #+#    #+#             */
/*   Updated: 2022/11/07 11:58:47 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter_val(t_list *lst, void (*f)(void *, void *), void *data)
{
	while (lst)
	{
		f(lst->content, data);
		lst = lst->next;
	}
}
