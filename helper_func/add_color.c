/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/11 11:41:00 by amarquez          #+#    #+#             */
/*   Updated: 2016/11/17 12:51:20 by amarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

char			*add_color(char *str, char *color)
{
	char		*temp;
	char		*final;

	final = NULL;
	if (str && color)
	{
		temp = str_join(color, str);
		if (temp)
		{
			final = str_join(temp, RESET);
			free(temp);
		}
		free(str);
	}
	else
		perror("ft_ls error: ");
	return (final);
}
