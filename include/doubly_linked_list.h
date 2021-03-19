/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doubly_linked_list.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okimdil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 16:45:18 by okimdil           #+#    #+#             */
/*   Updated: 2021/03/17 16:57:19 by okimdil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __DOUBLY_LINKED_LIST_H__
# define __DOUBLY_LINKED_LIST_H__

#include <stdlib.h>
#include <stdio.h>

typedef struct		s_node
{
	s_node *prev;
	void *value;
	s_node *next;
}					t_node;

// Given a ref to the head of DLL and it append a new Node at the end.
void	append(t_node **head, void *data);

// Given a ref to the head of DLL and it pushs a new Node at the beginning
void	push(t_node **head, void *data);

// Reverse the Linked list before pushing it to the file
s_node		*reverse_ll(t_node *head);

#endif
