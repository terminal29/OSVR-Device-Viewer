#pragma once
#include <string>
namespace interface_type {
	enum interface_type {
		interface_null,
		interface_alias,
		interface_device
	};
}

class interface_element
{
public:
	interface_element();
	~interface_element();
	std::string get_full_path();

	interface_type::interface_type type = interface_type::interface_null;
	std::string full_path = "/nil/";
};

