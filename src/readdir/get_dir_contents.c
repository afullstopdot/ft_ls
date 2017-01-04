/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dir_contents.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 12:55:49 by amarquez          #+#    #+#             */
/*   Updated: 2016/11/17 13:20:26 by amarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_ls.h"

char		**get_contents(struct s_ls *ls, char *dir)
{
	char			**dir_contents;
	size_t			size;
	int				count;

	count = 0;
	dir_contents = NULL;
	if (is_dir(dir) == 1)
	{
		size = dir_size(ls, dir);
		dir_contents = read_dir(ls, dir, size);
		if (ls->active->l)
		{
			put_str_e(file_total(dir_contents));
			clean_l(dir_contents, dir);
		}
		else
			clean(dir_contents, dir);
	}
	else
		dir_contents = read_file(ls, dir);
	return (dir_contents);
}
