#pragma once
#include <osvr/Common/PathNode.h>
#include <osvr/Common/PathTreeFull.h>
#include <osvr/Common/PathElementTypes.h>
#include <vector>
#include <string>
#include <utility>
#include <sstream>
#include "interface_element.h"

class path_tree_iterator : public boost::static_visitor<>, boost::noncopyable
{
public:
	path_tree_iterator();
	~path_tree_iterator();

	void operator()(osvr::common::PathNode const &node, osvr::common::elements::NullElement const &elem);
	void operator()(osvr::common::PathNode const &node, osvr::common::elements::AliasElement const &elem);
	void operator()(osvr::common::PathNode const &node, osvr::common::elements::DeviceElement const &elem);
	template <typename T> void operator()(osvr::common::PathNode const &node, T const &elem) {};

	std::vector<interface_element> interfaces;

};

