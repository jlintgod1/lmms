/*
 * InstrumentExperimentalView.h - widget in instrument-track-window with playground-
 *                                exclusive experimental features
 *
 * Copyright (c) 2005-2014 Tobias Doerffel <tobydox/at/users.sourceforge.net>
 * Copyright (c) 2020-2022 Martin Pavelek <he29.HS/at/gmail.com>
 * Copyright (c) 2026 Jlintgod <jlintgod/at/gmail.com>
 *
 * This file is part of LMMS - https://lmms.io
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public
 * License along with this program (see COPYING); if not, write to the
 * Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301 USA.
 *
 */

#ifndef LMMS_GUI_INSTRUMENT_EXPERIMENTAL_VIEW_H
#define LMMS_GUI_INSTRUMENT_EXPERIMENTAL_VIEW_H

#include <QWidget>

class QLabel;

namespace lmms
{

class InstrumentTrack;

namespace gui
{

class ComboBox;
class GroupBox;
class LedCheckBox;


class InstrumentExperimentalView : public QWidget
{
	Q_OBJECT
public:
	InstrumentExperimentalView(InstrumentTrack *it, QWidget *parent);

	GroupBox *humanizationGroupBox() {return m_humanizationGroupBox;}

	QLabel *humanizationNotSupportedLabel() {return m_humanizationNotSupportedLabel;}

private:
	GroupBox *m_humanizationGroupBox;

	QLabel *m_humanizationNotSupportedLabel;
};


} // namespace gui

} // namespace lmms

#endif // LMMS_GUI_INSTRUMENT_EXPERIMENTAL_VIEW_H
