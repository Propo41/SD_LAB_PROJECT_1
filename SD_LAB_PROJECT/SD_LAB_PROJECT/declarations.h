#ifndef DECLARATIONS_h
#define DECLARATIONS_h




void loadImagesBoss2();
void loadImagesCreep2();
void loadImagesHero2();
void loadImagesBackground2();

//*******************HERO*****************
void heroGotAttacked();
void loadImagesHero();
void showHero();
void heroMovement(int dir);
void heroAttack();
void renderHeroAttack();
void heroDamage(int mode);
void resetHero();
void heroGain(int mode);
void initializeHero(int mode);
//****************************************

//*****************CREEPS**********************
void loadImagesCreep();
void showCreeps();
void spawnCreeps();
void creepsMovement();
void creepsFollowPlayer(int direction);
void checkCreepsAlive();
void creepDamage(int mode);
void renderCreepAttack(int index);
void creepAttackLogic();
void creepTrigger(int stage);
void renderCreeps(int mode, int index);
void creepTriggers(int r, int g, int b, int dx, int dy); 

//**********************************************


//****************BOSS****************************
void loadImagesBoss();
void renderBoss(int mode);
void bossFollowPlayer(int dir);
void bossSpawn();
void bossMovement();
void bossAttackLogic(int mode);
void bossTriggers();
void bossTakingDamage();
void bossDamage(int mode);
//************************************************


//*****************BRIDGE*************************

void resetBridge();
void buildBridge();
void dropBridge();
void movePlayerOverBridge();
//************************************************



//******************BACKGROUND********************
void initializeBackground();
void showBackground();
void moveBackground(int direction);
void fix_Background(bool dir);
void renderRain();
void counterMotion(int character, int dir, int mode);
//***********************************************



void playSound(int mode);
void resetGame();

bool HeroJumpingAbility = false;
int heroJumpIndex = 14;
int CreepsTriggerCounter = 1;

//*******************HUD****************************
void renderHUD(int mode, int i);


//**************************************************




int JUMPLIMIT = 80;
const int fissureDuration = 10; // for hero 2
const int heroFissureLength = 395;


//canvas Dimensions
int canvasHeight = 768;
int canvasWidth = 1366;


bool backgroundEnd = false;

bool initLevel_2 = false;
bool initLevel_1 = false;

bool waveClear = false;

bool gameStart = false;
bool gameOver = false;
bool gameWon_1 = false;

bool level_1 = true;
bool level_2 = false;


int t = 8; //used to trigger creeps in creepAutoMotion

//background Dimensions
int backgroundWidth = 5464;
int backgroundHeight = 768;

int tileHeight = 218-3;
int stage = 0;
bool SlopeSegment = false;


long randomTime;
bool bloodEffect = false;


int checkTriggers[3];
int checkGap[3];


// used for the fissure's x and y coordinate. if not used, then when hero moves, the fissure moves as well with the player
int heroX_temp;
int heroY_temp;

bool gapPassed = false;


int timer_AUTOMOTION;
int timer_ENEMYMOTION;
int timer_HEROMOTION;




bool sound = true;
bool menuMusic = true;





enum motion{


	RIGHT, LEFT, MANUAL, AUTO
};


enum characterType{

     CREEPS,BOSS, HERO

};




enum HUD{

	HPBAR,
	LIFE,
	MANA,
	SCORE,
	STAGE_MARK,
	L1BOSSHPBAR,
	HERO_HURT_EFFECT,
	CONTROLS
};


enum mechanics{

	ATTACK, MOVE, DYING, POWER, DAMAGE,
	LIGHT_ATTACK, HEAVY_ATTACK, SLOPE, FALL,
	FISSURE

};



enum MenuController
{
	PLAY, FALLEN_KINGDOM, SELECTIONSCREEN, HIGHSCORE, OPTIONS, CREDITS, PAUSEMENU, GAMEOVER,
	VICTORY_1, VICTORY_2, HEROSELECTION, NARRATIVE_1, ENTERNAME, LOADING_1, LEVEL_1, LEVEL_2,
	HERO_1, HERO_2
};

#define DIRECTION_L 11
#define DIRECTION_R 12

#define MENU 4
#define STOP 3
#define INGAME 2
#define OBJECTIVE 1
#define NARRATIVE 2
#define L1_BOSSCUTSCENE 4
#define L1_CUTSCENE 5
#define WAVE 3

#define byBOSS 8
#define byCreeps 10

#define RED 255,0,0
#define GREEN 0,255,0
#define BLUE 0,0,255
#define WHITE 255,255,255

int creepsCount;

int loading_dx = 0;

int PassiveMouseX;
int PassiveMouseY;


bool hero_1 = false;
bool hero_2 = false;

bool bridgeSegment = false;


bool nameShort = false;



#endif