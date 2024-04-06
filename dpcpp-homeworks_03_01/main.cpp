#include <iostream>
#include <fstream>

class LogCommand {
public:
    virtual ~LogCommand() = default;
    virtual void print(const std::string& message) = 0;
};

class PrintToConsole : public LogCommand {
public:
   // ~PrintToConsole() = default;
    void print(const std::string& message) override {
        std::cout << message << std::endl;
    }
};

class PrintToFile : public LogCommand {
public:
    void print(const std::string& message) override {
        std::ofstream to_file;
        to_file.open("..\\hw_logfile.txt");
        
        if (to_file.is_open()) {
            to_file << message << std::endl;
        }
        else {
            std::cout << "Unable to open file!";
        }
        to_file.close();
    }
};
//private:
//    const std::string message_;
//};

void print(LogCommand& command) {
    command.print("message!");
}
   
int main() {
    PrintToConsole cons;
    PrintToFile file;
    print(cons);
    print(file);


	return 0;
}