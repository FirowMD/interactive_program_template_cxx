#include <cmdhandler.h>
#include <cmdbuiltin.h>
#include <map>
#include <vector>
#include <string>
#include <optional>
#include <iostream>
#include <sstream>
#include <algorithm>

void CommandHandler::Init()
{
    AddCommand(new CommandEcho(this));
    AddCommand(new CommandQuit(this));
    AddCommand(new CommandHelp(this));
}

void CommandHandler::AddCommand(Command* command)
{
    commands[command->name] = command;
    for (const auto& alias : command->aliases)
    {
        commands[alias] = command;
    }
}

std::optional<Command*> CommandHandler::GetCommand(const std::string& name)
{
    if (commands.count(name) > 0)
    {
        return commands[name];
    }
    return std::nullopt;
}

std::vector<Command*> CommandHandler::GetAllCommands()
{
    std::vector<Command*> res;
    for (const auto& pair : commands)
    {
        Command* cmd = pair.second;
        // Skip aliases
        if (std::find(res.begin(), res.end(), cmd) != res.end())
        {
            continue;
        }
        res.push_back(cmd);
    }

    return res;
}

void CommandHandler::Handle(const std::string& cmdline)
{
    std::vector<std::string> cmd_splitted;
    std::string arg;
    std::stringstream ss(cmdline);
    while (ss >> arg)
    {
        cmd_splitted.push_back(arg);
    }

    if (cmd_splitted.empty())
    {
        return;
    }

    std::string cmd_name = cmd_splitted[0];
    std::vector<std::string> args = {};

    if (cmd_splitted.size() >= 1)
    {
        args = std::vector<std::string>(cmd_splitted.begin() + 1, cmd_splitted.end());
    }

    if (commands.count(cmd_name) == 0)
    {
        if (!cmd_name.empty())
        {
            std::cout << "Command not found: " << cmd_name << std::endl;
        }

        return;
    }

    Command* cmd = commands[cmd_name];
    cmd->Run(args);
}

CommandHandler::~CommandHandler() {
    for (const auto& pair : commands)
    {
        delete pair.second;
    }
}
