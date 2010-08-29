#ifndef TETRIS_H
#define TETRIS_H

//Tile Size and Tile Border
#define TSIZE 20
#define BSIZE 2

//Spawn Point for pieces
#define SPAWNX 4
#define SPAWNY 20

//Number of lines and columns the field will have
#define FIELDL 20
#define FIELDC 10

//delay
#define WAITTIME 10

class game;
class piece;
class keyboard;

class tetris{
public:
	//data
	int wait;
	bool gameover;
	struct {
		bool m[FIELDL][FIELDC];
		float c[FIELDL][FIELDC][3];
		bool clearl[FIELDL];
	}field;
	game* g;
	piece *p, *hold, *next[6];
	int fixcount;

	//methods
	void draw();
	void drawTile(int x, int y, float *c);
	void handle();
	keyboard key(int k);

	void fixPiece();
	void callNextPiece();
	void holdPiece();
	void checkLineComplete(int l);
	void clearLine();

	//constructor
	tetris(game *parent);
	~tetris();
};

#endif //TETRIS_H
