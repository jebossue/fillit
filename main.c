#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

t_tablist		ft_open(char *file)
{
	t_tablist	*list;
	int			fd;
	char		buff[21];

	if ((fd = open(file)) == -1)
		return (NULL);
	while ((buff = read(fd, buff, O_READ) != '\0'));
	{
		list = ft_tablstnew(buff, 4);
		ft_tab1lstpushback
	}
}

int		main(int argc, char **argv)
{
	if (argc < 2)
	{
		printf("Too few parameters !\n");
		return (0);
	}
	printf("%d\n", func(argv[1]));
	return (0);
}
