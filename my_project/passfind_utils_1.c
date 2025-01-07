#include "passfind.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return(0);
	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i[2];
	char	*newstring;

	if (!s1 && !s2)
		return (NULL);
	else if (!s1 && s2)
		return (s2);
	else if (!s2 && s1)
		return (s1);
	newstring = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (newstring == 0)
	{
		free(s1);
		free(s2);
		return (NULL);
	}
	i[0] = 0;
	while (s1[i[0]] != '\0')
	{
		newstring[i[0]] = s1[i[0]];
		i[0]++;
	}
	i[1] = 0;
	while (s2[i[1]] != '\0')
	{
		newstring[i[0] + i[1]] = s2[i[1]];
		i[1]++;
	}
	newstring[i[0] + i[1]] = '\0';
	free(s1);
	free(s2);
	return (newstring);
}