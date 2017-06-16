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

void OSVR_Controller_Viewer::update_details_box() {

	QTextBrowser* text_browser = ui.textBrowser;
	std::stringstream html_data;
	html_data << "<style> .con{width:100%;table-size:fixed;} table tr td{max-width:50%;word-break:break-all;} .f{height: 40px; font-size:7pt;} .n{ font-weight:bold;} .c{  }</style>";
	html_data << "<table class='con' cellspacing='0' cellpadding='0' width='100%'>";
	
	html_data << "<tr class='f'><td width='50%' class='n c'>Button</td><td width='50%' class='c'>" << (global_states::btn_s ==  OSVR_BUTTON_PRESSED ? "Down" : "Up") << "</td></tr>";
	
	html_data << "<tr class='f'><td width='50%' class='n c'>Analog</td><td width='50%' class='c'>" << global_states::alg_s << "</td></tr>";

	html_data << "<tr class='f'><td width='50%' class='n c'>Pose</td><td width='50%' class='c'></td></tr>";

	html_data << "<tr class='f'><td width='50%' class='c'>&nbsp;Translation</td><td width='50%' class='c'> [" << std::setprecision(3) << global_states::p_s.translation.data[0] << ',' << global_states::p_s.translation.data[1] << ',' << global_states::p_s.translation.data[2] << std::setprecision(6) << "]</td></tr>";

	html_data << "<tr class='f'><td width='50%' class='c'>&nbsp;Rotation</td><td width='50%' class='c'> [" << std::setprecision(3) << global_states::p_s.rotation.data[0] << ',' << global_states::p_s.rotation.data[1] << ',' << global_states::p_s.rotation.data[2] << ',' << global_states::p_s.rotation.data[3] << std::setprecision(6) <<  "]</td></tr>";

	html_data << "<tr class='f'><td width='50%' class='n c'>Velocity</td><td width='50%' class='c'></td></tr>";

	html_data << "<tr class='f'><td width='50%' class='c'>&nbsp;Angular</td><td width='50%' class='c'>[" << std::setprecision(3) << global_states::v_s.angularVelocity.dt << "],[" << global_states::v_s.angularVelocity.incrementalRotation.data[0] << ',' << global_states::v_s.angularVelocity.incrementalRotation.data[1] << ',' << global_states::v_s.angularVelocity.incrementalRotation.data[2] << ',' << global_states::v_s.angularVelocity.incrementalRotation.data[3] << std::setprecision(6) << "]</td></tr>";

	html_data << "<tr class='f'><td width='50%' class='c'>&nbsp;Linear</td><td width='50%' class='c'>[" << std::setprecision(3) << global_states::v_s.linearVelocity.data[0] << ',' << global_states::v_s.linearVelocity.data[1] << ',' << global_states::v_s.linearVelocity.data[2] << "]</td></tr>";

	html_data << "<tr class='f'><td width='50%' class='n c'>Acceleration</td><td width='50%' class='c'></td></tr>";

	html_data << "<tr class='f'><td width='50%' class='c'>&nbsp;Angular</td><td width='50%' class='c'>[" << std::setprecision(3) << global_states::acc_s.angularAcceleration.dt << "],[" << global_states::acc_s.angularAcceleration.incrementalRotation.data[0] << ',' << global_states::acc_s.angularAcceleration.incrementalRotation.data[1] << ',' << global_states::acc_s.angularAcceleration.incrementalRotation.data[2] << ',' << global_states::acc_s.angularAcceleration.incrementalRotation.data[3] << std::setprecision(6) << "]</td></tr>";

	html_data << "<tr class='f'><td width='50%' class='c'>&nbsp;Linear</td><td width='50%' class='c'>[" << std::setprecision(3) << global_states::acc_s.linearAcceleration.data[0] << ',' << global_states::acc_s.linearAcceleration.data[1] << ',' << global_states::acc_s.linearAcceleration.data[2] << std::setprecision(6) << "]</td></tr>";
	
	html_data << "<tr class='f'><td width='50%' class='n c'>Direction</td><td width='50%' class='c'>[" << std::setprecision(3) << global_states::dir_s.data[0] << ',' << global_states::dir_s.data[1] << ',' << global_states::dir_s.data[2] << std::setprecision(6) <<  "]</td></tr>";

	html_data << "<tr class='f'><td width='50%' class='n c'>Location</td><td width='50%' class='c'>[" << std::setprecision(3) << global_states::l2d_s.data[0] << ',' << global_states::l2d_s.data[1] << std::setprecision(6) << "]</td></tr>";

	html_data << "<tr class='f'><td width='50%' class='n c'>Eye Tracker 2D</td><td width='50%' class='c'>[" << std::setprecision(3) << global_states::et2d_s.data[0] << ',' << global_states::et2d_s.data[1] << std::setprecision(6) << "]</td></tr>";

	html_data << "<tr class='f'><td width='50%' class='n c'>Eye Tracker 3D</td><td width='50%' class='c'></td></tr>";

	html_data << "<tr class='f'><td width='50%' class='c'>&nbsp;Base Point</td><td width='50%' class='c'>[" << std::setprecision(3) << global_states::et3d_s.basePoint.data[0] << ',' << global_states::et3d_s.basePoint.data[1] << ',' << global_states::et3d_s.basePoint.data[2] << std::setprecision(6) << "]</td></tr>";

	html_data << "<tr class='f'><td width='50%' class='c'>&nbsp;Direction</td><td width='50%' class='c'>[" << std::setprecision(3) << global_states::et3d_s.direction.data[0] << ',' << global_states::et3d_s.direction.data[1] << ',' << global_states::et3d_s.direction.data[2] << std::setprecision(6) << "]</td></tr>";

	html_data << "<tr class='f'><td width='50%' class='n c'>Eye Blink</td><td width='50%' class='c'>" << (global_states::etb_s == OSVR_BUTTON_PRESSED ? "Closed" : "Open") << "</td></tr>";

	html_data << "<tr class='f'><td width='50%' class='n c'>Imaging</td><td width='50%' class='c'></td></tr>";

	html_data << "<tr class='f'><td width='50%' class='c'>&nbsp;Width</td><td width='50%' class='c'>" << global_states::img_s.metadata.width << "</td></tr>";
	
	html_data << "<tr class='f'><td width='50%' class='c'>&nbsp;Height</td><td width='50%' class='c'>" << global_states::img_s.metadata.height << "</td></tr>";

	html_data << "<tr class='f'><td width='50%' class='c'>&nbsp;Channels</td><td width='50%' class='c'>" << (int)global_states::img_s.metadata.channels << "</td></tr>";
	
	html_data << "<tr class='f'><td width='50%' class='c'>&nbsp;Depth</td><td width='50%' class='c'>" << (int)global_states::img_s.metadata.depth << "</td></tr>";
	
	html_data << "<tr class='f'><td width='50%' class='c'>&nbsp;Type</td><td width='50%' class='c'>" << (global_states::img_s.metadata.type == OSVR_IVT_UNSIGNED_INT ? "unsigned int" : (global_states::img_s.metadata.type == OSVR_IVT_SIGNED_INT ? "int" : "float")) << "</td></tr>";
	
	html_data << "<tr class='f'><td width='50%' class='n c'>Navigation</td><td width='50%' class='c'></td></tr>";

	html_data << "<tr class='f'><td width='50%' class='c'>&nbsp;Position</td><td width='50%' class='c'>[" << std::setprecision(3) << global_states::npos_s.data[0] << ',' << global_states::npos_s.data[1] << std::setprecision(6) << "]</td></tr>";

	html_data << "<tr class='f'><td width='50%' class='c'>&nbsp;Velocity</td><td width='50%' class='c'>[" << std::setprecision(3) << global_states::nvel_s.data[0] << ',' << global_states::nvel_s.data[1] << std::setprecision(6) << "]</td></tr>";

	html_data << "</table>";

	text_browser->setHtml(html_data.str().c_str());
}


