//
// Created by lee on 21/12/17.
//

#include "../include/CommandManager.h"
#include "../include/StartCommand.h"
#include "../include/ListCommand.h"
#include "../include/PlayCommand.h"
#include "../include/CloseCommand.h"
#include "../include/JoinCommand.h"

CommandManager::CommandManager() {
    commandsMap["start"] = new StartCommand();
    commandsMap["list"] = new ListCommand();
    commandsMap["play"] = new PlayCommand();
    commandsMap["close"] = new CloseCommand();
    commandsMap["join"] = new JoinCommand();
}
void CommandManager::executeCommand(string
                                     command, vector<string> args) {
    Command *commandObj = commandsMap[command];
    commandObj->execute(args);
}
CommandManager::~CommandManager() {
    map<string, Command *>::iterator it;
    for (it = commandsMap.begin(); it !=
                                   commandsMap.end(); it++) {
        delete it->second;
    }
}