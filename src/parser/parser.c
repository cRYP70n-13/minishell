#include "../../include/minishell.h"

static int 		_isalpha(int c)
{
	return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

static char		*_strcpy(char *s1, char *s2)
{
	while (*s1++ = *s2++)
		;
	return s1;
}

int 	is_it_cmd(char *line)
{
	// TODO: check if we should do this one
	// NOTE: - if the line ends with backslash '\', we should read another line and push it to the old one then execute.
	// 		 - Once we read the line we search for quotes, the first one found triggers a quote state for the next characters
    // 		   that follows until we found the next quote from the same type
    // 		   		* If the first quote is ("):
    // 		   			-> All the characters expect for ($, " and \) lose their meanings including single quotes, spaces and newlines
    // 		   			-> if its a (') All the characters lose their meaning except for (') itself.
    return (0);
}

t_quote 		*parse_double_quotes(char *line, t_quote *quotes, t_cmd *command)
{
	// TODO: Implement the logic to fill the structure with the quotes inside of the line
	return (0);
}

t_quote 		*parse_single_quotes(char *line, t_quote *quotes, t_cmd *command)
{
	int cnt;

	cnt = 1;
	while (*line)
	{
		if (*line == '\'')
			cnt++;
		_strcpy(*command->arg, line);
		line++;
	}
	if (cnt % 2 != 0)
		ft_error_and_quit(2);
	return (0);
}

void			parse_quotes(char *line, t_quote *quotes, t_cmd *command)
{
	if (*line == '"')
		parse_double_quotes(line, quotes, command);
	if (*line == '\'')
		parse_single_quotes(line, quotes, command);
}

t_redirections		*parse_redir(char *line, t_redirections *redirections)
{
	// TODO: ...
}

t_separators		*parse_separators(char *line, t_separators *separators)
{
	// TODO: ...
}

t_cmd				*parse_line(char *line, t_cmd *commands, t_redirections *redirections, t_separators *separators, t_quote *quotes)
{
	while (*line)
	{
		if (*line == ' ')
			line++;
		if (_isalpha(*line))
		{
			// Construct the words in the **args and fill the structure
			_strcpy(*commands->arg, line); // FIXME: This might be a prob !!!
			line++;
		}
		if (*line == '<' || *line == '>' || (*line == '<' && *(++line) == '<'))
			parse_redir(line, redirections);
		if (*line == ';' || *line == '|')
			parse_separators(line, separators);
		if (*line == '\'' || *line == '"')
			parse_quotes(line, quotes, commands);
		if (*line == '\\')
			line++;
		line++;
	}
	return (commands);
}
