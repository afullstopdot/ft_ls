/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_for_str_split.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/26 10:40:17 by amarquez          #+#    #+#             */
/*   Updated: 2016/11/09 10:38:50 by amarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static void	count_strs(char *str, char delimiter, int *strs, int *loop)
{
	char	c;

	if (str[loop[0]] != '\'' && str[loop[0]] != '"')
	{
		(strs[0])++;
		while (str[loop[0]] != '\0' && str[loop[0]] != delimiter)
			(loop[0])++;
	}
	else
	{
		c = str[(loop[0])++];
		(strs[0])++;
		while (str[loop[0]] != '\0' && str[loop[0]] != c)
			(loop[0])++;
		(loop[0])++;
	}
}

static void	alloc_mem_for_2d_arr(char ***result, char *str, char delimiter)
{
	int	strs;
	int	loop;

	loop = 0;
	strs = 0;
	while (str[loop] != '\0')
	{
		if (str[loop] != delimiter)
			count_strs(str, delimiter, &strs, &loop);
		else
			loop++;
	}
	result[0] = (char**)malloc(sizeof(char*) * strs + 1);
	result[0][strs] = (char*)'\0';
}

static void	count_chars(char ***res, char *str, int *strs, int *l)
{
	int		chars;
	char	c;

	c = str[(l[0])++];
	chars = 0;
	while (str[l[0]] != '\0' && str[(l[0])++] != c)
		chars++;
	(l[0])++;
	res[0][strs[0]] = str_new(chars);
	(strs[0])++;
}

static void	alloc_mem_for_strings(char ***result, char *str, char delimiter)
{
	int		loop;
	int		string;
	int		chars;

	loop = 0;
	string = 0;
	while (str[loop] != '\0')
	{
		if (str[loop] != delimiter)
		{
			if (str[loop] != '"' && str[loop] != '\'')
			{
				chars = 0;
				while (str[loop] != '\0' && str[loop++] != delimiter)
					chars++;
				result[0][string] = str_new(chars);
				string++;
			}
			else
				count_chars(result, str, &string, &loop);
		}
		else
			loop++;
	}
}

void		mem_for_str_split(char ***result, char *str, char delimiter)
{
	alloc_mem_for_2d_arr(result, str, delimiter);
	if (result[0] != NULL)
		alloc_mem_for_strings(result, str, delimiter);
}
