#include "push-swap.h"

int count_array(long int *array, int i)
{
	while(array[i] != '\0')
		i++;
	return(i);
}

long int mid_list(t_list *a)
{
	long int *arr;
	long int m;

	arr = stack_to_array(a);
	m = mid(arr);
	free(arr);
	return (m);
}

long int sub_array(long int *arr)
{
	long int *sub;
	int i;
	int j;
	int max;

	max = mid(arr);
	i = 0;
	j = 0;
	while(arr[i])
	{
		if (arr[i]< max)
			j++;
	}
	sub = malloc(sizeof(long int)*(j + 1));
	if (sub == NULL)
        return (NULL);
	i = 0;
	j = 0;
	while(arr[i])
	{
		if (arr[i]< max)
		{
			sub[j] = arr[i];
			j++;
		}
		i++;
	}
	sub[j] = NULL;
	return (sub);
}

void add_push(t_list *new_node, int size, long int *arr)
{
	long int med;
    long int smid;
    long int sub2_mid;
    long int sub3_mid;
    long int sub4_mid;

	med = mid(arr);
    smid = mid(sub_array(arr));
    sub2_mid = mid(sub_array(sub_array(arr)));
    sub3_mid = mid(sub_array(sub_array(sub_array(arr))));
    sub4_mid = mid(sub_array(sub_array(sub_array(sub_array(arr)))));
	if (new_node->content < sub4_mid)
			new_node->push = 1;
		else if (new_node->content< sub3_mid)
			new_node->push = 2;
		else if (new_node->content < sub2_mid)
			new_node->push = 3;
		else if (new_node->content < smid)
			new_node->push = 4;
		else if (new_node->content < med)
			new_node->push = 5;		
		else
			new_node->push = 6;
}

void array_to_stack(long int *arr, int size, t_list **stack)
{
	t_list *new_node;

	*stack = NULL;
	int i = size - 1;
	while (i >= 0)
	{
		new_node = malloc(sizeof(t_list));
		new_node->content = arr[i];
		if (size > 50)
			add_push(new_node, size, arr);
		else
			new_node->push = 0;
		new_node->next = *stack;
		*stack = new_node;
		i--;
	}
}