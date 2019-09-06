const struct State	{
	unsigned long Out; 
	unsigned long Pout; 
	unsigned long Time; 
	unsigned long Next[8]; };
	
typedef const struct State STyp; 	
#define	goS 		0
#define	waitS 		1
#define	goW			2
#define waitW		3
#define pwaitS		4
#define pgoS		5
#define pwaitW		6
#define pgoW		7
#define	phurryS1 	8
#define phurryS2	9
#define phurryS3	10
#define phurryS4	11
#define	phurryW1 	12
#define phurryW2	13
#define phurryW3	14
#define phurryW4	15

STypFSM[16] = {
	{0x21,0x02,3000,{goS,waitS,goS,waitS,pwaitS,pwaitS,pwaitS,pwaitS}},									//0
	{0x22,0x02,300,	{goW,goW,goW,goW,goW,goW,goW,goW}},													//1
	{0x21,0x02,3000,{gow,goW,waitW,waitW,pwaitW,pwaitW,pwaitW,pwaitW}},									//2
	{0x14,0x02,300,	{goS,goS,goS,goS,goS,goS,goS}},														//3
	{0x22,0x02,300,	{pgoS,pgoS,pgoS,pgoS,pgoS,pgoS,pgoS,pgoS}},											//4
	{0x24,0x08,3000,{phurryS1,phurryS1,phurryS1,phurryS1,phurryS1,phurryS1,phurryS1,phurryS1}},			//5
	{0x14,0x02,300,	{pgoW,pgoW,pgoW,pgoW,pgoW,pgoW,pgoW,pgoW}},											//6
	{0x24,0x08,3000,{phurryW1,phurryW1,phurryW1,phurryW1,phurryW1,phurryW1,phurryW1,phurryW1}},			//7
	{0x24,0x00,100,	{phurryS2,phurryS2,phurryS2,phurryS2,phurryS2,phurryS2,phurryS2,phurryS2}},			//8
	{0x24,0x02,100,	{phurryS3,phurryS3,phurryS3,phurryS3,phurryS3,phurryS3,phurryS3,phurryS3}},			//9
	{0x24,0x00,100,	{phurryS4,phurryS4,phurryS4,phurryS4,phurryS4,phurryS4,phurryS4,phurryS4}},			//10
	{0x24,0x02,100,	{goW,goW,goW,goW,goW,goW,goW,goW}},													//11
	{0x24,0x00,100,	{phurryW2,phurryW2,phurryW2,phurryW2,phurryW2,phurryW2,phurryW2,phurryW2}},			//12
	{0x24,0x02,100,	{phurryW3,phurryW3,phurryW3,phurryW3,phurryW3,phurryW3,phurryW3,phurryW3}},			//13
	{0x24,0x00,100,	{phurryW4,phurryW4,phurryW4,phurryW4,phurryW4,phurryW4,phurryW4,phurryW4}},			//14
	{0x24,0x02,100,	{goS,goS,goS,goS,goS,goS,goS}},														//15
	

};