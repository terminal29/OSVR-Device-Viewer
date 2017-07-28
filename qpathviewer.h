#pragma once
#include <QtWidgets/qtreewidget.h>
#include <vector>
#include <mutex>
#include <utility>
#include <string>
#include <osvr/ClientKit/ClientKit.h>
#include <sstream>
#include "interface_element.h"

class QPathViewer : public QTreeWidget
{
	Q_OBJECT
public:
	QPathViewer(QWidget* parent);
	~QPathViewer();
	void set_path_ptr(std::vector<interface_element>* i_elems_ptr, std::mutex* i_lock_ptr);
	
private:
	std::vector<interface_element>* interface_elements_ptr = nullptr;
	std::mutex* interface_lock_ptr;

private slots:
	void update_interface_elements();

};

