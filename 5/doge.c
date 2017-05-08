#include <stdio.h>

void print_doge()
{
	printf("                   ▄              ▄\n");
	printf("                  ▌▒█           ▄▀▒▌\n");
	printf("                  ▌▒▒█        ▄▀▒▒▒▐\n");
	printf("                 ▐▄▀▒▒▀▀▀▀▄▄▄▀▒▒▒▒▒▐\n");
	printf("               ▄▄▀▒░▒▒▒▒▒▒▒▒▒█▒▒▄█▒▐\n");
	printf("             ▄▀▒▒▒░░░▒▒▒░░░▒▒▒▀██▀▒▌\n");
	printf("            ▐▒▒▒▄▄▒▒▒▒░░░▒▒▒▒▒▒▒▀▄▒▒▌\n");
	printf("            ▌░░▌█▀▒▒▒▒▒▄▀█▄▒▒▒▒▒▒▒█▒▐\n");
	printf("           ▐░░░▒▒▒▒▒▒▒▒▌██▀▒▒░░░▒▒▒▀▄▌\n");
	printf("           ▌░▒▄██▄▒▒▒▒▒▒▒▒▒░░░░░░▒▒▒▒▌\n");
	printf("          ▌▒▀▐▄█▄█▌▄░▀▒▒░░░░░░░░░░▒▒▒▐\n");
	printf("          ▐▒▒▐▀▐▀▒░▄▄▒▄▒▒▒▒▒▒░▒░▒░▒▒▒▒▌\n");
	printf("          ▐▒▒▒▀▀▄▄▒▒▒▄▒▒▒▒▒▒▒▒░▒░▒░▒▒▐\n");
	printf("           ▌▒▒▒▒▒▒▀▀▀▒▒▒▒▒▒░▒░▒░▒░▒▒▒▌\n");
	printf("           ▐▒▒▒▒▒▒▒▒▒▒▒▒▒▒░▒░▒░▒▒▄▒▒▐\n");
	printf("            ▀▄▒▒▒▒▒▒▒▒▒▒▒░▒░▒░▒▄▒▒▒▒▌\n");
	printf("              ▀▄▒▒▒▒▒▒▒▒▒▒▄▄▄▀▒▒▒▒▄▀\n");
	printf("                ▀▄▄▄▄▄▄▀▀▀▒▒▒▒▒▄▄▀\n");
	printf("\n         D O G E   M E S S E N G E R");
	printf("\n         Send your message to doge!!");
}

void hello_doge()
{
	int num;
	char* ptr;
#define SIZE 256
	char buf[SIZE];

	printf("\nHow many messages do you want to send? ");
	scanf("%d", &num);
	if (num > 10) {
		printf("\nDoge has other things to do as well.");
		return;
	}

	char c = getchar();
	if (!isspace(c))
		ungetc(c, stdin);

	while (num-- > 0) {
		printf("\nYour message: ");
		fgets(buf, SIZE, stdin);

		for (int i = 0; i < strlen(buf); ++i)
			if (isalpha(buf[i])) {
				if (isupper(buf[i]))
					buf[i] = tolower(buf[i]);
				else buf[i] = toupper(buf[i]);
			}

		printf("\nDoge's response: ");
		printf(buf);
	}
}

int main()
{
	setbuf(stdout, NULL);
	print_doge();

	char name[36];
	fputs("\n\nYour name: ", stdout);
	fgets(name, sizeof(name), stdin);
	hello_doge();
	return 0;
}
