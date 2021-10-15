/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wollio <wollio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 10:09:12 by wollio            #+#    #+#             */
/*   Updated: 2021/10/12 17:14:16 by wollio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_a_to_b(t_stack **head_a, t_stack **head_b, int length)
{
	int	index_head0;
	int	index_head1;
	int	*arr;
	int	len0;
	int	len1;

	arr = ft_array_sorted(*head_a, length);
	ft_insert_index(head_a, arr, length);
	len0 = ft_markup(*head_a, &index_head0);
	len1 = ft_markup_index(*head_a, &index_head1);
	if (len0 > len1)
		a_to_b0(head_a, head_b, index_head0, len0);
	else
		a_to_b1(head_a, head_b, index_head1, len1);
}

void	ft_sorting(t_stack **head_a, t_stack **head_b)
{
	t_stack	*temp;
	int		length;

	temp = *head_a;
	length = length_list(*head_a);
	if (length == 2 && temp->data > temp->next->data)
		ft_rotate(head_a, 'a');
	else if (length == 3)
		ft_three(head_a);
	else if (length == 4)
		ft_four(head_a, head_b);
	else if (length == 5)
		ft_five(head_a, head_b);
	else
	{
		push_a_to_b(head_a, head_b, length);
		push_b_to_a(head_a, head_b);
	}
}
