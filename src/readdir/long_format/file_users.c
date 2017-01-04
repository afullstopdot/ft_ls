/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_users.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 11:29:05 by amarquez          #+#    #+#             */
/*   Updated: 2016/11/17 09:04:45 by amarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/ft_ls.h"

static	char	*get_size(struct stat *st)
{
	return (add_color(str_dup(ft_itoa((int)st->st_size)), CYAN));
}

static	char	*get_uid(struct stat *st)
{
	char			*user;
	struct passwd	*pwd;

	pwd = NULL;
	if ((pwd = getpwuid(st->st_uid)))
		user = str_dup(pwd->pw_name);
	else
		user = str_dup(ft_itoa(st->st_uid));
	if (user)
		return (str_join(add_color(user, GREEN), "  "));
	return (NULL);
}

static	char	*get_gid(struct stat *st)
{
	char			*group;
	struct group	*grp;

	grp = NULL;
	if ((grp = getgrgid(st->st_gid)) != NULL)
		group = str_dup(grp->gr_name);
	else
		group = str_dup(ft_itoa(st->st_gid));
	if (group)
		return (str_join(str_join(add_color(group, RED), "  "), get_size(st)));
	return (NULL);
}

char			*file_users(struct stat *st)
{
	if (st)
		return (str_join(str_join(get_uid(st), get_gid(st)), "  "));
	return (str_dup("st failure\n"));
}
