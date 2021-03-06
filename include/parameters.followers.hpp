#ifndef __PARAMETERS_FOLLOWERS_H__
#define __PARAMETERS_FOLLOWERS_H__

#include "parameters.interface.hpp"

namespace azha {
	namespace parameters {
		namespace GET {
			namespace Followers {
				class IdsParameters : public ITwitterParameters {
				public:
					INIT(IdsParameters)
					METHOD(RequestMethod::GET)
					URL("https://api.twitter.com/1.1/followers/ids.json")

					PARAMETER(uint64_t, user_id)
					PARAMETER(std::string, screen_name)
					PARAMETER(uint64_t, cursor)
					PARAMETER(bool, stringify_ids)
					PARAMETER(uint64_t, count)
				};
				
				class ListParameters : public ITwitterParameters {
				public:
					INIT(ListParameters)
					METHOD(RequestMethod::GET)
					URL("https://api.twitter.com/1.1/followers/list.json")

					PARAMETER(uint64_t, user_id)
					PARAMETER(std::string, screen_name)
					PARAMETER(uint64_t, cursor)
					PARAMETER(uint64_t, count)
					PARAMETER(bool, skip_status)
					PARAMETER(bool, include_user_entities)
				};
			}
		}
	}
}

#endif // __PARAMETERS_FOLLOWERS_H__
