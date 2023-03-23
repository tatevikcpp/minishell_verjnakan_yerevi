#include "minishell.h"

void printf_pipe(t_pipe *pipe);

// $ls|"$ls   "
int parsing(t_data *data, char *ptr) 
{
// if (syntax_error(ptr, &i) == 1 || metachar_error(ptr) == 1 ) // >a     ev ls|ls | "|ls|"
    // 	continue ;
    // if (syntax_error(ptr, &i) == 1)
    // 	continue ;
    // if (metachar_error(ptr) == 1)
    // 	continue ;							// kara chlini
    // check_qoutes(ptr); // sxala ashxatum

    // check_quot_double(ptr);
    // check_quot_one(ptr);
    // print_list_head_env(&data);


    split_string(ptr, data); // ls|ls | "|ls|"  sxala ashxatum
    // print_lists(data->pipe);
    t_pipe *tmp1 = data->pipe;
    while (tmp1) //pttvum e michpaipain taracutjunerov u juraqanchjuri hamar gtnum redirektnery u faili anuner@
    {
        tmp1->red = redirect_test(tmp1); // sxal ls>a>b
        split_s__to_argv(/* &data,  */tmp1); // *(42) => 1
        tmp1 = tmp1->next;
    }
    printf_pipe(data->pipe);
    printf("pipe count: %d\n", data->pipe_count);
    return (0);
}