#include <stdio.h>
#include <stdlib.h>

int get_string_size(char *s)
{
	int index = 0;
	
	while (s[index] != '\0')
		index++;
	
	return (index);
}

char	to_lower_case(char c)
{
	char lower_result = c;
	
	if (c >= 'A' && c <= 'Z')
	{
		lower_result = c + 32;
	}
	
	return (lower_result);
}

char	to_upper_case(char c)
{
	char upper_result = c;

	if (c >= 'a' && c <= 'z')
	{
		upper_result = c - 32;
	}
	
	return (upper_result);
}

int	get_index_first_letter(char *word)
{
	int index = 0;

	while (word[index])
	{
		if (word[index] != ' ')
			break;
		index++;
	}
	
	return (index);
}

char	*to_camel_case(char *word, int index_first_letter, int size)
{
	char	*converted = (char *)malloc(sizeof(char)*size + 1);
	int i = 0;

	while (word[i])
	{
		if (i == index_first_letter)
			converted[i] = to_upper_case(word[i]);
		else
			converted[i] = to_lower_case(word[i]);
		i++;
	}
	
	return (converted);
}

char    *convert_string(char *s)
{
	int size = get_string_size(s);
	int index = get_index_first_letter(s);
	char *converted_string = to_camel_case(s, index, size);

    return (converted_string);
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