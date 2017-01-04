/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_l.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 08:15:47 by amarquez          #+#    #+#             */
/*   Updated: 2016/11/17 12:52:41 by amarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static	void		helper(char **dir, char *dir_n, struct stat *st, int c)
{
	if (str_len(dir_n) == 1 && (dir_n[0] == '/' || dir_n[0] == '~'))
	{
		if ((st->st_mode & S_IFMT) == S_IFLNK)
			dir[c] =
				str_join(get_full_info(dir[c]), dir_n);
		else
			dir[c] =
				str_join(get_full_info(dir[c]), split_dir(dir[c], dir_n));
	}
	else
	{
		if ((st->st_mode & S_IFMT) == S_IFLNK)
			dir[c] =
				str_join(get_full_info(dir[c]), link_info(dir[c], dir_n));
		else
			dir[c] =
				str_join(get_full_info(dir[c]), split_dir(dir[c], dir_n));
	}
}

void				clean_l(char **dir, char *dir_n)
{
	int				count;
	struct stat		st;

	count = 0;
	while (dir[count])
	{
		if (lstat(dir[count], &st) == -1)
			perror("ft_ls error: ");
		else
			helper(dir, dir_n, &st, count);
		count++;
	}
}
