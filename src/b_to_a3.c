/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_b_to_a3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wollio <wollio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 18:13:14 by wollio            #+#    #+#             */
/*   Updated: 2021/10/12 18:27:21 by wollio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*get_the_smallest_mov(t_stack **head_b)
{
	t_stack	*tmpb;
	t_stack	*min;
	int		min_nbr;

	min_nbr = INT_MAX;
	tmpb = (*head_b);
	while (tmpb->next != NULL)
	{
		if (min_nbr > tmpb->mov)
		{
			min = tmpb;
			min_nbr = tmpb->mov;
		}
		tmpb = tmpb->next;
	}
	if (min_nbr > tmpb->mov)
	{
		min = tmpb;
		min_nbr = tmpb->mov;
	}
	return (min);
}

t_stack	*get_the_smallest_index(t_stack **head_a)
{
	t_stack	*tmpa;
	t_stack	*min;
	int		min_nbr;

	min_nbr = INT_MAX;
	tmpa = (*head_a);
	while (tmpa->next != NULL)
	{
		if (min_nbr > tmpa->index)
		{
			min = tmpa;
			min_nbr = tmpa->index;
		}
		tmpa = tmpa->next;
	}
	if (min_nbr > tmpa->index)
	{
		min = tmpa;
		min_nbr = tmpa->index;
	}
	return (min);
}

t_stack	*get_the_biggest_index(t_stack **head_a)
{
	t_stack	*tmpa;
	t_stack	*max;
	int		max_nbr;

	max_nbr = INT_MIN;
	tmpa = (*head_a);
	while (tmpa->next != NULL)
	{
		if (max_nbr < tmpa->index)
		{
			max = tmpa;
			max_nbr = tmpa->index;
		}
		tmpa = tmpa->next;
	}
	if (max_nbr < tmpa->index)
	{
		max = tmpa;
		max_nbr = tmpa->index;
	}
	return (max);
}

t_stack	*get_next_smallest_index(t_stack **head_a, t_stack *min)
{
	t_stack	*temp;
	t_stack	*min_next;
	int		first;
	int		second;

	min->flag2 = 1;
	second = 10000;
	first = min->index;
	temp = *head_a;
	while (temp != NULL)
	{
		if (temp->index < first && temp->flag2 != 1)
		{
			second = first;
			first = temp->data;
		}
		else if (temp->index < second && temp->index != first
			&& temp->flag2 != 1)
		{
			second = temp->index;
			min_next = temp;
		}
		temp = temp->next;
	}
	return (min_next);
}

void	ft_init_flag2(t_stack **head_a)
{
	t_stack	*tmp;

	tmp = *head_a;
	while (tmp != NULL)
	{
		tmp->flag2 = 0;
		tmp = tmp->next;
	}
}
