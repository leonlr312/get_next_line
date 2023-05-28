
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define MAX_FD 1024
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>

typedef struct list
{
	char	*buffer;
	size_t	len_buffer;
	size_t	cap_buffer;
} LIST;

char	*get_next_line(int fd);
LIST	*lst_create(size_t cap);
char	*lst_find(LIST *lst, char number);
int		lst_expand(LIST *lst);
void	lst_destroy(LIST *lst);
char	*lst_getslice(LIST *lst, size_t start, size_t end);
void	*ft_memcpy(void *dest, const void *src, size_t n);

#endif
