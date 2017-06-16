// Standard Includes
#include <iostream>
#include <string>
#include <thread>
#include <vector>
#include <mutex>

// 3rd Party / Library Includes
#include <osvr/ClientKit/ClientKit.h>
#include <osvr/Common/ClientContext.h>
#include <osvr/Common/PathNode.h>
#include <osvr/Common/PathTreeFull.h>
#include <osvr/Common/ApplyPathNodeVisitor.h>
#include <osvr/ClientKit/Interface.h>
#include <osvr/Util/TreeTraversalVisitor.h>
#include <QtWidgets/QApplication>
#include <Windows.h>

// 1st Party Includes
#include "osvr_controller_viewer.h"
#include "path_tree_iterator.h"
#include "interface_element.h"

static std::mutex value_lock;
static std::vector<interface_element> interface_values;

OSVR_Controller_Viewer* w;

const char* app_id = "OSVR_Controller_Viewer";

osvr::clientkit::ClientContext ctx(app_id, 0);
std::mutex ctx_lock;

osvr::common::PathTree osvr_path_tree;

osvr::clientkit::Interface* current_interface = nullptr;

bool thread_close = false;
bool connected = false;

void update_path_values() {
	std::vector<std::pair<std::string, bool>> temp_button_values;

	osvr::common::clonePathTree(ctx.get()->getPathTree(), osvr_path_tree);

	path_tree_iterator p_tree_iter;

	osvr::util::traverseWith(osvr_path_tree.getRoot(),
		[&p_tree_iter](osvr::common::PathNode &node) {
		osvr::common::applyPathNodeVisitor(p_tree_iter, node);
	});

	value_lock.lock();
	interface_values = p_tree_iter.interfaces;
	value_lock.unlock();
}

void init_context() {
	if (!ctx.checkStatus()) {
		do {
			std::this_thread::sleep_for(std::chrono::milliseconds(200));
			ctx.update();
		} while (!ctx.checkStatus());
	}
}

void osvr_connect() {
	while (!thread_close) {
		ctx_lock.lock();
		if (!ctx.checkStatus()) {
			init_context();
		}
		ctx.update();
		update_path_values();
		ctx_lock.unlock();
		std::this_thread::sleep_for(std::chrono::milliseconds(10));
	}
}



int main(int argc, char *argv[])
{
	std::thread osvr_connection_thread = std::thread(osvr_connect);
	QApplication a(argc, argv);
	w = new OSVR_Controller_Viewer();
	Ui_OSVR_Controller_ViewerClass* ui = w->get_Ui();
	ui->pathTree->set_path_ptr(&interface_values, &value_lock);
	w->set_osvr_ctx_ptr(&ctx, &ctx_lock);
	w->show();
	int exec_res = a.exec();
	thread_close = true;
	osvr_connection_thread.join();
	return exec_res;
}
