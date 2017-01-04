/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_rights.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 11:45:32 by amarquez          #+#    #+#             */
/*   Updated: 2016/11/17 13:07:56 by amarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/ft_ls.h"

static	char		*u_rights(struct stat *st)
{
	char	*rights;

	rights = str_dup("---");
	if (rights)
	{
		if (st->st_mode & S_IRUSR)
			rights[0] = 'r';
		if (st->st_mode & S_IWUSR)
			rights[1] = 'w';
		if (st->st_mode & S_IXUSR)
			rights[2] = 'x';
		return (add_color(rights, CYAN));
	}
	else
		perror("ft_ls error: ");
	return (NULL);
}

static	char		*g_rights(struct stat *st)
{
	char	*rights;

	rights = str_dup("---");
	if (rights)
	{
		if (st->st_mode & S_IRGRP)
			rights[0] = 'r';
		if (st->st_mode & S_IWGRP)
			rights[1] = 'w';
		if (st->st_mode & S_IXGRP)
			rights[2] = 'x';
		return (add_color(rights, MAGENTA));
	}
	else
		perror("ft_ls error: ");
	return (NULL);
}

static	char		*a_rights(struct stat *st)
{
	char	*rights;

	rights = str_dup("---");
	if (rights)
	{
		if (st->st_mode & S_IROTH)
			rights[0] = 'r';
		if (st->st_mode & S_IWOTH)
			rights[1] = 'w';
		if (st->st_mode & S_IXOTH)
			rights[2] = 'x';
		return (str_join(add_color(rights, YELLOW), "  "));
	}
	else
		perror("ft_ls error: ");
	return (NULL);
}

char				*file_rights(struct stat *st)
{
	return (str_join(u_rights(st), str_join(g_rights(st), a_rights(st))));
}
