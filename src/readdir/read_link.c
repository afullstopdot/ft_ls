/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_link.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 09:07:30 by amarquez          #+#    #+#             */
/*   Updated: 2016/11/17 13:01:35 by amarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_ls.h"

static	void		read_fail(ssize_t read, struct stat *st)
{
	if (read == -1)
	{
		perror("ft_ls error: ");
		exit(EXIT_FAILURE);
	}
	if (read > st->st_size)
	{
		perror("ft_ls error: ");
		exit(EXIT_FAILURE);
	}
}

static	char		*remove_full(char *dir_n, char *dir)
{
	char			*new;

	new = NULL;
	if (str_len(dir) == 1 && (dir[0] == '/' || dir[0] == '~'))
		new = str_dup(str_split(dir_n, '/')[0]);
	else
		new = str_dup(str_split(dir_n, '/')[1]);
	if (new)
		return (new);
	return (NULL);
}

char				*link_info(char *name, char *dir)
{
	struct stat		st;
	ssize_t			read;
	char			*link_name;
	char			*temp;

	temp = NULL;
	if (lstat(name, &st) == -1)
		perror("ft_ls error: ");
	else
	{
		link_name = (char *)malloc(sizeof(char) * st.st_size + 1);
		if (link_name)
		{
			read = readlink(name, link_name, st.st_size + 1);
			read_fail(read, &st);
			link_name[read] = '\0';
			temp = str_join(remove_full(name, dir), add_color(str_dup(" -> "),
						RED));
			return (str_join(temp, add_color(link_name, YELLOW)));
		}
	}
	return (NULL);
}
