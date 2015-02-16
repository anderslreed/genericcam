///////////////////////////////////////////////////////////////////////////////
// Name               : ObjectPlacement.cpp
// Purpose            :
// Thread Safe        : Yes
// Platform dependent : No
// Compiler Options   :
// Author             : Tobias Schaefer
// Created            : 20.07.2011
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
///////////////////////////////////////////////////////////////////////////////

#include "ObjectPlacement.h"

#include <GL/gl.h>
#include <wx/arrimpl.cpp>
WX_DEFINE_OBJARRAY(ArrayOfObjectPlacement)

ObjectPlacement::ObjectPlacement()
{
	selected = false;
	objectNr = 0;

	slotWidth = 0.01; // 1 cm

	matrix.TranslateGlobal(0.00, 0.00, 0);
	isMovable = true;
	isKeepout = false;
	useContour = false;
}

ObjectPlacement::~ObjectPlacement()
{
}

void ObjectPlacement::Clear(void)
{

	objectNr = 0;
	slotWidth = 0.01;
	matrix.SetIdentity();

	isMovable = true;
	isKeepout = false;
	outline.Clear();
}

void ObjectPlacement::Update(const ArrayOfObject& objects)
{
	bbox.Clear();
	outline.Clear();
	if(objectNr < 0 || objectNr >= objects.GetCount()) return;
	for(int n = 0; n < objects[objectNr].geometries.GetCount(); n++){
		bbox.Insert(objects[objectNr].geometries[n],
				matrix * objects[objectNr].matrix);
	}

	outline.InsertPoint(0, 0, 0);
	outline.InsertPoint(bbox.GetSizeX(), 0, 0);
	outline.InsertPoint(bbox.GetSizeX(), bbox.GetSizeY(), 0);
	outline.InsertPoint(0, bbox.GetSizeY(), 0);
	outline.Close();
}

//void ObjectPlacement::SetKeepout(double x, double y, double sizex, double sizey)
//{
//	matrix.SetIdentity();
//	matrix.TranslateGlobal(x, y, 0.0);
//	outline.Clear();
//	outline.InsertPoint(0.0, 0.0, 0.0);
//	outline.InsertPoint(sizex, 0.0, 0.0);
//	outline.InsertPoint(sizex, sizey, 0.0);
//	outline.InsertPoint(0.0, sizey, 0.0);
//	outline.Close();
//	isMovable = false;
//	isKeepout = true;
//}

//void ObjectPlacement::Paint(void) const
//{
//	::glPushMatrix();
//	::glMultMatrixd(matrix.a);
//	outline.Paint();
//	::glPopMatrix();
//}
