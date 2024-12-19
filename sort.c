/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 17:56:33 by akovtune          #+#    #+#             */
/*   Updated: 2024/12/19 15:17:01 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
