#include "Server.hpp"

Server* Server::instance = 0;
Server* Server::getInstance()
{
	if (!instance) instance = new Server;
	return instance;
}

unordered_map <string, double> Server::liveData;

void Server::Connect(int port, const char* ip)
{
	cout<<"Waiting for the Simulator..."<<endl;
	int server_fd, new_socket, valread, counter = 0;
	struct sockaddr_in address;
	int opt = 1;
	int addrlen = sizeof(address);
	char buffer[4096] = {0};
	
	// Creating socket file descriptor
	if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
	{
		perror("socket failed");
		exit(EXIT_FAILURE);
	}
	
	// Forcefully attaching socket to the port PORT
	if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)))
	{
		perror("setsockopt");
		exit(EXIT_FAILURE);
	}
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons( port );
	
	// Forcefully attaching socket to the port PORT
	if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0)
	{
		perror("bind failed");
		exit(EXIT_FAILURE);
	}
	if (listen(server_fd, 3) < 0)
	{
		perror("listen");
		exit(EXIT_FAILURE);
	}
	if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0)
	{
		perror("accept");
		exit(EXIT_FAILURE);
	}
	
	while (counter == 0) 
	{
		valread = read( new_socket , buffer, 4096);
		ofstream myfile ("DataBase.txt");
		if (myfile.is_open())
		{
			myfile << buffer<<endl;
			myfile.close();
		}
		else cout << "Unable to open file";

        cout << buffer << endl;
        data = buffer;
        
		cout<<"counter is: "<< counter++ <<endl;
        
	}
    
}
