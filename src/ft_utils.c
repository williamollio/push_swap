/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wollio <wollio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 17:50:16 by wollio            #+#    #+#             */
/*   Updated: 2021/10/21 14:49:57 by wollio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_put_in_list(t_stack **stack, char **arr)
{
	int		i;
	long	nbr;

	i = 0;
	nbr = 0;
	while (arr[i])
	{
		nbr = ft_atol(arr[i]);
		if (nbr > INT32_MAX || nbr < INT32_MIN
			|| (nbr == 0 && ft_strncmp(arr[i], "0", 1)))
		{
			free_list(stack);
			ft_free2(arr);
			write(2, "Error\n", 6);
			exit(0);
		}
		add_back(stack, nbr);
		i++;
	}
	ft_free2(arr);
}

void	ft_print(char *s, char c)
{
	ft_putstr_fd(s, 1);
	write(1, &c, 1);
	write(1, "\n ", 1);
}
