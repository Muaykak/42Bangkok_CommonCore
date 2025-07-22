#include <ctype.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct s_cal_node {
	enum e_type {
		VAL,
		ADD,
		MULTI
	}					type;
	int					value;
	struct s_cal_node	*left;
	struct s_cal_node	*right;
}				t_cal_node;

t_cal_node	node_info(enum e_type type, int value, t_cal_node *left, t_cal_node *right)
{
	t_cal_node	info;

	info.left = left;
	info.right = right;
	info.type = type;
	info.value = value;
	return (info);
}

t_cal_node	*new_node(t_cal_node node)
{
	t_cal_node	*new;

	new = malloc(1 * sizeof(t_cal_node));
	if (new == NULL)
		return (NULL);
	*new = node;
	return (new);
}

void	destroy_node(t_cal_node *head)
{
	if (head == NULL)
		return ;
	destroy_node(head->left);
	destroy_node(head->right);
	free(head);
	return ;
}

int	calculation(t_cal_node *head)
{
	if (head == NULL)
		return (0);
	if (head->type == VAL)
		return (head->value);
	if (head->type == MULTI)
		return (calculation(head->left) * calculation(head->right));
	return (calculation(head->left) + calculation(head->right));
}

t_cal_node *parsing(char *argv)
{

}

/*
This calculation program doesn't need to handle subtraction and division

		dont handle whitespace 

		the number put to this program will be only 0 - 9 (single digit)

		should also show unexpected token if error occur on which character
*/
int	main(int argc, char **argv)
{
	t_cal_node	*cal_node;
	if (argc != 2)
		return (1);
	
	cal_node = parsing(argv[1]);
	printf("result = %d\n", calculation(cal_node));
	destroy_node(cal_node);
	return (0);
}
