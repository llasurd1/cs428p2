#include <iostream>
#include <stdlib.h> 
#include <unistd.h> 
#include <string.h> 
#include <time.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <netinet/in.h> 
#include <vector>

using namespace std;

#define PORT	 1027


int main() { 
	int sockfd, count;
	clock_t start, end;
	socklen_t len;
	char buffer[1024];
	buffer
	struct sockaddr_in servaddr, cliaddr; 
	
	// Create a UDP socket
	// Notice the use of SOCK_DGRAM for UDP packets
	sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	
	memset(&servaddr, 0, sizeof(servaddr)); 
	memset(&cliaddr, 0, sizeof(cliaddr)); 
	
	// Fill server information 
	servaddr.sin_family = AF_INET; // IPv4 
	servaddr.sin_addr.s_addr = INADDR_ANY; // localhost
	servaddr.sin_port = htons(PORT); // port number
	
	//Set timeout for 1 second
	//Keep track of number of pings
        count = 0;
	len = sizeof(servaddr);
	//Send message to server
	sendto(sockfd, (const char *) buffer, strlen(buffer), MSG_CONFIRM, (const struct sockaddr *) &servaddr, len);
	//Recieve message form server
	int n;
	n = recvfrom(sockfd, (char *)buffer, sizeof(buffer), MSG_WAITALL, (struct sockaddr *) &servaddr, &len);
	buffer[n] = '\0';
	//See how long has passed		
	cout << "Ping Number " << count << "Round Trip Time " << end << " Seconds" << endl;
	
	
	}
	return 0; 
} 
