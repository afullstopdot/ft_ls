/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_opts.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 10:22:40 by amarquez          #+#    #+#             */
/*   Updated: 2016/11/10 10:31:54 by amarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_ls.h"

static int		check(char *arg)
{
	int		i;

	i = 0;
	while (*arg)
	{
		if (*arg == 't' || *arg == 'l' || *arg == 'a' ||
				*arg == 'r' || *arg == 'R')
			i++;
		arg++;
	}
	return (i);
}

int				validate_args(int argc, char **argv)
{
	char	*arg;
	int		i;
	int		len;

	i = 0;
	len = 0;
	if (argc == 1)
		return (1);
	if (argc > 1 && (len = str_len(*++argv)) > 0)
	{
		arg = *argv;
		i = 1;
		if (*arg++ == '-')
			i = i + check(arg);
		if (*--arg != '-')
			return (1);
	}
	if (len == i)
		return (1);
	return (0);
}
