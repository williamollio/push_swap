/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to_a5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wollio <wollio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 19:21:16 by wollio            #+#    #+#             */
/*   Updated: 2021/10/12 19:25:13 by wollio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_insert_mov_tool(t_stack **head_a, t_length *length, t_stack *tmpb)
{
	t_stack	*min;
	t_stack	*min2;
	int		lengtha;

	min2 = NULL;
	lengtha = length->a;
	ft_init_flag2(head_a);
	min = get_the_smallest_index(head_a);
	while (lengtha--)
	{
		if (min->index - tmpb->index > 0)
		{
			r_or_rra(tmpb, length, min->pos, 0);
			break ;
		}
		min2 = get_next_smallest_index(head_a, min);
		min = min2;
	}
}

void	ft_insert_mov(t_stack **head_a, t_stack *tmpb, t_length *length)
{
	t_stack	*min;
	t_stack	*max;

	tmpb->mov = 1;
	ft_init_r_rr(tmpb);
	r_or_rrb(tmpb, length, tmpb->pos);
	max = get_the_biggest_index(head_a);
	if (tmpb->index == 0)
	{
		min = get_the_smallest_index(head_a);
		r_or_rra(tmpb, length, min->pos, 0);
		return ;
	}
	else if (tmpb->index > max->index)
		r_or_rra(tmpb, length, max->pos, 1);
	else
		ft_insert_mov_tool(head_a, length, tmpb);
}

void	ft_calculator(t_stack **head_a, t_stack **head_b, t_length *length)
{
	t_stack	*tmpb;

	tmpb = *head_b;
	ft_insert_pos(*head_a);
	ft_insert_pos(*head_b);
	length->a = lengtha_list_modif(*head_a, length);
	length->b = lengthb_list_modif(*head_b, length);
	while (tmpb != NULL)
	{
		ft_insert_mov(head_a, tmpb, length);
		tmpb = tmpb->next;
	}
}
