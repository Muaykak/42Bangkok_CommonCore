
#ifndef PASSFIND_H
# define PASSFIND_H

# include "get_next_line_bonus.h"
# include "ft_printf.h"
# include <fcntl.h>
# include "passfind.h"
# include "libft.h"
# define PASS_FILE "text.mark"

char	*get_passlist(int fd);

#endif