#include <cmdbuiltin.h>
#include <iostream>
#include <vector>
#include <string>

void CommandEcho::PrintHelp()
{
    std::cout << "Usage: echo <text>" << std::endl;
}

void CommandEcho::Run(std::vector<std::string> args)
{
    for (const auto& arg : args)
    {
        std::cout << arg << " ";
    }
    std::cout << std::endl;
}

void CommandQuit::PrintHelp()
{
    std::cout << "Usage: quit" << std::endl;
}

void CommandQuit::Run(std::vector<std::string> args)
{
    exit(0);
}

void CommandHelp::PrintHelp()
{
    std::cout << "Usage: help [command]" << std::endl;
}

void CommandHelp::Run(std::vector<std::string> args)
{
    if (args.empty())
    {
        std::vector<Command*> commands = cmdhandler->GetAllCommands();
        std::cout << "Available commands:" << std::endl;
        for (const auto& command : commands)
        {
            std::cout << "  " << command->name << " - " << command->description << std::endl;
        }
    }
    else
    {
        if (auto command = cmdhandler->GetCommand(args[0]))
        {
            command.value()->PrintHelp();
        }
        else
        {
            std::cout << "Command not found: " << args[0] << std::endl;
        }
    }
}
