#include <stdio.h>
#include <malloc.h>
#include <windows.h>
#include <assert.h>

int linesum(char* line);
char** form_text(char* src);
void sort_by_alphabet(char** src);
void sort_by_sum(char** src);
void print_text(char** src);

int lines_num = 0;

int main()
{
	char* source;
	char** text;
	int length;

	printf("Text length: ");
	scanf_s("%d", &length);
	rewind(stdin);
	
	assert(source = (char*)calloc(length + 2, sizeof(char)));
	fgets(source, length + 1, stdin);

	system("cls");

	text = form_text(source);
	
	sort_by_alphabet(text);

	print_text(text);

	printf("\n");

	sort_by_sum(text);

	print_text(text);

	return 0;
}

int line_sum(char* line)
{
	int sum = 0;
	for (const char* ln = line; *ln != '\0'; )
	{
		unsigned v, n;
		if (sscanf_s(ln, "%u%n", &v, &n) == 1)
			sum += v;
		else
			sscanf_s(ln, "%*s%n", &n);
		ln += n;
	}

	return sum;
}

char** form_text(char* src)
{
	char* symbol;
	char** result;
	int lines = 0, num = 0, line = 0, symb = 0;

	symbol = src;
		while (*symbol != '\0')
	{
		if (*symbol == '.')
			lines++;
		symbol++;
		num++;
	}
	printf("Lines num: %d\n", lines);

	assert(result = (char**)calloc(lines, sizeof(char*)));
	for (int i = 0; i < lines; i++)
		assert(result[i] = (char*)calloc(num, sizeof(char)));

	symbol = src;
	while (*symbol)
	{
		if (*symbol != '.')
		{
			result[line][symb] = *symbol;
			symb++;
		}
		else
		{
			if (*(symbol + 1) == ' ')
				symbol++;
			line++;
			symb = 0;
		}
		symbol++;
	}

	lines_num = lines;
	return result;
}

void sort_by_alphabet(char** src)
{
	char** line = src;
	for (int i = 0; i < lines_num; i++)
		for (int j = i; j < lines_num - 1; j++)
			for (int k = 0; k < 5; k++)
				if (line[j][k] > line[j+1][k])
				{
					char* tmp = line[j];
					line[j] = line[j + 1];
					line[j + 1] = tmp;
					break;
				}
}

void sort_by_sum(char** src)
{
	char** line = src;
	for (int i = 0; i < lines_num; i++)
		for (int j = i;  j < lines_num - 1; j ++)
		{
			if (line_sum(line[j]) > line_sum(line[j+1]))
			{
				char* tmp = line[j];
				line[j] = line[j + 1];
				line[j + 1] = tmp;
			}
		}
}

void print_text(char** src)
{
	char** line = src;
	for (int i = 0; i < lines_num; i++)
		puts(line[i]);
}