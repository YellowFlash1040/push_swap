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
		push(create_item(list->num), &stack);
		temp = list->next;
		free(list);
		list = temp;
	}
	printf("0 12 4 6 5 2 15 13 16 10 19 1 8 3 11 9 14 7 17 18\n");
	sort(arr, length);
	
	print_array(arr, length);
	solve(arr, length, stack);
	
	free(arr);
	arr = NULL;
}

// get the array of input numbers lets call it "numbers"
// copy "numbers" into the "stack_a"
// sort the array "numbers"
// find the median by simply dividing it's length into 2 and accessing element at that index
//

// 0 12 4 6 5 2 15 13 16 10 19 1 8 3 11 9 14 7 17 18 - input

// 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 - numbers
// length = 20
// 0 1 2 3 4 5 6 7 8 9 - X
// 0 1 2 3 4 - X_left (goes to the BOTTOM-B)
// 5 6 7 8 9 - X_right (goes to the TOP-B)
// 10 11 12 13 14 15 16 17 18 19 - Y

//>= Y-medin => go to X
//>= X-median => go to X_right

// Y-median = 10
// X-median = 5
// Y-median-index = 10
// X-median-index = 5

// move through stack_a looking for numbers in X and move them to appropriate location depending
// on their presence in the X_left or X_right
// cur_num_index = 1
// cur_num = 12

// 0
// 12
// 4
// 6
// 5
// 2
// 15
// 13
// 16
// 10
// 19
// 1
// 8
// 3
// 11
// 9
// 14
// 7
// 17
// 18
// --		--
// a		b

//--------------------------------------------------
//  Y
// 12		7
// 15		9
// 13		8      ^
// 16		5      |
// 10		6 -- start of X_right
// 19		0 -- start of X_left
// 11		4      |
// 14 		2      +
// 17		1
// 18		3
// --		--
// a		b