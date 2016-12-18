#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void recognize_request_test(void);

int main(int argc, char const *argv[])
{
	recognize_request_test();
	return 0;
}

int min(int, int);
int
min(int a, int b)
{
	return a > b ? b : a;
}

void
recognize_request_test(void)
{
	char *input = "GET /docs/index.html HTTP/1.1\r\n\
Host: www.nowhere123.com\r\n\
Accept: image/gif, image/jpeg, */*\r\n\
Accept-Language: en-us\r\n\
Accept-Encoding: gzip, deflate\r\n\
User-Agent: Mozilla/4.0 (compatible; MSIE 6.0; Windows NT 5.1)\r\n\r\n\
(blank line)\r\n\
more request stuff";

	// printf("%s\n", input);

	int num_lines = 0;

	int char_location = 0;
	int char_line_start = 0;

	int current_line_is_request = 0;

	int length = strlen(input);
	for (int i = 0; i < length; ++i)
	{
		if (input[i] == 'H' && 
			input[min(length, i + 1)] == 'T' &&
			input[min(length, i + 2)] == 'T' &&
			input[min(length, i + 3)] == 'P')
		{
			current_line_is_request = 1;
		}

		if (input[i] == '\r' && input[min(length, i + 1)] == '\n')
		{
			int current_line_zero_indexed = num_lines;
			int current_line_length = char_location - char_line_start;
			// printf("0-idx line number: %d is length: %d\n", current_line_zero_indexed, current_line_length);

			if (current_line_is_request)
			{
				current_line_is_request = 0;
				printf("HOST LINE: %.*s\n", current_line_length, input + char_line_start);
			}

			num_lines++;
			char_line_start = char_location + 2;
		}
		char_location++;
	}
	printf("0-idx line number: %d is length: %d\n", num_lines, char_location - char_line_start);

	printf("Number of lines is %d\n", num_lines);
}
