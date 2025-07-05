#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char keywords[32][10] = {
    "auto", "break", "case", "char", "const", "continue", "default", "do",
    "double", "else", "enum", "extern", "float", "for", "goto", "if",
    "int", "long", "register", "return", "short", "signed", "sizeof",
    "static", "struct", "switch", "typedef", "union", "unsigned", "void",
    "volatile", "while"
};

int isKeyword(char *word) {
    for(int i = 0; i < 32; i++) {
        if(strcmp(keywords[i], word) == 0)
            return 1;
    }
    return 0;
}

int isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' ||
           ch == '=' || ch == '<' || ch == '>' || ch == '!';
}

void lexicalAnalyzer(FILE *fp) {
    char ch, buffer[100];
    int i = 0;

    while((ch = fgetc(fp)) != EOF) {
        if(isalpha(ch)) {
            buffer[i++] = ch;
            while(isalnum(ch = fgetc(fp)) || ch == '_') {
                buffer[i++] = ch;
            }
            buffer[i] = '\0';
            i = 0;
            ungetc(ch, fp);
            if(isKeyword(buffer))
                printf("[Keyword]    %s\n", buffer);
            else
                printf("[Identifier] %s\n", buffer);
        }
        else if(isOperator(ch)) {
            printf("[Operator]   %c\n", ch);
        }
    }
}

int main() {
    FILE *fp = fopen("input.c", "r");
    if(fp == NULL) {
        printf("Could not open input file.\n");
        return 1;
    }

    printf("Lexical Analysis Output:\n\n");
    lexicalAnalyzer(fp);

    fclose(fp);
    return 0;
}

