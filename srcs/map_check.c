/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlouvrie <rlouvrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 13:37:17 by rlouvrie          #+#    #+#             */
/*   Updated: 2022/10/12 17:27:17 by rlouvrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	clean_malloc(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	filename_checker(char *filename)
{
	char	**filename_splited;

	filename_splited = ft_split(filename, '.');
	if (!filename_splited[1])
		return (clean_malloc(filename_splited), 2);
	if (ft_strncmp((const char *)filename_splited[1], "ber", 3) != 0)
		return (clean_malloc(filename_splited), 2);
	return (clean_malloc(filename_splited), 0);
}


char	**load_map(int fd)
{
	char	**map;
	char	*str;
	char	*nl;
	char	*swap;
	int		y;

	y = 0;
	str = malloc(sizeof(char));
	if (!str)
		return (NULL);
	str[0] = '\0';
	swap = NULL;
	while (1)
	{
		nl = NULL;
		nl = get_next_line(fd);
		if (!nl)
			break;
		y++;
		swap = ft_strjoin(str, nl);
		free(str);
		free(nl);
		str = NULL;
		str = swap;
	}
	if (y == 0)
		return (free(str), NULL);
	map = ft_split(str, '\n');
	free(str);
	return (map);
}

int	len_y(char **map)
{
	int i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

char	**map_checker(int fd)
{
	char	**map;
	int		y;
	int		i;
	int		j;
	int		len;


	if (fd < 0)
		return (NULL);
	map = load_map(fd);
	if (!map)
		return (NULL);
	y = len_y(map);
	i = 0;
	while (map[i])
	{
		j = 0;
		len = ft_strlen(map[i]);
		while (map[i][j])
		{
			if ((i == y - 1 || i == 0) && map[i][j] != '1')
				return (clean_malloc(map), NULL);
			else if (map[i][0] != '1' || map[i][len - 1] != '1')
				return (clean_malloc(map), NULL);
			else if (y == len)
				return (clean_malloc(map), NULL);
			else if (map[i][j] == '0' || map[i][j] == '1' || map[i][j] == 'C' || map[i][j] == 'E' || map[i][j] == 'P')
				j++;
		}
		i++;
	}
	return (map);
}




// Tant que map[i]
// calcule len y
// pour chaque ligne
	// Si i = 0



// Dabord verifier le fichier

// On cree et initialise a 0 une variable line_y
// Si fd < 0
	// Alors on return code error.
// Tant que fd est plus grand que 0:
	// line = gnl(fd)
	// Si line est null et len_y = 0:
		// error
	// Si line est null en last, et que fd == 0
		// verify_line
		// On return 0
	// Sinon si line n'est pas nul
		// on ajoute 1 a len_y
		// On calcule len(line) (len_x)
		// Si len_y == 1
			// len_last_x = len_x
			//verify_line
		// Sinon si len_y > 1 && len_x != len_last_line:
			// return error
		// On stocke dans un variable le resultat de la fonction verify_line
		// int verify_line(int len_x, int len_y);
			// Si -1 error sinon 
// Si len_y == len_x
	// return error

// La Carte:
//		- 0: Represente un emplacement vide (Ou le joueur peut circuler).
//		- 1: Represente un mur.
//		- C: Un item a collecter (au moins 1 obligatoires, plusieurs possible).
//		- E: Une sortie (au moins 1 obligatoires).
//		- P: Position de depart (1 obligatoires).
//
//	La carte doit etre rectangulaire (si len_x == len_y alors return error).
//	La carte doit être fermée en étant encadrée par des murs.
//		Line 1 & Line last ne doivent contenir que des 1.
//		Sur chaque autres lignes l'element 0 et l'element last doivent etre egale a 1.
//	Verifier qu'il y a un chemin valide.
// Si une erreur est detecter le programme doit quitter proprement.
// Check si un chemin est possible
