#include "osvr_controller_viewer.h"

OSVR_Controller_Viewer::OSVR_Controller_Viewer(QWidget *parent) : QMainWindow(parent)
{
	ui.setupUi(this);
	connect(ui.refreshButton, SIGNAL(clicked()),ui.pathTree, SLOT(update_interface_elements()));
	connect(ui.pathTree, SIGNAL(currentItemChanged(QTreeWidgetItem*, QTreeWidgetItem*)), this, SLOT(update_interface_details(QTreeWidgetItem*)));
	QTimer* update_timer = new QTimer(this);
	update_timer->setInterval(50);
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
	global_states::reset_all();
	if (widget != nullptr) {
		last_tree_item = *widget;
	}
	else {
		last_tree_item = QTreeWidgetItem();
	}

	ctx_lock->lock();
	if (clear_old_interface) {
		osvr_interface.free();
	}
	try {
		osvr_interface = ctx->getInterface(last_tree_item.text(1).toStdString().c_str());
	}
	catch (std::runtime_error err) {
		//Bad path
		ctx_lock->unlock();
		clear_old_interface = false;
		return;
	}
	clear_old_interface = true;
	ctx_lock->unlock();
	osvr_interface.registerCallback(&global_states::button_callback, NULL);
	osvr_interface.registerCallback(&global_states::analog_callback, NULL);
	osvr_interface.registerCallback(&global_states::acceleration_callback, NULL);
	osvr_interface.registerCallback(&global_states::direction_callback, NULL);
	osvr_interface.registerCallback(&global_states::eye_tracker_2d_callback, NULL);
	osvr_interface.registerCallback(&global_states::eye_tracker_3d_callback, NULL);
	osvr_interface.registerCallback(&global_states::eye_tracker_blink_callback, NULL);
	osvr_interface.registerCallback(&global_states::imaging_callback, NULL);
	osvr_interface.registerCallback(&global_states::location_2d_callback, NULL);
	osvr_interface.registerCallback(&global_states::navi_position_callback, NULL);
	osvr_interface.registerCallback(&global_states::navi_velocity_callback, NULL);
	osvr_interface.registerCallback(&global_states::pose_callback, NULL);
	osvr_interface.registerCallback(&global_states::velocity_callback, NULL);



}

void OSVR_Controller_Viewer::set_osvr_ctx_ptr(osvr::clientkit::ClientContext* ctx, std::mutex* ctx_lock) {
	OSVR_Controller_Viewer::ctx = ctx;
	OSVR_Controller_Viewer::ctx_lock = ctx_lock;
}

float truncate(float val, int nums) {
	return round((val*pow(10, nums))) / pow(10, nums);
}

void OSVR_Controller_Viewer::update_details_box() {

	std::stringstream d_str;
	d_str.precision(3);

	d_str << (global_states::btn_s == OSVR_BUTTON_PRESSED ? "down" : "up");
	ui.btn_lbl_i->setText(d_str.str().c_str());
	d_str.str("");
	
	d_str << global_states::alg_s;
	ui.alg_lbl_i->setText(d_str.str().c_str());
	d_str.str("");

	d_str << '[' << truncate(global_states::p_s.translation.data[0], 2) << ',' << truncate(global_states::p_s.translation.data[1], 2) << ',' << truncate(global_states::p_s.translation.data[2], 2) << ']';
	ui.p_t_lbl_i->setText(d_str.str().c_str());
	d_str.str("");

	d_str << '[' << truncate(global_states::p_s.rotation.data[0], 2) << ',' << truncate(global_states::p_s.rotation.data[1], 2) << ',' << truncate(global_states::p_s.rotation.data[2], 2) << ',' << truncate(global_states::p_s.rotation.data[3], 2) << ']';
	ui.p_r_lbl_i->setText(d_str.str().c_str());
	d_str.str("");

	d_str << '[' << truncate(global_states::v_s.angularVelocity.dt, 2) << "],[" << truncate(global_states::v_s.angularVelocity.incrementalRotation.data[0], 2) << ',' << truncate(global_states::v_s.angularVelocity.incrementalRotation.data[1], 2) << ',' << truncate(global_states::v_s.angularVelocity.incrementalRotation.data[2], 2) << ',' << truncate(global_states::v_s.angularVelocity.incrementalRotation.data[3], 2) << ']';
	ui.v_a_lbl_i->setText(d_str.str().c_str());
	d_str.str("");

	d_str << '[' << truncate(global_states::v_s.linearVelocity.data[0], 2) << ',' << truncate(global_states::v_s.linearVelocity.data[1], 2) << ',' << truncate(global_states::v_s.linearVelocity.data[2], 2) << ']';
	ui.v_l_lbl_i->setText(d_str.str().c_str());
	d_str.str("");

	d_str << '[' << truncate(global_states::acc_s.angularAcceleration.dt, 2) << "],[" << truncate(global_states::acc_s.angularAcceleration.incrementalRotation.data[0], 2) << ',' << truncate(global_states::acc_s.angularAcceleration.incrementalRotation.data[1], 2) << ',' << truncate(global_states::acc_s.angularAcceleration.incrementalRotation.data[2], 2) << ',' << truncate(global_states::acc_s.angularAcceleration.incrementalRotation.data[3], 2) << ']';
	ui.a_a_lbl_i->setText(d_str.str().c_str());
	d_str.str("");

	d_str << '[' << truncate(global_states::acc_s.linearAcceleration.data[0], 2) << ',' << truncate(global_states::acc_s.linearAcceleration.data[1], 2) << ',' << truncate(global_states::acc_s.linearAcceleration.data[2], 2) << ']';
	ui.a_l_lbl_i->setText(d_str.str().c_str());
	d_str.str("");

	d_str << '[' << truncate(global_states::dir_s.data[0], 2) << ',' << truncate(global_states::dir_s.data[1], 2) << ',' << truncate(global_states::dir_s.data[2], 2) << ']';
	ui.dir_lbl_i->setText(d_str.str().c_str());
	d_str.str("");

	d_str << '[' << truncate(global_states::l2d_s.data[0], 2) << ',' << truncate(global_states::l2d_s.data[1], 2) << ']';
	ui.loc_lbl_i->setText(d_str.str().c_str());
	d_str.str("");
	
	d_str << '[' << truncate(global_states::et2d_s.data[0], 2) << ',' << truncate(global_states::et2d_s.data[1], 2) << ']';
	ui.et2d_lbl_i->setText(d_str.str().c_str());
	d_str.str("");

	d_str << '[' << truncate(global_states::et3d_s.basePoint.data[0], 2) << ',' << truncate(global_states::et3d_s.basePoint.data[1], 2) << ',' << truncate(global_states::et3d_s.basePoint.data[1], 2) << ']';
	ui.et3d_bp_lbl_i->setText(d_str.str().c_str());
	d_str.str("");
	
	d_str << '[' << truncate(global_states::et3d_s.direction.data[0], 2) << ',' << truncate(global_states::et3d_s.direction.data[1], 2) << ',' << truncate(global_states::et3d_s.direction.data[1], 2) << ']';
	ui.et3d_dir_lbl_i->setText(d_str.str().c_str());
	d_str.str("");

	d_str << (global_states::etb_s == OSVR_EYE_BLINK ? "closed" : "open");
	ui.eb_lbl_i->setText(d_str.str().c_str());
	d_str.str("");

	d_str << global_states::img_s.metadata.width;
	ui.img_w_lbl_i->setText(d_str.str().c_str());
	d_str.str("");

	d_str << global_states::img_s.metadata.height;
	ui.img_h_lbl_i->setText(d_str.str().c_str());
	d_str.str("");

	d_str << (int)global_states::img_s.metadata.channels;
	ui.img_c_lbl_i->setText(d_str.str().c_str());
	d_str.str("");

	d_str << (int)global_states::img_s.metadata.depth;
	ui.img_d_lbl_i->setText(d_str.str().c_str());
	d_str.str("");

	d_str << (global_states::img_s.metadata.type == OSVR_IVT_UNSIGNED_INT ? "unsigned int" : (global_states::img_s.metadata.type == OSVR_IVT_SIGNED_INT ? "int" : "float"));
	ui.img_t_lbl_i->setText(d_str.str().c_str());
	d_str.str("");

	d_str << '[' << truncate(global_states::npos_s.data[0], 2) << ',' << truncate(global_states::npos_s.data[1], 2) << ']';
	ui.nav_p_lbl_i->setText(d_str.str().c_str());
	d_str.str("");

	d_str << '[' << truncate(global_states::nvel_s.data[0], 2) << ',' << truncate(global_states::nvel_s.data[1], 2) << ']';
	ui.nav_v_lbl_i->setText(d_str.str().c_str());
	d_str.str("");

}


