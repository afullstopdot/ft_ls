/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_dup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/26 10:42:48 by amarquez          #+#    #+#             */
/*   Updated: 2016/11/09 10:41:34 by amarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

char	*str_dup(char *str)
{
	int		loop;
	char	*new;

	loop = 0;
	new = str_new(str_len(str));
	if (new != NULL)
	{
		while (str[loop] != '\0')
		{
			new[loop] = str[loop];
			loop++;
		}
		new[loop] = '\0';
	}
	return (new);
}
