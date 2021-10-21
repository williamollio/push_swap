/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wollio <wollio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 16:49:32 by wollio            #+#    #+#             */
/*   Updated: 2021/10/21 14:51:15 by wollio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_list(t_stack **head_a)
{
	t_stack	*tmp;

	tmp = *head_a;
	while (tmp != NULL)
	{
		free(tmp);
		tmp = tmp->next;
	}
}

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_parse	parse;
	char	**arr;

	stack_a = NULL;
	stack_b = NULL;
	arr = ft_parse_input(argc, argv, &parse);
	ft_put_in_list(&stack_a, arr);
	if (check_error(&stack_a))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	ft_sorting(&stack_a, &stack_b);
	free_list(&stack_a);
	return (0);
}
