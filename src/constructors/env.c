
#include "minishell.h"

//initialize props
t_env   *init_env(int argc, char **argv, char **env_var)
{
    t_env   *env;

    MALLOC(env);
    MALLOC(env->input);    
    
    env->tokens = NULL;    //...
    env->commands = NULL;  //...
    return (env);
}

t_token *new_token(void *tok)
{
    t_token *token;

    MALLOC(token);
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