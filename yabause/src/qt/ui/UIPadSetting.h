/*	Copyright 2008 Filipe Azevedo <pasnox@gmail.com>

	This file is part of Yabause.

	Yabause is free software; you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation; either version 2 of the License, or
	(at your option) any later version.

	Yabause is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with Yabause; if not, write to the Free Software
	Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301  USA
*/
#ifndef UIPADSETTING_H
#define UIPADSETTING_H

#include "ui_UIPadSetting.h"
#include "QtYabause.h"

#include <QMap>

class QTimer;

class UIPadSetting : public QDialog, public Ui::UIPadSetting
{
	Q_OBJECT

public:
	UIPadSetting( PerInterface_struct* core, PerPad_struct* padbits, uint port, uint pad, QWidget* parent = 0 );
	virtual ~UIPadSetting();

protected:
	PerInterface_struct* mCore;
	PerPad_struct* mPadBits;
	uint mPort;
	uint mPad;
	u8 mPadKey;
	QTimer* mTimer;
	QMap<QToolButton*, u8> mPadButtons;
	QMap<u8, QString> mPadNames;

	void keyPressEvent( QKeyEvent* event );
	void setPadKey( u32 key );
	void loadPadSettings();

	virtual bool eventFilter( QObject* object, QEvent* event );

protected slots:
	void tbButton_clicked();
	void timer_timeout();
};

#endif // UIPADSETTING_H
