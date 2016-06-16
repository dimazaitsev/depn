#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define QTBi 19
#define QPBi 22

#define XBi 490
//#define YBi

char * HELP = "Generator of Petri nets which are strong/exact computers of double exponent 2^2^k\n"
			  "(Based on minimized and modified constructs of R.J.Lipton & J.Esparza)\n"
              "Product of Dmitry Zaitsev member.acm.org/~daze\n\n"
              "USAGE: depnz k [-p] > pnz_de_k.ndr\n"
              "  k  - exponent (k>0),\n"
              "  -p - exact computer obtained adding 4 priority arcs in each block,\n"
              "  output format - .ndr file of Tina www.laas.fr/tina\n\n";

int main( int argc, char * argv[] )
{
 int k,i,tt=0;
 int poff=0, toff=0, xoff=0, yoff=0;
 
 if( argc < 2 || argc > 3 )
 {
   fprintf(stderr,HELP);
   fprintf(stderr, "*** actually: %d arguments\n", argc-1);
   return 2;
 }
 
 k = atoi( argv[1] );
 if( k<1 )
 {
   fprintf(stderr,HELP);
   fprintf(stderr, "*** actually: k=%d\n", k);
   return 3;
 }
 
 if(argc>2)
 {
 	if(strcmp(argv[2], "-p")==0) tt=1;
 	else
 	{
	 	fprintf(stderr,HELP);
   		fprintf(stderr, "*** actually: arg2=%s\n", argv[2]);
   		return 4;
	}
 }
 
  
 for(i=0;i<k;i++)
 {
 	toff=i*QTBi;
 	poff=i*QPBi;
 	xoff=i*XBi;
 	yoff=0;
 	
 	// print common part nodes
 	
	printf("p %f %f p%d 0 n\n", 150.0+xoff, 95.0+yoff, 8+poff );
	printf("p %f %f p%d 0 s y'_%d n\n", 190.0+xoff, 35.0+yoff, 5+poff, i );
	printf("p %f %f p%d 0 nw\n", 270.0+xoff, 95.0+yoff, 9+poff );
	printf("t %f %f t%d c 0 w n {--y_%d, ++y'_%d, ++x_%d, ++y_%d, ++s'_%d, call-TST-y_%d} s\n", 210.0+xoff, 95.0+yoff, 2+toff, i, i, i+1, i+1, i+1, i );
	printf("t %f %f t%d c 0 w n {ret-ZERO-y_%d, call-TST-x_%d} n\n", 330.0+xoff, 95.0+yoff, 4+toff, i, i );
	printf("t %f %f t%d c 0 w n {ret-ZERO-x_%d} s\n", 450.0+xoff, 95.0+yoff, 6+toff, i );
	printf("p %f %f p%d 0 s\n", 390.0+xoff, 95.0+yoff, 10+poff );
	printf("t %f %f t%d c 0 w n {ret-NONZERO-y_%d} e\n", 210.0+xoff, 135.0+yoff, 3+toff, i );
	printf("p %f %f p%d 0 n {TST-z_%d} sw\n", 70.0+xoff, 295.0+yoff, 11+poff, i );
	printf("t %f %f t%d 0 w n\n", 70.0+xoff, 335.0+yoff, 9+toff );
	printf("p %f %f p%d 0 sw s_%d n\n", 270.0+xoff, 455.0+yoff, 6+poff, i );
	printf("p %f %f p%d 0 sw\n", 270.0+xoff, 335.0+yoff, 15+poff );
	printf("t %f %f t%d c 0 w n {call-DEC_%d} s\n", 270.0+xoff, 395.0+yoff, 12+toff, i );
	printf("t %f %f t%d c 0 w n {ret-NONZERO-x_%d} e\n", 210.0+xoff, 175.0+yoff, 5+toff, i );
	printf("t %f %f t%d c 0 w n {--y_%d, ++y'_%d} s\n", 190.0+xoff, 295.0+yoff, 8+toff, i, i );
	printf("t %f %f t%d c 0 w n {--x'_%d, --s'_%d, ++x_%d, ++s_%d} e\n", 330.0+xoff, 295.0+yoff, 10+toff, i, i, i, i );
	printf("t %f %f t%d c 0 w n {--y'_%d, --s'_%d, ++y_%d, ++s_%d} e\n", 390.0+xoff, 335.0+yoff, 11+toff, i, i, i, i );
	printf("p %f %f p%d 0 e zx sw\n", 250.0+xoff, 255.0+yoff, 12+poff );
	printf("p %f %f p%d 0 n {NONZERO-z_%d} se\n", 130.0+xoff, 175.0+yoff, 14+poff, i );
	printf("t %f %f t%d c 0 w n {--x_%d, ++x'_%d} s\n", 130.0+xoff, 255.0+yoff, 7+toff, i, i );
	printf("p %f %f p%d 0 s x'_%d n\n", 110.0+xoff, 35.0+yoff, 4+poff, i );
	printf("t %f %f t%d c 0 w n {--x_%d, ++x'_%d} n\n", 110.0+xoff, 95.0+yoff, 1+toff, i, i );
	printf("p %f %f p%d 0 e zy sw\n", 250.0+xoff, 295.0+yoff, 13+poff );
	printf("p %f %f p%d 0 n {ZERO-z_%d} e\n", 450.0+xoff, 175.0+yoff, 17+poff, i );
	printf("t %f %f t%d c 0 w n {ret-DEC_%d} s\n", 450.0+xoff, 395.0+yoff, 13+toff, i );
	printf("p %f %f p%d 0 s\n", 390.0+xoff, 395.0+yoff, 16+poff );

	if(i==0)
	{
		// marked INC_0=1, x_0=2, y_0=2, s'_0=2
		printf("p %f %f p%d 1 n {INC_%d} s\n", 30.0+xoff, 95.0+yoff, 7+poff, i+1 );
		printf("p %f %f p%d 2 s x_%d n\n", 70.0+xoff, 35.0+yoff, 1+poff, i );
		printf("p %f %f p%d 2 s y_%d n\n", 150.0+xoff, 35.0+yoff, 2+poff, i );
		printf("p %f %f p%d 2 se s'_%d n\n", 310.0+xoff, 455.0+yoff, 3+poff, i );
		
		// print B0 nodes of DEC_0
		printf("p %f %f p%d 0 nw DEC_0 sw\n", 190.0+xoff, 510.0+yoff, 18+poff );
		printf("t %f %f t%d c 0 w n {--s_0, ++s'_0} s\n", 250.0+xoff, 510.0+yoff, 14+toff );
		printf("p %f %f p%d 0 n\n", 290.0+xoff, 510.0+yoff, 19+poff );
		printf("t %f %f t%d c 0 w n {--s_0, ++s'_0} s\n", 330.0+xoff, 510.0+yoff, 15+toff );
		printf("p %f %f p%d 0 ne {fin-DEC_0} se\n", 370.0+xoff, 510.0+yoff, 20+poff );
	}
	else 
	{
		// unmarked INC_i=0, x_i=0, y_i=0, s'_i=0
		printf("p %f %f p%d 0 n {INC_%d} s\n", 30.0+xoff, 95.0+yoff, 7+poff, i+1 );
		printf("p %f %f p%d 0 s x_%d n\n", 70.0+xoff, 35.0+yoff, 1+poff, i );
		printf("p %f %f p%d 0 s y_%d n\n", 150.0+xoff, 35.0+yoff, 2+poff, i );
		printf("p %f %f p%d 0 se s'_%d n\n", 310.0+xoff, 455.0+yoff, 3+poff, i );
		
		// print Bi nodes of DEC_i
		printf("p %f %f p%d 0 nw DEC_%d s\n", 70.0+xoff, 515.0+yoff, 18+poff, i );
		printf("t %f %f t%d c 0 w n {--x_%d, ++x'_%d} n\n", 110.0+xoff, 515.0+yoff, 14+toff, i-1, i-1 );
		printf("p %f %f p%d 0 n\n", 170.0+xoff, 515.0+yoff, 19+poff );
		printf("t %f %f t%d c 0 w n {--y_%d, --s_%d, ++s'_%d, ++y'_%d, call-TST-y_%d} s\n", 230.0+xoff, 515.0+yoff, 15+toff, i-1, i, i, i-1, i-1 );
		printf("p %f %f p%d 0 nw\n", 290.0+xoff, 515.0+yoff, 20+poff );
		printf("t %f %f t%d c 0 w n {ret-NONZERO-y_%d} e\n", 230.0+xoff, 555.0+yoff, 16+toff, i-1 );
		printf("t %f %f t%d c 0 w n {ret-ZERO-y_%d, call-TST-x_%d} n\n", 350.0+xoff, 515.0+yoff, 17+toff, i-1, i-1 );
		printf("p %f %f p%d 0 sw\n", 410.0+xoff, 515.0+yoff, 21+poff );
		printf("t %f %f t%d c 0 w n {ret-NONZERO-x_%d} e\n", 230.0+xoff, 595.0+yoff, 18+toff, i-1 );
		printf("t %f %f t%d c 0 w n {ret-ZERO-x_%d} s\n", 450.0+xoff, 515.0+yoff, 19+toff, i-1 );
		printf("p %f %f p%d 0 n {fin-DEC_%d} se\n", 490.0+xoff, 515.0+yoff, 22+poff, i );
	}

	if(i==k-1)
	{
		// print fin-INC place
		printf("p %f %f p%d 0 n {fin-INC_%d} s\n", 510.0+xoff, 95.0+yoff, 7+poff+QPBi, i+1 );
		
		// print next data places: x_{i+1}, y_{i+1}, s'_{i+1}		
		printf("p %f %f p%d 0 s {x_%d} n\n", 250.0+xoff, 35.0+yoff, 1+poff+QPBi, i+1 );
		printf("p %f %f p%d 0 s {y_%d} n\n", 290.0+xoff, 35.0+yoff, 2+poff+QPBi, i+1 );
		printf("p %f %f p%d 0 s {s'_%d} n\n", 330.0+xoff, 35.0+yoff, 3+poff+QPBi, i+1 );
	}

	// print common arcs
	
	printf("e p%d t%d 1 n\n", 15+poff, 10+toff );
	printf("e t%d p%d 1 n\n", 10+toff, 15+poff );
	printf("e t%d p%d 1 n\n", 4+toff, 11+poff );
	printf("e p%d t%d 1 n\n", 17+poff, 6+toff );
	printf("e p%d t%d 1 n\n", 14+poff, 5+toff );
	printf("e p%d t%d 1 n\n", 12+poff, 6+toff );
	printf("e p%d t%d 1 n\n", 12+poff, 5+toff );
	printf("e t%d p%d 1 n\n", 4+toff, 12+poff );
	printf("e p%d t%d 1 n\n", 13+poff, 4+toff );
	printf("e p%d t%d 1 n\n", 13+poff, 3+toff );
	printf("e t%d p%d 1 n\n", 2+toff, 13+poff );
	printf("e p%d t%d 1 n\n", 3+poff, 10+toff );
	printf("e t%d p%d 1 n\n", 10+toff, 6+poff );
	printf("e p%d t%d 1 n\n", 4+poff, 10+toff );
	printf("e t%d p%d 1 n\n", 10+toff, 1+poff );
	printf("e t%d p%d 1 n\n", 10+toff, 12+poff );
	printf("e p%d t%d 1 n\n", 12+poff, 10+toff );
	printf("e t%d p%d 1 n\n", 11+toff, 13+poff );
	printf("e p%d t%d 1 n\n", 13+poff, 11+toff );
	printf("e t%d p%d 1 n\n", 8+toff, 13+poff );
	printf("e p%d t%d 1 n\n", 13+poff, 8+toff );
	printf("e t%d p%d 1 n\n", 7+toff, 12+poff );
	printf("e p%d t%d 1 n\n", 12+poff, 7+toff );
	printf("e t%d p%d 1 n\n", 7+toff, 14+poff );
	printf("e t%d p%d 1 n\n", 7+toff, 1+poff );
	printf("e p%d t%d 1 n\n", 1+poff, 7+toff );
	printf("e p%d t%d 1 n\n", 11+poff, 7+toff );
	printf("e t%d p%d 1 n\n", 2+toff, 5+poff );
	printf("e t%d p%d 1 n\n", 1+toff, 8+poff );
	printf("e t%d p%d 1 n\n", 1+toff, 4+poff );
	printf("e t%d p%d 1 n\n", 5+toff, 7+poff );
	printf("e t%d p%d 1 n\n", 3+toff, 8+poff );
	printf("e p%d t%d 1 n\n", 2+poff, 2+toff );
	printf("e p%d t%d 1 n\n", 1+poff, 1+toff );
	printf("e p%d t%d 1 n\n", 7+poff, 1+toff );
	printf("e p%d t%d 1 n\n", 8+poff, 2+toff );
	printf("e p%d t%d 1 n\n", 9+poff, 4+toff );
	printf("e p%d t%d 1 n\n", 9+poff, 3+toff );
	printf("e p%d t%d 1 n\n", 10+poff, 6+toff );
	printf("e p%d t%d 1 n\n", 10+poff, 5+toff );
	printf("e t%d p%d 1 n\n", 4+toff, 10+poff );
	printf("e t%d p%d 1 n\n", 2+toff, 9+poff );
	printf("e t%d p%d 1 n\n", 9+toff, 15+poff );
	printf("e p%d t%d 1 n\n", 3+poff, 11+toff );
	printf("e t%d p%d 1 n\n", 11+toff, 6+poff );
	printf("e t%d p%d 1 n\n", 11+toff, 15+poff );
	printf("e p%d t%d 1 n\n", 15+poff, 11+toff );
	printf("e p%d t%d 1 n\n", 16+poff, 13+toff );
	printf("e p%d t%d 1 n\n", 11+poff, 9+toff );
	printf("e p%d t%d 1 n\n", 15+poff, 12+toff );
	printf("e t%d p%d 1 n\n", 12+toff, 16+poff );
	printf("e t%d p%d 1 n\n", 13+toff, 17+poff );
	printf("e p%d t%d 1 n\n", 11+poff, 8+toff );
	printf("e t%d p%d 1 n\n", 8+toff, 14+poff );
	printf("e p%d t%d 1 n\n", 14+poff, 3+toff );
	printf("e p%d t%d 1 n\n", 17+poff, 4+toff );
	printf("e t%d p%d 1 n\n", 2+toff, 11+poff );
	printf("e p%d t%d 1 n\n", 2+poff, 8+toff );
	printf("e t%d p%d 1 n\n", 8+toff, 2+poff );
	printf("e t%d p%d 1 n\n", 11+toff, 2+poff );
	printf("e p%d t%d 1 n\n", 5+poff, 11+toff );

	// exact computer - priority relation tt arcs
	
	if(tt)
	{
		printf("e t%d t%d 1 n\n", 10+toff, 12+toff );
		printf("e t%d t%d 1 n\n", 7+toff, 9+toff );
		printf("e t%d t%d 1 n\n", 11+toff, 12+toff );
		printf("e t%d t%d 1 n\n", 8+toff, 9+toff );
	}
	
	if(i==0)
	{
		// print B0 arcs of DEC_0
		printf("e p%d t%d 1 n\n", 18+poff, 14+toff );
		printf("e t%d p%d 1 n\n", 12+toff, 18+poff );
		printf("e t%d p%d 1 n\n", 14+toff, 3+poff );
		printf("e p%d t%d 1 n\n", 6+poff, 14+toff );
		printf("e t%d p%d 1 n\n", 14+toff, 19+poff );
		printf("e p%d t%d 1 n\n", 19+poff, 15+toff );
		printf("e t%d p%d 1 n\n", 15+toff, 3+poff );
		printf("e p%d t%d 1 n\n", 6+poff, 15+toff );
		printf("e t%d p%d 1 n\n", 15+toff, 20+poff );
		printf("e p%d t%d 1 n\n", 20+poff, 13+toff );	
	}
	else 
	{
		// print Bi arcs of DEC_i
		printf("e p%d t%d 1 n\n", 18+poff, 14+toff );
		printf("e t%d p%d 1 n\n", 18+toff, 18+poff );
		printf("e t%d p%d 1 n\n", 12+toff, 18+poff );
		printf("e t%d p%d 1 n\n", 14+toff, 19+poff );
		printf("e p%d t%d 1 n\n", 19+poff, 15+toff );
		printf("e t%d p%d 1 n\n", 16+toff, 19+poff );
		printf("e t%d p%d 1 n\n", 15+toff, 20+poff );
		printf("e p%d t%d 1 n\n", 6+poff, 15+toff );
		printf("e t%d p%d 1 n\n", 15+toff, 3+poff );
		printf("e p%d t%d 1 n\n", 20+poff, 16+toff );
		printf("e p%d t%d 1 n\n", 20+poff, 17+toff );
		printf("e t%d p%d 1 n\n", 17+toff, 21+poff );
		printf("e p%d t%d 1 n\n", 21+poff, 18+toff );
		printf("e p%d t%d 1 n\n", 21+poff, 19+toff );
		printf("e t%d p%d 1 n\n", 19+toff, 22+poff );
		printf("e p%d t%d 1 n\n", 22+poff, 13+toff );	
	}	
	
		
	if(i==k-1)
	{
		// print arc to fin-INC
		printf("e t%d p%d 1 n\n", 6+toff, 7+poff+QPBi );
		
		// print arcs to next data places: x_{i+1}, y_{i+1}, s'_{i+1}		
		printf("e t%d p%d 1 n\n", 2+toff, 1+poff+QPBi );
		printf("e t%d p%d 1 n\n", 2+toff, 2+poff+QPBi );
		printf("e t%d p%d 1 n\n", 2+toff, 3+poff+QPBi );
	}
	
	
	if(i>0)
	{
		// connect with the previous block
		
		// control
		printf("e t%d p%d 1 n\n", 6+toff-QTBi, 7+poff );
		
		// data: ++x_i, ++y_i, ++s'_i	
		printf("e t%d p%d 1 n\n", 2+toff-QTBi, 1+poff );
		printf("e t%d p%d 1 n\n", 2+toff-QTBi, 2+poff );
		printf("e t%d p%d 1 n\n", 2+toff-QTBi, 3+poff );
		
		// data for TST-z_{i-1} calls: --x_{i-1}, ++x'_{i-1}; --y_{i-1}, ++y'_{i-1}		
		printf("e p%d t%d 1 n\n", 1+poff-QPBi, 14+toff );
		printf("e t%d p%d 1 n\n", 14+toff, 4+poff-QPBi );		
		printf("e p%d t%d 1 n\n", 2+poff-QPBi, 15+toff );
		printf("e t%d p%d 1 n\n", 15+toff, 5+poff-QPBi );
		
		// calls/returns for TST-z_{i-1}: TST-y and TST-x	
		printf("e t%d p%d 1 n\n", 15+toff, 11+poff-QPBi );
		printf("e t%d p%d 1 n\n", 15+toff, 13+poff-QPBi );
		printf("e p%d t%d 1 n\n", 14+poff-QPBi, 16+toff );
		printf("e p%d t%d 1 n\n", 13+poff-QPBi, 16+toff );
		printf("e p%d t%d 1 n\n", 17+poff-QPBi, 17+toff );
		printf("e p%d t%d 1 n\n", 13+poff-QPBi, 17+toff );
		printf("e t%d p%d 1 n\n", 17+toff, 11+poff-QPBi );
		printf("e t%d p%d 1 n\n", 17+toff, 12+poff-QPBi );
		printf("e p%d t%d 1 n\n", 14+poff-QPBi, 18+toff );
		printf("e p%d t%d 1 n\n", 12+poff-QPBi, 18+toff );
		printf("e p%d t%d 1 n\n", 17+poff-QPBi, 19+toff );
		printf("e p%d t%d 1 n\n", 12+poff-QPBi, 19+toff );		
	}
	
 } /* for i */
 
	
 // end of .ndr file - print net name
 	
 printf("h depnz_%d%c small\n", k, (tt)?'p':' ');

} /* main */

/*
The MIT License (MIT)

Copyright (c) 2015 Dmitry Zaitsev

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*/

