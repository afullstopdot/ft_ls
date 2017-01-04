/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_len.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 08:33:37 by amarquez          #+#    #+#             */
/*   Updated: 2016/11/16 17:02:12 by amarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int		count(struct s_filelist *temp)
{
	int	length;

	length = 0;
	while (temp)
	{
		length++;
		temp = temp->next;
	}
	return (length);
}
