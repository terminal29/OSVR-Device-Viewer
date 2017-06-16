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
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>
#include <QPathViewer.h>
#include <QRefreshButton.h>

QT_BEGIN_NAMESPACE

class Ui_OSVR_Controller_ViewerClass
{
public:
    QWidget *centralWidget;
    QPathViewer *pathTree;
    QRefreshButton *refreshButton;
    QLabel *btn_lbl;
    QListView *listView;
    QLabel *alg_lbl;
    QLabel *p_lbl;
    QLabel *p_t_lbl;
    QLabel *p_r_lbl;
    QLabel *v_lbl;
    QLabel *a_lbl;
    QLabel *dir_lbl;
    QLabel *loc_lbl;
    QLabel *et2d_lbl;
    QLabel *et3d_lbl;
    QLabel *v_a_lbl;
    QLabel *v_l_lbl;
    QLabel *a_a_lbl;
    QLabel *a_l_lbl;
    QLabel *et3d_bp_lbl;
    QLabel *et3d_dir_lbl;
    QLabel *eb_lbl;
    QLabel *img_lbl;
    QLabel *img_w_lbl;
    QLabel *img_h_lbl;
    QLabel *img_c_lbl;
    QLabel *img_d_lbl;
    QLabel *img_t_lbl;
    QLabel *nav_lbl;
    QLabel *nav_p_lbl;
    QLabel *nav_v_lbl;
    QLabel *btn_lbl_i;
    QLabel *alg_lbl_i;
    QLabel *p_t_lbl_i;
    QLabel *p_r_lbl_i;
    QLabel *v_a_lbl_i;
    QLabel *v_l_lbl_i;
    QLabel *a_a_lbl_i;
    QLabel *a_l_lbl_i;
    QLabel *dir_lbl_i;
    QLabel *loc_lbl_i;
    QLabel *et2d_lbl_i;
    QLabel *et3d_bp_lbl_i;
    QLabel *et3d_dir_lbl_i;
    QLabel *eb_lbl_i;
    QLabel *img_w_lbl_i;
    QLabel *img_h_lbl_i;
    QLabel *img_c_lbl_i;
    QLabel *img_d_lbl_i;
    QLabel *img_t_lbl_i;
    QLabel *nav_p_lbl_i;
    QLabel *nav_v_lbl_i;

    void setupUi(QMainWindow *OSVR_Controller_ViewerClass)
    {
        if (OSVR_Controller_ViewerClass->objectName().isEmpty())
            OSVR_Controller_ViewerClass->setObjectName(QStringLiteral("OSVR_Controller_ViewerClass"));
        OSVR_Controller_ViewerClass->resize(811, 461);
        OSVR_Controller_ViewerClass->setUnifiedTitleAndToolBarOnMac(true);
        centralWidget = new QWidget(OSVR_Controller_ViewerClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setMouseTracking(false);
        pathTree = new QPathViewer(centralWidget);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QStringLiteral("Interface Type"));
        pathTree->setHeaderItem(__qtreewidgetitem);
        pathTree->setObjectName(QStringLiteral("pathTree"));
        pathTree->setGeometry(QRect(10, 10, 501, 441));
        pathTree->setAutoFillBackground(false);
        pathTree->setFrameShape(QFrame::Box);
        pathTree->setFrameShadow(QFrame::Raised);
        pathTree->setProperty("showDropIndicator", QVariant(false));
        pathTree->setRootIsDecorated(true);
        pathTree->setItemsExpandable(false);
        pathTree->setExpandsOnDoubleClick(false);
        pathTree->setColumnCount(2);
        pathTree->header()->setVisible(true);
        refreshButton = new QRefreshButton(centralWidget);
        refreshButton->setObjectName(QStringLiteral("refreshButton"));
        refreshButton->setGeometry(QRect(520, 420, 281, 31));
        btn_lbl = new QLabel(centralWidget);
        btn_lbl->setObjectName(QStringLiteral("btn_lbl"));
        btn_lbl->setGeometry(QRect(530, 20, 101, 16));
        listView = new QListView(centralWidget);
        listView->setObjectName(QStringLiteral("listView"));
        listView->setGeometry(QRect(520, 10, 281, 401));
        listView->setFrameShadow(QFrame::Sunken);
        alg_lbl = new QLabel(centralWidget);
        alg_lbl->setObjectName(QStringLiteral("alg_lbl"));
        alg_lbl->setGeometry(QRect(530, 40, 101, 16));
        p_lbl = new QLabel(centralWidget);
        p_lbl->setObjectName(QStringLiteral("p_lbl"));
        p_lbl->setGeometry(QRect(530, 60, 101, 16));
        p_t_lbl = new QLabel(centralWidget);
        p_t_lbl->setObjectName(QStringLiteral("p_t_lbl"));
        p_t_lbl->setGeometry(QRect(530, 70, 101, 16));
        p_r_lbl = new QLabel(centralWidget);
        p_r_lbl->setObjectName(QStringLiteral("p_r_lbl"));
        p_r_lbl->setGeometry(QRect(530, 80, 101, 16));
        v_lbl = new QLabel(centralWidget);
        v_lbl->setObjectName(QStringLiteral("v_lbl"));
        v_lbl->setGeometry(QRect(530, 100, 101, 16));
        a_lbl = new QLabel(centralWidget);
        a_lbl->setObjectName(QStringLiteral("a_lbl"));
        a_lbl->setGeometry(QRect(530, 140, 101, 16));
        dir_lbl = new QLabel(centralWidget);
        dir_lbl->setObjectName(QStringLiteral("dir_lbl"));
        dir_lbl->setGeometry(QRect(530, 180, 101, 16));
        loc_lbl = new QLabel(centralWidget);
        loc_lbl->setObjectName(QStringLiteral("loc_lbl"));
        loc_lbl->setGeometry(QRect(530, 200, 101, 16));
        et2d_lbl = new QLabel(centralWidget);
        et2d_lbl->setObjectName(QStringLiteral("et2d_lbl"));
        et2d_lbl->setGeometry(QRect(530, 220, 101, 16));
        et3d_lbl = new QLabel(centralWidget);
        et3d_lbl->setObjectName(QStringLiteral("et3d_lbl"));
        et3d_lbl->setGeometry(QRect(530, 240, 101, 16));
        v_a_lbl = new QLabel(centralWidget);
        v_a_lbl->setObjectName(QStringLiteral("v_a_lbl"));
        v_a_lbl->setGeometry(QRect(530, 110, 101, 16));
        v_l_lbl = new QLabel(centralWidget);
        v_l_lbl->setObjectName(QStringLiteral("v_l_lbl"));
        v_l_lbl->setGeometry(QRect(530, 120, 101, 16));
        a_a_lbl = new QLabel(centralWidget);
        a_a_lbl->setObjectName(QStringLiteral("a_a_lbl"));
        a_a_lbl->setGeometry(QRect(530, 150, 101, 16));
        a_l_lbl = new QLabel(centralWidget);
        a_l_lbl->setObjectName(QStringLiteral("a_l_lbl"));
        a_l_lbl->setGeometry(QRect(530, 160, 101, 16));
        et3d_bp_lbl = new QLabel(centralWidget);
        et3d_bp_lbl->setObjectName(QStringLiteral("et3d_bp_lbl"));
        et3d_bp_lbl->setGeometry(QRect(530, 250, 101, 16));
        et3d_dir_lbl = new QLabel(centralWidget);
        et3d_dir_lbl->setObjectName(QStringLiteral("et3d_dir_lbl"));
        et3d_dir_lbl->setGeometry(QRect(530, 260, 101, 16));
        eb_lbl = new QLabel(centralWidget);
        eb_lbl->setObjectName(QStringLiteral("eb_lbl"));
        eb_lbl->setGeometry(QRect(530, 280, 101, 16));
        img_lbl = new QLabel(centralWidget);
        img_lbl->setObjectName(QStringLiteral("img_lbl"));
        img_lbl->setGeometry(QRect(530, 300, 101, 16));
        img_w_lbl = new QLabel(centralWidget);
        img_w_lbl->setObjectName(QStringLiteral("img_w_lbl"));
        img_w_lbl->setGeometry(QRect(530, 310, 101, 16));
        img_h_lbl = new QLabel(centralWidget);
        img_h_lbl->setObjectName(QStringLiteral("img_h_lbl"));
        img_h_lbl->setGeometry(QRect(530, 320, 101, 16));
        img_c_lbl = new QLabel(centralWidget);
        img_c_lbl->setObjectName(QStringLiteral("img_c_lbl"));
        img_c_lbl->setGeometry(QRect(530, 330, 101, 16));
        img_d_lbl = new QLabel(centralWidget);
        img_d_lbl->setObjectName(QStringLiteral("img_d_lbl"));
        img_d_lbl->setGeometry(QRect(530, 340, 101, 16));
        img_t_lbl = new QLabel(centralWidget);
        img_t_lbl->setObjectName(QStringLiteral("img_t_lbl"));
        img_t_lbl->setGeometry(QRect(530, 350, 101, 16));
        nav_lbl = new QLabel(centralWidget);
        nav_lbl->setObjectName(QStringLiteral("nav_lbl"));
        nav_lbl->setGeometry(QRect(530, 370, 101, 16));
        nav_p_lbl = new QLabel(centralWidget);
        nav_p_lbl->setObjectName(QStringLiteral("nav_p_lbl"));
        nav_p_lbl->setGeometry(QRect(530, 380, 101, 16));
        nav_v_lbl = new QLabel(centralWidget);
        nav_v_lbl->setObjectName(QStringLiteral("nav_v_lbl"));
        nav_v_lbl->setGeometry(QRect(530, 390, 101, 16));
        btn_lbl_i = new QLabel(centralWidget);
        btn_lbl_i->setObjectName(QStringLiteral("btn_lbl_i"));
        btn_lbl_i->setGeometry(QRect(640, 20, 151, 16));
        alg_lbl_i = new QLabel(centralWidget);
        alg_lbl_i->setObjectName(QStringLiteral("alg_lbl_i"));
        alg_lbl_i->setGeometry(QRect(640, 40, 151, 16));
        p_t_lbl_i = new QLabel(centralWidget);
        p_t_lbl_i->setObjectName(QStringLiteral("p_t_lbl_i"));
        p_t_lbl_i->setGeometry(QRect(640, 70, 151, 16));
        p_r_lbl_i = new QLabel(centralWidget);
        p_r_lbl_i->setObjectName(QStringLiteral("p_r_lbl_i"));
        p_r_lbl_i->setGeometry(QRect(640, 80, 151, 16));
        v_a_lbl_i = new QLabel(centralWidget);
        v_a_lbl_i->setObjectName(QStringLiteral("v_a_lbl_i"));
        v_a_lbl_i->setGeometry(QRect(640, 110, 151, 16));
        v_l_lbl_i = new QLabel(centralWidget);
        v_l_lbl_i->setObjectName(QStringLiteral("v_l_lbl_i"));
        v_l_lbl_i->setGeometry(QRect(640, 120, 151, 16));
        a_a_lbl_i = new QLabel(centralWidget);
        a_a_lbl_i->setObjectName(QStringLiteral("a_a_lbl_i"));
        a_a_lbl_i->setGeometry(QRect(640, 150, 151, 16));
        a_l_lbl_i = new QLabel(centralWidget);
        a_l_lbl_i->setObjectName(QStringLiteral("a_l_lbl_i"));
        a_l_lbl_i->setGeometry(QRect(640, 160, 151, 16));
        dir_lbl_i = new QLabel(centralWidget);
        dir_lbl_i->setObjectName(QStringLiteral("dir_lbl_i"));
        dir_lbl_i->setGeometry(QRect(640, 180, 151, 16));
        loc_lbl_i = new QLabel(centralWidget);
        loc_lbl_i->setObjectName(QStringLiteral("loc_lbl_i"));
        loc_lbl_i->setGeometry(QRect(640, 200, 151, 16));
        et2d_lbl_i = new QLabel(centralWidget);
        et2d_lbl_i->setObjectName(QStringLiteral("et2d_lbl_i"));
        et2d_lbl_i->setGeometry(QRect(640, 220, 151, 16));
        et3d_bp_lbl_i = new QLabel(centralWidget);
        et3d_bp_lbl_i->setObjectName(QStringLiteral("et3d_bp_lbl_i"));
        et3d_bp_lbl_i->setGeometry(QRect(640, 250, 151, 16));
        et3d_dir_lbl_i = new QLabel(centralWidget);
        et3d_dir_lbl_i->setObjectName(QStringLiteral("et3d_dir_lbl_i"));
        et3d_dir_lbl_i->setGeometry(QRect(640, 260, 151, 16));
        eb_lbl_i = new QLabel(centralWidget);
        eb_lbl_i->setObjectName(QStringLiteral("eb_lbl_i"));
        eb_lbl_i->setGeometry(QRect(640, 280, 151, 16));
        img_w_lbl_i = new QLabel(centralWidget);
        img_w_lbl_i->setObjectName(QStringLiteral("img_w_lbl_i"));
        img_w_lbl_i->setGeometry(QRect(640, 310, 151, 16));
        img_h_lbl_i = new QLabel(centralWidget);
        img_h_lbl_i->setObjectName(QStringLiteral("img_h_lbl_i"));
        img_h_lbl_i->setGeometry(QRect(640, 320, 151, 16));
        img_c_lbl_i = new QLabel(centralWidget);
        img_c_lbl_i->setObjectName(QStringLiteral("img_c_lbl_i"));
        img_c_lbl_i->setGeometry(QRect(640, 330, 151, 16));
        img_d_lbl_i = new QLabel(centralWidget);
        img_d_lbl_i->setObjectName(QStringLiteral("img_d_lbl_i"));
        img_d_lbl_i->setGeometry(QRect(640, 340, 151, 16));
        img_t_lbl_i = new QLabel(centralWidget);
        img_t_lbl_i->setObjectName(QStringLiteral("img_t_lbl_i"));
        img_t_lbl_i->setGeometry(QRect(640, 350, 151, 16));
        nav_p_lbl_i = new QLabel(centralWidget);
        nav_p_lbl_i->setObjectName(QStringLiteral("nav_p_lbl_i"));
        nav_p_lbl_i->setGeometry(QRect(640, 380, 151, 16));
        nav_v_lbl_i = new QLabel(centralWidget);
        nav_v_lbl_i->setObjectName(QStringLiteral("nav_v_lbl_i"));
        nav_v_lbl_i->setGeometry(QRect(640, 390, 151, 16));
        OSVR_Controller_ViewerClass->setCentralWidget(centralWidget);
        pathTree->raise();
        refreshButton->raise();
        listView->raise();
        btn_lbl->raise();
        alg_lbl->raise();
        p_lbl->raise();
        p_t_lbl->raise();
        p_r_lbl->raise();
        v_lbl->raise();
        a_lbl->raise();
        dir_lbl->raise();
        loc_lbl->raise();
        et2d_lbl->raise();
        et3d_lbl->raise();
        v_a_lbl->raise();
        v_l_lbl->raise();
        a_a_lbl->raise();
        a_l_lbl->raise();
        et3d_bp_lbl->raise();
        et3d_dir_lbl->raise();
        eb_lbl->raise();
        img_lbl->raise();
        img_w_lbl->raise();
        img_h_lbl->raise();
        img_c_lbl->raise();
        img_d_lbl->raise();
        img_t_lbl->raise();
        nav_lbl->raise();
        nav_p_lbl->raise();
        nav_v_lbl->raise();
        btn_lbl_i->raise();
        alg_lbl_i->raise();
        p_t_lbl_i->raise();
        p_r_lbl_i->raise();
        v_a_lbl_i->raise();
        v_l_lbl_i->raise();
        a_a_lbl_i->raise();
        a_l_lbl_i->raise();
        dir_lbl_i->raise();
        loc_lbl_i->raise();
        et2d_lbl_i->raise();
        et3d_bp_lbl_i->raise();
        et3d_dir_lbl_i->raise();
        eb_lbl_i->raise();
        img_w_lbl_i->raise();
        img_h_lbl_i->raise();
        img_c_lbl_i->raise();
        img_d_lbl_i->raise();
        img_t_lbl_i->raise();
        nav_p_lbl_i->raise();
        nav_v_lbl_i->raise();

        retranslateUi(OSVR_Controller_ViewerClass);

        QMetaObject::connectSlotsByName(OSVR_Controller_ViewerClass);
    } // setupUi

    void retranslateUi(QMainWindow *OSVR_Controller_ViewerClass)
    {
        OSVR_Controller_ViewerClass->setWindowTitle(QApplication::translate("OSVR_Controller_ViewerClass", "OSVR Device Viewer", 0));
        QTreeWidgetItem *___qtreewidgetitem = pathTree->headerItem();
        ___qtreewidgetitem->setText(1, QApplication::translate("OSVR_Controller_ViewerClass", "Full Path", 0));
        refreshButton->setText(QApplication::translate("OSVR_Controller_ViewerClass", "Refresh Paths", 0));
        btn_lbl->setText(QApplication::translate("OSVR_Controller_ViewerClass", "<html><head/><body><p><span style=\" font-weight:600;\">Button</span></p></body></html>", 0));
        alg_lbl->setText(QApplication::translate("OSVR_Controller_ViewerClass", "<html><head/><body><p><span style=\" font-weight:600;\">Analog</span></p></body></html>", 0));
        p_lbl->setText(QApplication::translate("OSVR_Controller_ViewerClass", "<html><head/><body><p><span style=\" font-weight:600;\">Pose</span></p></body></html>", 0));
        p_t_lbl->setText(QApplication::translate("OSVR_Controller_ViewerClass", "<html><head/><body><p>&nbsp;&nbsp;Translation</p></body></html>", 0));
        p_r_lbl->setText(QApplication::translate("OSVR_Controller_ViewerClass", "<html><head/><body><p>&nbsp;&nbsp;Rotation</p></body></html>", 0));
        v_lbl->setText(QApplication::translate("OSVR_Controller_ViewerClass", "<html><head/><body><p><span style=\" font-weight:600;\">Velocity</span></p></body></html>", 0));
        a_lbl->setText(QApplication::translate("OSVR_Controller_ViewerClass", "<html><head/><body><p><span style=\" font-weight:600;\">Acceleration</span></p></body></html>", 0));
        dir_lbl->setText(QApplication::translate("OSVR_Controller_ViewerClass", "<html><head/><body><p><span style=\" font-weight:600;\">Direction</span></p></body></html>", 0));
        loc_lbl->setText(QApplication::translate("OSVR_Controller_ViewerClass", "<html><head/><body><p><span style=\" font-weight:600;\">Location</span></p></body></html>", 0));
        et2d_lbl->setText(QApplication::translate("OSVR_Controller_ViewerClass", "<html><head/><body><p><span style=\" font-weight:600;\">Eye Tracker 2D</span></p></body></html>", 0));
        et3d_lbl->setText(QApplication::translate("OSVR_Controller_ViewerClass", "<html><head/><body><p><span style=\" font-weight:600;\">Eye Tracker 3D</span></p></body></html>", 0));
        v_a_lbl->setText(QApplication::translate("OSVR_Controller_ViewerClass", "<html><head/><body><p>\302\240\302\240Angular</p></body></html>", 0));
        v_l_lbl->setText(QApplication::translate("OSVR_Controller_ViewerClass", "<html><head/><body><p>\302\240\302\240Linear</p></body></html>", 0));
        a_a_lbl->setText(QApplication::translate("OSVR_Controller_ViewerClass", "<html><head/><body><p>\302\240\302\240Angular</p></body></html>", 0));
        a_l_lbl->setText(QApplication::translate("OSVR_Controller_ViewerClass", "<html><head/><body><p>\302\240\302\240Linear</p></body></html>", 0));
        et3d_bp_lbl->setText(QApplication::translate("OSVR_Controller_ViewerClass", "<html><head/><body><p>\302\240\302\240Base Point</p></body></html>", 0));
        et3d_dir_lbl->setText(QApplication::translate("OSVR_Controller_ViewerClass", "<html><head/><body><p>\302\240\302\240Direction</p></body></html>", 0));
        eb_lbl->setText(QApplication::translate("OSVR_Controller_ViewerClass", "<html><head/><body><p><span style=\" font-weight:600;\">Eye Blink</span></p></body></html>", 0));
        img_lbl->setText(QApplication::translate("OSVR_Controller_ViewerClass", "<html><head/><body><p><span style=\" font-weight:600;\">Imaging</span></p></body></html>", 0));
        img_w_lbl->setText(QApplication::translate("OSVR_Controller_ViewerClass", "<html><head/><body><p>&nbsp;&nbsp;Width</p></body></html>", 0));
        img_h_lbl->setText(QApplication::translate("OSVR_Controller_ViewerClass", "<html><head/><body><p>\302\240\302\240Height</p></body></html>", 0));
        img_c_lbl->setText(QApplication::translate("OSVR_Controller_ViewerClass", "<html><head/><body><p>\302\240\302\240Channels</p></body></html>", 0));
        img_d_lbl->setText(QApplication::translate("OSVR_Controller_ViewerClass", "<html><head/><body><p>\302\240\302\240Depth</p></body></html>", 0));
        img_t_lbl->setText(QApplication::translate("OSVR_Controller_ViewerClass", "<html><head/><body><p>\302\240\302\240Type</p></body></html>", 0));
        nav_lbl->setText(QApplication::translate("OSVR_Controller_ViewerClass", "<html><head/><body><p><span style=\" font-weight:600;\">Navigation</span></p></body></html>", 0));
        nav_p_lbl->setText(QApplication::translate("OSVR_Controller_ViewerClass", "<html><head/><body><p>\302\240\302\240Position</p></body></html>", 0));
        nav_v_lbl->setText(QApplication::translate("OSVR_Controller_ViewerClass", "<html><head/><body><p>&nbsp;&nbsp;Velocity</p></body></html>", 0));
        btn_lbl_i->setText(QApplication::translate("OSVR_Controller_ViewerClass", "<html><head/><body><p>1</p></body></html>", 0));
        alg_lbl_i->setText(QApplication::translate("OSVR_Controller_ViewerClass", "<html><head/><body><p>1</p></body></html>", 0));
        p_t_lbl_i->setText(QApplication::translate("OSVR_Controller_ViewerClass", "<html><head/><body><p>1</p></body></html>", 0));
        p_r_lbl_i->setText(QApplication::translate("OSVR_Controller_ViewerClass", "<html><head/><body><p>1</p></body></html>", 0));
        v_a_lbl_i->setText(QApplication::translate("OSVR_Controller_ViewerClass", "<html><head/><body><p>1</p></body></html>", 0));
        v_l_lbl_i->setText(QApplication::translate("OSVR_Controller_ViewerClass", "<html><head/><body><p>1</p></body></html>", 0));
        a_a_lbl_i->setText(QApplication::translate("OSVR_Controller_ViewerClass", "<html><head/><body><p>1</p></body></html>", 0));
        a_l_lbl_i->setText(QApplication::translate("OSVR_Controller_ViewerClass", "<html><head/><body><p>1</p></body></html>", 0));
        dir_lbl_i->setText(QApplication::translate("OSVR_Controller_ViewerClass", "<html><head/><body><p>1</p></body></html>", 0));
        loc_lbl_i->setText(QApplication::translate("OSVR_Controller_ViewerClass", "<html><head/><body><p>1</p></body></html>", 0));
        et2d_lbl_i->setText(QApplication::translate("OSVR_Controller_ViewerClass", "<html><head/><body><p>1</p></body></html>", 0));
        et3d_bp_lbl_i->setText(QApplication::translate("OSVR_Controller_ViewerClass", "<html><head/><body><p>1</p></body></html>", 0));
        et3d_dir_lbl_i->setText(QApplication::translate("OSVR_Controller_ViewerClass", "<html><head/><body><p>1</p></body></html>", 0));
        eb_lbl_i->setText(QApplication::translate("OSVR_Controller_ViewerClass", "<html><head/><body><p>1</p></body></html>", 0));
        img_w_lbl_i->setText(QApplication::translate("OSVR_Controller_ViewerClass", "<html><head/><body><p>1</p></body></html>", 0));
        img_h_lbl_i->setText(QApplication::translate("OSVR_Controller_ViewerClass", "<html><head/><body><p>1</p></body></html>", 0));
        img_c_lbl_i->setText(QApplication::translate("OSVR_Controller_ViewerClass", "<html><head/><body><p>1</p></body></html>", 0));
        img_d_lbl_i->setText(QApplication::translate("OSVR_Controller_ViewerClass", "<html><head/><body><p>1</p></body></html>", 0));
        img_t_lbl_i->setText(QApplication::translate("OSVR_Controller_ViewerClass", "<html><head/><body><p>1</p></body></html>", 0));
        nav_p_lbl_i->setText(QApplication::translate("OSVR_Controller_ViewerClass", "<html><head/><body><p>1</p></body></html>", 0));
        nav_v_lbl_i->setText(QApplication::translate("OSVR_Controller_ViewerClass", "<html><head/><body><p>1</p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class OSVR_Controller_ViewerClass: public Ui_OSVR_Controller_ViewerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OSVR_CONTROLLER_VIEWER_H
