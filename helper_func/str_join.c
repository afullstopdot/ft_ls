/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_join.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/28 09:53:00 by amarquez          #+#    #+#             */
/*   Updated: 2016/11/16 11:32:48 by amarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	str_cpy(char *dst, char *src)
{
	int	loop;

	loop = 0;
	while (src[loop] != '\0')
	{
		dst[loop] = src[loop];
		loop++;
	}
	dst[loop] = '\0';
}

char	*str_join(char *s1, char *s2)
{
	char	*new;
	size_t	len_s1;
	size_t	len_s2;

	len_s1 = str_len(s1);
	len_s2 = str_len(s2);
	new = str_new(len_s1 + len_s2);
	if (new)
	{
		str_cpy(new, s1);
		str_cpy(&(new[len_s1]), s2);
	}
	return (new);
}
