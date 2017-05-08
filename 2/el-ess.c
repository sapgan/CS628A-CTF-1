#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MSTR_(m) #m
#define MSTR(m) MSTR_(m)

int main()
{
	int i;
	char buf[100];
	char inp[16];
	char* ptr = buf;

	strcpy(buf, "/bin/ls ");

	printf("============================================================\n");
	printf("EL-ESS -- a drop-in replacement for ls\n");
	printf("============================================================\n");

	printf("Enter path: ");
	scanf("%16s", inp);

	ptr += strlen(buf);
	for (i = 0; i < sizeof(inp) && inp[i]; ++i) {
		if (inp[i] == '\'' || inp[i] == '"' || inp[i] == '`' || inp[i] == '$'
		    || inp[i] == ';' || inp[i] == '|' || inp[i] == '<' || inp[i] == '>')
			*ptr++ = '\\';
		*ptr++ = inp[i];
	}
	*ptr = '\0';
	strcat(buf, " 2> /dev/null");

	system(buf);
	return 0;
}
