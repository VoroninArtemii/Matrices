#include "library.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
        matrix mat={0,NULL};
        input(&mat);
        output(&mat);
	print(vector(mat));
        freematrix(&mat);
        return 0;
}
