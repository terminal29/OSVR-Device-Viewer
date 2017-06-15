#include "osvr_controller_viewer.h"

OSVR_Controller_Viewer::OSVR_Controller_Viewer(QWidget *parent) : QMainWindow(parent)
{
	ui.setupUi(this);
	connect(ui.refreshButton, SIGNAL(clicked()),ui.pathTree, SLOT(update_interface_elements()));
	connect(ui.pathTree, SIGNAL(currentItemChanged(QTreeWidgetItem*, QTreeWidgetItem*)), this, SLOT(update_interface_details(QTreeWidgetItem*)));
	QTimer* update_timer = new QTimer(this);
	update_timer->setInterval(200);
	update_timer->setSingleShot(false);
	connect(update_timer, SIGNAL(timeout()), this, SLOT(update_details_box()));
	update_timer->start();

}

OSVR_Controller_Viewer::~OSVR_Controller_Viewer()
{

}

Ui::OSVR_Controller_ViewerClass* OSVR_Controller_Viewer::get_Ui() {
	return &ui;
}

void OSVR_Controller_Viewer::update_interface_details(QTreeWidgetItem* widget) {
	if (widget != nullptr) {
		last_tree_item = *widget;
	}
	else {
		last_tree_item = QTreeWidgetItem();
	}
}

void OSVR_Controller_Viewer::set_osvr_ctx_ptr(osvr::clientkit::ClientContext* ctx, std::mutex* ctx_lock) {
	OSVR_Controller_Viewer::ctx = ctx;
	OSVR_Controller_Viewer::ctx_lock = ctx_lock;
}

void OSVR_Controller_Viewer::update_details_box() {
	if (ctx_lock == nullptr || ctx == nullptr ) {
		return;
	}
	QTextBrowser* text_browser = ui.textBrowser;
	if (last_tree_item.text(1).toStdString().length() < 1) {
		text_browser->setHtml("");
		return;
	}
	ctx_lock->lock();

	osvr::clientkit::Interface iface = ctx->getInterface(last_tree_item.text(1).toStdString());
	OSVR_PoseState pose;
	osvr::common::traits::StateFromReport_t<OSVR_PoseReport> p_r;
	// help

	text_browser->setHtml(last_tree_item.text(1));
	ctx_lock->unlock();
}


