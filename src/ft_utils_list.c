/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wollio <wollio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 13:29:38 by wollio            #+#    #+#             */
/*   Updated: 2021/10/13 18:41:56 by wollio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	add_front(t_stack **head, int new_data)
{
	t_stack	*new;

	new = NULL;
	new = (t_stack *) malloc(sizeof(t_stack));
	new->data = new_data;
	new->next = *head;
	*head = new;
}

void	add_after(t_stack *prev_node, int new_data)
{
	t_stack	*new;

	new = NULL;
	new = (t_stack *) malloc(sizeof(t_stack));
	new->data = new_data;
	new->next = prev_node->next;
	prev_node->next = new;
}

void	add_back(t_stack **head, int new_data)
{
	t_stack	*new;
	t_stack	*last;

	last = *head;
	new = (t_stack *) malloc(sizeof(t_stack));
	new->data = new_data;
	new->next = NULL;
	if ((*head) == NULL)
	{
		*head = new;
		return ;
	}
	while (last->next != NULL)
		last = last->next;
	last->next = new;
}
