/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_dup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 09:18:14 by amarquez          #+#    #+#             */
/*   Updated: 2016/11/10 09:25:57 by amarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

char	*remove_dup(char *str)
{
	int res_ind;
	int	ip_ind;

	res_ind = 1;
	ip_ind = 1;
	while (*(str + ip_ind))
	{
		if (*(str + ip_ind) != *(str + ip_ind - 1))
		{
			*(str + res_ind) = *(str + ip_ind);
			res_ind++;
		}
		ip_ind++;
	}
	*(str + res_ind) = '\0';
	return (str);
}
