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

#ifndef __CELL_H
#define __CELL_H

#include <QtGlobal>
class Element;

/**
 * This class represents a cell of the Kapman maze
 */
class Cell {

	public:

		/** The cell side size */
		static const qreal SIZE;

		/** The cell possible types */
		enum CellType {
			WALL = 0,
			CORRIDOR = 1,
			GHOSTCAMP = 2
		};

	private:

		/** The cell's type */
		CellType m_type;

		/** The cell's element */
		Element * m_element;

	public:

		/**
		 * Creates a new Cell instance
		 */
		Cell();

		/**
		 * Deletes the Cell instance
		 */
		~Cell();

		/**
		 * @return the cell type
		 */
		CellType getType();

		/**
		 * Sets the cell type
		 * @param p_type the new type to set
		 */
		void setType(CellType p_type);

		/**
		 * @return the cell Element
		 */
		Element * getElement();

		/**
		 * Sets the cell's item
		 * @param p_item the new item to set
		 */
		void setElement(Element* p_element);
};

#endif
