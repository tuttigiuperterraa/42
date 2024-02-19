#include "push-swap.h"

int mid(long int *array)
{
	int j;
	int k;
	int m;
	int dim;

	dim = count_array(array, 0);
	j = 0;
    while (j < dim - 1)
    {
        k = j + 1;
        while (k < dim)
        {
            if (array[j] > array[k])
            {
                int temp = array[j];
                array[j] = array[k];
                array[k] = temp;
            }
			k++;
        }
        j++;
    }
    if (dim % 2 == 0)
        m = array[dim / 2];
    else
        m = array[(dim - 1) / 2];
    return m;
}

int ft_check(long int *nums, int i)
{
	int j;

	i--;
    while (i >= 0)
    {
		j = 0;
		if(nums[i] > 2147483647 || nums[i] < -2147483648)
			return (0);
		while (j < i)
		{
			if((int)nums[i] == (int)nums[j])
				return (0);
			j++;
		}
		i--;
	}
	return (1);
}

int is_sign(char av)
{
	if (av == '+')
		return (1);
	else if(av == '-')
		return (-1);
	else
		return (0);
}

int ft_atoi(char **argv, long int *nums)
{
	char **nptr;
    int i = 1;
    long int num = 0;
    int n = 0;

	nptr = argv;
    while (nptr[i])
    {
        int sign = 1;
        int j = 0;
        while (nptr[i][j])
        {
            if (is_sign(nptr[i][j]) == 1 || is_sign(nptr[i][j]) == -1)
            {
                sign = is_sign(nptr[i][j]);
                j++;
            }
            while (nptr[i][j] >= '0' && nptr[i][j] <= '9')
            {
                num = num * 10 + (nptr[i][j] - '0');
                if (nptr[i][j + 1] == ' ' || nptr[i][j + 1] == '\0')
                {
                    nums[n] = sign * num;
                    num = 0;
                    n++;
                    if(nptr[i][j + 1] == '\0')
                        break;
                }
                j++;
            }
            j++;
        }
        i++;
    }
    return n;
}

int count_element(char **argv)
{
	int n;
    int i;
    int j;

	n = 0;
	i = 1;
    while (argv[i])
	{
        j = 0;
        while (argv[i][j])
        {
            if (argv[i][j] >= '0' && argv[i][j] <= '9')
            {
                while (argv[i][j] >= '0' && argv[i][j] <= '9')
                    j++;
                n++;
            }
            else
                j++;
        }
        i++;
    }
    return (n);
}

int main(int argc, char **argv)
{
    t_list	*stackA;
    t_list  *stackB;
    int n;

	stackA = malloc(sizeof(t_list));
	stackB = malloc(sizeof(t_list));
    n = count_element(argv);
    long int nums[n];
    ft_atoi(argv, nums);
    if (argc <= 2 || ft_check(nums, n) == 0)
        return (0);
    array_to_stack(nums, n, &stackA);
    sort(&stackA, &stackB, n); 
	ft_lstclear(stackA);
    ft_lstclear(stackB);
	free(nums);
    return (0);
}