/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wollio <wollio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 13:28:38 by wollio            #+#    #+#             */
/*   Updated: 2021/10/21 14:31:38 by wollio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include "./get_next_line.h"
# include "stdbool.h"
# include <limits.h>

typedef struct stack
{
	int				index;
	int				pos;
	int				markup;
	int				data;
	int				flag;
	int				mov;
	int				ra;
	int				rb;
	int				rr;
	int				rra;
	int				rrb;
	int				rrr;
	int				flag2;
	struct stack	*next;
}					t_stack;

typedef struct parse
{
	int				i;
	int				j;
	bool			space;
	bool			arg;
	char			**arr;
	char			*str;
	char			*tmp;
	char			*tmp2;

}					t_parse;

typedef struct length
{
	int				a;
	int				b;
	bool			even_a;
	bool			even_b;

}					t_length;

/** Parsing and error management **/

/* Put the arguments in a bi-dimensional array */
char	**ft_parse_input(int argc, char *argv[], t_parse *parse);
/* Search for arguments in between double quotes */
void	ft_if_space(int argc, char *argv[], t_parse *parse);
/* Insert inputs in a linked list */
void	ft_put_in_list(t_stack **stack, char **arr);

/** Tools **/

/* Print the name of the operation done */
void	ft_print(char *s, char c);
/* Free the list */
void	free_list(t_stack **head_a);

/** Tools to deal with linked list **/

/* Add a new node at the beginning of the linked list */
void	add_front(t_stack **head, int new_data);
/* Add a new node after a node in the linked list*/
void	add_after(t_stack *prev_node, int new_data);
/* Add a new node at the end of the linked list */
void	add_back(t_stack **head, int new_data);
/* Calculate the length of a list */
int		length_list(t_stack *n);
/* Attribute the right position to have in the stack to each nodes */
void	ft_insert_index(t_stack **head_a, int *arr, int length);
/* Searchs for the biggest sequence of number to keep in stack a by data */
int		ft_markup(t_stack *head_a, int *index_head);
/* Searchs for the biggest sequence of number to keep in stack a by index */
int		ft_markup_index(t_stack *head_a, int *index_head1);
/* Attribute the position for each elements of a stack */
void	ft_insert_pos(t_stack *n);
/* Get the length of the list a and determine if it's even or not */
int		lengtha_list_modif(t_stack *n, t_length *length);
/* Get the length of the list b and determine if it's even or not */
int		lengthb_list_modif(t_stack *n, t_length *length);

/** Operations available **/

/* Swap the two first elements at the top of the stack */
void	ft_swap(t_stack **head, char c);
/* Take the first element at the top of one stack1 and put it at the
* top of stack2 */
void	ft_push(t_stack **head_a, t_stack **head_b, char c);
/* Shift up all elements of the stack by 1.
* The first element becomes the last one. */
void	ft_rotate(t_stack **head1, char c);
/* Shift down all elements of stack a by 1.
* The last element becomes the first one. */
void	ft_rrotate(t_stack **head, char c);

/** Sort 3, 4 or 5 numbers **/

void	ft_three(t_stack **head_a);
void	ft_four(t_stack **head_a, t_stack **head_b);
void	ft_five(t_stack **head_a, t_stack **head_b);

/** Main sorting algorithm **/

/* Main function for sorting the stack */
void	ft_sorting(t_stack **head_a, t_stack **head_b);
/* Sort with brute force */
void	ft_brut_force(t_stack **head_a, t_stack **head_b);
/* Push elements from stack a to stack b when the markup by data is choosed */
void	a_to_b0(t_stack **head_a, t_stack **head_b, int index_head0, int len0);
/* Push elements from stack a to stack b when the markup by index is choosed */
void	a_to_b1(t_stack **head_a, t_stack **head_b, int index_head2, int len1);
/* Insert flag for each node when the markup by data is choosed*/
void	ft_init_flag0(t_stack *head_a, int index_head0, int len0);
/* Insert flag for each node when the markup by index is choosed*/
void	ft_init_flag1(t_stack **head_a, int index_head2);
/* Push elements from stack a to stack b */
void	push_a_to_b(t_stack **head_a, t_stack **head_b, int length);
/* Push elements from stack b to stack a */
void	push_b_to_a(t_stack **head_a, t_stack **head_b);
/* Number of moves in the stack to welcome the number from the stack b */
void	r_or_rra(t_stack *tmpb, t_length *length, int pos, int nbr);
/* Number of moves to put the number at the top of stack b */
void	r_or_rrb(t_stack *tmpb, t_length *length, int pos);
/* Initialize the variables for the rotate moves */
void	ft_init_r_rr(t_stack *tmpb);
/* Search by index the smallest element in the stack */
t_stack	*get_the_smallest_index(t_stack **head_a);
/* Search by index the biggest element in the stack */
t_stack	*get_the_biggest_index(t_stack **head_a);
/* Take as an argument the previous minimum and look for the next
* smallest one in the stack */
t_stack	*get_next_smallest_index(t_stack **head_a, t_stack *min);
/* Initialize the flag2 variable to keep track of the smallest elements */
void	ft_init_flag2(t_stack **head_a);
/* Search for the element which require the least amount of movement */
t_stack	*get_the_smallest_mov(t_stack **head_b);
/* Initialize rr and rrr operations if needed */
void	rr_or_rrr(t_stack *tmp);
/* Execute rotates operations */
void	do_rotate(t_stack **head_a, t_stack **head_b, t_stack *min);
/* Execute reverse rotates operations */
void	do_rrotate(t_stack **head_a, t_stack **head_b, t_stack *min);
/* Calculate the amount of rotate and reverse rotate operations
needed for one element */
void	ft_insert_mov(t_stack **head_a, t_stack *tmpb, t_length *length);
/* Calculate the amount of operations needed for all of the elements in
* stack b */
void	ft_calculator(t_stack **head_a, t_stack **head_b, t_length *length);
/* Execute the operations for the element choosed */
void	ft_do_it(t_stack **head_a, t_stack **head_b);

/** Tools to deal with the array **/

/* Sort the array */
int		*ft_array_sorted(t_stack *head_a, int length);
/* Insert the list in an array */
int		*ft_put_in_array(t_stack *head_a, int length);
/* Sort an array with the selection sort algorithm */
int		*ft_selection_sort(int *arr, int length);
/* To delete */
void	ft_print_array(int *arr, int length);
/* Swap two values*/
void	swap(int *min, int *i);

/** Error cases **/

/* Contains all the functions to manage error cases */
int		check_error(t_stack **head_a);
/* Check if the inputs are already sorted */
int		if_sorted(t_stack **head_a);
/* Check if there is only one number */
int		if_one(t_stack **head_a);
/* Check if there is two times the same number */
int		if_same(t_stack **head_a);
/* Handle some errors cases */
void	ft_error(int argc, char *argv[]);

/** BONUS PART **/

/* Read the instructions in standard input */
char	*ft_reading(char *buffer, t_stack **head_a);
/* Apply the instructions read to the stack */
void	ft_instructions(t_stack **head_a, t_stack **head_b, char *buffer);
/* Apply the instructions on the stack */
void	ft_apply(t_stack **head_a, t_stack **head_b, char *buffer);
/* Operations without the printing statement */
void	ft_rrotate2(t_stack **head);
void	ft_rotate2(t_stack **head1);
void	ft_push2(t_stack **head_1, t_stack **head_2);
void	ft_swap2(t_stack **head);
/* Check if the stack is sorted */
void	ft_verify(t_stack **head_a);
/* Check that the instructions exist */
int		check_3_char(char *buffer, int i);
int		check_4_char(char *buffer, int i);
/* Read the instructions and apply the instructions on the stacks */
void	read_one(t_stack **head_a, t_stack **head_b, char **arr, int i);
void	read_two(t_stack **head_a, t_stack **head_b, char **arr, int i);
/* Error management*/
int		check_error2(t_stack **head_a);
/* Check if there is two times the same number for bonus part */
int		if_same2(t_stack **head_a);
/* Check if the inputs are already sorted for bonus part */
int		if_sorted2(t_stack **head_a);
int		if_one2(t_stack **head_a);
#endif