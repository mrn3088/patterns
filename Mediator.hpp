// warning: this is problematic!
#ifndef Mediator_hpp
#define Mediator_hpp
#include <string>
#include <memory>
#include <vector>
#include <iostream>
class Mediator;
class Component
{
public:
    Component(std::shared_ptr<Mediator> aMediator) : m_mediator(aMediator) {}
    virtual void sendMessage(const std::string &aString) = 0;
    virtual void receiveMessage(const std::string &aString) = 0;

protected:
    std::shared_ptr<Mediator> m_mediator;
};
class Mediator
{
public:
    Mediator() = default;
    Mediator &registerComponent(std::shared_ptr<Component> theComponent)
    {
        m_components.push_back(theComponent);
        return *this;
    }
    Mediator &notify(Component *aSender, const std::string &aMessage)
    {
        std::for_each(m_components.begin(), m_components.end(),
                      [&](std::shared_ptr<Component> aComponent)
                      {
            if (aComponent.get() != aSender) {
            aComponent ->receiveMessage(aMessage);
            } });
        return *this;
    }

protected:
    std::vector<std::shared_ptr<Component>> m_components;
};

class Button : public Component
{
public:
    Button(std::shared_ptr<Mediator> aMediator) : Component(aMediator) {}
    void sendMessage(const std::string &aString) override
    {
        std::cout << "Button updated: " << aString << std::endl;
        m_mediator->notify(this, aString);
    }
    void receiveMessage(const std::string &aString) override
    {
        std::cout << "Button received: " << aString << std::endl;
    }
};
class Label : public Component
{
public:
    Label(std::shared_ptr<Mediator> aMediator) : Component(aMediator) {}
    void sendMessage(const std::string &aString) override
    {
        std::cout << "Label updated: " << aString << std::endl;
        m_mediator->notify(this, aString);
    }
    void receiveMessage(const std::string &aString) override
    {
        std::cout << "Label received: " << aString << std::endl;
    }
};

#endif