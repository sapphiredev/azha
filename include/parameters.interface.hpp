#ifndef __PARAMETERS_INTERFACE_H__
#define __PARAMETERS_INTERFACE_H__

#include <unordered_map>
#include <string>

namespace azha {
	namespace parameters {
		typedef std::unordered_map<std::string, std::string> RequestParams;

		enum class RequestMethod {
			GET,
			POST
		};

		class ITwitterParameters {
		public:
			virtual const RequestMethod &request_method() const = 0;
			virtual const std::string &url() const = 0;

			RequestParams parameters;
		};
	}
}

#endif // __PARAMETERS_INTERFACE_H__
