/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cburns <cburns@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 21:07:34 by cburns            #+#    #+#             */
/*   Updated: 2020/01/30 10:27:30 by cburns           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_lstaddend(t_list **alst, t_list *new)
{
	t_list	*current;

	if (!(*alst))
		*alst = new;
	else
	{
		current = *alst;
		while (current->next)
			current = current->next;
		current->next = new;
	}
}

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*element;

	if (!(element = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (!content)
	{
		element->content = NULL;
		element->content_size = 0;
	}
	else
	{
		if (!(element->content = malloc(content_size)))
		{
			free(element);
			return (NULL);
		}
		element->content = ft_memcpy(element->content, content, content_size);
		element->content_size = content_size;
	}
	element->next = NULL;
	return (element);
}

void		*ft_memalloc(size_t size)
{
	void	*mem;

	if (!(mem = malloc(size)))
		return (NULL);
	mem = ft_memset(mem, 0, size);
	return (mem);
}

void		ft_putstr_fd(char const *s, int fd)
{
	size_t	i;

	i = 0;
	if (s && fd >= 0)
		while (s[i])
			ft_putchar_fd(s[i++], fd);
}
