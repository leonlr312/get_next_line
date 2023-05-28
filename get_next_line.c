#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static LIST		fileds[MAX_FD];
	char			*newline;
	LIST			*lst;
	int				bytes;
	char			*line;

	if (fd < 0 || fd >= MAX_FD)
		return (NULL);
	lst = &fileds[fd];
	if (lst->buffer == NULL)
	{
		lst->buffer = malloc(sizeof(char) * BUFFER_SIZE);
		lst->cap_buffer = BUFFER_SIZE;
	}
	while (lst)
	{
		newline = lst_find(lst, '\n');
		if (newline != NULL)
		{
			line = lst_getslice(lst, 0, newline - lst->buffer);
			if (line == NULL)
				return (NULL);
			lst->len_buffer -= (newline + 1) - lst->buffer;
			ft_memcpy(lst->buffer, newline + 1, lst->len_buffer);
			return (line);
		}
		if (lst->len_buffer >= lst->cap_buffer && lst->buffer != NULL)
		{
			if (lst_expand(lst) == -1)
				return (NULL);
		}
		bytes = read(fd, lst->buffer + lst->len_buffer, lst->cap_buffer - lst->len_buffer);
		if (bytes == 0)
		{
			if (lst->len_buffer > 0)
			{
				line = lst_getslice(lst, 0, lst->len_buffer);
				if (line == NULL)
					return (NULL);
				free(lst->buffer);
				lst->buffer = NULL;
				lst->len_buffer = 0;
				return (line);
			}
			return (NULL);
		}
		lst->len_buffer += bytes;
	}
}
