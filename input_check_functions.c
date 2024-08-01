/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check_functions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linda <linda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 12:47:40 by linda             #+#    #+#             */
/*   Updated: 2024/08/01 14:02:37 by linda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int check_str_nbr(char   *str)
{
    if (str[0] == '+' && ft_isdigit(str[1]))
        str += 2;
    else
        while (*str != '\0')
        {
            if (ft_isdigit(*str))
                str++;
            else
                return (1);
        }
    return (0);
}
int check_nbr_in_range(long nbr)
{
    if (nbr >= 0 && nbr < INT_MAX)
    {
        return (0);
    }
    else
        return (1);
}
int input_check(char **input_argv)
{
    int i = 1;
    while (i < 5)
    {
       if (check_str_nbr(input_argv[i]) == 0)
       {
            if (check_nbr_in_range(ft_atol(input_argv[i])) == 0)
                i++;
            else
                return (1);
       } 
       else
            return (1);
    }
    return (0);
}