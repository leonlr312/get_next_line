/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoda-lu <leoda-lu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 09:41:03 by leoda-lu          #+#    #+#             */
/*   Updated: 2023/05/29 16:55:39 by leoda-lu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*lst_find(t_list *lst, char number)
{
	size_t	index;

	index = 0;
	while (lst->len_b > index)
	{
		if (lst->buffer[index] == number)
			return (&lst->buffer[index]);
		index++;
	}
	return (NULL);
}

int	lst_expand(t_list *lst)
{
	char	*expand;
	size_t	index;

	index = 0;
	expand = malloc(sizeof(char) * (lst->cap_b * 2));
	if (expand == NULL)
		return (-1);
	lst->cap_b = lst->cap_b * 2;
	while (lst->len_b > index)
	{
		expand[index] = lst->buffer[index];
		index++;
	}
	free(lst->buffer);
	lst->buffer = expand;
	return (0);
}

char	*lst_getslice(t_list *lst, size_t start, size_t end)
{
	char	*slice;
	size_t	index;

	index = start;
	slice = malloc(sizeof(char) * (end - start) + 1);
	if (slice == NULL)
		return (NULL);
	while (index < end)
	{
		slice[index] = lst->buffer[index];
		index++;
	}
	slice[index] = '\0';
	return (slice);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*dest1;
	const char	*dest2;
	size_t		index;

	index = 0;
	dest1 = (char *)dest;
	dest2 = (const char *)src;
	if (n == 0 || (dest == 0 && src == 0))
		return (dest);
	if (dest1 > dest2)
	{
		while (n--)
		{
			dest1[n] = dest2[n];
		}
	}
	else
	{
		while (index < n)
		{
			dest1[index] = dest2[index];
			index++;
		}
	}
	return (dest);
}
