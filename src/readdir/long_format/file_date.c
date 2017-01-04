/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_date.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 11:59:49 by amarquez          #+#    #+#             */
/*   Updated: 2016/11/14 12:13:39 by amarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/ft_ls.h"

char		*file_date(struct stat *st)
{
	char	*str;
	char	*str2;

	str = (char *)malloc(sizeof(char) * 12);
	str2 = ctime(&st->st_mtime) + 4;
	if (str && str2)
	{
		str_ncpy(str, str2, 12);
		str[12] = '\0';
		return (str_join(add_color(str, RED), "  "));
	}
	return (NULL);
}
