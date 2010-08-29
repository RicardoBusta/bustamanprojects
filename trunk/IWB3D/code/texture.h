#ifndef TEXTURE_H
#define TEXTURE_H

#include <string>

using namespace std;

class texture{
public:
///Construtores///
	texture();
	~texture();
///Atributos///
	unsigned int id;
///Métodos///
	void loadTexture(string filepath);
};

#endif //TEXTURE_H
