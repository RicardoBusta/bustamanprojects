#include "DCommon.h"

//fu

#include <cstdlib>

float abs(float a){
	if(a<0) return -a;
	return a;
}

void yeah(string test){
    int k;
    cout << "Yeah! " << test << endl;
    cin >> k;
}

int random(int begin, int end){
    int BEGIN, END;
    if(end > begin){
        END = end;
        BEGIN = begin;
    }else{
        END = begin;
        BEGIN = end;
    }
    return BEGIN+rand()%END+1;
}
