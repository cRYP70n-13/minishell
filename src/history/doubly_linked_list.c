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

void	push(node **head, void *data)
{
	if (!(node *new_node = malloc(sizeof(node))))
		return NULL;
	new_node->data = data;
	new_node->next = (*head_ref);
    new_node->prev = NULL;
}
