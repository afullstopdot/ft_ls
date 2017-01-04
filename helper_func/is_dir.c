/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_dir.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 13:07:14 by amarquez          #+#    #+#             */
/*   Updated: 2016/11/16 17:16:06 by amarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int		is_dir(char *path)
{
	struct stat	st;
	int			stat;

	stat = lstat(path, &st);
	if (stat == -1)
	{
		perror("ft_ls error: ");
		return (-1);
	}
	else
		return (S_ISDIR(st.st_mode));
	return (0);
}
