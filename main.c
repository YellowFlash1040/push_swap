#include "args_parser.h"
#include "stack.h"
#include "push_swap.h"
#include "sort.h"
#include <stdio.h>
#include "helpers.h"

// read
// write
// malloc
// free
// exit
// ft_printf

int	main(int argsc, char **args)
{
	t_list	*list;
	t_list	*temp;
	t_stack	*stack;
	// t_stack	*item;
	int		length;

	//0 12 4 6 5 2 15 13 16 10 19 1 8 3 11 9 14 7 17 18
	if (argsc < 2)
		return (0);
	length = argsc - 1;
	list = parse(argsc, args);
	stack = NULL;
	if (!list)
		return (1);
	int* arr = (int*)malloc(sizeof(int) * length);
	if (!arr)
		return (clear_list(&list), 1);
	int i = 0;
	while (list)
	{
		arr[i++] = list->num;
		push(create_item(list->num), &stack, false);
		temp = list->next;
		free(list);
		list = temp;
	}
	sort(arr, length);
	solve(arr, length, stack);
	
	free(arr);
	arr = NULL;
}
