#pragma once

#include <cmdhandler.h>
#include <string>
#include <vector>

class CommandEcho final: public Command {
public:
    CommandEcho(CommandHandler* cmdhandler)
    {
        this->name = "echo";
        this->description = "Prints the given text to the console.";
        this->aliases = {};
        this->cmdhandler = cmdhandler;
    }
    void PrintHelp() override;
    void Run(std::vector<std::string> args) override;
};

class CommandQuit final: public Command {
public:
    CommandQuit(CommandHandler* cmdhandler)
    {
        this->name = "quit";
        this->description = "Exits the program.";
        this->aliases = { "exit", "q" };
        this->cmdhandler = cmdhandler;
    }
    void PrintHelp() override;
    void Run(std::vector<std::string> args) override;
};

class CommandHelp final: public Command {
public:
    CommandHelp(CommandHandler* cmdhandler)
    {
        this->name = "help";
        this->description = "Prints the help message.";
        this->aliases = { "?", "h" };
        this->cmdhandler = cmdhandler;
    }
    void PrintHelp() override;
    void Run(std::vector<std::string> args) override;
};