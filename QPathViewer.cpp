#include "QPathViewer.h"



QPathViewer::QPathViewer(QWidget* parent) :QTreeWidget(parent)
{
}


QPathViewer::~QPathViewer()
{
}

void QPathViewer::update_interface_elements() {
	clear();
	interface_lock_ptr->lock();
	for (int i = 0; i < interface_elements_ptr->size(); i++) {
		QTreeWidgetItem* top_level_item = new QTreeWidgetItem(this);
		interface_element* elem = &interface_elements_ptr->at(i);
		std::string display_name = elem->get_full_path();
		std::string type_name;
		switch (elem->type) {
		case interface_type::interface_alias:
			type_name = "Alias";
			break;
		case interface_type::interface_device:
			type_name = "Device";
			break;
		case interface_type::interface_null:
			type_name = "Null";
			break;
		default:
			type_name = "Unknown";
		}
		top_level_item->setText(0, type_name.c_str());
		top_level_item->setText(1, display_name.c_str());
		QTreeWidget::addTopLevelItem(top_level_item);
	}
	interface_lock_ptr->unlock();
}

void QPathViewer::set_path_ptr(std::vector<interface_element>* i_elems_ptr, std::mutex* i_lock_ptr) {
	interface_elements_ptr = i_elems_ptr;
	interface_lock_ptr = i_lock_ptr;
}