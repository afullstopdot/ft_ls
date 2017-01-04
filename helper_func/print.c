/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 11:34:04 by amarquez          #+#    #+#             */
/*   Updated: 2016/11/17 13:14:57 by amarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void		print_p(char **str)
{
	int		size;
	int		coun;

	if (str)
	{
		coun = 0;
		size = d_strlen(str);
		while (coun < size)
		{
			put_str_e(str[coun]);
			coun++;
		}
	}
}
