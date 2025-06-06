#ifdef __cplusplus
 extern "C" {
#endif
 
typedef int TYPE;

#include <stdio.h>
#include <stdlib.h>

#define PLANE(A) {int i,j; for(i=1;i<=nrow;i++) for(j=1;j<=ncol;j++) {A};}

/* int rand();							*/
/* void srand();						*/
/* #define RANDOM()	(rand()*(1.0/(RAND_MAX+1.0)))		*/
/* #define SEED(A)		(srand((unsigned int)A))	*/

#define OpenGraphics(a,b)	OpenDisplay(a,b)
#define DisplayAt(a,b,c,d)	PlaneDisplay(a,c,b,d)
#define DisplayPlane(a,b,c,d)	PlaneDisplay(a,c,b,d)
#define DisplayRow(a,b,c,d)	RowDisplay(a,c,b,d)
#define DisplayBlock(a,b,c,d,e,f)	BlockDisplay(a,b,c,e,d,f)
#define FastDisplayBlock(a,b,c,d,e)	BlockDisplayFast(a,b,c,e,d)
#define CloseGraphics()		CloseDisplay()

#define OpenPS(a,b,c)		OpenPostscript(a,b,c)
#define PlanePS(a,b,c,d)	PlanePostscript(a,c,b,d)
#define DumpPS(a,b,c,d)		PlanePostscript(a,c,b,d)
#define BlockPS(a,b,c,d,e,f)	BlockPostscript(a,b,c,e,d,f)
#define RowPS(a,b,c,d)		RowPostscript(a,c,b,d)
#define TextPS(a,b,c)		TextPostscript(a,c,b)
#define PagePS()		PagePostscript()
#define ClosePS()		ClosePostscript()

#define LoadMV(a)		PlayMovie(a)
#define CloseMV()		CloseMovie()

#define RANDOM()	uniform()
#define SEED(A)		set_seed(A)

#define WRAP	0
#define	FIXED	1
#define	ECHO	2

#define BLACK	0
#define WHITE	1
#define RED	2
#define GREEN	3
#define	BLUE	4
#define YELLOW	5
#define MAGENTA 6
#define GRAY	7
#define GREY	7

#define CENTRAL	0
#define	NORTH	1
#define	WEST	2
#define	EAST	3
#define	SOUTH	4
#define	NORTHWEST	5
#define	NORTHEAST	6
#define	SOUTHWEST	7
#define	SOUTHEAST	8

/***********************************************basic*/
/*int InDat(char*,char*,int*);*/
int InDat(char*,char*,void*);
int FullInDat(FILE*,char*,char*,void*,int);
   /*int FullInDat(FILE*,char*,char*,int*,int);*/
int ReadOptions(char*);
TYPE **NewP();
TYPE **New();
int PlaneFree(TYPE**);
TYPE **Fill(TYPE**, TYPE);
long Total(TYPE**);
int Equal(TYPE**,TYPE**);
int Max(TYPE**);
int Min(TYPE**);
int **Explode(TYPE**,TYPE**);
TYPE **Copy(TYPE**,TYPE**);
TYPE *CopyRow(TYPE*,TYPE*);
TYPE **Diffusion(TYPE**,TYPE**,float);
TYPE **Motion(TYPE**,TYPE**,float,int);

/**************************************************io*/
int iPrint(FILE*,char*,TYPE**);
int cPrint(FILE*,TYPE**);
int bPrint(FILE*,TYPE**);
TYPE **ReadPat(TYPE**,int,int,char*);
TYPE **Init(TYPE**);

/******************************************arithmetic*/
TYPE **Sum(TYPE**, TYPE**, TYPE**);
TYPE **SumV(TYPE**, TYPE**, TYPE);
TYPE **Minus(TYPE**, TYPE**, TYPE**);
TYPE **MinusV(TYPE**, TYPE**, TYPE);
TYPE **Div(TYPE**, TYPE**, TYPE**);
TYPE **DivV(TYPE**,TYPE**,TYPE);
TYPE **Mod(TYPE**, TYPE**, TYPE**);
TYPE **ModV(TYPE**, TYPE**, TYPE);
TYPE **Mult(TYPE**, TYPE**, TYPE**);
TYPE **MultV(TYPE**, TYPE**, TYPE);
TYPE **MultF(TYPE**,TYPE**,float);
TYPE **BinSumOld(TYPE**,TYPE***,int); 
TYPE **BinSum(TYPE**,int, ...);
TYPE **RollRight(TYPE**,TYPE**,int);
TYPE **RollLeft(TYPE**,TYPE**,int);
TYPE **GetBits(TYPE**,TYPE**,int,int);
TYPE **PutBits(TYPE**,int,int);
TYPE **Hamming(TYPE**, TYPE**, TYPE**);

/***********************************************color*/
int ColorTable(int,int, ...);
int ColorRamp(int,int,int);
int ColorWheel(int,int);
int ColorRandom(int,int);
int ColorRGB(int,int,int,int);
int ColorDump(char*);
int ColorRead(char*);

/*********************************************logical*/
TYPE **And(TYPE**,TYPE**,TYPE**);
TYPE **AndNot(TYPE**,TYPE**,TYPE**);
TYPE **Or(TYPE**,TYPE**,TYPE**);
TYPE **Xor(TYPE**,TYPE**,TYPE**);
TYPE **Not(TYPE**,TYPE**);
TYPE **AndCopy(TYPE**,TYPE**,TYPE**);

/**********************************************filter*/
TYPE **EQ(TYPE**,TYPE**,TYPE);
TYPE **NE(TYPE**,TYPE**,TYPE);
TYPE **GE(TYPE**,TYPE**,TYPE);
TYPE **LE(TYPE**,TYPE**,TYPE);
TYPE **GT(TYPE**,TYPE**,TYPE);
TYPE **LT(TYPE**,TYPE**,TYPE);
TYPE **IN(TYPE**,TYPE**,int,int);

/***********************************************shift*/
TYPE **Boundaries(TYPE**);
TYPE **North(TYPE**,TYPE**);
TYPE **South(TYPE**,TYPE**);
TYPE **West(TYPE**,TYPE**);
TYPE **East(TYPE**,TYPE**);

/***********************************************noise*/
TYPE **Stir(TYPE**,TYPE**,TYPE**,TYPE**);
int RanIndex();
TYPE **NoiseBox(TYPE**);
int InitRandom();
TYPE **Random(TYPE**,float);
TYPE **Normalize(TYPE**,TYPE**);
TYPE **Shake(TYPE**,TYPE**);

/*******************************************neighbors*/
int InitNeigh();
TYPE ***Neighbors(TYPE***,TYPE**);
TYPE **Moore8(TYPE**,TYPE**);
TYPE **Moore9(TYPE**,TYPE**);
TYPE **VonNeumann4(TYPE**,TYPE**);
TYPE **VonNeumann5(TYPE**,TYPE**);
TYPE **Diagonal4(TYPE**,TYPE**);
TYPE **Diagonal5(TYPE**,TYPE**);
TYPE **RandomNeighbor(TYPE**,TYPE**);

/********************************************margolus*/
TYPE **Margolus(TYPE**,TYPE**,TYPE **(*)(),int);
void InitMargolus();
TYPE **Partition(TYPE**,int);
TYPE **Unpartition(TYPE**,int);

/*************************************************png*/
int OpenPNG(char*,int,int);
int PlanePNG(TYPE**,int);
int BlockPNG(unsigned char*,int,int,int);
int ClosePNG();

/***********************************************movie*/
int OpenMovie(char*,int,int);
int LoadMovie(char*,int*,int*);
int CloseMovie();
int PlaneMovie(TYPE**,int,int,TYPE);
int RowMovie(TYPE*,int,int,TYPE);
int BlockMovie(unsigned char*,int,int,int,int,int);
int writepairs(int,int,int,int,long);
int PlayMovie(int);
TYPE **MoviePlane(TYPE**);

/**************************************************ps*/
int PagePostscript();
int ClosePostscript();
int OpenPostscript(char*,int,int);
int TextPostscript(char*,int,int);
int psrect(int,int,int,int,int,int);
int PlanePostscript(TYPE**, int, int, int);
int RowPostscript(TYPE*, int, int, int);
int BlockPostscript(unsigned char*,int,int,int,int,int);

/**********************************************random*/
double uniform();
double ran2();
double gasdev();
int boolean();
double normal(double,double);
int set_seed(int);

/*************************************************x11*/
int Beep(int);
int Mouse();
int Erase();
int CloseDisplay();
void MakeColorMap();
int OpenDisplay(char*,int,int);
int PlaneDisplay(TYPE**,int,int,TYPE);
int RowDisplay(int*,int,int,TYPE);
int BlockDisplay(unsigned char*,int,int,int,int,int);
int BlockDisplayFast(unsigned char*,int,int,int,int);

#ifdef __cplusplus
 }
#endif

