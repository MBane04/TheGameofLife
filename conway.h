int mod(int n, int d);

typedef struct {
    //boundaries
    int x; //# rows
    int y; //# columns

    char wrap; //state

    char *board;
} conway;


int cellWrap(conway *c, int x, int y);

void startUp(conway *c, char wrap, int x, int y); //algorithms
void conway_seed(conway *c, char *seed, char empty); //initial state
void conway_seedTable(conway *c, char **seed, char empty);

void conwaySimulate(conway *c);
void conwaysimulateN(conway *c, int n);
void conwayDestroy(conway *c);