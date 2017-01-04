/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 09:41:29 by amarquez          #+#    #+#             */
/*   Updated: 2016/11/16 17:15:21 by amarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static	int	check_dash(char **argv)
{
	char	**tmp;
	int		count;

	tmp = argv;
	count = 0;
	while (*tmp)
	{
		if (str_chr(*tmp, '-'))
			count++;
		tmp++;
	}
	return (count);
}

int			check_if_dir(int argc, char **argv)
{
	int	mult;

	mult = check_dash(argv);
	if (mult > 0)
	{
		if ((mult + 1) == argc)
			return (1);
		else
			return (2);
	}
	return (3);
}
