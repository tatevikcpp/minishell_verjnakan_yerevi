#include "minishell.h"

// >>        a>>b>>c<d<e>f<<g<<h ls -la
// ">>        a>>b>>c<t<o>p<<t<<u ls -la";  ays depq@ chi ashxatum
// echo  >> amalia | ls <t >u -la | he'l'lo >> | m 'hello  | world'  
// echo abc &x     >>    amalia   < 121 | ls    <   t   >    u   -la | he'l'lo   >> | m 'hello  | w'
// 000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000

char *split_quote(char *top, int *i, char c)
{
	int	first;

	first = *i;
	char * str = malloc(sizeof(char));
	while (top[*i] != c)
		(*i)++;
	str =  ft_substr(top, first, *i - first);		
	return (str);
}