
#ifndef FUNCTIONS_H
# define FUNCTIONS_H

# include "minishell.h"

//This header file is only for functions' prototypes

/* 
## Allowed functions: 
####################
    malloc() free() write() open() read() 
    fork() wait() waitpid() wait3() wait4()
    stat() lstat() fstat() execve() pipe()
    chdir() opendir() readdir() closedir()
    getcwd() dup() dup2()
    signal() kill() close() exit()
    strerror() errno()
*/

// main
int         repl(ENV);
int         read_input(char **input);

// Constructos
t_token         *new_token(void *tok);
t_array         *new_array(int size);
t_env           *init_env(int argc, char **argv, char **env_var);

// Tokenizer
t_bool          tokenize_input(ENV);
t_token         *get_token(ENV);
t_token         *tokenize_quoted_input(ENV);
t_token         *tokenize_single_quoted(ENV);
t_token         *tokenize_double_quoted(ENV);

// Commands
t_bool          split_commands(ENV);
t_command       *new_cmd(void);

// Lexer
int             lex_tokens(ENV);

// strtools_0
size_t      str_len(const char *str);
void        put_char(char c);
void        put_str(const char *str);
void        fput_char(char c, int fd);
void        fput_str(const char *str, int fd);

// strtools_1
size_t      line_len(const char *str);
t_bool      find_eol(char *buff);
t_bool      line_isempty(char *line);
t_bool      str_cmp(char *s1, char *s2);
t_bool      str_ncmp(char *s1, char *s2, int max);
//char        *char_addr(char c, char **buff);

// strtools_2
char        *str_dup(const char *str);
char        *str_join(const char *s1, const char *s2);
char        *sub_str(
                    char const *s, int start, int end);
char        *clean_sub_str(
                    char const *s, int start, int end, t_array *arr );

//Quotes stuff
t_bool      check_quotes(char *str);
t_bool      check_quoted_str(char *str, char c);
t_bool      is_str_quoted(char *str, char mark);
t_bool      is_bad_quoted(char *str);

// idk
int         get_line(int fd, char **line);

// Linked list functions
t_node      *new_node(void *data);

void        push_back(LIST, void  *data);
t_node      *push_front(LIST, void  **data);

size_t      list_size(t_node    *list);
void        list_iter(LIST, void(*fun)(void **));
void        safe_free(void **p);
void        destroy_lst(LIST);
void        delete_lst(LIST);


//Parsing 
t_bool      split_by_type(char *buff, t_node **tokens);
int         tokenize(char *buff, ENV);



//tmp_utils
void    print_array(t_array *arr, t_bool minus);
void    print_tokens(t_node **tokens);

#endif