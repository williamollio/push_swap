/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wollio <wollio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 17:20:49 by wollio            #+#    #+#             */
/*   Updated: 2021/10/13 18:34:34 by wollio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	if_same2(t_stack **head_a)
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

int	if_sorted2(t_stack **head_a)
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

int	if_one2(t_stack **head_a)
{
	if (length_list(*head_a) == 1)
		return (1);
	return (0);
}

int	check_error2(t_stack **head_a)
{
	if (if_same2(head_a))
		return (1);
	else if (if_one2(head_a))
		return (1);
	return (0);
}
