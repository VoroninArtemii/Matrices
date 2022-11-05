#ifndef __library__
#define __library__

typedef struct line{
	int number;
	double *beginarray;
}line;

typedef struct matrix{
	int lines;
	line *pointerline;
}matrix;

void getint(int*);
void getdouble(double*);
void input(matrix*);
void output(matrix*);
void freematrix(matrix*);
double *sortingarray(line);
line *vector(matrix);
void print(line*);
double *copy(line);

#endif
