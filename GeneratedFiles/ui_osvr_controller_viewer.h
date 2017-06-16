/********************************************************************************
** Form generated from reading UI file 'osvr_controller_viewer.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OSVR_CONTROLLER_VIEWER_H
#define UI_OSVR_CONTROLLER_VIEWER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>
#include "QPathViewer.h"
#include "QRefreshButton.h"

QT_BEGIN_NAMESPACE

class Ui_OSVR_Controller_ViewerClass
{
public:
	QWidget *centralWidget;
	QPathViewer *pathTree;
	QRefreshButton *refreshButton;
	QTextBrowser *textBrowser;

	void setupUi(QMainWindow *OSVR_Controller_ViewerClass)
	{
		if (OSVR_Controller_ViewerClass->objectName().isEmpty())
			OSVR_Controller_ViewerClass->setObjectName(QStringLiteral("OSVR_Controller_ViewerClass"));
		OSVR_Controller_ViewerClass->resize(811, 401);
		OSVR_Controller_ViewerClass->setUnifiedTitleAndToolBarOnMac(true);
		centralWidget = new QWidget(OSVR_Controller_ViewerClass);
		centralWidget->setObjectName(QStringLiteral("centralWidget"));
		centralWidget->setMouseTracking(false);
		pathTree = new QPathViewer(centralWidget);
		QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
		__qtreewidgetitem->setText(0, QStringLiteral("Interface Type"));
		pathTree->setHeaderItem(__qtreewidgetitem);
		pathTree->setObjectName(QStringLiteral("pathTree"));
		pathTree->setGeometry(QRect(10, 10, 501, 381));
		pathTree->setAutoFillBackground(false);
		pathTree->setProperty("showDropIndicator", QVariant(false));
		pathTree->setRootIsDecorated(true);
		pathTree->setItemsExpandable(true);
		pathTree->setColumnCount(2);
		pathTree->header()->setVisible(true);
		refreshButton = new QRefreshButton(centralWidget);
		refreshButton->setObjectName(QStringLiteral("refreshButton"));
		refreshButton->setGeometry(QRect(520, 360, 281, 31));
		textBrowser = new QTextBrowser(centralWidget);
		textBrowser->setObjectName(QStringLiteral("textBrowser"));
		textBrowser->setGeometry(QRect(520, 10, 281, 341));
		OSVR_Controller_ViewerClass->setCentralWidget(centralWidget);

		retranslateUi(OSVR_Controller_ViewerClass);

		QMetaObject::connectSlotsByName(OSVR_Controller_ViewerClass);
	} // setupUi

	void retranslateUi(QMainWindow *OSVR_Controller_ViewerClass)
	{
		OSVR_Controller_ViewerClass->setWindowTitle(QApplication::translate("OSVR_Controller_ViewerClass", "OSVR Device Viewer", 0));
		QTreeWidgetItem *___qtreewidgetitem = pathTree->headerItem();
		___qtreewidgetitem->setText(1, QApplication::translate("OSVR_Controller_ViewerClass", "Full Path", 0));
		refreshButton->setText(QApplication::translate("OSVR_Controller_ViewerClass", "Refresh Paths", 0));
	} // retranslateUi

};

namespace Ui {
	class OSVR_Controller_ViewerClass : public Ui_OSVR_Controller_ViewerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OSVR_CONTROLLER_VIEWER_H
