
#include "minishell.h"

//initialize props
t_env   *init_env(int argc, char **argv, char **env_var)
{
    t_env   *env;

    MALLOC(env);
    env->tokens = NULL;    //...
    env->commands = NULL;  //...

    MALLOC(env->input);
    env->input->i = 0;
    env->input->len = 0;
    env->input->line = NULL;
    return (env);
}

void    list_map_func(LIST)//, )
{
    t_node  *iter;
    t_token *token;

    iter = *list;
    while (iter)
    {
        token = iter->data;


        iter = iter->next;
    }
}

void    destroy_token(t_token *token)
{
    if (token->tok)
    {
        free(token->tok);
        // token->tok = NULL;
    }
    free(token);
    // token = NULL;
}

void    reset_env(ENV)
{
    reset_commands(env);
}

void    reset_commands(ENV)
{
    t_node      *iter;
    t_command   *cmd;

    iter = env->commands;
    while (iter)
    {
        cmd = iter->data;
        if (cmd->cmd)
            free(cmd->cmd);
        // list_map_func(cmd->tokens, &destroy_token);
        iter = iter->next;
    }
    free(env->commands);
    env->commands = NULL;
}

t_token *new_token(void *tok)
{
    t_token *token;

    MALLOC(token);
    if (tok)
        token->tok = tok;
    // else
    //     token->tok = NULL;
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