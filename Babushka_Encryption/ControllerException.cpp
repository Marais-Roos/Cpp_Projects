#include "ControllerException.h"

ControllerException::ControllerException(std::string customMessage)
{
    this->customMessage = customMessage;
    this->hasBabushka = false;
}

ControllerException::ControllerException(BabushkaException& babushkaException, std::string customMessage)
{
    this->customMessage = customMessage;

    this->babushkaException = &babushkaException;

    this->hasBabushka = true;
}

void ControllerException::printMessage()
{
    std::cout << this->customMessage << std::endl;
    if (this->hasBabushka)
        this->babushkaException->printMessage();
}