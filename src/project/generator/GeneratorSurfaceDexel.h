///////////////////////////////////////////////////////////////////////////////
// Name               : GeneratorSurfaceDexel.h
// Purpose            :
// Thread Safe        : Yes
// Platform dependent : No
// Compiler Options   :
// Author             : Tobias Schaefer
// Created            : 23.12.2017
// Copyright          : (C) 2017 Tobias Schaefer <tobiassch@users.sourceforge.net>
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

#ifndef GENERATORSURFACEDEXEL_H_
#define GENERATORSURFACEDEXEL_H_

/*!\class GeneratorSurfaceDexel
 * \ingroup Generator
 * \brief ...
 *
 * ...
 */

#include "GeneratorDexel.h"

class GeneratorSurfaceDexel:public GeneratorDexel {
public:
	GeneratorSurfaceDexel();
	virtual ~GeneratorSurfaceDexel();

	virtual void CopyParameterFrom(const Generator * other);
	virtual wxString GetName(void) const;
	virtual void AddToPanel(wxPanel * panel, CollectionUnits* settings);
	virtual void TransferDataToPanel(void) const;
	virtual void TransferDataFromPanel(void);
	virtual void GenerateToolpath(void);

public:

private:
	wxStaticText* m_staticTextTwiddleFactor;
	wxTextCtrl* m_textCtrlTwiddleFactor;
	wxStaticText* m_staticTextUnit;

};

#endif /* GENERATORSURFACEDEXEL_H_ */
