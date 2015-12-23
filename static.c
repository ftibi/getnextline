#include <stdio.h>

int	stat()
{
	static int i = 5;

	i += 5;
	return (i);
}

char	*stat2()
{
	static char tmp[5];
	
	tmp[1] += 1;
	return(tmp);
}

void	def(char *buf)
{
	buf[1] += 1;
}

int	main(void)
{

//	printf("%d", stat());
//	stat2();
//	stat2();
//	stat2();
//	stat2();
//	printf("%s", stat2());

//	static char buf[5] = "salut";
//	def(buf);
//	def(buf);
//	def(buf);
//	def(buf);
//	def(buf);
//	printf("%s",buf);
	



	return (0);
}


