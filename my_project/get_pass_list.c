
#include "passfind.h"

char	*get_passlist(int fd)
{
	char	*str;

	str = get_next_line(fd);
	if (str == NULL || str[0])
		return (NULL);
	
}


