/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_to_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wollio <wollio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 10:58:26 by wollio            #+#    #+#             */
/*   Updated: 2021/10/12 17:02:36 by wollio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_init_flag_tool1(t_stack *head_a)
{
	t_stack	*temp;
	int		index_head2;

	index_head2 = head_a->index;
	temp = head_a->next;
	while (temp != NULL)
	{
		if (index_head2 + 1 == temp->index)
		{
			temp->flag = 1;
			index_head2++;
		}
		else
			temp->flag = 0;
		temp = temp->next;
	}
}

void	ft_init_flag1(t_stack **head_a, int index_head2)
{
	t_stack	*temp;
	int		i;

	i = 0;
	temp = *head_a;
	while (temp != NULL)
	{
		if (index_head2 == i)
		{
			temp->flag = 1;
			ft_init_flag_tool1(temp);
			return ;
		}
		else
			temp->flag = 0;
		i++;
		temp = temp->next;
	}
}

void	a_to_b1(t_stack **head_a, t_stack **head_b, int index_head2, int len1)
{
	int	i;
	int	length;
	int	j;

	i = 0;
	ft_init_flag1(head_a, index_head2);
	length = length_list(*head_a);
	j = length - len1;
	while (i < length && j)
	{
		if ((*head_a)->flag == 0)
		{
			ft_push(head_a, head_b, 'b');
			j--;
		}
		else if ((*head_a)->flag == 1)
			ft_rotate(head_a, 'a');
		i++;
	}
}

void	ft_init_flag0(t_stack *head_a, int index_head0, int len0)
{
	t_stack	*temp;
	int		i;
	int		previous;

	previous = 0;
	i = 0;
	temp = head_a;
	while (i != index_head0)
	{
		i++;
		temp->flag = 0;
		temp = temp->next;
	}
	while (len0--)
	{
		temp->flag = 1;
		temp = temp->next;
	}
}

void	a_to_b0(t_stack **head_a, t_stack **head_b, int index_head0, int len0)
{
	int	i;
	int	length;
	int	j;

	i = 0;
	ft_init_flag0(*head_a, index_head0, len0);
	length = length_list(*head_a);
	j = length - len0;
	while (i < length && j)
	{
		if ((*head_a)->flag == 0)
		{
			ft_push(head_a, head_b, 'b');
			j--;
		}
		else if ((*head_a)->flag == 1)
			ft_rotate(head_a, 'a');
		i++;
	}
}
