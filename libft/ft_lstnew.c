/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysihetii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 15:33:27 by ysihetii          #+#    #+#             */
/*   Updated: 2017/11/13 15:33:28 by ysihetii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list *node;

	node = (t_list*)malloc(sizeof(t_list));
	if (!node)
		return (0);
	node->next = 0;
	node->content = malloc(content_size);
	if (!node->content)
	{
		free(node);
		return (0);
	}
	node->content_size = (!content) ? 0 : (content_size);
	node->content = (!content) ? 0 :
	ft_memcpy(node->content, content, node->content_size);
	return (node);
}
