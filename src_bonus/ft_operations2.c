/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wollio <wollio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 14:41:01 by wollio            #+#    #+#             */
/*   Updated: 2021/10/15 12:39:38 by wollio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_swap2(t_stack **head)
{
	t_stack	*temp;
	t_stack	*temp1;

	temp = *head;
	if (temp == NULL || temp->next == NULL || temp->next->next == NULL)
	{
		write(1, "KO\n", 3);
		exit(0);
	}
	*head = (*head)->next;
	temp1 = (*head)->next;
	(*head)->next = temp;
	temp->next = temp1;
}

void	ft_push2(t_stack **head_1, t_stack **head_2)
{
	t_stack	*temp;
	t_stack	*temp1;

	temp = (*head_1);
	if ((*head_1) == NULL)
	{
		write(1, "KO\n", 3);
		exit(0);
	}
	(*head_1) = (*head_1)->next;
	temp1 = (*head_2);
	(*head_2) = temp;
	if ((*head_2))
		temp->next = temp1;
}

void	ft_rotate2(t_stack **head1)
{
	t_stack	*temp;
	t_stack	*temp1;

	if (*head1 == NULL || (*head1)->next == NULL)
	{
		write(1, "KO\n", 3);
		exit(0);
	}
	temp = *head1;
	while (temp->next != NULL)
		temp = temp->next;
	temp1 = *head1;
	temp->next = temp1;
	*head1 = (*head1)->next;
	temp1->next = NULL;
}

void	ft_rrotate2(t_stack **head)
{
	t_stack	*temp;
	t_stack	*temp1;

	if (*head == NULL || (*head)->next == NULL)
	{
		write(1, "KO\n", 3);
		exit(0);
	}
	temp = *head;
	temp1 = *head;
	while (temp->next != NULL)
		temp = temp->next;
	while (temp1->next->next != NULL)
		temp1 = temp1->next;
	temp->next = *head;
	*head = temp;
	temp1->next = NULL;
}
