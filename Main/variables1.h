#define screenWidth 1600
#define screenHeight 700


#define peterWidth 200
#define peterHeight 200
#define webNumber 15
#define jumplimit 400

#define thug1Number 2
#define thug2Number 1
#define fireNumber 2
bool thugUlt = false;
#define dOrbNumber 1

int gamestate = -1;
int gamephase = 0;


//main menu details
int title;
int menu;
int num = 5;
int buttons[5];
int inst;
int highscore;
int credits;
int victory;
int mx, my;

//Structure for button co-ordinates
struct buttonCoordinate {
	int x;
	int y;
}bCoordinate[5];


//extras
int imgx, imgy;
int image1;
bool ctr = false;
//background moving variables and structures
#define bgSpeed 5
#define n 5
int bg[n];
struct background
{
	int x;
	int y;
};
background mainbg[n];
bool movebg = false;

//____________________peter associated variables__________________//


int spideyIcon;
int t1;

//initial position of peter
int x = 15;
int y = 95;

//stand variables
int peterStand[3];
int sindex = 0;
bool stand = true;
int standCounter = 0;

//running right varibales
int peterRun1[7];
int r1index = 0;
bool RIGHT = false;

//running left variables
int peterRun2[7];
int r2index = 0;
bool LEFT = false;

//jump variables
bool jump = false;
bool jumpUp = false;
bool jumper = true;
int peterCordinateJump = 0;
int peterJump[2];
int peterJump1[2];
bool jumpL = false;
bool jumpR = false;

//punch variables
int punch[7];
int punchIndex = 0;
bool pun = false;

//kick variables
int kick[4];
int kickIndex = 0;
bool kic = false;

//ult
int ult;
int ultIndex = 0;
bool ulti = false;

//block
int block;
int blockIndex = 0;
bool bloc = false;

int spidermanHealth = 500;
int dBar = 0;
int uBar = 0;

//for score

/*__________________________________________web________________________________________*/
int web[2];
struct web
{
	int webX;
	int webY;
	int webIndex;
	bool webShow;

}webs[webNumber];

/*_________________________________________________Health ORB DEFINITIONS____________________________________________________________*/
int Horb[5];
struct hOrb
{
	int hOrb_x;
	int hOrb_y;
	int hOrbIndex;
	bool hOrbShow;
} horb[1];

/*_________________________________________________Dimensional ORB DEFINITIONS____________________________________________________________*/
int orb[5];
struct dOrb
{
	int dOrb_x;
	int dOrb_y;
	int dOrbIndex;
	bool dOrbShow;
} dorb[1];

/*_________________________________________________Ultimate ORB DEFINITIONS____________________________________________________________*/
int Uorb[5];
struct uOrb
{
	int uOrb_x;
	int uOrb_y;
	int uOrbIndex;
	bool uOrbShow;
} uorb[1];

/*________________________________________________thug-1_____________________________________________*/
int thugRun[3];
struct thugs
{
	int thugX;
	int thugY;
	int thugIndex;
	int thugHealth = 100;
	bool thugShow;

} enemy[thug1Number];

/*________________________________________________thug-2_____________________________________________*/
int thug2Run[3];
struct bullets
{

	int bullX;
	int bullY;
	int bullIndex;
	int bullHealth = 100;
	bool bullShow;

}enemy2[thug2Number];

/*__________________________________________fire________________________________________*/
int firing;
struct fire
{
	int fireX;
	int fireY;
	int fireIndex;
	bool fireShow;
} fire[1];
int c1;
int c2;
int c3;
