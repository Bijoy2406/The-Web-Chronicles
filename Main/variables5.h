#define mysterioWidth 580
#define mysterioHeight 480
int mysterioIcon;
int t25;

int spideyIcon5;
int t15;

//background moving variables and structures
#define bgSpeed5 5
#define n5 5
int bg5[n5];
struct background5
{
	int x5;
	int y5;
};
background5 mainbg5[n5];
bool movebg5 = false;

//____________________mysterio associated variables__________________//

//initial position of mysterio
int msx = 1100;
int msy = -55;

//stand variables for mysterio
int mysterioStand[14];
int mysterioIndex = 0;
bool mysStand = true;
int mysterioStandCounter = 0;

//running right variables for mysterio
int mysterioRun1[6];
int mysterio1index = 0;
bool mysterioRIGHT = false;

//running left variables for mysterio
int mysterioRun2[6];
int mysterio2index = 0;
bool mysterioLEFT = false;

//jump variables for mysterio
bool mysterioJump = false;
bool mysterioJumpUp = false;
bool mysterioJumper = true;
int mysterioCordinateJump = 0;
int mysterioJump1[2];
int mysterioJump2[2];
bool mysterioJumpL = false;
bool mysterioJumpR = false;

//punch variables for mysterio
int mysterioPunch[3];
int mysterioPunchIndex = 0;
bool mysterioPun = false;

//kick variables for mysterio
int mysterioKick[5];
int mysterioKickIndex = 0;
bool mysterioKic = false;

//ult variables for mysterio
int mysterioUlt[8];
int mysterioUltIndex = 0;
bool mysterioUlti = false;
int mysterioUlt2;
int mystImage;
bool mysterioUlti2 = false;

//____________________miles associated variables__________________//

//initial position of miles
int x5 = 15;
int y5 = 35;

//stand variables
int peterStand5[9];
int sindex5 = 0;
bool stand5 = true;
int standCounter5 = 0;

//running right varibales
int peterRun15[5];
int r1index5 = 0;
bool RIGHT5 = false;

//running left variables
int peterRun25[5];
int r2index5 = 0;
bool LEFT5 = false;

//jump variables
bool jump5 = false;
bool jumpUp5 = false;
bool jumper5 = true;
int peterCordinateJump5 = 0;
int peterJump5[2];
int peterJump15[2];
bool jumpL5 = false;
bool jumpR5 = false;

//punch variables
int punch5[8];
int punchIndex5 = 0;
bool pun5 = false;

//kick variables
int kick5[5];
int kickIndex5 = 0;
bool kic5 = false;

//ult
int ult5;
int ultIndex5 = 0;
bool ulti5 = false;

//block
int block5;
int blockIndex5 = 0;
bool bloc5 = false;

//_________________extra______________________//
int imgst;
int ult25[11];
int ultIndex25 = 0;
bool ulti25 = false;

int ult35[9];
int ultIndex35 = 0;
bool ulti35 = false;

//__________________________________________//

int spidermanHealth5 = 1000;
int mysterioHealth = 1000;
int Web5[2];
struct web5
{
	int webX5;
	int webY5;
	int webIndex5;
	bool webShow5;
}webs5[webNumber];

int imgd;
int imge;