#ifndef __PARSER__
# define __PARSER__

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct is_quote {
	short int 	single_quote; // 1 or 0
	short int 	double_quote; // 1 or 0
	size_t 		num_quotes; // is it odd or even
}				t_is_quote;

int 		check_for_double_quote(char *line);
int 		is_it_cmd(char *line);

#endif
