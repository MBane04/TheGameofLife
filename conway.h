int mod(int n, int d);

typedef struct {
    //boundaries
    int x; //# rows
    int y; //# columns

    char wrap; //state

    char *board;
} conway;


int cellWrap(conway *c, int x, int y); //wrap function

void startUp(conway *c, char wrap, int x, int y); //algorithms
void initLine(conway *c, char *seed, char empty); //initial state
void initBoard(conway *c, char **seed, char empty);

void conwaySimulate(conway *c); //runs the game of life
void conwaysimulateN(conway *c, int n); //runs the game of life N times
void conwayDestroy(conway *c); //destroys life

char **conway_print(conway *c);