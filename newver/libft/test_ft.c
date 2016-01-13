/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfolly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 11:56:19 by tfolly            #+#    #+#             */
/*   Updated: 2015/12/07 19:20:36 by tfolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <ctype.h>

void	donneu(char *c)
{
	*c = 'U';
}
char	plusun(char c)
{
	return (c + 1);
}
void	ufdel(void *d, size_t s)
{
	free(d);
	(void)s;
	d = NULL;
}

int ft_mult(int *a, int *b)
{
	return (*a * *b);
}

int	ft_sum(int *a, int *b)
{

	return(*a + *b);
}

int ft_cmp(int *a)
{
	if (*a > (3 + '0'))
		return (0);
	return (1);
}

int	main(void)
{
//	ft_putchar('A');
//	ft_putchar('\n');
//	ft_putstr("salut");
//	ft_putchar('\n');
//	ft_putnbr(256);
//	ft_putchar('\n');
//	ft_putnbr(ft_strlen("salut"));
//	ft_putchar('\n');
//	ft_putendl("coucou");
//	ft_putchar('\n');

//	//test ft_putnbr
//	ft_putnbr(-10);
//	ft_putchar('\n');

//	//test de donneu
//	char i = 'K';
//	ft_putchar(i);
//	donneu(&i);
//	ft_putchar(i);
//	ft_putchar('\n');

//	// test de ft_striter
//	void (*f)(char *) = donneu;
//	char str[] = "Salut";
//	ft_putstr(str);
//	ft_putchar('\n');
//	ft_striter(str,f);
//	ft_putstr(str);

//	//test de ft_strmap
//	char const str2[] = "bonjour ici";
//	
//	ft_putstr(str2);
//	ft_putchar('\n');
//	ft_putstr(ft_strmap(str2, plusun));
//	ft_putchar('\n');

//	//test de ft_itoa
//	ft_putstr(ft_itoa(0));
//	ft_putchar('\n');
//	ft_putstr(ft_itoa(-10));
//	ft_putchar('\n');
//	ft_putstr(ft_itoa(256 + 40 + 20));
//	ft_putchar('\n');
//	ft_putstr(ft_itoa(-2147483648));
//	ft_putchar('\n');
//	ft_putstr(ft_itoa(2147483647));




//	//test de ft_strequ
//	char const *stra = "bonjour";
//	char const *strb = "bonjour";
//	char const *strc = "salut";
//	ft_putnbr(ft_strequ(stra, strb));
//	ft_putchar('\n');
//	ft_putnbr(ft_strequ(stra, strc));

//	//test de strcpy
//	const char src[] = "Hello";
//	char dst[] = "0000000";
//	ft_strcpy(dst, src);
//	ft_putstr(dst);
//	ft_putchar('\n');
//	strcpy(dst, src);
//	ft_putstr(dst);

//	// test de str_join
//	char const *chaine1 = "salut";
//	char const *chaine2 = " les amis";
//	ft_putstr(ft_strjoin(chaine1, chaine2));
//	ft_putchar('\n');

//	//test de ft_strtrim
//	char const *stringu = "  salut ca  vaaaa \n		";
//	ft_putstr(stringu);
//	ft_putchar('\n');
//	ft_putstr(ft_strtrim(stringu));
//	ft_putchar('\n');

//	//test de strdup
//	char const *srcsrc = "salut les copains";
//	ft_putstr(ft_strdup(srcsrc));
//	ft_putchar('\n');

//	//test de strchr
//	char *strwithb = "salut bbb c est beau la vie";
//	ft_putstr(ft_strchr(strwithb, (int)('b')));
//	ft_putchar('\n');

//	//test de strrchr
//	char *strwithb = "salut bbb c est beau la vie";
//	(ft_strrchr(strwithb, 0));
//	ft_putchar('\n');
//	//ft_putstr(strrchr(strwithb, 0));
//	ft_putchar('\n');

//	//test de strstr
//	char *s11 = "zarabozaraboze";
//	char *s22 = "ozaraboze";
//	
//	ft_putstr(ft_strstr(s11,s22));
//	ft_putchar('\n');
//	ft_putstr(ft_strstr("salut", ""));


//	//test de strnstr
//	char *saa = "bonjour les amis comment allez vous";
//	char *sbb = "amigos";
//	unsigned long n = 3;
//	ft_putstr(ft_strnstr(saa,sbb, n));
//	ft_putchar('\n');

//	//test de strcmp
//	char *chaine11 = "salut \200";	
//	char *chaine22 = "salut \0";	
//	ft_putnbr(ft_strcmp(chaine11, chaine22));
//	ft_putchar('\n');

//	//test de strncmp
//	char *chaine11 = "abc";	
//	char *chaine22 = "abcdef";	
//	ft_putnbr(ft_strncmp(chaine11, chaine22, 3));
//	ft_putchar('\n');

	//test de atoi
//	ft_putnbr(ft_atoi("-256"));
//	ft_putchar('\n');
//	ft_putnbr(ft_atoi("325"));
//	ft_putchar('\n');
//	ft_putnbr(ft_atoi("0"));
//	ft_putchar('\n');
//	ft_putnbr(ft_atoi("    234"));
//	ft_putchar('\n');

//	//test de ft_strcat
//	char stu[] = "yoman";
//	char stv[] = "arrigato";
//	ft_putstr(ft_strcat(stu, stv));

//	//test de atoi	
//	ft_putnbr(ft_atoi("+2798"));
//	ft_putchar('\n');
//	ft_putchar('X');

//	//test de isalpha
//	ft_putnbr((char)0x100);

//	// test de memccpy
//	char	buf1[] = "Ceci est un test.";
//	char	buf2[200];
//	void	*p1, *p2;
//
//	p1 = memccpy(buf2, buf1, 'i', 10);
//	p2 = ft_memccpy(buf2, buf1, 'i', 10);
//	ft_putstr("P1 : ");
//	ft_putstr(p1);
//	ft_putchar('\n');
//	ft_putstr("P2 : ");
//	ft_putstr(p2);

//	test de memchr
//	ft_putstr(memchr("abcdef", 'c', 5));
//	ft_putchar('\n');
//	ft_putstr(ft_memchr("abcdef", 'c', 5));
	
//	//test de strncpy
//	char c1[] = "00\000000000000000000000";	
//	char c2[] = "salut 111";
//	
////	ft_putstr(strncpy(c1, c2, 2));
//	ft_putstr(ft_strncpy(c1, c2, 20));
//	ft_putchar('\n');
//	ft_putstr(strncpy(c1, c2, 20));
//	ft_putchar('\n');
//	char	buf[6];
//	char	buf2[6];
//
//	memset(buf, 33, 6);
//	ft_strncpy(buf, "abc", 6);
//	ft_putnbr(memcmp(buf, "abc\0\0", 6));
//	ft_putchar('\n');
//	ft_putstr(buf);
//	ft_putchar('\n');
//	memset(buf2, 33, 6);
//	strncpy(buf2, "abc", 6);
//	ft_putnbr(memcmp(buf2, "abc\0\0", 6));
//	ft_putchar('\n');
//	ft_putstr(buf2);

//	//test de strsplit
//	char *str = "salut les loulou";
//	char **tab;
//
//	tab = ft_strsplit(str, ' ');
//	while (*tab != NULL)
//	{
//		ft_putstr(*tab);
//		ft_putchar('\n');
//		tab++;
//	}

	// test de strlcat
//	char s1[] = "abc\0\0\0\0\0\0\0\0\0\0";
//	char s1b[] = "abc\0\0\0\0\0\0\0\0\0\0";
//	char s2[] = "abcdef";
//
//	ft_putnbr(ft_strlcat(s1, s2, 1));
//	ft_putchar('\n');
//	ft_putstr(s1);
//	ft_putchar('\n');
//	ft_putnbr(ft_strcmp(s1, "abcab"));	
//	ft_putchar('\n');
//	ft_putchar('\n');
//	ft_putnbr(strlcat(s1b, s2, 1));
//	ft_putchar('\n');
//	ft_putstr(s1b);
//	ft_putchar('\n');
//	ft_putnbr(strcmp(s1b, "abcab"));	
//	ft_putchar('\n');

//	//test strnstr
//	char	buf2[] = "ozarabozaraboze123";
//
//	ft_putstr(ft_strnstr(buf2, "ozaraboze", 15));

//	//test de strclr
//	char s[] = "salut";
//	ft_strclr(s);
//	ft_putstr(s);
//
//	// test des fcts sur les listes
//	t_list	*lst;
//	char str[] = "salut comment ca va ? ";
//	lst = ft_lstnew(str, ft_strlen(str) + 1); 
//	ft_lstprint(lst);
//	lst = ft_lst_strsplit(str,' ');
//	ft_lstaddend(&lst, ft_lstnew("bien?", ft_strlen("bien?") + 1));
//	ft_lstdelfirst(&lst,ufdel);
//	ft_lstdellast(&lst, ufdel);
//	ft_lstprint(lst);	
	
//	//test de lst fold
	t_list *lst;
	int a = 1 + '0';
	int b = 2 + '0';
	int c = 3 + '0';
	int d = 4 + '0';
	int e = 5 + '0';
//	int f;

	lst = ft_lstnew(&a, sizeof(int)); 
	ft_lstaddend(&lst, ft_lstnew(&b, sizeof(int)));
	ft_lstaddend(&lst, ft_lstnew(&c, sizeof(int)));
	ft_lstaddend(&lst, ft_lstnew(&d, sizeof(int)));
	ft_lstaddend(&lst, ft_lstnew(&e, sizeof(int)));
//	f = ft_lstfold(lst, (void*)ft_sum);	
//	ft_putnbr(f);
	ft_lstprint(lst);
	ft_putchar('\n');
	ft_lstdelcmp(&lst,ufdel, (void*)ft_cmp);	
	ft_lstprint(lst);
	
	
	
	
	
	
	return (0);
}

//il faut que je rajoute des tests dallocation malloc sur les fcts qui lutilisent
