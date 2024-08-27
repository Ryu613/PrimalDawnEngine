#include "json_util.hpp"
#include <boost/fusion/include/for_each.hpp>
#include <boost/fusion/include/adapt_struct.hpp>
 
namespace PrimalDawn {
	template<typename T>
	void JsonUtil::deserialize(T& obj, const json::object& jsonObj) {
		boost::fusion::for_each(obj, [&](auto& field) {
			auto fieldName = boost::fusion::extension::struct_member_name<T, &field>::call();
			if (jsonObj.contains(fieldName)) {
				field = json::value_to<std::decay_t<decltype(field)>>(jsonObj.at(fieldName));
			}
		});
	}
}