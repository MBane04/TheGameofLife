int mod(int n, int d);

typedef struct {
    //boundaries
    int x; //# rows
    int y; //# columns

    char wrap; //state

    char *board;
} conway;

void startUp(conway *c, char wrap, int x, int y); //algorithms
void initLine(conway *c, char *seed, char empty); //initial state
void initTable(conway *c, char **seed, char empty);

void conwaySimulate(conway *c); //runs the game of life
void conwaysimulateN(conway *c, int n); //runs the game of life N times
void conwayDestroy(conway *c); //destroys life

char **conwayPrint(conway *c,char alive, char dead, char **ret);