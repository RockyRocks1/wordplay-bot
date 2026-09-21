#include <httplib.h>
#include <iostream>
int main() {
	// from example
	httplib::Server svr;

	svr.Get("/hi", [](const httplib::Request&, httplib::Response& res) {
		std::cout << "Hi" << std::endl;
		res.set_content("Hello World!", "text/plain");
	});

	svr.listen("0.0.0.0", 8080);
}