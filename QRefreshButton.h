#pragma once
#include <QtWidgets/qpushbutton.h>
#include "QPathViewer.h"
class QRefreshButton : public QPushButton
{
	Q_OBJECT
public:
	QRefreshButton(QWidget* parent);
	~QRefreshButton();
};

