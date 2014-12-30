///////////////////////////////////////////////////////////////////////////////
// Name               : DialogAnimation.cpp
// Purpose            : A window displaying the animation controls.
// Thread Safe        : Yes
// Platform dependent : No
// Compiler Options   :
// Author             : Tobias Schaefer
// Created            : 12.07.2011
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
///////////////////////////////////////////////////////////////////////////////

#include "DialogAnimation.h"

DialogAnimation::DialogAnimation(wxWindow* parent) :
		GUIAnimation(parent)
{
	linkedProject = NULL;
}

DialogAnimation::~DialogAnimation()
{
}

void DialogAnimation::InsertProject(Project *project)
{
	linkedProject = project;
	TransferDataToWindow();
}

void DialogAnimation::OnClose(wxCommandEvent &event)
{
	Close();
}

bool DialogAnimation::TransferDataToWindow(void)
{
	return true;
}
bool DialogAnimation::TransferDataFromWindow(void)
{
	return true;
}

void DialogAnimation::OnLast(wxCommandEvent& event)
{
}
void DialogAnimation::OnBegin(wxCommandEvent& event)
{
}
void DialogAnimation::OnPlayStop(wxCommandEvent& event)
{
}
void DialogAnimation::OnEnd(wxCommandEvent& event)
{
}
void DialogAnimation::OnNext(wxCommandEvent& event)
{
}