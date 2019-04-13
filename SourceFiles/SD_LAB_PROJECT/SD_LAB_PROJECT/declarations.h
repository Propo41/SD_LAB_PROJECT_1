#ifndef DECLARATIONS_h
#define DECLARATIONS_h






bool gameWon_2 = false;
int victoryIndex = 29;
bool princessSegment = false;
bool princessCutscene = false;

enum motion{

	RIGHT, LEFT, MANUAL, AUTO
};

enum characterType{

	CREEPS, BOSS, HERO

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
	HERO_1, HERO_2, LOADING_2
};

enum Objective
{

	OBJECTIVE, NARRATIVE, L1_BOSSCUTSCENE, L1_CUTSCENE, WAVE
};




/*****************TIMER FUNCTIONS*********************/

void autoMotion();
void enemyAutoMotion();
void loadImages();
void heroAutoMotion();
void initLevels();

/*******************LOADING IMAGES**********************************/

void loadImagesBoss2();
void loadImagesCreep2();
void loadImagesHero2();
void loadImagesBackground2();

//*******************HERO*****************
void heroGotAttacked();
void loadImagesHero();
void loadImagesHero2();
void showHero();
void showHeroJump();
void heroMovement(int dir);
void heroAttack();
void renderHeroAttack(int mode);
void heroDamage(int mode);
void resetHero();
void heroGain(int mode);
void initializeHero(int mode);
void renderHero();
void heroJump();
void checkHeroDamage();


int ProjectileDistance = 0; // the max amount of distance the projectile covers. It helps to find out that
int JUMPLIMIT = 80; // defines the maximum limit of the jump
bool temp_5 = false; // used to enter gameover music only once
const int fissureDuration = 10; // defines for how long the fissure stays on ground
const int heroFissureLength = 395; // length of the fissure of hero

bool hero_1 = false;
bool hero_2 = false;

bool HeroJumpingAbility = false;
int heroJumpIndex = 14;


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
void creepTriggers(int r, int g, int b, int dx, int dy);
void renderCreeps(int mode, int index);
void loadImagesCreep2();
void creepHurtLogic();

int creepsAlive = 0; // used to show how many creeps are alive in a wave
char creepsAliveArray[100]; // stores the number of creeps alive to use in itext
int creepsLimit = 3; // the more the value, the greater number of creeps will be spawned
bool creepsSegment = false; // when inside creep segment this is true else false
int rangeLeft;// if creeps come near hero's range then they get damaged. 
int rangeRight;// if creeps come near hero's range then they get damaged. 
int creepsCount; // number of creeps spawned in a wave
int CreepsTriggerCounter = 1;
// used for reducing code. ie the loop iteration over creeps[i] would had to repeated many times for each block.
// since it's commong for all, the bool variable was used
bool creepsHP = false;


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

//level2boss
void bossChase();  //Boss x axis is changed here
void showBossAttacking(); // attacking animation is shown here and a also index controlling of the attacking animation
void change();




int wait = 0;// used for how long the fissure stays on the ground
bool temp_2 = true;//calls only once. it is used for channeling attacks for boss. ie the boss does not attack consecutively. it attacks after a few seconds
bool temp_3 = true;//it is used to enter the block that resets the index values of boss power/attack. if not used in that place, a bug occurs
bool temp_6 = true;//used for initializing the sprite animation for boss rotating after dying or else it rotates twice
int temp_7 = 0;//the variable is used for how long the boss SLIDES on the floor before the game finishes
int fissureLength = 400; // lenght of fissure
int moveBoss = false; // after boss trigger, the boss moves a certain distance. This variable is used to control that
bool bossSegment = false;// true when boss segment is true


// level 2
bool bossAttacking = false; // the entire boss attacking sequence. it becomes false when attack is complete
bool reversePower = false; // projectile comes back when this is true
int bossTargetX = 0; // when hero goes from left to right of boss or vice versa there is a bug on power so had to use this variable
int bossImages[50];
int bossAttackImages[50];
int bossImageIndex = 6;
int bossAttackIndex = 12;
//L2Boss.dyingIndex = 0;
bool bossMovingLeft = true;
bool bossMovingRight = false;
bool bossAnimationComplete = false;
int actualBossX;



//*****************BRIDGE*************************

void resetBridge();
void buildBridge();
void dropBridge();
void movePlayerOverBridge();
void bridge();


int tileHeight = 218 - 3; //  heigh of tile
bool build_bridge = false; // when pressing space bridge is being built
bool bridge_fall = false; // bridge falling when p is pressed 
bool bridgeDone = false; // when p is pressed this is true
bool rotateBridge = false; //  when p is pressed this is true
int bridgeGap[] = { 113, 206, 332 }; // stores the coordinates of the length of the gaps
int bridgeEdgeCoordinate[] = { 177, 470, 854 }; // stores the bridge edge coordinates
int blockCenterCoordinate[] = { 0, 292, 676, 1190 }; // for the hero to be at the center of the blocks, so that the player can reposition himself at the center 
int bridge_x;// x cordinate of bridge 
int bridge_y = tileHeight;  // y coordinate is bridge
int bridge_width = 10, bridge_height = 0;
int theta = 0; // the with which it is being rotated
int step = 0; // running time over bridge
int bridgeIndex = 0; // indexing of bridge
bool gapPassed = false;



//******************BACKGROUND********************
void initializeBackground();
void showBackground();
void moveBackground(int direction);
void fix_Background(bool dir);
void renderRain();
void counterMotion(int character, int dir, int mode);
void loadImagesBackground();
void loadImagesBackground2();
void moveScreen(int dir);
void moveTile(int dir);
void environmentTriggers();
void environmentTriggers2(int mode);


int t = 8; //used to trigger creeps in
int backgroundWidth = 5464;//background Dimensions
int backgroundHeight = 768;//background Dimensions
int stage = 0;  // used to iterate through the different environmental trigger stages
bool SlopeSegment = false; // this is turned false when hero passes the entire slope segment
long randomTime; // used for the time function
bool bloodEffect = false;
int checkTriggers[3];
int checkGap[3];
int canvasHeight = 768; //canvas Dimensions
int canvasWidth = 1366; //canvas Dimensions
// backgroundEnd indicates when the boss is triggered. If the boss comes, then backgroundEND is made true
// and the player cannot escape the region
bool backgroundEnd = false;
int loading_dx = 0; // used for the loading screen of level 1
int PassiveMouseX; // stores the x cordinate of mouse
int PassiveMouseY;// stores the y cordinate of mouse

// for slope mechanics
bool HeroGoingDown = false;// in slope movement
bool HeroGoingUp = false; // in slope movement
bool leftSlope = false; // true when hero inside left slope
bool RightSlope = false;// true when hero inside right slope
int blockID_L; // the mystic circles to restrict motion when boss comes
int blockID_R;// the mystic circles to restrict motion when boss comes
bool fixBackground = false; // when the bridge segment is over, the background moves by itself. this variable is used for that
int backgroundCounter = 0; // used to fix the background
int temp_4 = false;   // when boss automatically moves a certain distance, the block is executed only once. ln: 649; inside bossSegment of enemyAutoMotion
bool temp_8 = false; // temp_8 is used for entering once inside this block. ie the objective "space to jump" will only be shown once the hero is within the given range
const int backgroundConstrain_1 = -1000; // used as a reference variable. it's used to stop the background moving when player tries to reach the bridgesegment again by pressing LEFT . after fixBackground is used after crossing bridgeSegment, the value of screen.x becomes -1000. Thus this reference -1000 is used
const int backgroundConstrain_2 = 0; // level 2: initially the player cannot go any further to the left.
bool bridgeSegment = false; // when bridge segment is over


//************************HUD************************

void renderHUD(int mode, int i);
void loadImagesUI();
void loadImagesUI2();
void initializeObjective();
void initializeObjective();
void initializeObjective2();
void initializeCutscenes();
void initializeCutscenes2();
void loadImagesEffects();
void renderEffects();
void renderMenu();
void renderUI();
void renderNarrative();
void menuLogic();


int MenuController = FALLEN_KINGDOM, PreviousMenu = FALLEN_KINGDOM;
char scoreArray[1000];
int score = 0;
int p = 0; // used for the blink counter effect for the font
int narrativeCounter = 0;
bool cutscene = false;
bool bossCutscene = false;
int cutsceneIndex = 0;
int objectiveIndex = 0;
int waveIndex = -1;
char UserNameInput[200];  // the input taken from the user will be in this character array
int UserNameInputIndex = 0;


//*************************GAME***************************
void playSound(int mode);
void resetGame();
void HighScoreFiles();
void SettingNewHighScore();

bool initLevel_2 = false;
bool initLevel_1 = false;
bool waveClear = false;
bool gameStart = false;
bool gameOver = false;
bool gameWon_1 = false;
bool level_1 = true;
bool level_2 = false;

int timer_AUTOMOTION;
int timer_ENEMYMOTION;
int timer_HEROMOTION;

bool sound = true;
bool menuMusic = true;
char nameArray[1000];
bool nameShort = false; // when name is too short, this is used to toggle that

//******************************************************



#define DIRECTION_L 11
#define DIRECTION_R 12


#define byBOSS 8
#define byCreeps 10

enum Sound
{
	MENU, STOP, INGAME
};

#define RED 255,0,0
#define GREEN 0,255,0
#define BLUE 0,0,255
#define WHITE 255,255,255



#endif