#ifndef VERT_H
#define VERT_H

class Vert{
public:
    float x,y,z;
    Vert();
    Vert(int x, int y, int z);
    Vert operator= (Vert v);
    Vert operator- (Vert v);
    Vert operator+ (Vert v);
};

#endif // VERT_H
