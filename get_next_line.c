#include "get_next_line.h"

// line sert a stocker la ligne lu, donc elle doit contenir la ligne sans le newline
// comment stocker ce qui a ete lu en trop par le buffer ?


int		get_next_line(int const fd, char **line)
{
	static char	buf[BUFF_SIZE];
	int		i;
	char		*tmp;

	if (buf[0] == 0)
	{
		ret = read(fd, buf, BUFF_SIZE);
	}
	tmp = (char*)malloc(sizeof(char) * BUFF_SIZE + 1);
	tmp = ft_strcpy(tmp, buf);
	while (!ft_strchr(tmp, '\n'))
	{
		ret = read(fd, buf, BUFF_SIZE);
		tmp = filltmp(tmp, buf);
	}

}

static char	*filltmp(char *tmp, char *buf)
{
	char	*tmp2;
	
	if (!tmp)
	{
		tmp = (char*)malloc(sizeof(char) * BUFF_SIZE + 1);
		tmp = strncpy(tmp, buf, BUFFSIZE);
		tmp[BUFF_SIZE] = '\0';
	}
	else
	{
		tmp2 = (char*)ft_memalloc(sizeof(char) * BUFF_SIZE + ft_strlen(tmp) + 1);
		tmp2 = ft_strcpy(tmp2, tmp);
		tmp2 = ft_strncat(tmp2, buf, BUFF_SIZE);
		free(tmp);
		tmp = tmp2;
	}
	return (tmp);	
}





//static permet a une variable de garder sa valeur si on invoque plsr 
//fois la fonction !
//
//pour le bonus sur les differents fd, stocker les buf dans une liste chainee
//contenant a la fois buf et fb
//
//peut etre utiliser strchr
