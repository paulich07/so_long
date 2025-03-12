/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 20:35:02 by plichota          #+#    #+#             */
/*   Updated: 2025/02/28 19:47:19 by plichota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(int content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}
/* 
int	main(void)
{
	t_list *new;
	void *c;
	char s[] = "ciao";

	c = s;
	new = ft_lstnew(c);
	if (!new)
		printf("Error\n");
	printf("%s", (char *)new->content);
	free(new);
} */