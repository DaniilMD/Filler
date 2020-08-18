#include "filler.h"

void		free_map(t_param *param)
{
	int		i;

	i = 0;
	while (param->map[i] != NULL)
	{
		free(param->map[i]);
		i++;
	}
}

void		create_map(t_param *param, char *curr_line)
{
	int i;

	i = 0;
	while (curr_line[i] != ' ')
		i++;
	param->size_y = ft_atoi(curr_line + i + 1);
	i++;
	while (curr_line[i] != ' ')
		i++;
	param->size_x = ft_atoi(curr_line + i + 1);
	param->map = (char**)malloc(sizeof(char*) * (param->size_y + 1));
	param->map[param->size_y] = NULL;
}

void		read_map(t_param *param, char *curr_line)
{
	int		i;
	int		j;
	char	*line;

	if (param->map != NULL)
		free_map(param);
	if (param->map == NULL)
		create_map(param, curr_line);
	get_next_line(0, &line);
	free(line);
	i = 0;
	while (i < param->size_y)
	{
		get_next_line(0, &line);
		j = 0;
		while (line[j] != ' ')
			j++;
		param->map[i] = ft_strdup(line + j + 1);
		free(line);
		i++;
	}
}

void		get_token(t_param *param)
{
	int		i;
	char	*line;

	if (param->token.token_map != NULL)
		free_char_starstar(param->token.token_map);
	get_next_line(0, &line);
	i = 0;
	while (line[i] != ' ')
		i++;
	param->token.token_s_y = ft_atoi(line + i++ + 1);
	while (line[i] != ' ')
		i++;
	param->token.token_s_x = ft_atoi(line + i + 1);
	free(line);
	param->token.token_map = (char**)malloc(sizeof(char*)
		* (param->token.token_s_y + 1));
	param->token.token_map[param->token.token_s_y] = NULL;
	i = 0;
	while (i < param->token.token_s_y)
	{
		get_next_line(0, &line);
		param->token.token_map[i] = ft_strdup(line);
		free(line);
		i++;
	}
}
