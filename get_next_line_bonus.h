/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoda-lu <leoda-lu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 09:40:45 by leoda-lu          #+#    #+#             */
/*   Updated: 2023/06/01 14:49:23 by leoda-lu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# define MAX_FD 1024
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_struct
{
	char	*buffer;
	size_t	len_b;
	size_t	cap_b;
}	t_list;

char	*get_next_line(int fd);
char	*lst_find(t_list *lst, char number);
int		lst_expand(t_list *lst);
char	*lst_getslice(t_list *lst, size_t start, size_t end);
void	*ft_memmove(void *dest, const void *src, size_t n);

#endif
