#include <stdio.h>
#include <stdlib.h>
#include "library.h"

void getdouble(double *a){
        while(!scanf("%lf",a)){
                printf("Incorrect symbol!\n");
                scanf("%*c");
        }
}

void getint(int *a){
        while(!scanf("%d",a)){
                printf("Incorrect symbol!\n");
                scanf("%*c");
        }
	if (*a<0){
		printf("Negative number!\n");
		getint(a);
	}
}

void input(matrix *mat){
        int n;
        printf("Enter amount of lines:\n");
        getint(&n);
        mat->lines=n;
        mat->pointerline=(line*)calloc(n,sizeof(line));
        for (int i=0;i<n;i++){
                printf("Enter amount of elements in %d string:\n", i);
                int m;
                getint(&m);
                mat->pointerline->number=m;
                mat->pointerline->beginarray=(double*)calloc(m,sizeof(double));
                printf("Enter numbers in %d string:\n", i);
                for (int j=0;j<m;j++){
                        getdouble(mat->pointerline->beginarray);
                        (mat->pointerline->beginarray)++;
                }
                mat->pointerline->beginarray=(mat->pointerline->beginarray)-m;
                (mat->pointerline)++;
        }
        mat->pointerline=(mat->pointerline)-n;
}

void output(matrix *mat){
        int n=mat->lines;
	printf("\nMatrix:\n");
        for (int i=0;i<n;i++){
                int m=mat->pointerline->number;
		printf("String %d: ",i);
                for (int j=0;j<m;j++){
                        printf("%lf ",*(mat->pointerline->beginarray));
                        (mat->pointerline->beginarray)++;
                }
                mat->pointerline->beginarray=(mat->pointerline->beginarray)-m;
                (mat->pointerline)++;
                printf("\n");
        }
	printf("\n");
        mat->pointerline=(mat->pointerline)-n;
}

void freematrix(matrix *mat){
        int n=mat->lines;
        for (int i=0;i<n;i++){
                line *temp=(mat->pointerline)+i;
                free(temp->beginarray);
        }
        free(mat->pointerline);
}

double *sortingarray(line l){
    double *array=copy(l);
    for (int i=0;i<l.number;i++){
        for (int j=0;j<l.number-1;j++){
            if (*(array+j)>*(array+j+1)){
                double temp;
                temp=*(array+j+1);
                *(array+j+1)=*(array+j);
                *(array+j)=temp;
            }
        }
    }
    return array;
}

line *vector(matrix mat){
    int n=mat.lines;
    line *vector=(line*)malloc(sizeof(line));
    vector->number=n;
    vector->beginarray=(double*)malloc(n*sizeof(double));
    for (int i=0;i<n;i++){
        int m=(mat.pointerline+i)->number;
	double *array=sortingarray(*(mat.pointerline+i));
        int answer=1;
        for (int j=0;j<m-1;j++){
            if (*(array+j)<*(array+j+1))
                answer++;
        }
        *(vector->beginarray+i)=answer;
        free(array);
    }
    return vector;
}

void print(line *l){
        printf("Vector:\n");
        for (int i=0;i<l->number;i++)
                printf("Amount of different elements in %d string: %d\n",i,(int)*(l->beginarray+i));
        printf("\n");
	free(l->beginarray);
        free(l);
}

double *copy(line l){
    double *array2=(double*)malloc(l.number*sizeof(double));
    for (int i=0;i<l.number;i++)
        *(array2+i)=*(l.beginarray+i);
    return array2;
}
