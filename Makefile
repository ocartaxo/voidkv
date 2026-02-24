# 1. Compilation variables (Best Practices)
# CXX defines which C++ compiler to use. CXXFLAGS defines the options (C++17, warnings, and optimization).
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2

# 2. The 'all' rule is the default target. If you just type 'make' in the terminal, it will be called.
all: server client

# 3. Rule to compile the server
# Dependencies: server.cpp, buffer.cpp, and buffer.h
server: server.cpp buffer.cpp buffer.h
	@$(CXX) $(CXXFLAGS) server.cpp buffer.cpp -o server
	@echo "server compiled successfully!"

# 4. Rule to compile the client
# Dependencies: client.cpp
client: client.cpp
	@$(CXX) $(CXXFLAGS) client.cpp -o client
	@echo "client compiled successfully!"

# 5. Clean rule to keep the directory organized
clean:
	@rm -f server client
	@echo "cleaned"