#include <stdio.h>
#include <stdlib.h>

typedef struct s_pipe
{
    int                   s;
    struct s_pipe        *next;  // null
}    t_pipe;

typedef struct s_data
{
    t_pipe                *pipe;        // NULL
}    t_data;


void    ft_lstadd_front(t_pipe **lst, t_pipe *new)
{
    if (!lst || !new)
        return ;
    new->next = *lst;
    *lst = new;
}

t_pipe    *ft_lstlast(t_pipe *lst)
{
    if (!lst)
        return (0);
    while (lst)
    {
        if (!lst->next)
            return (lst);
        lst = lst->next;
    }
    return (lst);
}

void    ft_lstadd_back(t_pipe **lst, t_pipe *new)
{
    t_pipe    *new_node;

    if (!new)
        return ;
    if (!*lst)
    {
        *lst = new;
        return ;
    }
    new_node = ft_lstlast(*lst);
    new_node->next = new;
}


t_pipe    *ft_lstnew(int content)
{
    t_pipe    *new_node;

    new_node = (t_pipe *)malloc(sizeof(t_pipe));
    if (!new_node)
        return (NULL);
    new_node->s = content;
    new_node->next = NULL;
    return (new_node);
}


void foo(t_data *data)
{
    while(data->pipe)
    {
        printf("%d\n", data->pipe->s);
        data->pipe = data->pipe->next;
    }
}
void foo1(t_pipe *pipe)
{
    while(pipe)
    {
        printf("%d\n", pipe->s);
        pipe = pipe->next;
    }   
}

int main() {
  t_data data;
  int i = 0;
  
  data.pipe = NULL;
  while(i < 5)
  {
    ft_lstadd_back(&data.pipe, ft_lstnew(i++));
  }

    foo1(data.pipe);
    foo(&data);

  while(data.pipe)
  {
      printf("%d\n", data.pipe->s);
      data.pipe = data.pipe->next;
  }

  while(data.pipe)
  {
      printf("%d\n", data.pipe->s);
      data.pipe = data.pipe->next;
  }

  return 0;
}