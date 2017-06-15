#include "path_tree_iterator.h"



path_tree_iterator::path_tree_iterator()
{
}


path_tree_iterator::~path_tree_iterator()
{
}

void path_tree_iterator::operator()(osvr::common::PathNode const &node, osvr::common::elements::NullElement const &elem) {
	interface_element null_interface;
	std::string alias_path = node.getName();
	osvr::common::PathNode* n_node = node.getParent();

	while (n_node != nullptr) {
		alias_path = std::string(n_node->getName()) + '/' + alias_path; // yuck
		n_node = n_node->getParent();
	}
	null_interface.type = interface_type::interface_null;
	null_interface.full_path = alias_path;
	interfaces.push_back(null_interface);
}

void path_tree_iterator::operator()(osvr::common::PathNode const &node, osvr::common::elements::AliasElement const &elem) {
	interface_element alias_interface;
	std::string alias_path = node.getName();
	osvr::common::PathNode* n_node = node.getParent();

	while (n_node != nullptr) {
		alias_path = std::string(n_node->getName()) + '/' + alias_path; // yuck
		n_node = n_node->getParent();
	}
	alias_interface.type = interface_type::interface_alias;
	alias_interface.full_path = alias_path;
	interfaces.push_back(alias_interface);
}

void path_tree_iterator::operator()(osvr::common::PathNode const &node, osvr::common::elements::DeviceElement const &elem) {
	interface_element device_interface;
	std::string alias_path = node.getName();
	osvr::common::PathNode* n_node = node.getParent();

	while (n_node != nullptr) {
		alias_path = std::string(n_node->getName()) + '/' + alias_path; // yuck
		n_node = n_node->getParent();
	}
	device_interface.type = interface_type::interface_device;
	device_interface.full_path = alias_path;
	interfaces.push_back(device_interface);
}
