/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_dir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 08:18:19 by amarquez          #+#    #+#             */
/*   Updated: 2016/11/17 08:18:56 by amarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

char		*split_dir(char *dir_n, char *dir)
{
	char			*name;

	name = NULL;
	if (str_len(dir) == 1 && (dir[0] == '/' || dir[0] == '~'))
		name = str_split(dir_n, '/')[0];
	else
		name = str_split(dir_n, '/')[1];
	if (name)
		return (name);
	return (NULL);
}
