#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_list
{
	long			content;
    int             push;
	struct s_list	*next;
}					t_list;

/*void ft_lstclear(t_list **lst, void (*del)(void *))
{
    if (*lst == NULL || del == NULL)
        return;
    while (*lst)
    {
        t_list *tmp = *lst;
        *lst = (*lst)->next;
        del((long int *)tmp->content);
        free(tmp);
    }
}*/

void ft_lstclear(t_list *head) {
    t_list *current = head;
    t_list *next;

    while (current != NULL) {
        next = current->next; // Salva il puntatore al prossimo nodo
        free(current); // Libera il nodo corrente
        current = next; // Passa al prossimo nodo
    }
}

/*double	media_list(t_list *a)
{
	int i;
	t_list *temp;
	double val;

	i = 0;
	temp = a;
	val = 0;
	while (temp != NULL)
	{
		i++;
		val +=temp->content;
		temp = temp->next;
	}
	return (val/i);
}*/

long int *stack_to_array(t_list *a)
{
	long int *arr;
	int size;
	int n;
	t_list *tmp;

	size = counter(a);
	n = size;
	arr = (long int *)malloc(sizeof(long int)* (size + 1));
	if (!arr)
		return (NULL);
	tmp = a;
	while(tmp && size > 0)
	{
		arr[n - size] = tmp->content;
		size--;
		tmp = tmp->next;
	}
	arr[n] = '\0';
	return (arr);
}

long int mid_list(t_list *a)
{
	long int *arr;
	int m;

	arr = stack_to_array(a);
	m = mid(arr, NULL);
	free(arr);
	return (m);
}

int count_array(long int *array, int i)
{
	while(array[i] != '\0')
		i++;
	return(i);
}

long int *dup_array(long int *array, int dim)
{
	int i;
	long int *a;

	i = 0;
	a = (long int *)malloc(sizeof(long int)* dim);
	while (i < dim)
	{
		a[i]=array[i];
		i++;
	}
	return (a);
}


int mid(long int *array, long int threshold)
{
	int j;
	int k;
	int m;
	int dim;
	long int *a;

	dim = count_array(array, 0);
	a = dup_array(array, dim);
    while (j < dim - 1)
    {
        k = j + 1;
        while (k < dim)
        {
            if (a[j] > a[k])
            {
                int temp = a[j];
                a[j] = a[k];
                a[k] = temp;
            }
			k++;
        }
        j++;
    }
    j = 0;
    if(threshold != NULL)
    {
        while (j < dim)
        {
            if (array[j] > threshold)
                break;
			j++;
        }
        dim = j;
    }
    if (dim % 2 == 0)
        m = a[dim / 2];
    else
        m = a[(dim - 1) / 2];
	free(a);
    return m;
}

int max(t_list **stack)
{
	int	max;
	t_list *temp;

	temp = *stack;
	max = INT_MIN;
	while (temp)
	{
		if (max < temp->content)
			max = temp->content;
		temp = temp->next;	
	}
	return (max);
}

int type_rot_b(t_list **stack)
{
	t_list *temp;
	int rot;
	int rev;
	
	if (!stack || !(*stack) || !(*stack)->next)
		return (0);
	temp = (t_list *)malloc(sizeof(t_list));
	if (!temp)
		return (0);
	temp = *stack;
	rot = 0;
	rev = 0;
	while (temp)
	{
		if (temp->content == max(stack))
			break ;
		rot++;
		temp = temp->next;
	}
	rev = counter(*stack) - rot;
	if (rot <= rev)
		return (rot);
	else
		return (rev * -1);	
}

/*float media_array(long array[], int lunghezza)
{
	float media;
    int i;
	int somma;

    if (lunghezza == 0)
        return 0;
    somma = 0;
    while (i < lunghezza)
        somma += array[i++];
	media = (float)somma / lunghezza;    
	return (media);
}*/

int is_sorted(long int *arr, int n)
{
	int i;
	
	i = 1;
	while (i < n)
	{
		if (arr[i] < arr[i - 1])
			return (0);
		i++;
	}
	return (1);
}

int is_sorted_list(t_list *list)
{
	t_list *tmp;
	int i = 0;
	
	tmp = list;
	while (tmp->next != NULL)
	{
		if (!(tmp->next->content > tmp->content))
			i++;
		tmp = tmp->next;	
	}
	return (i);
}

void little_check(t_list **a, t_list **b)
{
	int i;
	int rot_b;
	
	i = 0;
	if (!a || !(*a) || !b || !(*b))
		return ;
	if (!(*a)->next || !(*b)->next)
		return ;
	while (counter(*b) > 1)
	{
		rot_b = type_rot_b(b);
		if (rot_b <= 0)
		{
			while ((*b)->content != max(b))
			{
				rev_rotate(b);
				write(1, "rrb\n", 4);
			}
			pa(a, b);
		}
		else if (rot_b > 0)
		{
			while ((*b)->content != max(b))
			{
				rotate(b);
				write(1, "rb\n", 3);
			}
			pa(a, b);
		}
	}
}

/*void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	if (*lst == NULL || del == NULL || lst == NULL)
		return ;
	if ((*lst)->next != NULL)
		ft_lstclear(&(*lst)->next, del);
	del((*lst)->content);
	free(*lst);
	*lst = NULL;
}*/

int	counter(t_list *a)
{
	int n;
	t_list *temp;

	n = 0;
	temp = a;
	while (temp != NULL)
	{
		temp = temp->next;
		n++;
	}
	return (n);
}

int	check_med(t_list *a, int med)
{
	t_list *tmp;

	tmp = a;
	while(tmp)
	{
		if (tmp->content < med)
			return(1);
		tmp = tmp->next;
	}
	return (0);
}

int find_direction_med(t_list *a, int med, int A)
{
	int pi;
	int pj;

	pi = penality_r(a, med);
	pj = penality_rr(a, med);
    if (pj < pi)
	{
		if (A)
			return (4);
		return (5);
	}  
    else 
	{
		if (A)
			return (1);
	}
	return (2);
}

int find_direction_push(t_list *a, int push, int A)
{
	int pi;
	int pj;

	pi = penality_r_push(a, push);
	pj = penality_rr_push(a, push);
    if (pj < pi)
	{
		if (A)
			return (4);
		return (5);
	}  
    else 
	{
		if (A)
			return (1);
	}
	return (2);
}

int penality_r_push(t_list *a, int t)
{
    int pi;
    int i;
    t_list *head;
    
    head = a;
    i = 0;
    pi = 0;
    while (i++ < counter(a)/2)
    {
        if (head->push != t)
        {
            pi++;
            head = head->next;
        } 
    }
	return (pi); 
}

int penality_rr_push(t_list *a, int t)
{
    int pj;
    int j;
    t_list *mid;
    
    mid = a;
    j = 0;
    pj = 0;
    while (j++ < counter(a)/2 -1)
        mid = mid->next;
    while (mid)
    {
        if (mid->push != t)
        {
            pj++;
            mid = mid->next;
        }
        return (counter(a)/2 -pj);
    }
}

int penality_r(t_list *a, int t)
{
    int pi;
    int i;
    t_list *head;
    
    head = a;
    i = 0;
    pi = 0;
    while (i++ < counter(a)/2)
    {
        if (head->content >= t)
        {
            pi++;
            head = head->next;
        } 
    }
	return (pi); 
}

int penality_rr(t_list *a, int t)
{
    int pj;
    int j;
    t_list *mid;
    
    mid = a;
    j = 0;
    pj = 0;
    while (j++ < counter(a)/2 -1)
        mid = mid->next;
    while (mid)
    {
        if (mid->content >= t)
        {
            pj++;
            mid = mid->next;
        }
        return (counter(a)/2 -pj);
    }
}

void	sort(t_list **a, t_list **b, int n)
{
	int	med;
	int i;

	*b = NULL;
	if ((*a)->push != 0)
		pre_order(a, b);
	while (counter(*a) > 2)
	{
		if (is_sorted_list(*a) == 0)
			break;
		med = mid_list(*a);	
		while(check_med(*a, med))
		{	
			if (is_sorted_list(*a) == 0)
				break;
			if ((*a)->content < med)
				pb(b, a);
			else if (*b && (*b)->next && (*b)->content < (*b)->next->content)
				do_rotate(a, b, 3);
			else
				do_rotate(a, b, find_direction_med(*a, med, 1));
		}
	}
	if ((*a)->content > (*a)->next->content && !(counter(*a) > 2))
	{
		sa(a);
		write(1, "sa\n", 3);
	}
	little_check(a, b);
    check_ss(a, b);
    pa(a, b);
    pa(a, b);
}

int check_push(t_list **a, int i)
{
	t_list *temp;

	temp = *a;
	while (temp)
	{
		if (temp->push == i)
			return (1);
		temp = temp->next;
	}
	return (0);
}

void do_rotate(t_list **a, t_list **b, int cod)
{
    if (cod == 1 && a && *a && (*a)->next)
    {
        rotate(a);
        write(1, "ra\n", 3);
    }
    else if (cod == 2 && b && *b && (*b)->next)
    {
        rotate(b);
        write(1, "rb\n", 3);
    }
    else if (cod == 3 && a && *a && (*a)->next && b && *b && (*b)->next)
    {
        rotate(a);
        rotate(b);
        write(1, "rr\n", 3);
    }
    else if (cod == 4 && a && *a && (*a)->next)
    {
        rev_rotate(a);
        write(1, "rra\n", 4);
    }
    else if (cod == 5 && b && *b && (*b)->next)
    {
        rev_rotate(b);
        write(1, "rrb\n", 4);
    }
    else if (cod == 6 && a && *a && (*a)->next && b && *b && (*b)->next)
    {
        rev_rotate(a);
        rev_rotate(b);
        write(1, "rrr\n", 4);
    }
}

void rotate(t_list **stack)
{
    t_list *node_2;
    t_list *tmp;

    if (*stack == NULL || (*stack)->next == NULL)
        return;
    tmp = *stack;
    node_2 = (*stack)->next;
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = *stack;
    (*stack)->next = NULL;
    *stack = node_2;
}

void rev_rotate(t_list **stack)
{
    t_list *tmp;
    t_list *end;

    if (stack && *stack && (*stack)->next)
    {
        tmp = *stack;
        while (tmp->next->next)
            tmp = tmp->next;

        end = tmp->next;
        tmp->next = NULL;
        end->next = *stack;
        *stack = end;
    }
    else
        return;
}

void pa(t_list **add, t_list **take)
{
	t_list *g;

	g = (t_list *)malloc(sizeof(t_list));
	if (!g || !*take || !take)
		return ;
	g->content = (*take)->content;
	g->next = *add;
	*add = g;
	*take = (*take)->next;
	write(1, "pa\n", 3);
	free(g);
}

void pb(t_list **add, t_list **take)
{
	t_list *g;
	t_list *current;
	t_list *temp;

	g = (t_list *)malloc(sizeof(t_list));
	if (!g || !*take || !take)
		return ;
	g->content = (*take)->content;
	g->next = *add;
	*add = g;
	current = *add;
	temp = *take;
	*take = (*take)->next;
	write(1, "pb\n", 3);
	free(temp);
	current = *take;
}


void sa(t_list **a)
{
    int t;

    if (!a || !*a || !(*a)->next)
        return;

    t = (*a)->content;
    (*a)->content = (*a)->next->content;
    (*a)->next->content = t;
}

void sb(t_list **a)
{
    int t;

    if (!a || !*a || !(*a)->next)
        return;

    t = (*a)->content;
    (*a)->content = (*a)->next->content;
    (*a)->next->content = t;
}

void ss(t_list **a, t_list **b)
{
    sa(a);
    sb(b);
    write(1, "ss\n", 3);
}

void check_ss(t_list **a, t_list **b)
{
    if (!a || !*a || !(*a)->next || !b || !*b || !(*b)->next)
        return ;
    if ((*a)->next != NULL && (*b)->next != NULL)
    {
        if ((*a)->content > (*a)->next->content && (*b)->content < (*b)->next->content)
            ss(a, b);
    }

    if ((*a)->next != NULL && (*a)->content > (*a)->next->content)
    {
        write(1, "sa\n", 3);
        sa(a);
    }

    if ((*b)->next != NULL && (*b)->content < (*b)->next->content)
    {
        write(1, "sb\n", 3);
        sb(b);
    }
}

void pre_order(t_list **a, t_list **b)
{
    int i;

    i = 1;
    while (i < 6)
    {
        if ((*a)->push == i)
            pb(b, a);
		else if(*b && (*b)->next && (*b)->content < (*b)->next->content)
            do_rotate(a, b, 3);
        else
            do_rotate(a, b, find_direction_push(*a, i, 1));//Qui non dovrebbe guardare med ma il push
        if (!check_push(a, i))
        	i++;
    }
}

void add_push(t_list *new_node, int size, long int *arr)
{
	int med;
    int smid;
    int sub2_mid;
    int sub3_mid;
    int sub4_mid;

	med = mid(arr, NULL);
    smid = mid(arr, med);
    sub2_mid = mid(arr, smid);
    sub3_mid = mid(arr, sub2_mid);
    sub4_mid = mid(arr, sub3_mid);
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
	int i;

	*stack = NULL;
	i = size - 1;
	while (i >= 0)
	{
		//printf("ARR1: %i i: %i \n", arr[i], i);
		i--;
	}
	i = size - 1;
	while (i >= 0)
	{
		//printf("ARR2: %i i: %i \n", arr[i], i); //MA come è possibile??????
        new_node = malloc(sizeof(t_list));
        if (!new_node)
        {
            while (*stack != NULL)
            {
                t_list *temp = *stack;
                *stack = (*stack)->next;
                free(temp);
            }
            return;
        }
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

int ft_atoi(char **nptr, long int *nums)
{
    int i = 1;
    long int num = 0;
    int n = 0;

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
	if (!stackA)
		return (0);
	stackB = malloc(sizeof(t_list));
	if (!stackB)
		return (0);
    n = count_element(argv);
    long int nums[n];
    ft_atoi(argv, nums);
    if (argc < 2 || ft_check(nums, n) == 0)
        return (write(1, "Errore\n", 7));
    array_to_stack(nums, n, &stackA);
    sort(&stackA, &stackB, n); 
	/*ft_lstclear(stackA);
    ft_lstclear(stackB);
	free(nums);*/
    return (0);
}
