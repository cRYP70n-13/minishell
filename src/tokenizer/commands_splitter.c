
#include "minishell.h"

t_command       *get_quoted_command(ENV)
{
    t_command   *cmd;

    if (env->input->line[env->input->i] == SINGLE_QT)
        cmd = single_quoted_cmd(env);
    else
        cmd = double_quoted_cmd(env);
    //Should be cleaned from backSlashes?
    return (cmd);
}

/*
**  [!] Single quotes are weird; that's why they are single.
**  e.g.
**      $ echo "$(echo "hh")" => hh
**      $ echo '$(echo "hh")' => $(echo "hh")
*/

t_command    *single_quoted_cmd(ENV)
{
    t_command   *cmd;
    //pizza is comming.
    return (cmd);
}

t_command    *double_quoted_cmd(ENV)
{
    
    return (NULL); //test

    t_command   *cmd;
    char        *line;
    t_bool      quote_is_open;
    size_t      j;

    cmd = new_cmd();
    line = env->input->line;
    j = env->input->i + 1;
    // 'echo' 'peace;' ";" ; "cat file;"
    while (j < env->input->len)
    {
        if (line[j] == SEP && line[j - 1] != BACK_SLASH && !quote_is_open)
            break ;
        else if (line[j] == DOUBLE_QT)
        {
            quote_is_open = !quote_is_open;
        }
        j++;
    }
    bye;
    cmd->cmd = sub_str(line, env->input->i, j);
    env->input->i = j;
    return (cmd);
}

t_command       *get_command(ENV)
{
    t_command   *cmd;
    char        *line;
    int         j;
    t_bool      double_quote_is_open;
    t_bool      single_quote_is_open;
    t_bool      back_slash;

    cmd = new_cmd();
    line = env->input->line;
    double_quote_is_open = FALSE;
    single_quote_is_open = FALSE;
    back_slash = FALSE;
    j = env->input->i;
    while (j < env->input->len)
    {
        if (line[j] == BACK_SLASH)
            back_slash = TRUE;
        if (line[j] == DOUBLE_QT && !back_slash)
        {
            back_slash = FALSE;
            double_quote_is_open = !double_quote_is_open;
        }
        else if (line[j] == SINGLE_QT && !back_slash)
        {
            back_slash = FALSE;
            single_quote_is_open = !single_quote_is_open;
        }
        else if (line[j] == SEP && !back_slash)
        {
            back_slash = FALSE;
            if (!double_quote_is_open && !single_quote_is_open && ++j)
                break ;
        }
        j++;
    }
    cmd->cmd = sub_str(line, env->input->i, j);
    env->input->i = j;
    return cmd;
}

t_bool      split_commands(ENV)
{
    t_token     *token;
    t_command   *cmd;
    char        *line;
    int         i;

    line = env->input->line;
    i = 0;
    while (i < env->input->len)
    {
        env->input->i = i;
        if (line[i] != SPACE)
        {
            if (line[i] == DOUBLE_QT || line[i] == SINGLE_QT)
                cmd = get_quoted_command(env);
            else
                cmd = get_command(env);
            // cmd->len = i - env->input->i;
            cmd->len = str_len(cmd->cmd);
            push_back(&env->commands, cmd);
            i = env->input->i;
        }
        else
            i++;
    }
    return (0);
}
