#ifndef __PARAMETERS_H__
#define __PARAMETERS_H__

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
		
		namespace OAuth {
			class RequestTokenParameters : public ITwitterParameters {
			public:
				const RequestMethod &request_method() const {
					static const RequestMethod _request_method = RequestMethod::POST;
					return _request_method;
				}
				const std::string &url() const {
					static const std::string _url = "https://api.twitter.com/oauth/request_token";
					return _url;
				}
				
				RequestTokenParameters& oauth_callback(const std::string &_oauth_callback) {
					parameters["oauth_callback"] = _oauth_callback;
					return *this;
				}
				RequestTokenParameters& x_auth_access_type(const std::string &_x_auth_access_type) {
					parameters["x_auth_access_type"] = _x_auth_access_type;
					return *this;
				}
				
				const std::string& oauth_callback() {
					return parameters["oauth_callback"];
				}
				const std::string& x_auth_access_type() {
					return parameters["x_auth_access_type"];
				}
			};
			
			class AccessTokenParameters : public ITwitterParameters {
			public:
				const RequestMethod& request_method() const {
					static const RequestMethod _request_method = RequestMethod::POST;
					return _request_method;
				}
				const std::string& url() const {
					static const std::string _url = "https://api.twitter.com/oauth/access_token";
					return _url;
				}
				
				AccessTokenParameters& x_auth_password(const std::string &_x_auth_password) {
					parameters["x_auth_password"] = _x_auth_password;
					return *this;
				}
				AccessTokenParameters& x_auth_username(const std::string &_x_auth_username) {
					parameters["x_auth_username"] = _x_auth_username;
					return *this;
				}
				AccessTokenParameters& x_auth_mode(const std::string &_x_auth_mode) {
					parameters["x_auth_mode"] = _x_auth_mode;
					return *this;
				}
				AccessTokenParameters& oauth_verifier(const std::string &_oauth_verifier) {
					parameters["oauth_verifier"] = _oauth_verifier;
					return *this;
				}
				
				const std::string& x_auth_password() {
					return parameters["x_auth_password"];
				}
				const std::string& x_auth_username() {
					return parameters["x_auth_username"];
				}
				const std::string& x_auth_mode() {
					return parameters["x_auth_mode"];
				}
				const std::string& oauth_verifier() {
					return parameters["oauth_verifier"];
				}
			};
		}
		
		namespace Statuses {
			class MentionsTimelineParameters : public ITwitterParameters {
			public:
				const RequestMethod& request_method() const {
					static const RequestMethod _request_method = RequestMethod::GET;
					return _request_method;
				}
				const std::string& url() const {
					static const std::string _url = "";
					return _url;
				}
				
				MentionsTimelineParameters& count(const uint64_t _count) {
					parameters["count"] = std::to_string(_count);
					return *this;
				}
				MentionsTimelineParameters& since_id(const uint64_t _since_id) {
					parameters["since_id"] = std::to_string(_since_id);
					return *this;
				}
				MentionsTimelineParameters& max_id(const uint64_t _max_id) {
					parameters["max_id"] = std::to_string(_max_id);
					return *this;
				}
				MentionsTimelineParameters& trim_user(const bool _trim_user) {
					parameters["trim_user"] = _trim_user ? "true" : "false";
					return *this;
				}
				MentionsTimelineParameters& contributor_details(const bool _contributor_details) {
					parameters["contributor_details"] = _contributor_details ? "true" : "false";
					return *this;
				}
				MentionsTimelineParameters& include_entities(const bool _include_entities) {
					parameters["include_entities"] = _include_entities ? "true" : "false";
					return *this;
				}
				
				const uint64_t count() {
					return std::stoull(parameters["count"]);
				}
				const uint64_t since_id() {
					return std::stoull(parameters["since_id"]);
				}
				const uint64_t max_id() {
					return std::stoull(parameters["max_id"]);
				}
				const bool trim_user() {
					return (parameters["trim_user"] == "true");
				}
				const bool contributor_details() {
					return (parameters["contributor_details"] == "true");
				}
				const bool include_entities() {
					return (parameters["include_entities"] == "true");
				}
			};
			
			class UpdateParameters : public ITwitterParameters {
			public:
				const RequestMethod& request_method() const {
					static const RequestMethod _request_method = RequestMethod::POST;
					return _request_method;
				}
				const std::string& url() const {
					static const std::string _url = "https://api.twitter.com/1.1/statuses/update.json";
					return _url;
				}
				
				UpdateParameters& status(const std::string &_status) {
					parameters["status"] = _status;
					return *this;
				}
				UpdateParameters& in_reply_to_status_id(const uint64_t _in_reply_to_status_id) {
					parameters["in_reply_to_status_id"] = std::to_string(_in_reply_to_status_id);
					return *this;
				}
				UpdateParameters& possibly_sensitive(const bool _possibly_sensitive) {
					parameters["possibly_sensitive"] = _possibly_sensitive ? "true" : "false";
					return *this;
				}
				UpdateParameters& lat(const double _lat) {
					parameters["lat"] = std::to_string(_lat);
					return *this;
				}
				UpdateParameters& lng(const double _lng) {
					parameters["long"] = std::to_string(_lng);
					return *this;
				}
				UpdateParameters& place_id(const std::string &_place_id) {
					parameters["place_id"] = _place_id;
					return *this;
				}
				UpdateParameters& display_coordinates(const bool _display_coordinates) {
					parameters["display_coordinates"] = _display_coordinates ? "true" : "false";
					return *this;
				}
				UpdateParameters& trim_user(const bool _trim_user) {
					parameters["trim_user"] = _trim_user ? "true" : "false";
					return *this;
				}
				UpdateParameters& media_ids(const uint64_t _media_ids) {
					parameters["media_ids"] = std::to_string(_media_ids);
					return *this;
				}
				
				const std::string& status() {
					return parameters["status"];
				}
				const uint64_t in_reply_to_status_id() {
					return std::stoull(parameters["in_reply_to_status_id"]);
				}
				const bool possibly_sensitive() {
					return (parameters["possibly_sensitive"] == "true");
				}
				const double lat() {
					return std::stod(parameters["lat"]);
				}
				const double lng() {
					return std::stod(parameters["lng"]);
				}
				const std::string& place_id() {
					return parameters["place_id"];
				}
				const bool display_coordinates() {
					return (parameters["display_coordinates"] == "true");
				}
				const bool trim_user() {
					return (parameters["trim_user"] == "true");
				}
				const uint64_t media_ids() {
					return std::stoull(parameters["media_ids"]);
				}
			};
		}
	}
}

#endif // __PARAMETERS_H__