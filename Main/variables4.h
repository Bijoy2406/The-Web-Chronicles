#define kravenWidth 580
#define kravenHeight 480

int spideyIcon4;
int t14;


int kravenIcon;
int t24;

//background moving variables and structures
#define bgSpeed4 5
#define n4 5
int bg4[n4];
struct background4
{
	int x4;
	int y4;
};
background4 mainbg4[n4];
bool movebg4 = false;

//____________________kraven associated variables__________________//

//initial position of kraven
int kx = 1100;
int ky = -55;

//stand variables for kraven
int kravenStand[7];
int kravenIndex = 0;
bool kraStand = true;
int kravenStandCounter = 0;

//running right variables for kraven
int kravenRun1[7];
int kraven1index = 0;
bool kravenRIGHT = false;

//running left variables for kraven
int kravenRun2[7];
int kraven2index = 0;
bool kravenLEFT = false;

//jump variables for kraven
bool kravenJump = false;
bool kravenJumpUp = false;
bool kravenJumper = true;
int kravenCordinateJump = 0;
int kravenJump1[2];
int kravenJump2[2];
bool kravenJumpL = false;
bool kravenJumpR = false;

//punch variables for kraven
int kravenPunch[3];
int kravenPunchIndex = 0;
bool kravenPun = false;

//kick variables for kraven
int kravenKick[11];
int kravenKickIndex = 0;
bool kravenKic = false;

//ult variables for kraven
int kravenUlt[10];
int kravenUltIndex = 0;
bool kravenUlti = false;

//____________________miles associated variables__________________//

//initial position of miles
int x4 = 15;
int y4 = 35;

//stand variables
int peterStand4[5];
int sindex4 = 0;
bool stand4 = true;
int standCounter4 = 0;

//running right varibales
int peterRun14[5];
int r1index4 = 0;
bool RIGHT4 = false;

//running left variables
int peterRun24[5];
int r2index4 = 0;
bool LEFT4 = false;

//jump variables
bool jump4 = false;
bool jumpUp4 = false;
bool jumper4 = true;
int peterCordinateJump4 = 0;
int peterJump4[2];
int peterJump14[2];
bool jumpL4 = false;
bool jumpR4 = false;

//punch variables
int punch4[5];
int punchIndex4 = 0;
bool pun4 = false;

//kick variables
int kick4[5];
int kickIndex4 = 0;
bool kic4 = false;

//ult
int ult4;
int ultIndex4 = 0;
bool ulti4 = false;

//block
int block4;
int blockIndex4 = 0;
bool bloc4 = false;

int spidermanHealth4 = 1000;
int kravenHealth = 1000;

//web
int Web4[2];
struct web4
{
	int webX4;
	int webY4;
	int webIndex4;
	bool webShow4;
}webs4[webNumber];
void setWebVariables4();

int imgk, imgl;
int imgm, imgn;
