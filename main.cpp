#include "Mediator.hpp"
int main()
{
    auto theMediator = std::make_shared<Mediator>();
    auto theButton = std::make_shared<Button>(theMediator);
    auto theLabel = std::make_shared<Label>(theMediator);
    theButton ->sendMessage("Button Clicked!");
    theLabel -> sendMessage("Label Changed!");
}