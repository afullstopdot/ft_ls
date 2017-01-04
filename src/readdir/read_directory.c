/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_directory.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 10:55:22 by amarquez          #+#    #+#             */
/*   Updated: 2016/11/17 11:35:17 by amarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_ls.h"

void		help(char **dir_c, struct s_ls *ls, char *dir, DIR *p_dir)
{
	struct dirent	*drnt;
	int				count;

	count = 0;
	while ((drnt = readdir(p_dir)) != NULL)
		if (ls->active->a)
		{
			if (!str_chr(dir, '/'))
				dir_c[count] = str_join(str_join(dir, "/"), drnt->d_name);
			else
				dir_c[count] = str_join(dir, drnt->d_name);
			count++;
		}
		else
		{
			if ((drnt->d_name[0] != '.'))
			{
				if (!str_chr(dir, '/'))
					dir_c[count] = str_join(str_join(dir, "/"), drnt->d_name);
				else
					dir_c[count] = str_join(dir, drnt->d_name);
				count++;
			}
		}
}

char		**read_dir(struct s_ls *ls, char *dir, size_t size)
{
	DIR				*p_dir;
	char			**dir_contents;

	if ((dir_contents = (char **)malloc(sizeof(char *) * (size + 1))))
	{
		if ((p_dir = opendir(dir)))
		{
			help(dir_contents, ls, dir, p_dir);
			dir_contents[size] = NULL;
			if (ls->active->t)
			{
				sort_time(dir_contents, d_strlen(dir_contents));
				if (ls->active->r)
					dir_contents = str_rev(dir_contents);
			}
			else
			{
				sort_char(dir_contents);
				if (ls->active->r)
					dir_contents = str_rev(dir_contents);
			}
			closedir(p_dir);
		}
	}
	return (dir_contents);
}
