// Isaac Neibaur Quiz 1 7/24/2019

// Code for random string genartion was mofidied from code found on
//https://www.codeproject.com/Questions/640193/Random-string-in-language-C
//
//    static const char alphanum[] =     "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
//
//    for (int i = 0; i < len; ++i) {
//        s[i] = alphanum[rand() % (sizeof(alphanum) - 1)];
//    }
//    s[len] = 0;

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

char inputChar()
{
    // TODO: rewrite this function
    char c;
    static const char charset[] = "[({ ax})]";

    c = charset[rand() % (sizeof(charset) - 1)];
    
    return c;
}

char *inputString()
{
    // TODO: rewrite this function
    char *s;
    int len = 5;
    static const char stringset[] =     "rest";

    for (int i = 0; i < len; ++i) {
        s[i] = stringset[rand() % (sizeof(stringset) - 1)];
    }

    s[len] = 0;
    
    return s;
}

void testme()
{
  int tcCount = 0;
  char *s;
  char c;
  int state = 0;
    
  while (1)
  {
    tcCount++;
    c = inputChar();
    s = inputString();
    printf("Iteration %d: c = %c, s = %s, state = %d\n", tcCount, c, s, state);

    if (c == '[' && state == 0) state = 1;
    if (c == '(' && state == 1) state = 2;
    if (c == '{' && state == 2) state = 3;
    if (c == ' '&& state == 3) state = 4;
    if (c == 'a' && state == 4) state = 5;
    if (c == 'x' && state == 5) state = 6;
    if (c == '}' && state == 6) state = 7;
    if (c == ')' && state == 7) state = 8;
    if (c == ']' && state == 8) state = 9;
    if (s[0] == 'r' && s[1] == 'e'
       && s[2] == 's' && s[3] == 'e'
       && s[4] == 't' && s[5] == '\0'
       && state == 9)
    {
      printf("error ");    
        exit(200);
    }
  }
}


int main(int argc, char *argv[])
{
    srand(time(NULL));
    testme();
    return 0;
}
