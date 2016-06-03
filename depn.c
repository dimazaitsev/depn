#include <stdlib.h>
#include <stdio.h>

#define QTBi 50
#define QTB0 48
#define QPBi 53
#define QPB0 54

#define XB0 2100
//#define YB0
#define XBi 1560
//#define YBi

char * HELP = "Generator of Petri nets which count double exponent 2^2^k\n"
			  "after R.J.Lipton & J.Esparza constructs.\n"
              "Product of Dmitry Zaitsev member.acm.org/~daze\n\n"
              "USAGE: depn k > pn_de_k.ndr\n"
              "  k - exponent (k>0),\n"
              "  output format - .ndr file of Tina www.laas.fr/tina\n\n";

int main( int argc, char * argv[] )
{
 int k,i;
 int poff=0, toff=0, xoff=0, yoff=0;
 
 if( argc < 2 )
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
 
 // print zero block
 
printf("p 580.0 95.0 p14 0 n INC_1 se\n");
printf("t 620.0 95.0 t8 0 w n\n");
printf("p 660.0 95.0 p15 0 n\n");
printf("t 700.0 95.0 t9 0 w n\n");
printf("p 740.0 95.0 p16 0 n\n");
printf("t 780.0 95.0 t10 0 w n\n");
printf("p 820.0 95.0 p17 0 n\n");
printf("t 860.0 95.0 t11 0 w n\n");
printf("p 900.0 95.0 p18 0 n\n");
printf("t 940.0 95.0 t12 c 0 w n {inc-x_1} s\n");
printf("p 980.0 95.0 p19 0 n\n");
printf("t 1020.0 95.0 t13 c 0 w n {inc-y_1} s\n");
printf("p 1140.0 95.0 p21 0 n\n");
printf("t 1180.0 95.0 t15 c 0 w n {call_TST-y_0} s\n");
printf("t 1300.0 95.0 t17 c 0 w n {ret-ZERO-y_0} n\n");
printf("p 1340.0 95.0 p23 0 n\n");
printf("t 1380.0 95.0 t18 c 0 w n {call-TST-x_0} n\n");
printf("t 2020.0 95.0 t20 c 0 w n {ret-ZERO-x_0} n\n");
printf("p 2060.0 95.0 p25 0 n {fin-INC_1} s\n");
printf("t 780.0 335.0 t22 0 w n\n");
printf("p 820.0 335.0 p28 0 n\n");
printf("t 860.0 335.0 t23 0 w n\n");
printf("p 900.0 335.0 p29 0 n\n");
printf("t 940.0 335.0 t24 0 w n\n");
printf("p 820.0 375.0 p31 0 n\n");
printf("t 860.0 375.0 t26 0 w n\n");
printf("p 900.0 375.0 p32 0 n\n");
printf("t 940.0 375.0 t27 0 w n\n");
printf("p 980.0 375.0 p33 0 n\n");
printf("t 1020.0 375.0 t28 0 w n\n");
printf("p 1060.0 375.0 p34 0 n\n");
printf("t 1100.0 375.0 t29 0 w n\n");
printf("p 1140.0 375.0 p35 0 n\n");
printf("t 1140.0 475.0 t30 0 w n\n");
printf("p 660.0 335.0 p26 0 n {TST-y_0} s\n");
printf("t 700.0 335.0 t21 0 w n\n");
printf("p 740.0 335.0 p27 0 n\n");
printf("t 740.0 375.0 t25 0 w n\n");
printf("p 1240.0 375.0 p36 0 n\n");
printf("t 1300.0 375.0 t32 c 0 w n {ret-DEC_0} e\n");
printf("t 1200.0 195.0 t16 c 0 w n {ret-NONZERO-y_0} e\n");
printf("t 1500.0 335.0 t34 0 w n\n");
printf("p 1540.0 335.0 p40 0 n\n");
printf("t 1580.0 335.0 t35 0 w n\n");
printf("p 1620.0 335.0 p41 0 n\n");
printf("t 1660.0 335.0 t36 0 w n\n");
printf("p 1540.0 375.0 p43 0 n\n");
printf("t 1580.0 375.0 t38 0 w n\n");
printf("p 1620.0 375.0 p44 0 n\n");
printf("t 1660.0 375.0 t39 0 w n\n");
printf("p 1700.0 375.0 p45 0 n\n");
printf("t 1740.0 375.0 t40 0 w n\n");
printf("p 1780.0 375.0 p46 0 n\n");
printf("t 1820.0 375.0 t41 0 w n\n");
printf("p 1860.0 375.0 p47 0 n\n");
printf("t 1860.0 475.0 t42 0 w n\n");
printf("t 1900.0 375.0 t43 c 0 w n {call-DEC_0} s\n");
printf("p 1380.0 335.0 p38 0 nw {TST-x_0} s\n");
printf("t 1420.0 335.0 t33 0 w n\n");
printf("p 1460.0 335.0 p39 0 n\n");
printf("t 1460.0 375.0 t37 0 w n\n");
printf("p 1960.0 375.0 p48 0 n\n");
printf("t 2020.0 375.0 t44 c 0 w n {ret-DEC_0} s\n");
printf("p 1220.0 555.0 p50 0 nw DEC_0 s\n");
printf("t 1260.0 555.0 t45 0 w n\n");
printf("p 1300.0 555.0 p51 0 s\n");
printf("t 1340.0 555.0 t46 0 w n\n");
printf("p 1380.0 555.0 p52 0 s\n");
printf("t 1420.0 555.0 t47 0 w n\n");
printf("p 1460.0 555.0 p53 0 s\n");
printf("t 1500.0 555.0 t48 0 w n\n");
printf("p 1540.0 555.0 p54 0 n {fin-DEC_0} s\n");
printf("t 1180.0 375.0 t31 c 0 w n {call-DEC_0} se\n");
printf("p 1740.0 335.0 p42 0 nw {NONZERO-x_0} e\n");
printf("p 2020.0 330.0 p49 0 nw {ZERO-x_0} e\n");
printf("p 1200.0 335.0 p30 0 nw {NONZERO-y_0} e\n");
printf("p 1300.0 335.0 p37 0 nw {ZERO-y_0} e\n");
printf("t 540.0 95.0 t7 0 w n\n");
printf("p 500.0 95.0 p7 0 n {fin-INC_0} s\n");
printf("t 460.0 95.0 t6 0 w n\n");
printf("p 1060.0 95.0 p20 0 n\n");
printf("t 1100.0 95.0 t14 c 0 w n {inc-s'_1} s\n");
printf("p 1240.0 95.0 p22 0 n\n");
printf("p 420.0 95.0 p6 0 n\n");
printf("t 380.0 95.0 t5 0 w n\n");
printf("p 340.0 95.0 p5 0 n\n");
printf("t 300.0 95.0 t4 0 w n\n");
printf("p 260.0 95.0 p4 0 n\n");
printf("t 220.0 95.0 t3 0 w n\n");
printf("t 60.0 95.0 t1 0 w n\n");
printf("p 100.0 95.0 p2 0 n\n");
printf("t 140.0 95.0 t2 0 w n\n");
printf("p 180.0 95.0 p3 0 n\n");
printf("p 20.0 95.0 p1 1 n INC_0 s\n");
printf("p 1260.0 455.0 p12 0 sw s_0 n\n");
printf("p 1500.0 455.0 p13 0 se s'_0 n\n");
printf("p 880.0 35.0 p11 0 e y'_0 n\n");
printf("p 800.0 35.0 p10 0 e y_0 n\n");
printf("p 720.0 35.0 p9 0 e x'_0 n\n");
printf("p 640.0 35.0 p8 0 e x_0 n\n");
printf("t 1740.0 235.0 t19 c 0 w n {ret-NONZERO-x_0} e\n");
printf("p 1740.0 95.0 p24 0 n\n");
printf("e t7 p14 1 n\n");
printf("e p7 t7 1 n\n");
printf("e t6 p7 1 n\n");
printf("e t27 p10 1 n\n");
printf("e p13 t29 1 n\n");
printf("e p13 t41 1 n\n");
printf("e t46 p13 1 n\n");
printf("e t28 p12 1 n\n");
printf("e t40 p12 1 n\n");
printf("e p12 t45 1 n\n");
printf("e p8 t8 1 n\n");
printf("e p10 t10 1 n\n");
printf("e t9 p9 1 n\n");
printf("e t11 p11 1 n\n");
printf("e p54 t44 1 n\n");
printf("e t43 p50 1 n\n");
printf("e p54 t32 1 n\n");
printf("e t31 p50 1 n\n");
printf("e p50 t45 1 n\n");
printf("e t45 p51 1 n\n");
printf("e p51 t46 1 n\n");
printf("e t46 p52 1 n\n");
printf("e p52 t47 1 n\n");
printf("e t47 p53 1 n\n");
printf("e p53 t48 1 n\n");
printf("e t48 p54 1 n\n");
printf("e p12 t47 1 n\n");
printf("e t48 p13 1 n\n");
printf("e p49 t20 1 n\n");
printf("e p42 t19 1 n\n");
printf("e t18 p38 1 n\n");
printf("e p48 t44 1 n\n");
printf("e p38 t33 1 n\n");
printf("e t33 p39 1 n\n");
printf("e p39 t37 1 n\n");
printf("e p39 t34 1 n\n");
printf("e t34 p40 1 n\n");
printf("e p40 t35 1 n\n");
printf("e t35 p41 1 n\n");
printf("e p41 t36 1 n\n");
printf("e t36 p42 1 n\n");
printf("e p8 t35 1 n\n");
printf("e t36 p8 1 n\n");
printf("e t37 p43 1 n\n");
printf("e p43 t38 1 n\n");
printf("e t38 p44 1 n\n");
printf("e p44 t39 1 n\n");
printf("e t39 p45 1 n\n");
printf("e p45 t40 1 n\n");
printf("e t40 p46 1 n\n");
printf("e p9 t38 1 n\n");
printf("e p46 t41 1 n\n");
printf("e t41 p47 1 n\n");
printf("e p47 t42 1 n\n");
printf("e p47 t43 1 n\n");
printf("e t42 0.5000000002 148.0 p43 0.7500000812 100.0 1 n\n");
printf("e t43 p48 1 n\n");
printf("e t44 p49 1 n\n");
printf("e p37 t17 1 n\n");
printf("e p30 t16 1 n\n");
printf("e t15 p26 1 n\n");
printf("e p36 t32 1 n\n");
printf("e p26 t21 1 n\n");
printf("e t21 p27 1 n\n");
printf("e p27 t25 1 n\n");
printf("e p27 t22 1 n\n");
printf("e t22 p28 1 n\n");
printf("e p28 t23 1 n\n");
printf("e t23 p29 1 n\n");
printf("e p29 t24 1 n\n");
printf("e t24 p30 1 n\n");
printf("e p10 t23 1 n\n");
printf("e t24 p10 1 n\n");
printf("e t25 p31 1 n\n");
printf("e p31 t26 1 n\n");
printf("e t26 p32 1 n\n");
printf("e p32 t27 1 n\n");
printf("e t27 p33 1 n\n");
printf("e p33 t28 1 n\n");
printf("e t28 p34 1 n\n");
printf("e p11 t26 1 n\n");
printf("e p34 t29 1 n\n");
printf("e t29 p35 1 n\n");
printf("e p35 t30 1 n\n");
printf("e p35 t31 1 n\n");
printf("e t30 0.5000000002 148.0 p31 0.7500001367 100.0 1 n\n");
printf("e t31 p36 1 n\n");
printf("e t32 p37 1 n\n");
printf("e t19 0.5003120682 510.0009804 p14 0.750000026 139.0 1 n\n");
printf("e p24 t19 1 n\n");
printf("e p24 t20 1 n\n");
printf("e t18 p24 1 n\n");
printf("e t20 p25 1 n\n");
printf("e p23 t18 1 n\n");
printf("e p22 t16 1 n\n");
printf("e t17 p23 1 n\n");
printf("e p22 t17 1 n\n");
printf("e t15 p22 1 n\n");
printf("e p21 t15 1 n\n");
printf("e t11 p18 1 n\n");
printf("e p19 t13 1 n\n");
printf("e t12 p19 1 n\n");
printf("e p18 t12 1 n\n");
printf("e t9 p16 1 n\n");
printf("e p16 t10 1 n\n");
printf("e t10 p17 1 n\n");
printf("e p17 t11 1 n\n");
printf("e p15 t9 1 n\n");
printf("e t8 p15 1 n\n");
printf("e p14 t8 1 n\n");
printf("e t16 0.5013839212 230.0086955 p16 0.7500000662 100.0 1 n\n");
printf("e t39 p8 1 n\n");
printf("e t13 p20 1 n\n");
printf("e p20 t14 1 n\n");
printf("e t14 p21 1 n\n");
printf("e p6 t6 1 n\n");
printf("e t5 p6 1 n\n");
printf("e p5 t5 1 n\n");
printf("e t4 p5 1 n\n");
printf("e p4 t4 1 n\n");
printf("e t3 p4 1 n\n");
printf("e t6 p13 1 n\n");
printf("e t5 p10 1 n\n");
printf("e t4 p8 1 n\n");
printf("e p1 t1 1 n\n");
printf("e t1 p2 1 n\n");
printf("e p2 t2 1 n\n");
printf("e t2 p3 1 n\n");
printf("e p3 t3 1 n\n");
printf("e t3 p13 1 n\n");
printf("e t2 p10 1 n\n");
printf("e t1 p8 1 n\n");

 // end of zero block
 

 
 for(i=1;i<k;i++)
 {
 	toff=(i-1)*QTBi+QTB0+1;
 	poff=(i-1)*QPBi+QPB0;
 	xoff=(i-1)*XBi+XB0;
 	yoff=0;
 	
 	// print i-th block
 	
printf("p %f %f p%d 0 n {INC_%d} se\n", 60.0+xoff, 95.0+yoff, 7+poff, i+1);
printf("t %f %f t%d 0 w n\n", 100.0+xoff, 95.0+yoff, 1+toff );
printf("p %f %f p%d 0 n\n", 140.0+xoff, 95.0+yoff, 8+poff );
printf("t %f %f t%d 0 w n\n", 180.0+xoff, 95.0+yoff, 2+toff);
printf("p %f %f p%d 0 n\n", 220.0+xoff, 95.0+yoff, 9+poff);
printf("t %f %f t%d 0 w n\n", 260.0+xoff, 95.0+yoff, 3+toff);
printf("p %f %f p%d 0 n\n", 300.0+xoff, 95.0+yoff, 10+poff);
printf("t %f %f t%d 0 w n\n", 340.0+xoff, 95.0+yoff, 4+toff);
printf("p %f %f p%d 0 n\n", 380.0+xoff, 95.0+yoff, 11+poff);
printf("t %f %f t%d c 0 w n {inc-x_%d} s\n", 420.0+xoff, 95.0+yoff, 5+toff, i+1 );
printf("p %f %f p%d 0 n\n", 460.0+xoff, 95.0+yoff, 12+poff );
printf("t %f %f t%d c 0 w n {inc-y_%d} s\n", 500.0+xoff, 95.0+yoff, 6+toff, i+1 );
printf("p %f %f p%d 0 n\n", 620.0+xoff, 95.0+yoff, 14+poff );
printf("t %f %f t%d c 0 w n {call-TST-y_%d} s\n", 660.0+xoff, 95.0+yoff, 8+toff, i );
printf("t %f %f t%d c 0 w n {call-TST-x_%d} se\n", 840.0+xoff, 95.0+yoff, 11+toff, i );
printf("t %f %f t%d 0 w n\n", 260.0+xoff, 335.0+yoff, 15+toff );
printf("p %f %f p%d 0 n\n", 300.0+xoff, 335.0+yoff, 21+poff );
printf("t %f %f t%d 0 w n\n", 340.0+xoff, 335.0+yoff, 16+toff );
printf("p %f %f p%d 0 n\n", 380.0+xoff, 335.0+yoff, 22+poff );
printf("t %f %f t%d 0 w n\n", 420.0+xoff, 335.0+yoff, 17+toff );
printf("p %f %f p%d 0 n\n", 300.0+xoff, 375.0+yoff, 24+poff );
printf("t %f %f t%d 0 w n\n", 340.0+xoff, 375.0+yoff, 19+toff );
printf("p %f %f p%d 0 n\n", 380.0+xoff, 375.0+yoff, 25+poff );
printf("t %f %f t%d 0 w n\n", 420.0+xoff, 375.0+yoff, 20+toff );
printf("p %f %f p%d 0 n\n", 460.0+xoff, 375.0+yoff, 26+poff );
printf("t %f %f t%d 0 w n\n", 500.0+xoff, 375.0+yoff, 21+toff );
printf("p %f %f p%d 0 n\n", 540.0+xoff, 375.0+yoff, 27+poff );
printf("t %f %f t%d 0 w n\n", 580.0+xoff, 375.0+yoff, 22+toff );
printf("p %f %f p%d 0 n\n", 620.0+xoff, 375.0+yoff, 28+poff );
printf("t %f %f t%d 0 w n\n", 620.0+xoff, 475.0+yoff, 23+toff );
printf("p %f %f p%d 0 n {TST-y_%d} s\n", 140.0+xoff, 335.0+yoff, 19+poff, i );
printf("t %f %f t%d 0 w n\n", 180.0+xoff, 335.0+yoff, 14+toff );
printf("p %f %f p%d 0 n\n", 220.0+xoff, 335.0+yoff, 20+poff );
printf("t %f %f t%d 0 w n\n", 220.0+xoff, 375.0+yoff, 18+toff );
printf("p %f %f p%d 0 n\n", 720.0+xoff, 375.0+yoff, 29+poff );
printf("t %f %f t%d c 0 w n {ret-NONZERO-y_%d} e\n", 700.0+xoff, 195.0+yoff, 9+toff, i );
printf("t %f %f t%d 0 w n\n", 960.0+xoff, 335.0+yoff, 27+toff );
printf("p %f %f p%d 0 n\n", 1000.0+xoff, 335.0+yoff, 33+poff );
printf("t %f %f t%d 0 w n\n", 1040.0+xoff, 335.0+yoff, 28+toff );
printf("p %f %f p%d 0 n\n", 1080.0+xoff, 335.0+yoff, 34+poff );
printf("t %f %f t%d 0 w n\n", 1120.0+xoff, 335.0+yoff, 29+toff );
printf("p %f %f p%d 0 nw\n", 1000.0+xoff, 375.0+yoff, 36+poff );
printf("t %f %f t%d 0 w n\n", 1040.0+xoff, 375.0+yoff, 31+toff );
printf("p %f %f p%d 0 n\n", 1080.0+xoff, 375.0+yoff, 37+poff );
printf("t %f %f t%d 0 w n\n", 1120.0+xoff, 375.0+yoff, 32+toff );
printf("p %f %f p%d 0 n\n", 1160.0+xoff, 375.0+yoff, 38+poff );
printf("t %f %f t%d 0 w n\n", 1200.0+xoff, 375.0+yoff, 33+toff );
printf("p %f %f p%d 0 n\n", 1240.0+xoff, 375.0+yoff, 39+poff );
printf("t %f %f t%d 0 w n\n", 1280.0+xoff, 375.0+yoff, 34+toff );
printf("p %f %f p%d 0 n\n", 1320.0+xoff, 375.0+yoff, 40+poff );
printf("t %f %f t%d 0 w n\n", 1320.0+xoff, 475.0+yoff, 35+toff );
printf("t %f %f t%d c 0 w n {call-DEC_%d} s\n", 1360.0+xoff, 375.0+yoff, 36+toff, i );
printf("p %f %f p%d 0 ne {TST-x_%d} s\n", 840.0+xoff, 335.0+yoff, 31+poff, i );
printf("t %f %f t%d 0 w n\n", 880.0+xoff, 335.0+yoff, 26+toff );
printf("p %f %f p%d 0 n\n", 920.0+xoff, 335.0+yoff, 32+poff );
printf("t %f %f t%d 0 w n\n", 920.0+xoff, 375.0+yoff, 30+toff );
printf("p %f %f p%d 0 n\n", 1420.0+xoff, 375.0+yoff, 41+poff );
printf("t %f %f t%d c 0 w n {ret-DEC_%d} se\n", 1480.0+xoff, 375.0+yoff, 37+toff, i );
printf("t %f %f t%d c 0 w n {call-DEC_%d} se\n", 660.0+xoff, 375.0+yoff, 24+toff, i );
printf("p %f %f p%d 0 nw DEC_%d sw\n", 540.0+xoff, 575.0+yoff, 43+poff, i );
printf("t %f %f t%d c 0 w n {dec-x_%d} s\n", 580.0+xoff, 575.0+yoff, 38+toff, i-1 );
printf("p %f %f p%d 0 n\n", 620.0+xoff, 575.0+yoff, 44+poff );
printf("t %f %f t%d c 0 w n {inc-x'_%d} s\n", 660.0+xoff, 575.0+yoff, 39+toff, i-1 );
printf("p %f %f p%d 0 n\n", 700.0+xoff, 575.0+yoff, 45+poff );
printf("t %f %f t%d c 0 w n {dec-y_%d} s\n", 740.0+xoff, 575.0+yoff, 40+toff, i-1 );
printf("p %f %f p%d 0 n\n", 780.0+xoff, 575.0+yoff, 46+poff );
printf("t %f %f t%d c 0 w n {inc-y'_%d} s\n", 820.0+xoff, 575.0+yoff, 41+toff, i-1 );
printf("p %f %f p%d 0 n\n", 860.0+xoff, 575.0+yoff, 47+poff );
printf("t %f %f t%d 0 w n\n", 900.0+xoff, 575.0+yoff, 42+toff );
printf("p %f %f p%d 0 n\n", 940.0+xoff, 575.0+yoff, 48+poff );
printf("t %f %f t%d 0 w n\n", 980.0+xoff, 575.0+yoff, 43+toff );
printf("p %f %f p%d 0 n\n", 1020.0+xoff, 575.0+yoff, 49+poff );
printf("t %f %f t%d c 0 w n {call-TST-y_%d} s\n", 1060.0+xoff, 575.0+yoff, 44+toff, i-1 );
printf("p %f %f p%d 0 n\n", 1120.0+xoff, 575.0+yoff, 50+poff );
printf("t %f %f t%d c 0 w n {ret-ZERO-y_%d} s\n", 1180.0+xoff, 575.0+yoff, 46+toff, i-1 );
printf("p %f %f p%d 0 n\n", 1220.0+xoff, 575.0+yoff, 51+poff );
printf("t %f %f t%d c 0 w n {call-TST-x_%d} s\n", 1260.0+xoff, 575.0+yoff, 47+toff, i-1 );
printf("p %f %f p%d 0 n\n", 1320.0+xoff, 575.0+yoff, 52+poff );
printf("t %f %f t%d c 0 w n {ret-ZERO-x_%d} s\n", 1380.0+xoff, 575.0+yoff, 49+toff, i-1 );
printf("p %f %f p%d 0 ne {fin-DEC_%d} se\n", 1420.0+xoff, 575.0+yoff, 53+poff, i );
printf("p %f %f p%d 0 n\n", 540.0+xoff, 95.0+yoff, 13+poff );
printf("t %f %f t%d c 0 w n {inc-s'_%d} s\n", 580.0+xoff, 95.0+yoff, 7+toff, i+1 );
printf("p %f %f p%d 0 n\n", 700.0+xoff, 95.0+yoff, 15+poff );
printf("t %f %f t%d c 0 w n {ret-DEC_%d} s\n", 760.0+xoff, 375.0+yoff, 25+toff, i );
printf("p %f %f p%d 0 nw {NONZERO-x_%d} e\n", 1180.0+xoff, 335.0+yoff, 35+poff, i );
printf("t %f %f t%d c 0 w n {ret-NONZERO-x_%d} e\n", 1180.0+xoff, 235.0+yoff, 12+toff, i );
printf("p %f %f p%d 0 n\n", 1180.0+xoff, 95.0+yoff, 17+poff );
printf("p %f %f p%d 0 nw {ZERO-x_%d} e\n", 1480.0+xoff, 335.0+yoff, 42+poff, i );
printf("t %f %f t%d c 0 w n {ret-ZERO-x_%d} sw\n", 1480.0+xoff, 95.0+yoff, 13+toff, i );
printf("p %f %f p%d 0 n {fin-INC_%d} s\n", 1520.0+xoff, 95.0+yoff, 18+poff, i+1 );
printf("p %f %f p%d 0 nw {ZERO-y_%d} e\n", 760.0+xoff, 335.0+yoff, 30+poff, i );
printf("t %f %f t%d c 0 w n {ret-ZERO-y_%d} n\n", 760.0+xoff, 95.0+yoff, 10+toff, i );
printf("p %f %f p%d 0 n\n", 800.0+xoff, 95.0+yoff, 16+poff );
printf("p %f %f p%d 0 nw {NONZERO-y_%d} e\n", 640.0+xoff, 335.0+yoff, 23+poff, i );
printf("p %f %f p%d 0 sw s_%d n\n", 900.0+xoff, 515.0+yoff, 6+poff, i );
printf("p %f %f p%d 0 se s'_%d n\n", 980.0+xoff, 515.0+yoff, 3+poff, i );
printf("t %f %f t%d c 0 w n {ret-NONZERO-y_%d} s\n", 1120.0+xoff, 675.0+yoff, 45+toff, i-1 );
printf("t %f %f t%d c 0 w n {ret-NONZERO-x_%d} s\n", 1320.0+xoff, 715.0+yoff, 48+toff, i-1 );
printf("p %f %f p%d 0 e y'_%d n\n", 360.0+xoff, 35.0+yoff, 5+poff, i );
printf("p %f %f p%d 0 e y_%d n\n", 280.0+xoff, 35.0+yoff, 2+poff, i );
printf("p %f %f p%d 0 e x_%d n\n", 120.0+xoff, 35.0+yoff, 1+poff, i );
printf("p %f %f p%d 0 e x'_%d n\n", 200.0+xoff, 35.0+yoff, 4+poff, i );
printf("t %f %f t%d 0 w n\n", 20.0+xoff, 95.0+yoff, 0+toff );
printf("e t%d p%d 1 n\n", 0+toff, 7+poff );
printf("e t%d p%d 1 n\n", 32+toff, 1+poff );
printf("e p%d t%d 1 n\n", 42+poff, 13+toff );
printf("e p%d t%d 1 n\n", 35+poff, 12+toff );
printf("e t%d p%d 1 n\n", 11+toff, 31+poff );
printf("e p%d t%d 1 n\n", 41+poff, 37+toff );
printf("e p%d t%d 1 n\n", 31+poff, 26+toff );
printf("e t%d p%d 1 n\n", 26+toff, 32+poff );
printf("e p%d t%d 1 n\n", 32+poff, 30+toff );
printf("e p%d t%d 1 n\n", 32+poff, 27+toff );
printf("e t%d p%d 1 n\n", 27+toff, 33+poff );
printf("e p%d t%d 1 n\n", 33+poff, 28+toff );
printf("e t%d p%d 1 n\n", 28+toff, 34+poff );
printf("e p%d t%d 1 n\n", 34+poff, 29+toff );
printf("e t%d p%d 1 n\n", 29+toff, 35+poff );
printf("e t%d p%d 1 n\n", 30+toff, 36+poff );
printf("e p%d t%d 1 n\n", 36+poff, 31+toff );
printf("e t%d p%d 1 n\n", 31+toff, 37+poff );
printf("e p%d t%d 1 n\n", 37+poff, 32+toff );
printf("e t%d p%d 1 n\n", 32+toff, 38+poff );
printf("e p%d t%d 1 n\n", 38+poff, 33+toff );
printf("e t%d p%d 1 n\n", 33+toff, 39+poff );
printf("e p%d t%d 1 n\n", 39+poff, 34+toff );
printf("e t%d p%d 1 n\n", 34+toff, 40+poff );
printf("e p%d t%d 1 n\n", 40+poff, 35+toff );
printf("e p%d t%d 1 n\n", 40+poff, 36+toff );
printf("e t%d 0.5000000002 148.0 p%d 0.7500001083 100.0 1 n\n", 35+toff, 36+poff );
printf("e t%d p%d 1 n\n", 36+toff, 41+poff );
printf("e t%d p%d 1 n\n", 37+toff, 42+poff );
printf("e p%d t%d 1 n\n", 30+poff, 10+toff );
printf("e p%d t%d 1 n\n", 23+poff, 9+toff );
printf("e t%d p%d 1 n\n", 8+toff, 19+poff );
printf("e p%d t%d 1 n\n", 29+poff, 25+toff );
printf("e p%d t%d 1 n\n", 19+poff, 14+toff );
printf("e t%d p%d 1 n\n", 14+toff, 20+poff );
printf("e p%d t%d 1 n\n", 20+poff, 18+toff );
printf("e p%d t%d 1 n\n", 20+poff, 15+toff );
printf("e t%d p%d 1 n\n", 15+toff, 21+poff );
printf("e p%d t%d 1 n\n", 21+poff, 16+toff );
printf("e t%d p%d 1 n\n", 16+toff, 22+poff );
printf("e p%d t%d 1 n\n", 22+poff, 17+toff );
printf("e t%d p%d 1 n\n", 17+toff, 23+poff );
printf("e t%d p%d 1 n\n", 18+toff, 24+poff );
printf("e p%d t%d 1 n\n", 24+poff, 19+toff );
printf("e t%d p%d 1 n\n", 19+toff, 25+poff );
printf("e p%d t%d 1 n\n", 25+poff, 20+toff );
printf("e t%d p%d 1 n\n", 20+toff, 26+poff );
printf("e p%d t%d 1 n\n", 26+poff, 21+toff );
printf("e t%d p%d 1 n\n", 21+toff, 27+poff );
printf("e p%d t%d 1 n\n", 27+poff, 22+toff );
printf("e t%d p%d 1 n\n", 22+toff, 28+poff );
printf("e p%d t%d 1 n\n", 28+poff, 23+toff );
printf("e p%d t%d 1 n\n", 28+poff, 24+toff );
printf("e t%d 0.5000000002 148.0 p%d 0.7500001049 100.0 1 n\n", 23+toff, 24+poff );
printf("e t%d p%d 1 n\n", 24+toff, 29+poff );
printf("e t%d p%d 1 n\n", 25+toff, 30+poff );
printf("e t%d 0.5003120682 510.0009804 p%d 0.7500000448 139.0 1 n\n", 12+toff, 7+poff );
printf("e p%d t%d 1 n\n", 17+poff, 12+toff );
printf("e p%d t%d 1 n\n", 17+poff, 13+toff );
printf("e t%d p%d 1 n\n", 11+toff, 17+poff );
printf("e t%d p%d 1 n\n", 13+toff, 18+poff );
printf("e p%d t%d 1 n\n", 16+poff, 11+toff );
printf("e p%d t%d 1 n\n", 15+poff, 9+toff );
printf("e t%d p%d 1 n\n", 10+toff, 16+poff );
printf("e p%d t%d 1 n\n", 15+poff, 10+toff );
printf("e t%d p%d 1 n\n", 8+toff, 15+poff );
printf("e p%d t%d 1 n\n", 14+poff, 8+toff );
printf("e t%d p%d 1 n\n", 4+toff, 11+poff );
printf("e p%d t%d 1 n\n", 12+poff, 6+toff );
printf("e t%d p%d 1 n\n", 5+toff, 12+poff );
printf("e p%d t%d 1 n\n", 11+poff, 5+toff );
printf("e t%d p%d 1 n\n", 2+toff, 9+poff );
printf("e p%d t%d 1 n\n", 9+poff, 3+toff );
printf("e t%d p%d 1 n\n", 3+toff, 10+poff );
printf("e p%d t%d 1 n\n", 10+poff, 4+toff );
printf("e p%d t%d 1 n\n", 8+poff, 2+toff );
printf("e t%d p%d 1 n\n", 1+toff, 8+poff );
printf("e p%d t%d 1 n\n", 7+poff, 1+toff );
printf("e t%d 0.5013839212 230.0086955 p%d 0.7500000416 100.0 1 n\n", 9+toff, 9+poff );
printf("e t%d 0.5003120682 510.0009804 p%d 0.7500000072 139.0 1 n\n", 48+toff, 43+poff );
printf("e p%d t%d 1 n\n", 52+poff, 48+toff );
printf("e p%d t%d 1 n\n", 52+poff, 49+toff );
printf("e t%d p%d 1 n\n", 47+toff, 52+poff );
printf("e t%d p%d 1 n\n", 49+toff, 53+poff );
printf("e p%d t%d 1 n\n", 51+poff, 47+toff );
printf("e p%d t%d 1 n\n", 50+poff, 45+toff );
printf("e t%d p%d 1 n\n", 46+toff, 51+poff );
printf("e p%d t%d 1 n\n", 50+poff, 46+toff );
printf("e t%d p%d 1 n\n", 44+toff, 50+poff );
printf("e p%d t%d 1 n\n", 49+poff, 44+toff );
printf("e t%d p%d 1 n\n", 41+toff, 47+poff );
printf("e t%d p%d 1 n\n", 43+toff, 3+poff );
printf("e p%d t%d 1 n\n", 6+poff, 42+toff );
printf("e t%d p%d 1 n\n", 43+toff, 49+poff );
printf("e p%d t%d 1 n\n", 48+poff, 43+toff );
printf("e t%d p%d 1 n\n", 42+toff, 48+poff );
printf("e p%d t%d 1 n\n", 47+poff, 42+toff );
printf("e t%d p%d 1 n\n", 39+toff, 45+poff );
printf("e p%d t%d 1 n\n", 45+poff, 40+toff );
printf("e t%d p%d 1 n\n", 40+toff, 46+poff );
printf("e p%d t%d 1 n\n", 46+poff, 41+toff );
printf("e p%d t%d 1 n\n", 44+poff, 39+toff );
printf("e t%d p%d 1 n\n", 38+toff, 44+poff );
printf("e p%d t%d 1 n\n", 43+poff, 38+toff );
printf("e t%d 0.5013839212 230.0086955 p%d 0.7500000551 100.0 1 n\n", 45+toff, 45+poff );
printf("e t%d p%d 1 n\n", 24+toff, 43+poff );
printf("e p%d t%d 1 n\n", 53+poff, 25+toff );
printf("e t%d p%d 1 n\n", 36+toff, 43+poff );
printf("e p%d t%d 1 n\n", 53+poff, 37+toff );
printf("e p%d t%d 1 n\n", 1+poff, 1+toff );
printf("e p%d t%d 1 n\n", 1+poff, 28+toff );
printf("e t%d p%d 1 n\n", 29+toff, 1+poff );
printf("e t%d p%d 1 n\n", 2+toff, 4+poff );
printf("e p%d t%d 1 n\n", 4+poff, 31+toff );
printf("e t%d p%d 1 n\n", 20+toff, 2+poff );
printf("e p%d t%d 1 n\n", 2+poff, 3+toff );
printf("e p%d t%d 1 n\n", 2+poff, 16+toff );
printf("e t%d p%d 1 n\n", 17+toff, 2+poff );
printf("e t%d p%d 1 n\n", 4+toff, 5+poff );
printf("e p%d t%d 1 n\n", 5+poff, 19+toff );
printf("e t%d p%d 1 n\n", 21+toff, 6+poff );
printf("e t%d p%d 1 n\n", 33+toff, 6+poff );
printf("e p%d t%d 1 n\n", 3+poff, 22+toff );
printf("e p%d t%d 1 n\n", 3+poff, 34+toff );
printf("e t%d p%d 1 n\n", 6+toff, 13+poff );
printf("e p%d t%d 1 n\n", 13+poff, 7+toff );
printf("e t%d p%d 1 n\n", 7+toff, 14+poff );

	// end of i-th block
	
	// connect i-th block to (i-1)-block

	// control
if(i==1)
printf("e p%d t%d 1 n\n", 25, toff );
else
printf("e p%d t%d 1 n\n", (18-QPBi)+poff, toff );

	// connect DEC_i to the previous x_{i-1}, x'_{i-1}, y_{i-1}, y'_{i-1}
	
if(i==1)
{
printf("e p%d t%d 1 n\n", 8, 38+toff );
printf("e t%d p%d 1 n\n", 39+toff, 9 );
printf("e p%d t%d 1 n\n", 10, 40+toff );
printf("e t%d p%d 1 n\n", 41+toff, 11 );
}else
{
printf("e p%d t%d 1 n\n", (1-QPBi)+poff, 38+toff );
printf("e t%d p%d 1 n\n", 39+toff, (4-QPBi)+poff );
printf("e p%d t%d 1 n\n", (2-QPBi)+poff, 40+toff );
printf("e t%d p%d 1 n\n", 41+toff, (5-QPBi)+poff );
}
	
	// call subroutines

if(i==1)
{
	// call subroutine TST-y_0
printf("e t%d p%d 1 n\n", 44+toff, 26);
printf("e p%d t%d 1 n\n", 30, 45+toff );
printf("e p%d t%d 1 n\n", 37, 46+toff );
 	// call subroutine TST-x_0
printf("e t%d p%d 1 n\n", 47+toff, 38 );
printf("e p%d t%d 1 n\n", 42, 48+toff );
printf("e p%d t%d 1 n\n", 49, 49+toff );
}else
{
	// call subroutine TST-y_{i-1}
printf("e t%d p%d 1 n\n", 44+toff, (19-QPBi)+poff );
printf("e p%d t%d 1 n\n", (23-QPBi)+poff, 45+toff );
printf("e p%d t%d 1 n\n", (30-QPBi)+poff, 46+toff );
 	// call subroutine TST-x_{i-1}
printf("e t%d p%d 1 n\n", 47+toff, (31-QPBi)+poff );
printf("e p%d t%d 1 n\n", (35-QPBi)+poff, 48+toff );
printf("e p%d t%d 1 n\n", (42-QPBi)+poff, 49+toff );
}

	// connect x_i, y_i, s'_i to the porevious

if(i==1)
{
	// to INC_0
printf("e t%d p%d 1 n\n", 12, 1+poff);
printf("e t%d p%d 1 n\n", 13, 2+poff);
printf("e t%d p%d 1 n\n", 14, 3+poff);

}else
{
	// to INC_{i-1}
printf("e t%d p%d 1 n\n", (5-QTBi)+toff, 1+poff);
printf("e t%d p%d 1 n\n", (6-QTBi)+toff, 2+poff);
printf("e t%d p%d 1 n\n", (7-QTBi)+toff, 3+poff);

}
	

 	
 } /* for i */
 
 
 	// connect x_k, y_k, s'_k to the porevious
if(k==1)
{
printf("p %f %f p%d 0 e {x_1} n\n", 2120.0+xoff, 35.0+yoff, 55+poff );
printf("p %f %f p%d 0 e {y_1} n\n", 2180.0+xoff, 35.0+yoff, 56+poff );
printf("p %f %f p%d 0 e {s'_1} n\n", 2240.0+xoff, 35.0+yoff, 57+poff );
printf("e t%d p%d 1 n\n", 12+toff, 55+poff);
printf("e t%d p%d 1 n\n", 13+toff, 56+poff);
printf("e t%d p%d 1 n\n", 14+toff, 57+poff);
}else
{
printf("p %f %f p%d 0 e {x_%d} n\n", 1580.0+xoff, 35.0+yoff, 54+poff, k );
printf("p %f %f p%d 0 e {y_%d} n\n", 1640.0+xoff, 35.0+yoff, 55+poff, k );
printf("p %f %f p%d 0 e {s'_%d} n\n", 1700.0+xoff, 35.0+yoff, 56+poff, k );
printf("e t%d p%d 1 n\n", 5+toff, 54+poff);
printf("e t%d p%d 1 n\n", 6+toff, 55+poff);
printf("e t%d p%d 1 n\n", 7+toff, 56+poff);
} 	

 
printf("h depn_%d small\n", k);

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

