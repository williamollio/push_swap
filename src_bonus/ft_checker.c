/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wollio <wollio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 18:46:47 by wollio            #+#    #+#             */
/*   Updated: 2021/10/15 13:58:25 by wollio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_parse	parse;
	char	**arr;
	char	*buffer;

	stack_a = NULL;
	stack_b = NULL;
	buffer = NULL;
	arr = ft_parse_input(argc, argv, &parse);
	ft_put_in_list(&stack_a, arr);
	if (check_error2(&stack_a))
	{
		write(2, "Error\n", 6);
		exit(0);
	}
	ft_free2(arr);
	buffer = ft_reading(buffer, &stack_a);
	ft_instructions(&stack_a, &stack_b, buffer);
	if (stack_b != NULL)
	{
		write(1, "KO\n", 3);
		exit(0);
	}
	write(1, "OK\n", 3);
}
