/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_exists.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 08:57:25 by amarquez          #+#    #+#             */
/*   Updated: 2016/11/17 08:57:49 by amarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_ls.h"

int				file_exist(char *file)
{
	struct stat	st;
	int			stat;

	stat = lstat(file, &st);
	if (stat == -1)
	{
		perror("ft_ls error: ");
		return (-1);
	}
	return (1);
}
