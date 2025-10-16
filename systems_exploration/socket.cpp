#include <iostream>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <cstring>

// Function to check and print file type using `fstat`
void checkFileType(int fd, const std::string& description) {
    struct stat fileStat;
    if (fstat(fd, &fileStat) == -1) {
        perror(("Error retrieving file status for " + description).c_str());
        return;
    }

    // Checking the file type
    std::cout << description << " (FD: " << fd << "): ";
    if (S_ISREG(fileStat.st_mode))
        std::cout << "Regular File\n";
    else if (S_ISFIFO(fileStat.st_mode))
        std::cout << "FIFO (Pipe)\n";
    else if (S_ISSOCK(fileStat.st_mode))
        std::cout << "Socket\n";
    else
        std::cout << "Other File Type\n";
}

int main() {
    // Open a regular file
	// O_CREAT: Create the file if it does not exist
	// O_WRONLY: Open the file for writing only
	// O_TRUNC: If the file already exists, truncate it to zero length
	// These are file access modes, and can be combined using bitwise OR
	// 0644 is the file permission mode 
    int fileFD = open("example.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (fileFD == -1) {
        perror("Error creating/opening regular file");
        return 1;
    }

    // Create a pipe
    int pipeFDs[2];
    if (pipe(pipeFDs) == -1) {
        perror("Error creating pipe");
        close(fileFD);
        return 1;
    }

    // Create a socket
	// AF_INET: IPv4 Internet Protocol
	// SOCK_STREAM: Provides sequenced, reliable, two-way, connection-based byte streams
	// 0: Protocol value for Internet Protocol
    int socketFD = socket(AF_INET, SOCK_STREAM, 0);
    if (socketFD == -1) {
        perror("Error creating socket");
        close(fileFD);
        close(pipeFDs[0]);
        close(pipeFDs[1]);
        return 1;
    }

    // Check file types
    checkFileType(fileFD, "Regular File");
    checkFileType(pipeFDs[0], "Pipe (Read End)");
    checkFileType(pipeFDs[1], "Pipe (Write End)");
    checkFileType(socketFD, "Socket");

    // Cleanup
    close(fileFD);
    close(pipeFDs[0]);
    close(pipeFDs[1]);
    close(socketFD);

    return 0;
}
