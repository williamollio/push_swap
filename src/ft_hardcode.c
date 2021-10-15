/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hardcode.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wollio <wollio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 14:37:56 by wollio            #+#    #+#             */
/*   Updated: 2021/10/12 17:09:04 by wollio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*get_the_smallest_element(t_stack **head_a)
{
	t_stack	*tmpa;
	t_stack	*min;
	int		min_nbr;

	min_nbr = INT_MAX;
	tmpa = (*head_a);
	while (tmpa->next != NULL)
	{
		if (min_nbr > tmpa->data)
		{
			min = tmpa;
			min_nbr = tmpa->data;
		}
		tmpa = tmpa->next;
	}
	if (min_nbr > tmpa->data)
	{
		min = tmpa;
		min_nbr = tmpa->data;
	}
	return (min);
}

void	ft_three(t_stack **head_a)
{
	int	a;
	int	b;
	int	c;

	a = (*head_a)->data;
	b = (*head_a)->next->data;
	c = (*head_a)->next->next->data;
	if (a > b && b > c && a > c)
	{
		ft_swap(head_a, 'a');
		ft_rrotate(head_a, 'a');
	}
	else if (a > b && b < c && a > c)
		ft_rotate(head_a, 'a');
	else if (a > b && b < c && a < c)
		ft_swap(head_a, 'a');
	else if (a < b && b > c && a > c)
		ft_rrotate(head_a, 'a');
	else if (a < b && b > c && a < c)
	{
		ft_rrotate(head_a, 'a');
		ft_swap(head_a, 'a');
	}
}

void	ft_four(t_stack **head_a, t_stack **head_b)
{
	t_stack	*min;

	min = get_the_smallest_element(head_a);
	ft_insert_pos(*head_a);
	if (min->pos == 1)
		ft_rotate(head_a, 'a');
	else if (min->pos == 2)
	{
		ft_rotate(head_a, 'a');
		ft_rotate(head_a, 'a');
	}
	else if (min->pos == 3)
		ft_rrotate(head_a, 'a');
	ft_push(head_a, head_b, 'b');
	ft_three(head_a);
	ft_push(head_b, head_a, 'a');
}

static void	ft_five_tool(t_stack **head_a, t_stack **head_b, t_stack *min)
{
	t_stack	*temp;

	ft_insert_pos(*head_a);
	if (min->pos == 1)
		ft_rotate(head_a, 'a');
	else if (min->pos == 2)
	{
		ft_rotate(head_a, 'a');
		ft_rotate(head_a, 'a');
	}
	else if (min->pos == 3)
		ft_rrotate(head_a, 'a');
	ft_push(head_a, head_b, 'b');
	ft_three(head_a);
	temp = *head_b;
	if (temp->data < temp->next->data)
		ft_rotate(head_b, 'b');
	ft_push(head_b, head_a, 'a');
	ft_push(head_b, head_a, 'a');
}

void	ft_five(t_stack **head_a, t_stack **head_b)
{
	t_stack	*min;

	min = get_the_smallest_element(head_a);
	ft_insert_pos(*head_a);
	if (min->pos == 1)
		ft_rotate(head_a, 'a');
	else if (min->pos == 2)
	{
		ft_rotate(head_a, 'a');
		ft_rotate(head_a, 'a');
	}
	else if (min->pos == 3)
	{
		ft_rrotate(head_a, 'a');
		ft_rrotate(head_a, 'a');
	}
	else if (min->pos == 4)
	{
		ft_rrotate(head_a, 'a');
	}
	ft_push(head_a, head_b, 'b');
	min = get_the_smallest_element(head_a);
	ft_five_tool(head_a, head_b, min);
}
