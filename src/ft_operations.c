/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wollio <wollio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 14:41:01 by wollio            #+#    #+#             */
/*   Updated: 2021/10/12 17:10:12 by wollio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_swap(t_stack **head, char c)
{
	t_stack	*temp;
	t_stack	*temp1;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	temp = *head;
	*head = (*head)->next;
	temp1 = (*head)->next;
	(*head)->next = temp;
	temp->next = temp1;
	ft_print("s", c);
}

void	ft_push(t_stack **head_1, t_stack **head_2, char c)
{
	t_stack	*temp;
	t_stack	*temp1;

	temp = (*head_1);
	if ((*head_1) == NULL)
		return ;
	(*head_1) = (*head_1)->next;
	temp1 = (*head_2);
	(*head_2) = temp;
	if ((*head_2))
		temp->next = temp1;
	ft_print("p", c);
}

void	ft_rotate(t_stack **head1, char c)
{
	t_stack	*temp;
	t_stack	*temp1;

	if (*head1 == NULL || (*head1)->next == NULL)
		return ;
	temp = *head1;
	while (temp->next != NULL)
		temp = temp->next;
	temp1 = *head1;
	temp->next = temp1;
	*head1 = (*head1)->next;
	temp1->next = NULL;
	if (c == 'c')
		return ;
	ft_print("r", c);
}

void	ft_rrotate(t_stack **head, char c)
{
	t_stack	*temp;
	t_stack	*temp1;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	temp = *head;
	temp1 = *head;
	while (temp->next != NULL)
		temp = temp->next;
	while (temp1->next->next != NULL)
		temp1 = temp1->next;
	temp->next = *head;
	*head = temp;
	temp1->next = NULL;
	if (c == 'c')
		return ;
	ft_print("rr", c);
}
