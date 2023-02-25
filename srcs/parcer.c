/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel-idr <yoel-idr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 14:10:36 by yoel-idr          #+#    #+#             */
/*   Updated: 2023/02/25 17:15:08 by yoel-idr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/leet3d.h"

void    error_(char *error, int errno_s, int flag)
{
    ft_putstr_fd("Error : ", 2);
    if (flag & ERROR && error)
        ft_putstr_fd(error, 2);
    if (flag & FATAL)
        strerror(errno_s);
    ft_putstr_fd("\n", 2);
    exit(EXIT_FAILURE);
}

int     container_tools(t_parcer **container, int flag)
{
    int i;

    i = 0;
    if (flag & INIT)
    {
        while (i < 4)
            (*container)->texture[i++] = NULL;
        ft_memset((*container)->c_ceiling, 0, sizeof(3));
        ft_memset((*container)->c_floor, 0, sizeof(3));
        return (EXIT_SUCCESS);
    }
    if ((*container)->texture[0] && (*container)->texture[1] && \
        (*container)->texture[2] && (*container)->texture[3])
        return (1);
    return (0);
}

bool    extensions(char *target)
{
    if (!target)
        return (false);
    target += (int)sizeof(target) + 1;
    while (target)
    {
        if (*target == '.')
            return (!ft_memcmp(target, ".cub", sizeof(".cub")));
        target -= 1;
    }
    return (false);
}

void    analysis_rgb(t_parcer **container, char **colors, t_setting flag)
{
    int index;
    
    index = 0;
    while (colors[index])
    {
        if (ft_atoi(colors[index]) > 255 || ft_atoi(colors[index]) < 0)
            return (error_("rgb error", 0, ERROR));
        if (flag & C_C)
            (*container)->c_ceiling[index] = ft_atoi(colors[index]);
        if (flag & C_F)
            (*container)->c_floor[index] = ft_atoi(colors[index]);
        index ++;
    }
}

void    set_cloros(t_parcer **container, char *line, t_setting flag)
{
    char    **colors;
    char    *tmp;
    int     index;

    while (*line && ft_isspace(*line))
        line ++;
    if (!*line || !ft_isdigit(*line) || !ft_strchr(line, ','))
        return (error_("error colors 1", 0, ERROR));
    colors = ft_split(line, ',');
    index = 0;
    while (colors[index])
        index ++;
    if (index > 3 || index < 3)
        return (error_("color error 2", 0, ERROR));
    while (index)
    {
        tmp = ft_strtrim(colors[index], " ");
        free(colors[index]);
        colors[index] = tmp;
        index --;
    }
    analysis_rgb(container, colors, flag);
}

void    set_texture(t_parcer **container, char *line, t_setting ret)
{
    int fd_texture;
    int i;

    if (!*line)
        return (error_("texture 1", 0, ERROR));
    i = (int)log2(ret);
    while (*line)
    {
        while (*line && ft_isspace(*line) && ft_memcmp(line, "./", sizeof("./")))
            line ++;
        if (!*line || *line != '.')
            return (error_("error ./", 0, ERROR));
        (*container)->texture[i] = ft_strndup(line, ft_strlen(line) - 1);
        // fd_texture = open((*container)->texture[i], O_RDONLY, 0644);
        // if (fd_texture == -1)
        //     return (error_("path texture", 0, ERROR));
        return ((void)close(fd_texture));
    }
    return (error_("MISSIN", 0, ERROR));
}

void    set_data(t_parcer **container, int fd_map)
{
    t_setting   ret;
    char        *line;
    
    line = get_next_line(fd_map);
    while (line)
    {
        while (*line != '\n' && ft_isspace(*line))
            line ++;
        ret = (!ft_memcmp(line, "NO ", ft_strlen("NO "))) * NO + \
              (!ft_memcmp(line, "SO ", ft_strlen("SO "))) * SO + \
              (!ft_memcmp(line, "WE ", ft_strlen("WE "))) * WE + \
              (!ft_memcmp(line, "EA ", ft_strlen("EA "))) * EA + \
              (!ft_memcmp(line, "F ", ft_strlen("F "))) * C_F +  \
              (!ft_memcmp(line, "C ", ft_strlen("C "))) * C_C;
        if (ret & (NO | EA | SO | WE))
            set_texture(container, line + 3, ret);
        if (ret & (C_C | C_F))
            set_cloros(container, line + 2, ret);
        line = get_next_line(fd_map);
    }
}

char    **realloc_arrays(char ***arrays, char *new)
{
    char    **ret;
    int     i;
    int     j;

    i = -1;
    if (!*arrays)
	{
		ret = malloc(sizeof(char *) * 2);
        if (!ret)
            return (error_(NULL, ENOMEM, FATAL), NULL);
		return (ret[0] = ft_strdup(new), ret[1] = NULL, ret);
	}
    while ((*arrays)[++i])
        ;
    ret = malloc(sizeof(char *) * (i + 2));
    if (!ret)
        return (error_(NULL, ENOMEM, FATAL), NULL);
    i = 0;
    while ((*arrays)[i])
        ret[i] = ft_strdup((*arrays)[i++]);
    ret[i] = new;
    return (array_destroyer(*arrays), ret[i] = NULL, ret);
}

void set_map(t_parcer **container, char **argv)
{
    char    *line;
    int     fd_map;

    if (!container_tools(NULL, CHECK))
        return (error_("ERROR in set map 1", 0, ERROR));
    
    fd_map = open(*argv, O_RDONLY, 0644);
    line = get_next_line(fd_map);
    while (line)
    {
        

        
        
        free(line);
        line = get_next_line(fd_map);
    }
    close(fd_map);
}

t_parcer    *parcer(char **argv)
{
    t_parcer    *container;
    int         fd_map;
    
    container = malloc(sizeof(t_parcer));
    if (!container)
        return (error_(NULL, ENOMEM, FATAL), NULL);
    if (!extensions(*argv))
        return (error_(EXEC, 0, ERROR), NULL);
    fd_map = open(*argv, O_RDONLY, 0644);
    if (fd_map == -1)
        return (error_(NULL, ENOENT, FATAL), NULL);
    ft_memset(container, 0, sizeof(t_parcer));
    container_tools(&container, INIT);
    set_data(&container, fd_map);
    set_map(&container, argv);
    return (close(fd_map), container);
}







int main(int ac, char **av)
{
    t_parcer *test;

    if (ac != 2)
        return (puts("arg"), 1);
    av ++;
    test = parcer(av);

    int i = 0, j = 0, t = 0;


    puts(RED"\nprint c_floor"WHITE);
    
    while (i < 3)
    {
        printf("Colors c_floor [%d] ==> [%d]\n", i, test->c_floor[i]);
        i ++;
    }
    puts(RED"\nprint c_ceiling"WHITE);
    
    while (j < 3)
    {
        printf("Colors c_ceiling [%d] ==> [%d]\n", j, test->c_ceiling[j]);
        j ++;
    }
    
    puts(RED"\nprint texture"WHITE);
    
    while (t < 4)
    {
        printf("texture [%d] ==> [%s]\n", t, test->texture[t]);
        t ++;
    }
    
    exit(0);
}