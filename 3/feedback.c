#include <stdio.h>

void getName() {
    char name[100];
    printf("Enter your name here: ");
    scanf("%s",name);
    printf("Welcome to Feedback Submission Portal ");
    printf(name);
    putchar('\n');
}

void submitFeedback() {
    char feedback[528];
    printf("Enter your feedback here: ");
    read(0,feedback,582);
    printf("Thank You\n");
}

int main() {
    setbuf(stdout, NULL);
    getName();
    submitFeedback();
    return 0;
}