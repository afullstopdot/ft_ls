/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_split.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/26 10:43:52 by amarquez          #+#    #+#             */
/*   Updated: 2016/11/09 10:44:09 by amarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static void	copy_contents(char ***res, char *str, int *loop, int *strs)
{
	int		chars;
	char	c;

	c = str[(loop[0])++];
	chars = 0;
	while (str[loop[0]] != '\0' && str[loop[0]] != c)
		res[0][strs[0]][chars++] = str[(loop[0])++];
	(strs[0])++;
	(loop[0])++;
}

char		**str_split(char *str, char d)
{
	char	**result;
	int		loop;
	int		strings;
	int		chars;

	loop = 0;
	strings = 0;
	mem_for_str_split(&result, str, d);
	while (str[loop] != '\0')
		if (str[loop] != d)
		{
			if (str[loop] != '\'' && str[loop] != '"')
			{
				chars = 0;
				while (str[loop] != '\0' && str[loop] != d)
					result[strings][chars++] = str[loop++];
				strings++;
			}
			else
				copy_contents(&result, str, &loop, &strings);
		}
		else
			loop++;
	return (result);
}
