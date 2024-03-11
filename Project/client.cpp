#include <boost/asio.hpp>


int socket() {
	using namespace boost::asio;
	using ip::tcp;
	using namespace std;

	boost::asio::io_service io_service;
	tcp::socket socket(io_service);
	socket.connect(tcp::endpoint
	(boost::asio::ip::address::from_string("127.0.0.1"), 12345));
	const string msg = "Hello from Client!\n";
	boost::system::error_code error;
	boost::asio::write(socket, boost::asio::buffer(msg), error);
	if (!error)
	{
		printf("Client send hello message!");
	}
	else
	{
		printf("send failed: %s\n", error.message().c_str());
	}

	boost::asio::streambuf receive_buffer;
	boost::asio::read(socket, receive_buffer, boost::asio::transfer_all(), error);

	if (error && error != boost::asio::error::eof)
	{
		printf("receive failed: ");
		printf("%s\n", error.message().c_str());
	}
	else
	{
		const char* data = boost::asio::buffer_cast<const char*>(receive_buffer.data());
		printf("Received: ");
		printf("%s\n", data);
	}

	return 0;
}