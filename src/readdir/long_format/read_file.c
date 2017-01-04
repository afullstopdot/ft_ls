/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 10:44:57 by amarquez          #+#    #+#             */
/*   Updated: 2016/11/17 13:06:54 by amarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/ft_ls.h"

char	*get_full_info(char *name)
{
	struct stat st;
	char		*long_format;

	if (name)
	{
		if (lstat(name, &st) == -1)
			perror("ft_ls error: ");
		else
		{
			long_format = str_join(file_type(&st), file_rights(&st));
			long_format = str_join(long_format, file_nlink(&st));
			long_format = str_join(long_format, file_users(&st));
			long_format = str_join(long_format, file_date(&st));
			return (long_format);
		}
	}
	else
		perror("ft_ls error: ");
	return (NULL);
}
