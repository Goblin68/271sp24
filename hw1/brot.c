#include <stdlib.h>
#include <stdio.h>
#include <complex.h>
 
// rip from https://rosettacode.org/wiki/Bitmap/Write_a_PPM_file#C
// try "convert x.ppm x.png" and follow the install instructions to get a png

// In C, we make a 3 dimension unsigned char array of size * size * 3
// Hint - how many times should loop? How many times should you call malloc?
unsigned char ***create_base(int size)
{
	unsigned char*** array = (unsigned char***)malloc(size * sizeof(unsigned char**));
	if (array == NULL){
		return NULL;
	}

    for (int i = 0; i < size; i++) {
        array[i] = (unsigned char**)malloc(size * sizeof(unsigned char*));
        for (int j = 0; j < size; j++) {
			array[i][j] = (unsigned char*)malloc(size*sizeof(unsigned char*));

			array[i][j][0] = 0;
			array[i][j][1] = 0;
			array[i][j][2] = 0;
        }

    }
	return array;
}


// Calculate z_(n+1) = z_n^2 + c and return the result
// in C, we accept two complex values and produce a complex output
// I've included sample code to work with complex values.
// Hint - don't use exponentiation
double complex m_seq(double complex z_n, double complex c)
{
	//double a = 0, b = 0;
	//double complex r = a + b * I;
	//return r;
	double complex z_n = 0.0 + 0.0 *I;
	double complex c = 1.0 + 1.0 *I
	double complex z_n+1 = z_n*z_n + c *I; //AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA I DONT UNDERSTAND COMPLEX NUMBERS WHY
	return z_n+1;
}

// in C we accept a complex value and an integer size and two integer pointers, and populate the integer points with the x and y results
// I've included sample code to zero out x and y.
void c2b(double complex c, int size, int *x, int *y)
{
	//*x = 0;
	//*y = 0;
	//return;
	int x = (int)((creal(c) + 2) * size / 4);
    int y = (int)((cimag(c) + 2) * size / 4);

	if (x < 0){
		x = 0;		
	}

	else{
		(x >= size ? size - 1 : x);
	}
	if (y < 0){
		y = 0;		
	}

	else{
		(y >= size ? size - 1 : y);
	}
	return (x,y);
}

// in C, we use b2c to loop over all pixels rather than relying on randomization
// return the complex associated with a location x, y
// I've included sample code to work with complex values.
double complex b2c(int size, int x, int y)
{
	//double a = 0, b = 0;
	//double complex r = a + b * I;
	//return r;
	// def b2c(x,y,size):
	//return complex((x * 4.0 / size - 2.0), (y * 4.0 / size - 2.0))
    double real = x * 4.0 / size - 2.0;
    double imag = y * 4.0 / size - 2.0;

    return real + imag * I;
}

// in C we accept a complex value, and integer number of iterations, and returns with an int that represents whether c escapes, or exceeds absolute value 2 in iters applications of m_seq.
// I included the absolute value sample code
//def escapes(c, iters):
	//z_n = c
	//for _ in range(iters):
		//z_n = m_seq(z_n, c)
		//if abs(z_n) > 2:
			//return True
	//return False
int escapes(double complex c, int iters)
{
	double complex z_n = c;
	for( int i  = 0; i < iters; i++){
		z_n = m_seq(z_n, c);
        if (abs(z_n) > 2) {
            return abs(c) > 2;
		}
	}
	return abs(c) > 2;
}

// in C, we accept a 3d array base, an integer for size and for iterations, a color channel of 0,1,2, and a complex value c
void one_val(unsigned char ***base, int size, int iters, int color, double complex c)
{
	return;
}

// in C, we accept a 3d array base, an integer for size and for iterations
void get_colors(unsigned char ***base, int size, int iters)
{
	return;
}

// OPTIONAL
// That said, you images will look bad without this.
// The Python sample had a hacky solution.
// We accept a base, and equalize values to percentiles rather than counts
// You equalized images in CS 151 ImageShop.
void equalize(unsigned char ***base, int size)
{
	return;
}
 
// Given an edge size and starting iteration count, make a buddhabrot.
// I'm leaving the ppm code
void make_brot(int size, int iters)
{

	FILE *fp = fopen("brot.ppm", "wb"); /* b - binary mode */
	fprintf(fp, "P6\n%d %d\n255\n", size, size);
	static unsigned char color[3];

	fflush(stdout);
	for ( int x = 0 ; x < size ; x++ )
	{
		for ( int y = 0 ; y < size ; y++ )
		{
			color[0] = 0;  /* red */
			color[1] = 0;  /* green */
			color[2] = 0;  /* blue */
			fwrite(color, 1, 3, fp);
		}
	}
	fclose(fp);
	return;
}

 
int main()
{
	//make_brot(4000,50);
	return 0;
}
