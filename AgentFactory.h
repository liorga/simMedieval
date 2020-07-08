//
// Created by evyat on 7/8/2020.
//

#ifndef EX3_SIMMEDIEVAL_AGENTFACTORY_H
#define EX3_SIMMEDIEVAL_AGENTFACTORY_H

#include <memory>
#include "Agent.h"
#include <vector>
//Singleton Agent factory
//abstract factory
class AgentFactory {

public:
    static AgentFactory& getInstance();
    std::shared_ptr<Agent> createAgent(std::vector<std::string>&);
private:
    AgentFactory();
    ~AgentFactory();
};


#endif //EX3_SIMMEDIEVAL_AGENTFACTORY_H
