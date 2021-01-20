#include "libft.h"

char		*ft_strccpy(char *dest, char const *str, char c)
{
	int		i;

	i = 0;
	while (str[i] != c && str[i])
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}