///////////////////////////////////////////////////////////////////////////////
// Name               : Workpiece.h
// Purpose            : The workpiece.
// Thread Safe        : Yes
// Platform dependent : No
// Compiler Options   :
// Author             : Tobias Schaefer
// Created            : 29.03.2010
// Copyright          : (C) 2010 Tobias Schaefer <tobiassch@users.sourceforge.net>
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
//$LastChangedDate: 2011-07-20 23:54:54 +0200 (Mi, 20 Jul 2011) $
//$Revision: 76 $
//$LastChangedBy: tobiassch $
///////////////////////////////////////////////////////////////////////////////


#ifndef WORKPIECE_H_
#define WORKPIECE_H_

#include "../3D/Vector3.h"
#include "../project/StockMaterial.h"
#include "../generator/Imprinter.h"

class Workpiece:public Imprinter {
	// Constructor / Destructor
public:
	Workpiece(const double sizeX = 0.1, const double sizeY = 0.1,
			const double sizeZ = 0.05, const double resolutionX = 0.001,
			const double resolutionY = 0.001);
	Workpiece(StockMaterial* material, const double resolution = 0.001);

	virtual ~Workpiece();

	// Member variables
public:


	// Methods
public:

	void Paint();

	void SetupBox(const double sizeX, const double sizeY, const double sizeZ,
			const double resolutionX = 0.001, const double resolutionY = 0.001);
	void InsertTriangle(Vector3 a, Vector3 b, Vector3 c);
};

#endif /* WORKPIECE_H_ */