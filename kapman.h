/**
 * Copyright 2007-2008 Thomas Gallinari <tg8187@yahoo.fr>
 * 
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of 
 * the License, or (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __KAPMAN_H
#define __KAPMAN_H

#include "character.h"

/**
 * This class represents the main character of the game
 */
class Kapman : public Character {

	Q_OBJECT

	private:

		/** Kapman asked speed */
		qreal m_askedXSpeed, m_askedYSpeed;

	public:

		/**
		 * Creates a new Kapman instance
		 * @param p_x the initial x coordinate
		 * @param p_y the initial y coordinate
		 * @param p_maze the maze the Kapman is on
		 */
		Kapman(qreal p_x, qreal p_y, Maze* m_maze);

		/**
		 * Deletes the Kapman instance
		 */
		~Kapman();

		/**
		 * Makes the Kapman ask to go up
		 */
		void goUp();

		/**
		 * Makes the Kapman ask to go down
		 */
		void goDown();

		/**
		 * Makes the Kapman ask to go to the right
		 */
		void goRight();

		/**
		 * Makes the Kapman ask to go to the left
		 */
		void goLeft();

		/**
		 * Updates the Kapman move
		 */
		void updateMove();

		/**
		 * @return the asked x speed value
		 */
		qreal getAskedXSpeed() const;

		/**
		 * @return the asked y speed value
		 */
		qreal getAskedYSpeed() const;

		/**
		 * Manages the loss of a life
		 */
		void loseLife();

		/**
		 * Manages the points won
		 */
		void winPoints(qreal p_points, qreal p_x, qreal p_y);
		
		/**
		 * Emits a signal to Kapmanitem in order to manage collisions
		 */
		void emitGameUpdated();

	private:

		/**
		 * Updates the Kapman direction with the asked direction
		 */
		void updateDirection();

		/**
		 * @return the next cell the kapman will move on with its asked direction
		 */
		Cell getAskedNextCell();

		/**
		 * Stops moving the Kapman
		 */
		void stopMoving();

	signals:
		
		/**
		 * Signals to the game that the kapman lost a life
		 */
		void lifeLost();
		
		/**
		 * Signals to the game that the kapman win points
		 */
		void sWinPoints(qreal p_points, qreal p_x, qreal p_y);
		
		/**
		 * Signals to Kapmanitem that the game has been updated
		 */
		 void gameUpdated();
};

#endif
