/*
 * InstrumentExperimentalView.cpp - Instrument settings for playground-exclusive
 *                                  experimental features
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

#include "InstrumentExperimentalView.h"

#include <QHBoxLayout>
#include <QLabel>
#include <QPixmap>
#include <QVBoxLayout>

#include "ComboBox.h"
#include "GroupBox.h"
#include "GuiApplication.h"
#include "FontHelper.h"
#include "InstrumentTrack.h"
#include "LedCheckBox.h"
#include "MainWindow.h"
#include "PixmapButton.h"
#include "Knob.h"


namespace lmms::gui
{


InstrumentExperimentalView::InstrumentExperimentalView(InstrumentTrack *it, QWidget *parent) :
	QWidget(parent)
{
	auto layout = new QVBoxLayout(this);
	layout->setContentsMargins(5, 5, 5, 5);

	// Humanized Pitch
	m_humanizationNotSupportedLabel = new QLabel(tr("Humanization is not available for MIDI-based instruments."));
	m_humanizationNotSupportedLabel->setWordWrap(true);
	m_humanizationNotSupportedLabel->hide();
	layout->addWidget(m_humanizationNotSupportedLabel);

	m_humanizationGroupBox = new GroupBox(tr("HUMANIZATION"));
	layout->addWidget(m_humanizationGroupBox);
	
	auto humanizationLayout = new QHBoxLayout(m_humanizationGroupBox);
	humanizationLayout->setContentsMargins(8, 18, 8, 8);

	auto m_randomPitchMinKnob = new Knob(KnobType::Bright26, tr("Min"), this, Knob::LabelRendering::WidgetFont);
	m_randomPitchMinKnob->setHintText( tr( "Random Pitch Min:" ), tr( " cents" ) );
	m_randomPitchMinKnob->setModel(it->randomPitchMinModel());
	humanizationLayout->addWidget(m_randomPitchMinKnob);

	auto m_randomPitchMaxKnob = new Knob(KnobType::Bright26, tr("Max"), this, Knob::LabelRendering::WidgetFont);
	m_randomPitchMaxKnob->setHintText( tr( "Random Pitch Max:" ), tr( " cents" ) );
	m_randomPitchMaxKnob->setModel(it->randomPitchMaxModel());
	humanizationLayout->addWidget(m_randomPitchMaxKnob);

	// Fill remaining space
	layout->addStretch();
}


} // namespace lmms::gui
