#include "sort.h"

static bool	is_sorted(int *arr, int length);

// heap sort
void	sort(int *arr, int length)
{
	int	child;
	int	parent;
	int	end;
	int	temp;

	end = length - 1;
	while (end > 0)
	{
		child = end;
		while (child > 0)
		{
			parent = (child - 1) / 2;
			if (arr[child] > arr[parent])
			{
				temp = arr[parent];
				arr[parent] = arr[child];
				arr[child] = temp;
			}
			child--;
		}
		temp = arr[end];
		arr[end] = arr[0];
		arr[0] = temp;
		end--;
	}
}

static bool	is_sorted(int *arr, int length)
{
	int	i;

	i = 0;
	while (++i < length)
		if (arr[i] < arr[i - 1])
			return (false);
	return (true);
}