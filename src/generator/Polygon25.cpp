///////////////////////////////////////////////////////////////////////////////
// Name               : Polygon25.cpp
// Purpose            : Contains a 2.5D polygon.
// Thread Safe        : Yes
// Platform dependent : No
// Compiler Options   :
// Author             : Tobias Schaefer
// Created            : 17.07.2011
// Copyright          : (C) 2011 Tobias Schaefer <tobiassch@users.sourceforge.net>
// Licence            : GNU General Public License version 3.0 (GPLv3)
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
//
//$LastChangedDate: $
//$Revision: $
//$LastChangedBy: $
///////////////////////////////////////////////////////////////////////////////


#include "Polygon25.h"

#include <GL/gl.h>
#include <wx/arrimpl.cpp> // this is a magic incantation which must be done!
WX_DEFINE_OBJARRAY(ArrayOfPolygon25)

Polygon25::Polygon25()
{
}

Polygon25::~Polygon25()
{
}

double Polygon25::GetLengthXY(void) const
{
	if(elements.GetCount() <= 1) return 0.0;
	double d = 0.0;
	size_t i;
	Vector3 temp, temp2;

	temp = elements[0];
	for(i = 1; i < elements.GetCount(); i++){
		temp2 = temp - elements[i];
		temp2.z = 0;
		d += temp2.Abs();
		temp = elements[i];
	}
	if(isClosed){
		temp2 = temp - elements[0];
		temp2.z = 0;
		d += temp2.Abs();
	}
	return d;
}

void Polygon25::PolygonFillHoles(void)
{
	//TODO: This is crude! Find a better way.
	size_t i;
	size_t nrp;
	double m;
	m = 0.0;
	nrp = 0;
	for(i = 0; i < elements.GetCount(); i++){
		if(elements[i].z > -0.5){
			nrp++;
			m += elements[i].z;
		}
	}
	if(nrp == 0) return;
	m /= (double) nrp;
	for(i = 0; i < elements.GetCount(); i++){
		if(elements[i].z < -0.5){
			elements[i].z = m;
		}
	}
}

void Polygon25::PolygonSmooth(void)
{
	size_t i;
	Vector3 d;
	ArrayOfVector3 temp;
	temp = elements;

	for(i = 0; i < elements.GetCount(); i++){
		if(i > 0)
			d = elements[i - 1];
		else
			d = elements[elements.GetCount() - 1];
		d += elements[i];
		if(i + 1 < elements.GetCount())
			d += elements[i + 1];
		else
			d += elements[0];
		temp[i] = d / 3;
	}
	elements = temp;
}

void Polygon25::PolygonExpand(double r)
{
	if(elements.GetCount() < 2) return;
	size_t i;
	Vector3 o, n, d;
	o = elements[0];
	for(i = 1; i < elements.GetCount(); i++){
		n = elements[i];
		o = n - o;
		o.Normalize();
		d.x = o.y;
		d.y = -o.x;
		d.z = o.z;
		o = n;
		elements[i] = n + d * r;
	}
}

void Polygon25::PolygonDiminish(double r)
{
	this->PolygonExpand(-r);
}

