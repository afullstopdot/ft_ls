/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 16:32:11 by amarquez          #+#    #+#             */
/*   Updated: 2016/11/17 12:55:19 by amarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

struct	s_filelist		*struct_rev(struct s_filelist *root)
{
	struct s_filelist	*new_root;
	struct s_filelist	*next;

	new_root = NULL;
	while (root)
	{
		next = root->next;
		root->next = new_root;
		new_root = root;
		root = next;
	}
	return (new_root);
}

char					**str_rev(char **str)
{
	char				**new_str;
	int					len;
	int					count;

	len = d_strlen(str);
	count = 0;
	new_str = (char **)malloc(sizeof(char *) * len + 1);
	if (new_str)
	{
		while (str[count])
		{
			new_str[count] = str[(len - 1) - count];
			count++;
		}
		new_str[count] = NULL;
		return (new_str);
	}
	else
		perror("ft_ls error: ");
	return (NULL);
}
