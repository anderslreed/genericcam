///////////////////////////////////////////////////////////////////////////////
// Name               : DexelTarget.h
// Purpose            :
// Thread Safe        : Yes
// Platform dependent : No
// Compiler Options   :
// Author             : Tobias Schaefer
// Created            : 06.07.2011
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


#ifndef DEXELTARGET_H_
#define DEXELTARGET_H_

/*!\class DexelTarget
 * \brief ...
 *
 * ...
 */

#include "../generator/Imprinter.h"
#include <wx/dynarray.h>
#include <wx/xml/xml.h>

#include "../project/Object.h"
#include "../3D/Polygon25.h"
#include "../project/ToolPath.h"
#include "../machine/Tool.h"
//#include <cstddef>

class DexelTarget:public Imprinter {
	// Constructor/ Destructor
public:
	DexelTarget();
	virtual ~DexelTarget();

	//Member variables:
public:
	//double shiftZ;
	Polygon25 outLine;
	Polygon25 supportLine;

	ToolPath toolpath;
	ToolPath toolpathFlipped;

	//Methods:
public:
	void ToXml(wxXmlNode* parentNode);
	bool FromXml(wxXmlNode* node);

	void InsertObject(Object &object, const AffineTransformMatrix & shift);

	int NextDir(int sx, int sy, double height, int olddir);
	int NextDir(int sx, int sy, int olddir);
	const Polygon25 GeneratePolygon(int sx, int sy, double height);
	const Polygon25 GeneratePolygon(int sx, int sy);
	const Polygon25 GenerateConvexOutline(void);

	void DocumentField(int x,int y,double height);
	void DocumentField(int x, int y);
	void GenerateDistanceMap(double height, bool invert = false);
	void RaiseDistanceMap(double height, bool invert);
	void FoldLowerDistance(int x, int y, const DexelTarget &b);
	bool FindNextDistance(int &x, int&y);
	bool IsInsideWorkingArea(int x, int y);
	bool HasToBeCut(int x, int y);
	bool HadBeenCut(int x, int y);
	void MoveInDir(int &x, int &y, int dir);
	int NextDirReverseDistance(int sx, int sy, int olddir);
	int NextDirForwardDistance(int sx, int sy, int olddir);
	bool FindStartCutting(int &x, int &y);
	Polygon25 FindCut(int &x, int &y);

	double GetMinLevel(void);
	double GetMaxUpsideLevel(int &x, int &y);

	// Polygon3 Methods

	void PolygonDropDexelTarget(Polygon3 &polygon, DexelTarget &tool);
	void PolygonDrop(Polygon3 &polygon, double level);
	void VectorDrop(double &x, double &y, double &z, double level);
	void FillOutsidePolygon(Polygon3 &polygon);

	void SetupDrill(Tool &tool, double diameter, double depth);

	void AddSupport(Polygon3 &polygon, double distance, double height,
			double width, double slotWidth);

	void Simulate(void);

	void Paint(void);
};
WX_DECLARE_OBJARRAY(DexelTarget, ArrayOfDexelTarget)
;

#endif /* DEXELTARGET_H_ */
