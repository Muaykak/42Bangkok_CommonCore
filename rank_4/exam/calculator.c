#include <ctype.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>



typedef enum e_type {
	VAL,
	ADD,
	MULTI
}			t_type;

typedef struct s_cal_node {

	t_type				type;
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

EXAM RANK 4
						   104
			<<- "(((((2 x 4) + 1) + 7) + 2 x 2) x 5 + 4)"

							+
						   / \
						  x   4
						 / \
						+   5
					  /   \
					 +     x
				   /  \   /  \
				  +    7  2   2 
				/   \
			    x	1
			  /  \
			 2    4
*/
t_cal_node	*fake_parsing(void)
{
	return (new_node(node_info(ADD, 0, new_node(node_info(MULTI, 0, \
new_node(node_info(ADD, 0, new_node(node_info(ADD, 0, \
new_node(node_info(ADD, 0, new_node(node_info(MULTI, 0, \
new_node(node_info(VAL, 2, NULL, NULL)), \
new_node(node_info(VAL, 4, NULL, NULL)))), \
new_node(node_info(VAL, 1, NULL, NULL)))), \
new_node(node_info(VAL, 7, NULL, NULL)))), \
new_node(node_info(MULTI, 0, new_node(node_info(VAL, 2, NULL, NULL)), \
new_node(node_info(VAL, 2, NULL, NULL)))))), \
new_node(node_info(VAL, 5, NULL, NULL)))), new_node(node_info(VAL, 4, NULL, NULL)))));
}

/*
	Example: 2+2+2

		+
       / \
	  2   +
	  	 / \
		2   2
	
	Example: 1x2+3   				1x(2+3)

				+						x
			   / \					   / \
			  x   3					  1   +
			 / \						 / \
			1   2						2   3

*/

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
	
	cal_node = fake_parsing();
	printf("result = %d\n", calculation(cal_node));
	destroy_node(cal_node);
	return (0);
}
