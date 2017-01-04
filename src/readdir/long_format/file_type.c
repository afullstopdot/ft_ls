/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_type.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 10:50:47 by amarquez          #+#    #+#             */
/*   Updated: 2016/11/17 09:01:24 by amarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/ft_ls.h"

static	void	pop_arr(struct stat *st, char *perm)
{
	if ((st->st_mode & S_IFMT) & S_IFDIR)
		perm[0] = 'd';
	else if ((st->st_mode & S_IFMT) == S_IFLNK)
		perm[0] = 'l';
	else if ((st->st_mode & S_IFMT) == S_IFIFO)
		perm[0] = 'p';
	else if ((st->st_mode & S_IFMT) == S_IFCHR)
		perm[0] = 'c';
	else if ((st->st_mode & S_IFMT) == S_IFBLK)
		perm[0] = 'b';
	else if ((st->st_mode & S_IFMT) == S_IFSOCK)
		perm[0] = 's';
	else if ((st->st_mode & S_IFMT) == S_IFWHT)
		perm[0] = 'w';
	else
		perm[0] = '-';
	perm[1] = '\0';
}

char			*file_type(struct stat *st)
{
	char	*perm;

	perm = str_new(2);
	if (perm)
	{
		pop_arr(st, perm);
		return (perm);
	}
	else
		perror("ft_ls error: ");
	return (NULL);
}
