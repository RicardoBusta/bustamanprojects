#ifndef DText_H
#define DText_H

#include <string>

using namespace std;

class DText{
private:
	double font_size;
	string text;
public:
//Construtor
	DText();
	DText(string);

//Definição
	void set_text(string);
	void set_pos(int x,int y, int z);
//Desenho
	void draw_character(char);
	void draw();
};

#endif //DText_H
