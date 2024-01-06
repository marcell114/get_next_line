/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpal <mpal@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 18:48:10 by mpal              #+#    #+#             */
/*   Updated: 2024/01/06 15:13:38 by mpal             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

int found_newline(t_list *list)
{
    int i;

    if (list == NULL)
        return (0);
    while (list)
    {
        i = 0;
        while (list->str_buf[i] && i < BUFFER_SIZE)
        {
            if (list->str_buf[i] == '\n')
                return (1);
            ++i;
        }
        list = list->next;
    }
    return (0);
}

t_list  *find_last_node(t_list *list)
{
    if (list == NULL)
        return (NULL);
    while (list->next)
        list = list->next;
    return (list);
}

void copy_str(t_list *list, char *str)
{
    int i;
    int j;

    if(list == NULL)
        return ;
    j = 0;
    while (list)
    {
        i = 0;
        while (list->str_buf[i])
        {
            if (list->str_buf[i] == '\n')
            {
                str[j++] = '\n';
                str[j] = '\0';
                return ;
            }
            str[j++] = list->str_buf[i++];
        }
        list = list->next;
    }
    str[j] = '\0';
}

int len_to_newline(t_list *list)
{
    int i;
    int len;

    if (list == NULL)
        return (0);
    len = 0;
    while (list)
    {
        i = 0;
        while (list->str_buf[i])
        {
            if (list->str_buf[i] == '\n')
            {
                ++len;
                return (len);
            }
            ++i;
            ++len;
        }
        list = list->next;
    }
    return (len);
}

void    dealloc(t_list **list,t_list *clean_node, char *buf)
{
    t_list  *tmp;

    if (*list == NULL)
        return ;
    while (*list)
    {
        tmp = (*list)->next;
        free((*list)->str_buf);
        free(*list);
        *list = tmp;
    }
    *list = NULL;
    if (clean_node->str_buf[0])
        *list = clean_node;
    else
    {
        free(buf);
        free(clean_node);
    }
}
