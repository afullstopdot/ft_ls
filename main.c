/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 12:57:46 by amarquez          #+#    #+#             */
/*   Updated: 2016/11/17 13:30:20 by amarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

static	void	ls(int argc, char **argv)
{
	struct s_ls			*ls;
	struct s_filelist	*dirs;
	int					size;

	ls = init(argc, argv);
	dirs = ls->file_args;
	size = count(dirs);
	if (size > 1)
	{
		while (dirs)
		{
			print_dir_name(dirs->dir_name);
			if (file_exist(dirs->dir_name) == 1)
			{
				print_p(get_contents(ls, dirs->dir_name));
			}
			if ((dirs = dirs->next))
				put_char('\n');
		}
	}
	else
	{
		if (file_exist(dirs->dir_name) == 1)
			print_p(get_contents(ls, dirs->dir_name));
	}
}

int				main(int argc, char **argv)
{
	default_args(&argc, &argv);
	create_new_args(&argc, &argv);
	if (validate_args(argc, argv))
		ls(argc, argv);
	else
		cmd_nf(argv[1]);
	return (0);
}
