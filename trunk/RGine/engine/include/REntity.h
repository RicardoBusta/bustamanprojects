/**
 * @file
 * @author Ricardo Bustamante de Queiroz <ricardobqueiroz@gmail.com>
 * @version
 *
 * @section LICENSE
 *
 * This file is part of RGine.
 *
 * RGine is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Foobar is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with RGine.  If not, see <http://www.gnu.org/licenses/>.
 *
 * @section DESCRIPTION
 *
 * File: REntity.h
 * Created on: Aug 5, 2011
 */

#ifndef RENTITY_H_
#define RENTITY_H_

//TODO this class will be every single object handled in this game

#include <RFrame.h>

/**
 * Every single object in the game will be an entity.
 * Capable of having position, graphics and physics attached to it
 */
class REntity {
public:
	REntity();
	virtual ~REntity();

	/**
	 * Every entity should be able to handle itself. It means moving, rotating,
	 * interacting or whatever it's supposed to do.
	 */
	void handle();
private:
	RFrame frame;
};

#endif /* RENTITY_H_ */
