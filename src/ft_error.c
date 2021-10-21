/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wollio <wollio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 21:12:58 by wollio            #+#    #+#             */
/*   Updated: 2021/10/21 14:40:35 by wollio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_error(int argc, char *argv[])
{
	if (argc == 1)
		exit(0);
	else if (argc == 2 && argv == '\0')
	{
		write(2, "Error\n", 6);
		exit(0);
	}
}

int	if_same(t_stack **head_a)
{
	t_stack	*tmp;
	t_stack	*tmp1;
	int		i;

	i = 0;
	tmp = *head_a;
	while (tmp->next != NULL)
	{
		tmp1 = tmp->next;
		while (tmp1->next != NULL)
		{
			if (tmp->data == tmp1->data)
				return (1);
			tmp1 = tmp1->next;
		}
		if (tmp->data == tmp1->data)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	if_sorted(t_stack **head_a)
{
	t_stack	*tmp;
	int		previous;

	tmp = *head_a;
	while (tmp->next != NULL)
	{
		if (tmp->data > tmp->next->data)
			return (0);
		previous = tmp->data;
		tmp = tmp->next;
	}
	if (previous > tmp->data)
		return (0);
	return (1);
}

int	if_one(t_stack **head_a)
{
	if (length_list(*head_a) == 1)
		return (1);
	return (0);
}

int	check_error(t_stack **head_a)
{
	if (if_same(head_a))
		return (1);
	else if (if_sorted(head_a))
		exit(0);
	else if (if_one(head_a))
		exit(0);
	return (0);
}
