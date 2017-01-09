#include <iostream>

#include "azha.hpp"

void access_token_callback(const int code, const std::unordered_map<std::string, std::string> &response) {
	for(auto iter = response.begin(); iter != response.end(); ++iter) {
		std::cout << iter->first << " " << iter->second << std::endl;
	}
	
	azha::Client::instance().access_token(response.at("oauth_token"), response.at("oauth_token_secret"));
	
	azha::parameters::Statuses::UpdateParameters p;
	p.status("hello, world!");
	azha::Client::instance().request(p, nullptr);
}

void request_token_callback(const int code, const std::unordered_map<std::string, std::string> &response) {
	std::cout << "https://twitter.com/oauth/authorize?oauth_token=" << response.at("oauth_token") << std::endl;
	
	azha::Client::instance().access_token(response.at("oauth_token"), "");
	
	std::string oauth_verifier;
	std::cin >> oauth_verifier;
	
	azha::parameters::OAuth::AccessTokenParameters p;
	p.oauth_verifier(oauth_verifier);
	azha::Client::instance().request(p, access_token_callback);
}

int main() {
	std::string consumer_key = "IQKbtAYlXLripLGPWd0HUA";
	std::string consumer_secret = "GgDYlkSvaPxGxC4X8liwpUoqKwwr3lCADbz8A7ADU";
	
	azha::Client::instance().consumer_key(consumer_key, consumer_secret);
	
	azha::parameters::OAuth::RequestTokenParameters p;
	p.oauth_callback("oob");
	azha::Client::instance().request(p, request_token_callback);
	
	return 0;
}

