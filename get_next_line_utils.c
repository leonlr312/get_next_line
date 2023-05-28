#include "get_next_line.h"

char	*lst_find(LIST *lst, char number)
{
	int	index;

	index = 0;
	while (lst->len_buffer > index)
	{
		if (lst->buffer[index] == number)
			return (&lst->buffer[index]);
		index++;
	}
	return (NULL);
}

int	lst_expand(LIST *lst)
{
	char	*expand;
	int		index;

	index = 0;
	expand = malloc(sizeof(char) * (lst->cap_buffer * 2));
	if (expand == NULL)
		return (-1);
	lst->cap_buffer = lst->cap_buffer * 2;
	while (lst->len_buffer > index)
	{
		expand[index] = lst->buffer[index];
		index++;
	}
	free(lst->buffer);
	lst->buffer = expand;
	return (0);
}

char	*lst_getslice(LIST *lst, size_t start, size_t end)
{
	char	*slice;
	int		index;

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

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*dest1;
	const char	*dest2;
	size_t		index;

	index = 0;
	dest1 = (char *)dest;
	dest2 = (const char *)src;
	if (dest == 0 && src == 0)
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