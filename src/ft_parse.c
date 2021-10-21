/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wollio <wollio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 13:04:15 by wollio            #+#    #+#             */
/*   Updated: 2021/10/21 14:34:08 by wollio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_init(t_parse *parse)
{
	parse->str = NULL;
	parse->tmp = NULL;
	parse->tmp2 = NULL;
	parse->space = false;
	parse->arg = false;
}

void	ft_if_space(int argc, char *argv[], t_parse *parse)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] == ' ')
				parse->space = true;
			j++;
		}
		i++;
	}
	if (parse->space == true && argc == 2)
		parse->arg = true;
}

char	**ft_parse_input(int argc, char *argv[], t_parse *parse)
{
	ft_error(argc, argv);
	parse->space = 0;
	parse->i = 1;
	ft_init(parse);
	ft_if_space(argc, argv, parse);
	parse->str = ft_strdup("");
	while (parse->i < argc)
	{
		parse->arr = ft_split(argv[parse->i], ' ');
		parse->j = 0;
		while (parse->arr[parse->j])
		{
			parse->tmp = ft_strjoin(parse->arr[parse->j], "_");
			parse->tmp2 = parse->str;
			parse->str = ft_strjoin(parse->tmp2, parse->tmp);
			ft_free1(parse->tmp2);
			ft_free1(parse->tmp);
			parse->j++;
		}
		ft_free2(parse->arr);
		parse->i++;
	}
	parse->arr = ft_split(parse->str, '_');
	ft_free1(parse->str);
	return (parse->arr);
}
