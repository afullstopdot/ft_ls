/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/26 10:43:42 by amarquez          #+#    #+#             */
/*   Updated: 2016/10/25 11:17:19 by amarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	str_clr(char *str)
{
	int	loop;

	loop = 0;
	while (str[loop] != '\0')
	{
		str[loop] = '\0';
		loop++;
	}
}

char	*str_new(size_t size)
{
	char	*new;

	new = (char*)malloc(sizeof(char) * size + 1);
	if (new != NULL)
	{
		new[size] = '\0';
		str_clr(new);
	}
	return (new);
}
