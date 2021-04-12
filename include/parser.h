#ifndef __PARSER_H__
# define __PARSER_H__

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

<<<<<<< HEAD
typedef struct s_quote {
	short int 	single_quote; // 1 or 0
	short int 	double_quote; // 1 or 0
	size_t 		num_quotes; // is it odd or even
}				t_quote;

typedef struct s_cmd
{
	char *cmd;
	char *arg;
	char separator;
}				t_cmd;

typedef enum	s_bool
{
	false = 0,
	true = !false  // This is just for the compiler so that he takes care of false value based on the data type
} 				bool;
=======
typedef struct		is_quote {
	short int		single_quote; // 1 or 0
	short int		double_quote; // 1 or 0
	size_t			num_quotes; // is it odd or even
}					s_is_quote;

typedef enum	t_my_bool {
	false = 0, true = !false  // This is just for the compiler so that he takes care of false value based on the data type
} 				e_bool;

// Macros
# define DIGITS         "0123456789"
# define ASCII_LOWER    "abcdefghijklmnopqrstuvwxyz"
# define ASCII_UPPER    "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
# define PUNCTS         "!\"#$%&\'()*+,-./:;<=>?@[\\]^_`{|}~"
# define WHITESPACES    " \t\n\r\x0b\x0c"
>>>>>>> e3cd5a164aeea6c51d88f089085a2f84ad5b6f38

int 		check_for_double_quote(char *line);
int 		is_it_cmd(char *line);
int 		parse_special_chars(char *line);
<<<<<<< HEAD
t_cmd		*parse_line(char *line, t_cmd *commands);
=======
int			check_special_operator(char *line);
>>>>>>> e3cd5a164aeea6c51d88f089085a2f84ad5b6f38

#endif
