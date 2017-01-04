/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_filelist.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 09:16:32 by amarquez          #+#    #+#             */
/*   Updated: 2016/11/17 09:27:48 by amarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_ls.h"

struct s_filelist	*create_node(char *dir_name)
{
	struct s_filelist		*next_node;

	next_node = (struct s_filelist *)malloc(sizeof(struct s_filelist));
	if (dir_name)
	{
		if (next_node)
		{
			next_node->dir_name = dir_name;
			return (next_node);
		}
	}
	return (NULL);
}

void				sort_s(struct s_multi *active, struct s_filelist *root)
{
	if (active->t)
	{
		sort_struct_t(root);
		if (active->r)
			root = struct_rev(root);
	}
	else
	{
		sort_struct(root);
		if (active->r)
			root = struct_rev(root);
	}
}

struct s_filelist	*init_filelist(int argc, char **argv, struct s_multi *act)
{
	struct s_filelist		*root;
	struct s_filelist		*current_node;
	int						count;

	count = 2;
	root = NULL;
	if (argc == 3)
	{
		root = create_node(argv[2]);
		root->next = NULL;
	}
	if (argc > 3)
	{
		root = create_node(argv[count++]);
		current_node = root;
		while (count < argc)
		{
			current_node->next = create_node(argv[count]);
			current_node = current_node->next;
			count++;
		}
		current_node->next = NULL;
		sort_s(act, root);
	}
	return (root);
}
