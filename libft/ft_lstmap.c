/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysihetii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 21:07:04 by ysihetii          #+#    #+#             */
/*   Updated: 2017/11/13 21:07:05 by ysihetii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	t_list	*ft_nnode(t_list *q)
{
	t_list *node;

	node = (t_list*)malloc(sizeof(t_list));
	node->next = 0;
	node->content = malloc(q->content_size);
	node->content_size = q->content_size;
	node->content = ft_memcpy(node->content, q->content, q->content_size);
	return (node);
}

static	void	ft_lstaddback(t_list **alst, t_list *new)
{
	t_list *tmp;

	tmp = (*alst);
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*res;
	t_list	*tmp;

	if (!lst || !f)
		return (0);
	res = ft_nnode(f(lst));
	lst = lst->next;
	while (lst)
	{
		tmp = lst->next;
		ft_lstaddback(&res, ft_nnode(f(lst)));
		lst = tmp;
	}
	return (res);
}
