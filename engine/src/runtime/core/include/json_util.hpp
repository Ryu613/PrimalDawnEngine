#pragma once

#include <boost/json.hpp>

namespace json = boost::json;

namespace PrimalDawn {
	class JsonUtil {
	public:
		template<typename T>
		void deserialize(T& obj, const json::object& jsonObj);
	};
}