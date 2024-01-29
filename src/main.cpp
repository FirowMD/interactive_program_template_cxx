#include <cmdhandler.h>
#include <cmdbuiltin.h>
#include <iostream>

int main(int argc, char **argv)
{
    std::cout << "Interactive program. Type \"help\" to see available commands.\n";
    std::cout << "Type \"quit\" to exit.\n";

    CommandHandler cmdhandler;
    cmdhandler.Init();

    while (true)
    {
        std::string cmdline;
        std::cout << "> ";
        std::getline(std::cin, cmdline);
        cmdhandler.Handle(cmdline);
    }

    return 0;
}