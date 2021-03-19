/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doubly_linked_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okimdil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 16:48:59 by okimdil           #+#    #+#             */
/*   Updated: 2021/03/17 17:07:08 by okimdil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/doubly_linked_list.h"
#include "../../include/errors.h"

void	push(t_node **head, void *data)
{
	t_node		*new_node;

	if (!(new_node = malloc(sizeof(t_node))))
		ft_error_and_quit(1);
	new_node->value = data;
	new_node->next = (*head);
    new_node->prev = NULL;
}

void	append(t_node **head, void *data)
{
	t_node		*new_node;
	t_node		*last;

	if (!(new_node = malloc(sizeof(t_node))))
		ft_error_and_quit(1);
	new_node->value = data;
	new_node->next = NULL;

	if (*head == NULL)
	{
		new_node->prev = NULL;
		*head = new_node;
		return ;
	}

	while (last->next != NULL)
		last = last->next;
	last->next = new_node;
	new_node->prev = last;

    return ;
}

void	reverse(t_node **head)
{
	t_node *temp;
	t_node *current;

	temp = NULL;
	current = *head;

	while (current !=  NULL)
	{
	  temp = current->prev;
	  current->prev = current->next;
	  current->next = temp;
	  current = current->prev;
	}

	if(temp != NULL)
		*head= temp->prev;
}
