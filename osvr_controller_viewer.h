#ifndef OSVR_CONTROLLER_VIEWER_H
#define OSVR_CONTROLLER_VIEWER_H

#include <QtWidgets/QMainWindow>
#include "ui_osvr_controller_viewer.h"
#include <string>
#include <sstream>
#include <osvr/clientkit/context.h>
#include <osvr/clientkit/ClientKit.h>
#include <osvr/ClientKit/Interface.h>
#include <osvr/common/clientContext.h>
#include <osvr/common/ClientInterfacePtr.h>
#include <osvr/common/ClientInterface.h>
#include <osvr/Common/ReportTypes.h>
#include <mutex>
#include <qtimer.h>

class OSVR_Controller_Viewer : public QMainWindow
{
	Q_OBJECT

public:
	OSVR_Controller_Viewer(QWidget *parent = 0);
	~OSVR_Controller_Viewer();
	Ui::OSVR_Controller_ViewerClass* get_Ui();
	Ui::OSVR_Controller_ViewerClass ui;
	void set_osvr_ctx_ptr(osvr::clientkit::ClientContext* ctx, std::mutex* ctx_lock);

private:
	bool keep_updating = false;
	bool last_thread_running = false;
	osvr::clientkit::ClientContext* ctx = nullptr;
	std::mutex* ctx_lock = nullptr;
	QTreeWidgetItem last_tree_item;

public slots:
void update_interface_details(QTreeWidgetItem* tree_elem_ptr);
void update_details_box();

};

#endif // OSVR_CONTROLLER_VIEWER_H
