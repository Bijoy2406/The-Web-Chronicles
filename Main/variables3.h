int spideyIcon3;
int t13;
bool thugUlt3 = false;

//background moving variables and structures
#define bgSpeed3 5
#define n3 5
int bg3[n3];
struct background3
{
	int x3;
	int y3;
};
background3 mainbg3[n3];
bool movebg3 = false;

//____________________peter associated variables__________________//

//initial position of peter
int x3 = 15;
int y3 = 20;

//stand variables
int peterStand3[5];
int sindex3 = 0;
bool stand3 = true;
int standCounter3 = 0;

//running right varibales
int peterRun13[5];
int r1index3 = 0;
bool RIGHT3 = false;

//running left variables
int peterRun23[5];
int r2index3 = 0;
bool LEFT3 = false;

//jump variables
bool jump3 = false;
bool jumpUp3 = false;
bool jumper3 = true;
int peterCordinateJump3 = 0;
int peterJump3[2];
int peterJump13[2];
bool jumpL3 = false;
bool jumpR3 = false;

//punch variables
int punch3[5];
int punchIndex3 = 0;
bool pun3 = false;

//kick variables
int kick3[5];
int kickIndex3 = 0;
bool kic3 = false;

//ult
int ult3;
int ultIndex3 = 0;
bool ulti3 = false;

//block
int block3;
int blockIndex3 = 0;
bool bloc3 = false;

int spidermanHealth3 = 500;
int dBar3 = 0;
int uBar3 = 0;
bool ctr3 = false;

int Web3[2];
struct web3
{
	int webX3;
	int webY3;
	int webIndex3;
	bool webShow3;

}webs3[webNumber];


int Horb3[5];
struct hOrb3
{
	int hOrb_x3;
	int hOrb_y3;
	int hOrbIndex3;
	bool hOrbShow3;
} horb3[1];

int orb3[5];
struct dOrb3
{
	int dOrb_x3;
	int dOrb_y3;
	int dOrbIndex3;
	bool dOrbShow3;
} dorb3[1];

int Uorb3[5];
struct uOrb3
{
	int uOrb_x3;
	int uOrb_y3;
	int uOrbIndex3;
	bool uOrbShow3;
} uorb3[1];

int thugRun3[3];
struct thugs3
{
	int thugX3;
	int thugY3;
	int thugIndex3;
	int thugHealth3 = 100;
	bool thugShow3;

} enemy3[thug1Number];

int thug2Run3[9];
struct bullets3
{

	int bullX3;
	int bullY3;
	int bullIndex3;
	int bullHealth3 = 100;
	bool bullShow3;

}enemy23[thug2Number];

int firing3;
struct fire3
{
	int fireX3;
	int fireY3;
	int fireIndex3;
	bool fireShow3;
} fire3[1];
bool ctr2 = false;