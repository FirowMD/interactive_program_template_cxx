#pragma once

#include <map>
#include <vector>
#include <optional>
#include <string>

class CommandHandler;

class Command {
public:
    std::string name;
    std::string description;
    std::vector<std::string> aliases;    
    CommandHandler* cmdhandler;

    bool operator==(const Command& other) const
    {
        return this->name == other.name;
    }
    virtual void PrintHelp() {}
    virtual void Run(std::vector<std::string> args) {}
};

class CommandHandler {
private:
    std::map<std::string, Command*> commands;
public:
    CommandHandler() {}

    void Init();
    void AddCommand(Command* command);
    std::optional<Command*> GetCommand(const std::string& name);
    std::vector<Command*> GetAllCommands();
    void Handle(const std::string& cmdline);
    ~CommandHandler();
};