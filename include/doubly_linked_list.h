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

typedef struct node
{
	doubly_linked_list *prev;
	void *value;
	doubly_linked_list *next;
}				node;

// Given a ref to the head of DLL and it append a new Node at the end.
void	append(node **head, void *data);

// Given a ref to the head of DLL and it pushs a new Node at the beginning
void	push(node **head, void *data);

#endif
