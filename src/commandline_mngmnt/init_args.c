/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 09:29:41 by amarquez          #+#    #+#             */
/*   Updated: 2016/11/17 09:27:56 by amarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_ls.h"

static	struct s_arguments	*init_args(int argc)
{
	struct s_arguments		*ls_args;

	ls_args = (struct s_arguments *)malloc(sizeof(struct s_arguments));
	if (ls_args)
	{
		ls_args->flags = 0;
		ls_args->files = 0;
		if (argc == 2)
			ls_args->flags = 1;
		if (argc > 2)
		{
			ls_args->flags = 1;
			ls_args->files = 1;
		}
	}
	return (ls_args);
}

static	struct s_multi		*init_multi(char *cmd)
{
	struct s_multi			*multi;

	multi = (struct s_multi *)malloc(sizeof(struct s_multi));
	if (multi)
	{
		multi->a = 0;
		multi->t = 0;
		multi->r = 0;
		multi->l = 0;
		while (*cmd)
		{
			if (*cmd == 'a')
				multi->a = 1;
			if (*cmd == 't')
				multi->t = 1;
			if (*cmd == 'r')
				multi->r = 1;
			if (*cmd == 'l')
				multi->l = 1;
			cmd++;
		}
	}
	else
		perror("ft_ls error: ");
	return (multi);
}

struct	s_ls				*init(int argc, char **argv)
{
	struct s_ls				*ls_init;

	ls_init = (struct s_ls *)malloc(sizeof(struct s_ls));
	if (ls_init)
	{
		ls_init->active = init_multi(argv[1] + 1);
		ls_init->args_details = init_args(argc);
		ls_init->file_args = init_filelist(argc, argv, ls_init->active);
		ls_init->flag = argv[1];
		ls_init->argc = argc;
		return (ls_init);
	}
	else
		perror("ft_ls error: ");
	return (NULL);
}
