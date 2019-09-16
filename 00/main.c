#include <stdio.h>
#include <stdlib.h>

int get_string_size(char *s)
{
	int index;
	
	index = 0;
	while (s[index] != '\0')
		index++;
	return (index);
}

int	is_upper_case(char c)
{
	int result;

	result = 0;
	if (c >= 'A' && c <= 'Z')
		result = 1;
	return (result);
}

char	to_lower_case(char c)
{
	return (c + 32);
}

char	to_upper_case(char c)
{
	return (c - 32);
}
char    *convert_string(char *s)
{
    char *result;
	int size;

	size = get_string_size(s);
	result = (char *)malloc(sizeof(char)*size + 1);

	if (is_upper_case(s[0]) == 1)
		result[0] = s[0];
	else
		result[0] = to_upper_case(s[0]);

	int i = 1;
	while (s[i] != '\0')
	{
		if (is_upper_case(s[i]) == 1)
			result[i] = to_lower_case(s[i]);
		else
			result[i] = s[i];
		i++;
	}

	result[i] = '\0';

    return (result);
}

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        char *s = argv[1];
        char *result = convert_string(s);
        printf("Before '%s'\n", s);
        printf("After  '%s'\n", result);
    }
    return  (0);
}