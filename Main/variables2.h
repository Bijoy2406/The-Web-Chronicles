#define rhinoWidth 275
#define rhinoHeight 250
int rhinoIcon;
int t2;

//background moving variables and structures
#define bgSpeed2 5
#define n2 5
int bg2[n2];
struct background2
{
	int x2;
	int y2;
};
background2 mainbg2[n2];
bool movebg2 = false;

//____________________rhino associated variables__________________//

//initial position of rhino
int rx = 1275;
int ry = 95;

//stand variables for rhino
int rhinoStand[4];
int rhinoIndex = 0;
bool rhiStand = true;
int rhinoStandCounter = 0;

//running right variables for rhino
int rhinoRun1[11];
int rhino1index = 0;
bool rhinoRIGHT = false;

//running left variables for rhino
int rhinoRun2[11];
int rhino2index = 0;
bool rhinoLEFT = false;

//jump variables for rhino
bool rhinoJump = false;
bool rhinoJumpUp = false;
bool rhinoJumper = true;
int rhinoCordinateJump = 0;
int rhinoJump1[2];
int rhinoJump2[2];
bool rhinoJumpL = false;
bool rhinoJumpR = false;

//punch variables for rhino
int rhinoPunch[7];
int rhinoPunchIndex = 0;
bool rhinoPun = false;

//kick variables
int rhinoKick[4];
int rhinoKickIndex = 0;
bool rhinoKic = false;

//ult
int rhinoUlt[7];
int rhinoUltIndex = 0;
bool rhinoUlti = false;

//____________________peter associated variables__________________//

//initial position of peter
int x2 = 15;
int y2 = 95;

//stand variables
int peterStand2[3];
int sindex2 = 0;
bool stand2 = true;
int standCounter2 = 0;

//running right varibales
int peterRun12[7];
int r1index2 = 0;
bool RIGHT2 = false;

//running left variables
int peterRun22[7];
int r2index2 = 0;
bool LEFT2 = false;

//jump variables
bool jump2 = false;
bool jumpUp2 = false;
bool jumper2 = true;
int peterCordinateJump2 = 0;
int peterJump2[2];
int peterJump12[2];
bool jumpL2 = false;
bool jumpR2 = false;

//punch variables
int punch2[7];
int punchIndex2 = 0;
bool pun2 = false;

//kick variables
int kick2[4];
int kickIndex2 = 0;
bool kic2 = false;

//ult
int ult2;
int ultIndex2 = 0;
bool ulti2 = false;

//block
int block2;
int blockIndex2 = 0;
bool bloc2 = false;

int spidermanHealth2 = 1000;
int rhinoHealth = 1000;

//web
int Web2[2];
struct web2
{
	int webX2;
	int webY2;
	int webIndex2;
	bool webShow2;
}webs2[webNumber];

int imga;
int imgb;