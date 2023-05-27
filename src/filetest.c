#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (str != NULL)
	{
		while (str[i])
			i++;
		return (i);
	}
	return (i);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;

	i = 0;
	while (s1[i] && i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char )s1[i] - (unsigned char )s2[i]);
		i++;
	}
	if (s2[i] == '\0' || i == n)
	{
		return (0);
	}
	else
		return (s1[i] - s2[i]);
}

char	*pathname(char *envp[])
{
	int	n;
	int	i;

	n = 0;
	i = 0;
	while (envp[n])
	{
		if ((ft_strncmp("PATH=", envp[n], ft_strlen("PATH="))) == 0)
		{
			return (envp[n]);
		}
		n++;
	}
	return (NULL);
}
