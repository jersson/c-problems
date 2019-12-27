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


int	*get_words_index(char *words, int size)
{
	int *words_index =  (int *)malloc(sizeof(int)*size*2 + 1);
	int i = 0;
    int j = 0;

    if (words[i] != ' ')
    {
        words_index[j] = i;
        j++;
        i++;
    }

    while (words[i])
    {
        if (words[i - 1] == ' ' && words[i] != ' ')
        {
            words_index[j] = i;
            j++;
        }
        i++;
    }
	words_index[j] = '\0';

	return (words_index);
}

char	*to_camel_case(char *words, int *words_index, int size)
{
	char *converted = (char *)malloc(sizeof(char)*size + 1);
	int i = 0;
    int j = 0;

	while (words[i])
	{
		if (i == words_index[j])
		{
			converted[i] = to_upper_case(words[i]);
			j++; 
		}
		else
		{
			converted[i] = to_lower_case(words[i]);
		}
		
		i++;
	}	

    return (converted);
}


char    *convert_string(char *original)
{
	int size = get_string_size(original);
    int *words_index =  get_words_index(original, size);
	char *converted = to_camel_case(original, words_index, size);

	free(words_index);

    return (converted);
}

int main(int argc, char **argv)
{
    if (argc >= 2)
    {
		for (int i = 1; i < argc; ++i) {
			printf("Parameter Nro '%d' \n", i);
			char *s = argv[i];
			char *result = convert_string(s);
			printf("Before '%s'\n", s);
			printf("After  '%s'\n", result);
			printf("*************************** \n");
		}
    }
    return  (0);
}
