/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 08:13:40 by amarquez          #+#    #+#             */
/*   Updated: 2016/11/17 12:52:16 by amarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static	void		helper(char **content, char *dir, struct stat *st, int c)
{
	if (str_len(dir) == 1 && (dir[0] == '/' || dir[0] == '~'))
	{
		if ((st->st_mode & S_IFMT) == S_IFDIR)
			content[c] =
				add_color(str_split(content[c], '/')[0], CYAN);
		if ((st->st_mode & S_IFMT) == S_IFREG)
			content[c] =
				add_color(str_split(content[c], '/')[0], YELLOW);
		if ((st->st_mode & S_IFMT) == S_IFLNK)
			content[c] =
				add_color(str_split(content[c], '/')[0], GREEN);
	}
	else
	{
		if ((st->st_mode & S_IFMT) == S_IFDIR)
			content[c] =
				add_color(str_split(content[c], '/')[1], CYAN);
		if ((st->st_mode & S_IFMT) == S_IFREG)
			content[c] =
				add_color(str_split(content[c], '/')[1], YELLOW);
		if ((st->st_mode & S_IFMT) == S_IFLNK)
			content[c] =
				add_color(str_split(content[c], '/')[1], GREEN);
	}
}

void				clean(char **dir_content, char *dir)
{
	size_t			count;
	struct stat		st;

	count = 0;
	while (dir_content[count])
	{
		if (lstat(dir_content[count], &st) == -1)
			perror("ft_ls error: ");
		else
			helper(dir_content, dir, &st, count);
		count++;
	}
}
