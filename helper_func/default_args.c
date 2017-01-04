/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   default_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 09:33:52 by amarquez          #+#    #+#             */
/*   Updated: 2016/11/17 08:11:55 by amarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static	void	default_arg1(int *argc, char ***argv)
{
	char		**new;

	new = (char **)malloc(sizeof(char *) * 4);
	if (new)
	{
		new[0] = str_dup((*argv)[0]);
		new[1] = str_dup("-R");
		new[2] = str_dup(".");
		new[3] = NULL;
		*argv = new;
		*argc = 3;
	}
}

static	void	default_arg2(int *argc, char ***argv)
{
	char		**new;
	int			count;

	count = 1;
	new = (char **)malloc(sizeof(char *) * ((*argc) + 2));
	if (new)
	{
		new[0] = str_dup((*argv)[0]);
		while (*((*argv) + count))
		{
			new[count] = str_dup(*((*argv) + count));
			count++;
		}
		new[count] = str_dup(".");
		new[count + 1] = NULL;
		*argv = new;
		*argc = *argc + 1;
	}
}

static	void	default_arg3(int *argc, char ***argv)
{
	char		**new;
	int			count;

	count = 2;
	new = (char **)malloc(sizeof(char *) * (*argc + 2));
	if (new)
	{
		new[0] = str_dup((*argv)[0]);
		new[1] = str_dup("-R");
		while (*((*argv) + (count - 1)))
		{
			new[count] = str_dup(*((*argv) + (count - 1)));
			count++;
		}
		new[count] = NULL;
		*argv = new;
		*argc = *argc + 1;
	}
}

void			default_args(int *argc, char ***argv)
{
	char		**new;
	int			check;

	new = NULL;
	check = 0;
	if (*argc == 1)
	{
		default_arg1(argc, argv);
	}
	else if (*argc > 1)
	{
		if ((check = check_if_dir(*argc, *argv)) == 1)
			default_arg2(argc, argv);
		if (check == 3)
			default_arg3(argc, argv);
	}
}
