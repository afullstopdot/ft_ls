/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_nlink.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 11:09:47 by amarquez          #+#    #+#             */
/*   Updated: 2016/11/17 13:03:51 by amarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/ft_ls.h"

char		*file_nlink(struct stat *st)
{
	char	*nlink;

	nlink = str_dup(ft_itoa(st->st_nlink));
	if (nlink)
	{
		if ((nlink = add_color(nlink, CYAN)))
			if ((nlink = str_join(nlink, " ")))
				return (nlink);
	}
	else
		perror("ft_ls error: ");
	return (NULL);
}
