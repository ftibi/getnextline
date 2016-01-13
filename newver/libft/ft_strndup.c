#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	char	*resp;
	char 	*save;
	size_t	i;

	resp = (char*)ft_memalloc(n + 1);
	if (!resp)
		return (NULL);
	save = resp;
	i = 0;
	while (*s1 && i < n)
	{
		*resp = *s1;
		resp++;
		s1++;
		i++;
	}
	return (save);
}
