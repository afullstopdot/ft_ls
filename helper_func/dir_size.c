/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 12:59:08 by amarquez          #+#    #+#             */
/*   Updated: 2016/11/17 13:41:53 by amarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

size_t				dir_size(struct s_ls *ls, char *dir)
{
	DIR				*p_dir;
	struct dirent	*p_dirent;
	size_t			i;

	i = 0;
	if ((p_dir = opendir(dir)) == NULL)
	{
		put_str_e("ft_ls: Permission denied ");
		exit(1);
	}
	else
	{
		while ((p_dirent = readdir(p_dir)) != NULL)
		{
			if (ls->active->a)
				i++;
			else
			{
				if ((p_dirent->d_name[0] != '.'))
					i++;
			}
		}
	}
	closedir(p_dir);
	return (i);
}
