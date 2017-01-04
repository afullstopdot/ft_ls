/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 12:25:52 by amarquez          #+#    #+#             */
/*   Updated: 2016/11/17 11:33:53 by amarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void				sort_struct_t(struct s_filelist *txt)
{
	struct stat		a;
	struct stat		b;
	int				n;
	int				i;
	int				j;

	i = 0;
	j = 0;
	n = count(txt);
	while (i++ < n)
	{
		while (j < n)
		{
			if (txt->next)
			{
				if (!(lstat(txt->dir_name, &a) < 0 ||
							lstat(txt->next->dir_name, &b) < 0))
					if (a.st_mtime < b.st_mtime)
						swap_d(&txt->dir_name, &txt->next->dir_name);
				txt = txt->next;
			}
			j++;
		}
		j = 0;
	}
}

void				sort_struct(struct s_filelist *txt)
{
	int				n;
	int				i;
	int				j;

	i = 0;
	j = 0;
	n = count(txt);
	while (i++ < n)
	{
		while (j < n)
		{
			if (txt->next)
			{
				if (str_cmp(txt->dir_name, txt->next->dir_name) > 0)
					swap_d(&txt->dir_name, &txt->next->dir_name);
				txt = txt->next;
			}
			j++;
		}
		j = 0;
	}
}

void				sort_time(char **content, int n)
{
	struct stat		a;
	struct stat		b;
	int				i;
	int				j;

	i = 0;
	j = 0;
	while (i++ < n - 1)
	{
		while (j < n - 1)
		{
			if (lstat(content[j], &a) < 0 || lstat(content[j + 1], &b) < 0)
				perror("ft_ls erro: ");
			else
			{
				if (a.st_mtime < b.st_mtime)
					swap_d(&content[j], &content[j + 1]);
			}
			j++;
		}
		j = 0;
	}
}

void				sort_char(char **txt)
{
	int				n;
	int				i;
	int				j;

	i = 0;
	j = 0;
	n = d_strlen(txt);
	while (i++ < n - 1)
	{
		while (j < n - 1)
		{
			if (str_cmp(txt[j], txt[j + 1]) > 0)
				swap_d(&txt[j], &txt[j + 1]);
			j++;
		}
		j = 0;
	}
}

void				sort_str(char **txt)
{
	char			*str;
	int				n;
	int				i;
	int				j;

	i = 0;
	j = 0;
	str = *txt;
	n = str_len(str);
	while (i++ < n - 1)
	{
		while (j < n - 1)
		{
			if ((int)str[j] > (int)str[j + 1])
				swap(&str[j], &str[j + 1]);
			j++;
		}
		j = 0;
	}
}
