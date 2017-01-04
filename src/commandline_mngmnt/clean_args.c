/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 10:28:15 by amarquez          #+#    #+#             */
/*   Updated: 2016/11/17 12:59:16 by amarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_ls.h"

static char		*join_commands(int num, char **argv)
{
	char	*dest;
	int		count;

	count = 0;
	dest = str_dup("-");
	if (dest)
	{
		while (count < num)
		{
			argv[count] = str_dup(argv[count] + 1);
			dest = str_join(dest, argv[count]);
			count++;
		}
		sort_str(&dest);
		remove_dup(dest);
		return (dest);
	}
	else
		perror("ft_ls error: ");
	return (NULL);
}

static	char	**new_argv(char **argv, int argc, char *commands, int multiple)
{
	char	**args;
	int		count;

	count = 2;
	args = (char **)malloc(sizeof(char *) * argc + 1);
	if (args)
	{
		args[0] = str_dup(argv[0]);
		args[1] = str_dup(commands);
		while (count < argc)
		{
			args[count] = str_dup(argv[count + multiple - 1]);
			count++;
		}
		args[count] = NULL;
		return (args);
	}
	else
		perror("ft_ls error:");
	return (NULL);
}

int				ft_multiple_args(int argc, char **argv)
{
	char	**args;
	int		i;
	int		x;

	x = 0;
	i = 0;
	args = argv;
	while (i < argc)
	{
		if (str_chr(*argv, '-'))
			x++;
		argv++;
		i++;
	}
	if (x == 1 && str_len(args[1]) > 2)
		return (1);
	if (x > 1)
		return (x);
	return (0);
}

void			create_new_args(int *argc, char ***argv)
{
	char	**args;
	int		mult;

	mult = ft_multiple_args(*argc, *argv);
	args = *argv;
	if (mult > 1)
	{
		*argc = *argc - mult + 1;
		*argv = new_argv(*argv, *argc, join_commands(mult, (*argv + 1)), mult);
		if (!argv)
		{
			perror("ft_ls error: ");
			exit(1);
		}
	}
	else
	{
		sort_str(&args[1]);
		remove_dup(args[1]);
	}
}
