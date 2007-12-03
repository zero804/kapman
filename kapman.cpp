/* This file is part of Kapman.
   Created by Thomas Gallinari <tg8187@yahoo.fr>

   Kapman is free software; you can redistribute it and/or
   modify it under the terms of the GNU General Public
   License as published by the Free Software Foundation, version 2.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
   02110-1301, USA
*/
#include <QGraphicsScene>

#include "kapman.h"

const qreal Kapman::SPEED = 2.5;

Kapman::Kapman() : m_x(260), m_y(335), m_xSpeed(0), m_ySpeed(0) {

}

Kapman::~Kapman() {

}

void Kapman::goUp() {
	m_xSpeed = 0;
	m_ySpeed = -SPEED;
}

void Kapman::goDown() {
	m_xSpeed = 0;
	m_ySpeed = SPEED;
}

void Kapman::goRight() {
	m_xSpeed = SPEED;
	m_ySpeed = 0;
}

void Kapman::goLeft() {
	m_xSpeed = -SPEED;
	m_ySpeed = 0;
}

void Kapman::move() {
	m_x += m_xSpeed;
	m_y += m_ySpeed;
	
	emit(moved(m_x, m_y));
}

/** Accessors */
qreal Kapman::getSPEED() const {
	return SPEED;
}

qreal Kapman::getX() const {
	return m_x;
}

qreal Kapman::getY() const {
	return m_y;
}

qreal Kapman::getXSpeed() const {
	return m_xSpeed;
}

qreal Kapman::getYSpeed() const {
	return m_ySpeed;
}

/** SLOTS */
void Kapman::changeMazeSide(qreal p_newX, qreal p_newY) {
	m_x = p_newX;
	m_y = p_newY;
}
