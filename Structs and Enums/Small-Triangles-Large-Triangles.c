#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct triangle
{
	int a;
	int b;
	int c;
};

typedef struct triangle triangle;
void sort_by_area(triangle* tr, int n) 
{
    float p[n], s[n];
    for (int i = 0; i < n; i++)
    {
        p[i] =  (float)(( (float)tr[i].a +  (float)tr[i].b +  (float)tr[i].c)/2);
        s[i] = sqrt(p[i] * (p[i] - (float)tr[i].a) * (p[i] - (float)tr[i].b) * (p[i] - (float)tr[i].c));
    }
    for (int i = 0; i < n - 1; i++)
    {
        triangle *temp = malloc(n * sizeof(triangle));
        float temp2[n];
        for (int j = i + 1; j < n; j++)
        {
            if (s[j] < s[i])
            {    
                temp[i].a = tr[i].a;
                tr[i].a = tr[j].a;
                tr[j].a = temp[i].a;
                
                temp[i].b = tr[i].b;
                tr[i].b = tr[j].b;
                tr[j].b = temp[i].b;
                
                temp[i].c = tr[i].c;
                tr[i].c = tr[j].c;
                tr[j].c = temp[i].c;
                
                temp2[i] = s[i];
                s[i] = s[j];
                s[j] = temp2[i];
            }
        }
    }
}

int main()
{
	int n;
	scanf("%d", &n);
	triangle *tr = malloc(n * sizeof(triangle));
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &tr[i].a, &tr[i].b, &tr[i].c);
	}
	sort_by_area(tr, n);
	for (int i = 0; i < n; i++) {
		printf("%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);
	}
	return 0;
}
