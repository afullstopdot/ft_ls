/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_f.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 11:47:56 by amarquez          #+#    #+#             */
/*   Updated: 2016/11/17 11:47:58 by amarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_ls.h"

char		**read_file(struct s_ls *ls, char *dir)
{
	char	**dir_contents;

	if ((dir_contents = (char **)malloc(sizeof(char *) * 2)))
	{
		dir_contents[1] = NULL;
		if (ls->active->l)
		{
			if (is_dir(dir) != -1)
				dir_contents[0] = get_full_info(dir);
		}
		else
		{
			if (is_dir(dir) == -1)
				exit(EXIT_FAILURE);
			else
				dir_contents[0] = str_dup(dir);
		}
	}
	else
		perror("ft_ls error: ");
	return (dir_contents);
}
