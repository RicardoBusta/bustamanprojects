/*
 * RList.h
 *
 *  Created on: Jul 14, 2011
 *      Author: Ricardo Bustamante de Queiroz
 *      e-mail: ricardobqueiroz@gmail.com
 */

#ifndef RLIST_H_
#define RLIST_H_

//TODO make this class to replace c++ default list (maybe)

template <class T>
class RList {
public:
	RList();
	virtual ~RList();

	T operator[](const int index);
private:
};

#endif /* RLIST_H_ */
