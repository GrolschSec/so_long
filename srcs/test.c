/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlouvrie <rlouvrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 14:48:47 by rlouvrie          #+#    #+#             */
/*   Updated: 2023/02/20 17:23:12 by rlouvrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	is_valid_position(char **map, int rows, int cols, int x, int y, int **visited)
{
    if (x < 0 || x >= rows || y < 0 || y >= cols)
        return (0);
    if (visited[x][y] || map[x][y] == '1')
        return (0);
    return (1);
}

int is_collectible(char **map, int x, int y)
{
    return (map[x][y] == 'C');
}

int is_end(char **map, int x, int y)
{
    return (map[x][y] == 'E');
}

int is_valid_path(char **map, int rows, int cols, int x, int y, int **visited)
{
    if (is_end(map, x, y))
        return (1);

    visited[x][y] = 1;

    if (map[x][y] == 'C')
    {
        int i = 0;
        int count = 0;
        while (i < rows * cols)
        {
            int x_c = i / cols;
            int y_c = i % cols;
            if (is_collectible(map, x_c, y_c) && !visited[x_c][y_c])
            {
                count++;
                if (count > 1)
                    break ;
            }
            i++;
        }
        if (count == 1)
        {
            int res = is_valid_path(map, rows, cols, x, y, visited);
            visited[x][y] = 0;
            return (res);
        }
    }

    int res = 0;
    if (is_valid_position(map, rows, cols, x - 1, y, visited))
        res = is_valid_path(map, rows, cols, x - 1, y, visited);
    if (!res && is_valid_position(map, rows, cols, x + 1, y, visited))
        res = is_valid_path(map, rows, cols, x + 1, y, visited);
    if (!res && is_valid_position(map, rows, cols, x, y - 1, visited))
        res = is_valid_path(map, rows, cols, x, y - 1, visited);
    if (!res && is_valid_position(map, rows, cols, x, y + 1, visited))
        res = is_valid_path(map, rows, cols, x, y + 1, visited);

    visited[x][y] = 0;

    return (res);
}

int main()
{
    char *map[] = {
        "11111111111111111111111111111111",
        "10010000000000000P11111111000111",
        "10C10000000000001111111000000011",
        "10010010011111111111111100011101",
        "1111111E111111111111111101001011",
        "11111111111111111111111111111111",
        NULL
    };
    int rows = 5;
    int cols = 32;

    int **visited = (int **)calloc(rows, sizeof(int *));
    for (int i = 0; i < rows; i++)
        visited[i] = (int *)calloc(cols, sizeof(int));

    int res = is_valid_path(map, rows, cols, 1, 17, visited);
	printf("%d", res);
	
}