
#include "minishell.h"

t_env   *init_env(int argc, char **argv, char **env_var)
{
    t_env   *env;

    MALLOC(env);
    env->commands = NULL;  //...

    MALLOC(env->input);
    env->input->i = 0;
    env->input->len = 0;
    env->input->line = NULL;
    return (env);
}

void    reset_env(ENV)
{
    list_iter(&env->commands, destroy_command);
    free(env->input);
    env->input = NULL;
}

t_token *new_token(void *tok)
{
    t_token *token;

    MALLOC(token);
    token->tok = NULL;
    token->type = NULL;
    token->order = -1;
    token->quoted = FALSE;
    if (tok)
        token->tok = tok;
    return (token);
}

t_command *new_cmd(void)
{
    t_command *cmd;

    cmd = malloc(sizeof(cmd));
    if (!cmd)
        return (NULL);
    cmd->tokens = NULL;
    cmd->i = 0;
    cmd->len = 0;
    cmd->ret = 0;
    cmd->sep = 0;
    return (cmd);
}

t_array *new_array(int size)
{
    t_array *array;
    int     i;

    MALLOC(array);
    ARRLLOC(array->arr, size);
    array->size = size;
    i = 0;
    while (i < size)
        array->arr[i++] = -1;
    return (array);
}