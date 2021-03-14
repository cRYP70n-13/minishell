
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
    t_command   *cmd;
    char        *line;
    t_bool      open_quote;
    size_t      j;



    cmd = new_cmd();
    line = env->input->line;
    j = env->input->i;
    while (j < env->input->len)
    // 'echo' 'peace;' ";" ; "cat file;"
    {
        if (line[j] == DOUBLE_QT)
        {
            open_quote = TRUE;
        }
    }
    
    
    open_quote = FALSE;
    return (cmd);
}

t_command       *get_command(ENV)
{
    t_command   *cmd;
    char        *line;
    int         j;

    cmd = new_cmd();
    j = env->input->i;
    line = env->input->line;
    while (j < env->input->len)
    {
        if (line[j] == ';' && line[j - 1] != BACK_SLASH)
            break ;
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
            i = env->input->i; //updates index
            print("---");
            print(cmd->cmd);
            print("---");
            push_back(&env->commands, cmd);
        }
        else
            i++;
    }
    return (0);
}
