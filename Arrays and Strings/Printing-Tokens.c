    #include <stdio.h>
    #include <string.h>
    #include <math.h>
    #include <stdlib.h>

    int main() {

        char *s;
        int i = 0, spaceLoc = 0, j;
        s = malloc(1024 * sizeof(char));
        scanf("%[^\n]", s);
        s = realloc(s, strlen(s));
        *(s + strlen(s)) = ' ';
        while (i < strlen(s))
        {
            if (*(s + i) == ' ')
            {
                for (j = spaceLoc; j < i; j++)
                    {
                        printf("%c", *(s + j));
                    }
                printf("\n");
                spaceLoc = j + 1;
            }
            i++;
        }    
        
        free(s);
        return 0;
    }
