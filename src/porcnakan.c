//  #include "minishell.h"

// void hendl_dolar(t_data *data, char *str)
// {
    
//     int i;
//     int j;    
//     char *str1;
//     char *val;

//     i = 0;
//     j = 0;    
//     // int len_val = 0;
//     while (str[j])
//     {
//         if (/* str[j -1] != '\'' && */ str[j] == '$' && (ft_isalpha(str[j+1]) || str[j+1] == '_'))
//         {
//             j++;
//             i = j;
//             while((ft_isalpha(str[j]) || str[j] == '_' || ft_isdigit(str[j])))
//                 j++;
//             str1 = ft_substr(str,i,j - i);
//             data-> len_key_sum += ft_strlen(str1);
//             val = get_dolar_val(data, str1);
//             j--;
//             printf("str1 = %s\n",  str1);
//             // printf("len_key_sum = %d\n",data->len_key_sum);
//         }
//         j++;
//     }    
//     // printf("len_key_sum = %d\n", data->len_key_sum);
// }

// char *get_dolar_val(t_data *data, char *str1)
// {
//     t_env *head;
//     char *str;
//     int len_val_sum;

//     // len_val_sum = 0;
//     str = NULL;
//     {       
//         if (ft_strcmp(head->key , str1) == 0)
//         {
//             str = head->val;
//             // printf("val = %s\n", str);
//             data->len_val_sum += ft_strlen(str);
//         }
//         head = head->next;
//     }
//     // printf("len_val_sum = %d\n", data->len_val_sum);
//     // printf("******\n");

//     return (str);
// }


// // char *hendl_dolar_inline(t_data *data, char *str)
// // {
    
// //     int i;
// //     int j;    
// //     char *str1 = NULL;
// //     char *val;

// //     i = 0;
// //     j = 0;    
// //     // int len_val = 0;
// //     while (str[j])
// //     {
// //         if (str[j -1] != '\'' && str[j] == '$' && (ft_isalpha(str[j+1]) || str[j+1] == '_'))
// //         {
// //             j++;
// //             i = j;
// //             while((ft_isalpha(str[j]) || str[j] == '_' || ft_isdigit(str[j])))
// //                 j++;
// //             str1 = ft_substr(str,i,j - i);
// //             data-> len_key_sum += ft_strlen(str1);
// //             val = get_dolar_val(data, str1);
// //             j--;
// //             // printf("str1 = %s\n",  str1);
// //             // printf("len_key_sum = %d\n",data->len_key_sum);
// //         }
// //         j++;
// //     }    
// //     return (str1);
// // }


// char *hendl_doloar_comand(t_data *data, char *test)
// {
//     int     p;
//     int     i;
//     int     j;
//     int     len;
//     char    *ptr = NULL;
//     char    *str1;
//     char    *str_line;

//     i = 0;
//     j = 0;
//     str_line = ptr;
//     len = ft_strlen(test);
//     str_line = malloc(sizeof(char)*(len - data->len_key_sum + data->len_val_sum + 1));
//     // ptr = test;
//     p = len - data->len_key_sum + data->len_val_sum;
//     // printf("p = %d\n", p);
//     while(test[j])
//     {
//         if (test[j -1] != '\'' && test[j] == '$' && (ft_isalpha(test[j+1]) || test[j+1] == '_'))
//         {
//             j++;
//             i = j;
//             while((ft_isalpha(test[j]) || test[j] == '_' || ft_isdigit(test[j])))
//                 j++;
//             str1 = ft_substr(test,i,j - i);
//             get_dolar_val(data, str1);
//             /* if(get_dolar_val(data, str1) != NULL)
//             {
//                 ptr = get_dolar_val(data, str1);
//                 str_line = ft_strjoin(str_line,ptr);
//                 // printf(" 4444 = %s\n", ptr);
//             } */
//             ptr = get_dolar_val(data, str1);
// 			if (ptr)
//                 str_line = ft_strjoin(str_line,ptr);
//             j--;
//             // printf("str1 = %s\n",  str1);
//             // printf("len_key_sum = %d\n",data->len_key_sum);
//         }
//        /*  if (test[j] != '\"' || test[j] != '$') */
//         else
//         {
//             ptr = ft_substr(test, j, 1);
//             str_line = ft_strjoin(str_line,ptr);
//             // printf("else_ptr:%s\n", ptr);
//             // printf("j = %c", test[j]);
//         }
//         j++;
// 	}
//     // printf("str_line%s\n", str_line);
//     return (str_line);
// }
// //leaks     'dsgsdgsd$PWD g'
//  int main(int ac,  char **av,  char **env)//kaskaceli e Tatevi hamar u shaaat 
// {
// 	(void)(av+ac);
// 	// int j;
//     int i;
// 	t_data	data;
    
// 	// char *ptr = ft_strdup(" ");
//     // char *str1;
//     // int len;
//     // int p;
// 	// j = 0;
//     i = 0;
// 	 struct_zeroed(&data, env);
// 	// init(&data, env);
// 	// printf("%s\n", ft_get_value("PATH", &data));
// 	// char	*test = "la -la \"$PWD\"$HOME $SFAFSF biuhbui $PWD  '$HOME'  sdgsdg";
//     char *test;
//     while (1)
//     {
// 		test = readline("minishell-$ ");
//         add_history(test);
// 	// char	*test = "la -la  'kshja' \"$OKK0M\" \"$PWD\"$HOME $SFAFSF biuhbui $PWD barev okokok '$HOME'  sdgsdg";
//     hendl_dolar(&data, test);
//     // ptr = hendl_doloar_comand(&data, test);
//     // printf("ptr: %s\n", ptr - 87);
//     printf("comand : %s\n", hendl_doloar_comand(&data, test));

//     }

//     // ptr = test;
//     // while (*test != '\0')
//     //     test++;
//     // printf("1111 = %s\n", ptr);
//     // printf("test: %s\n", test - 87);
// 	return (0);
// }