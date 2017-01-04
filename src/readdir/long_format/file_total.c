/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_total.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 11:57:41 by amarquez          #+#    #+#             */
/*   Updated: 2016/11/17 12:39:00 by amarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/ft_ls.h"

char		*file_total(char **dirs)
{
	struct stat st;
	int			size;

	size = 0;
	if (dirs)
	{
		while (*dirs)
		{
			if (lstat(*dirs, &st) == -1)
				perror("ft_ls error: ");
			else
				size += st.st_blocks;
			dirs++;
		}
		return (str_join(str_dup("total "), ft_itoa(size)));
	}
	return (NULL);
}
