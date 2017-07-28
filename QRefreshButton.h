#pragma once
#include <QtWidgets/qpushbutton.h>
#include "qpathviewer.h"
class QRefreshButton : public QPushButton
{
	Q_OBJECT
public:
	QRefreshButton(QWidget* parent);
	~QRefreshButton();
};

