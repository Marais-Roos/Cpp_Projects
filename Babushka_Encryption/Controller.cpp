#include "Controller.h"

Controller::Controller(std::string filePath)
{
    std::ifstream file(filePath, std::ios::in);

    if (file.fail())
    {
        std::cout << "Error: " << filePath << std::endl;
        exit(1);
    }

    std::string line;

    getline(file, line);
    this->numBabushkas = stoi(line.substr(line.find(':') + 1));

    this->babushkaArr = new Babushka*[this->numBabushkas];

    enum Colours {DARKBLUE, LIGHTBLUE, GOLD, GREEN, RED, YELLOW};

    unsigned int count = 0;
    while (count < this->numBabushkas)
    {
        getline(file, line);
        std::stringstream ss(line);
        std::string colour;
        getline(ss, colour, ':');
        
        for (unsigned i = 0; i < colour.length(); i++) colour[i] = tolower(colour[i]);

        Colours c;

        if (colour == "darkblue") c = DARKBLUE;
        else if (colour == "lightblue") c = LIGHTBLUE;
        else if (colour == "gold") c = GOLD;
        else if (colour == "green") c = GREEN;
        else if (colour == "red") c = RED;
        else if (colour == "yellow") c = YELLOW;

        std::string id;
        std::string op;

        switch (c)
        {
            case DARKBLUE:
            {
                getline(ss, id,':');
                getline(ss, op);
                this->babushkaArr[count] = new DarkBlueBabushka((unsigned char*)id.c_str(), (unsigned int)stoul(op));
                break;
            }
            case LIGHTBLUE:
            {
                getline(ss, id,':');
                getline(ss, op);
                this->babushkaArr[count] = new LightBlueBabushka((unsigned char*)id.c_str(), stoul(op));
                break;
            }  
            case GOLD:
            {
                getline(ss, id,':');
                getline(ss, op);
                unsigned char * c_str = new unsigned char[op.length()];
                for (unsigned i = 0; i < op.length(); i++)
                    c_str[i] = op[i];
                c_str[op.length()] = '\0';
                this->babushkaArr[count] = new GoldBabushka((unsigned char*)id.c_str(), *c_str);
                break;
            }
            case GREEN:
            {
                getline(ss, id,':');
                getline(ss, op);
                this->babushkaArr[count] = new GreenBabushka((unsigned char*)id.c_str(), stoul(op));
                break;
            }
            case RED:
            {
                getline(ss, id,':');
                getline(ss, op);
                this->babushkaArr[count] = new RedBabushka(reinterpret_cast<const unsigned char*>(id.c_str()), (unsigned int)stoul(op));
                break;
            } 
            case YELLOW:
            {
                getline(ss, id,':');
                this->babushkaArr[count] = new YellowBabushka(reinterpret_cast<const unsigned char*>(id.c_str()));
                break;
            } 
        }

        count++;
    }

    file.close();
}

Controller::~Controller()
{
    for (unsigned int i = 0; i < this->numBabushkas; i++)
    {
        delete this->babushkaArr[i];
    }
    delete [] this->babushkaArr;
    this->numBabushkas = 0;
}

ReturnStruct Controller::decrypt(const unsigned char* array, unsigned int size)
{
    try
    {
        //create deep copy of array parameter
        unsigned char* arrCopy = new unsigned char[size];
        for (unsigned int i = 0; i < size; i++)
        {
            arrCopy[i] = array[i];
        }
        //print original array
        this->printArray(arrCopy, size);

        ReturnStruct result;

        //for each babushka in the babushkaArr member variable
        for (unsigned int i = this->numBabushkas - 1; i >= 0; i++)
        {
            //decrypt
            this->babushkaArr[i]->decrypt(result.returnArray, result.arraySize);

            //reduce array
            result = this->reduceArray(arrCopy, size, this->babushkaArr[i]->getId(), this->babushkaArr[i]->getIdLength());

            //print array
            this->printArray(result.returnArray, result.arraySize);
        }

        //return resulting array as ReturnStruct
        return result;
    }
    catch(BabushkaException& e)
    {
        throw ControllerException(e, "decrypt exception");
    }
}

ReturnStruct Controller::encrypt(const unsigned char* array, unsigned int size)
{
    try
    {
        //create deep copy of array parameter
        unsigned char* arrCopy = new unsigned char[size];
        for (unsigned int i = 0; i < size; i++)
        {
            arrCopy[i] = array[i];
        }
        //print original array
        std::cout << "printing original" << std::endl;
        this->printArray(arrCopy, size);

        ReturnStruct result;

        //for each babushka in the babushkaArr member variable
        for (unsigned int i = 0; i < this->numBabushkas; i++)
        {
            //expand array
            result = this->expandArray(arrCopy, size, this->babushkaArr[i]->getId(), this->babushkaArr[i]->getIdLength());

            //encrypt
            this->babushkaArr[i]->encrypt(result.returnArray, result.arraySize);

            //print array
            this->printArray(result.returnArray, result.arraySize);
        }

        //return resulting array as ReturnStruct
        return result;
    }
    catch(BabushkaException& e)
    {
        throw ControllerException(e, "encrypt exception");
    }
}

ReturnStruct Controller::expandArray(unsigned char* array, unsigned int currentSize, const unsigned char* id, int idSize)
{
    unsigned int newSize = currentSize + (2 * idSize);
    unsigned char* newArr = new unsigned char[newSize];
   
    //add id to the front of array
    std::memcpy(newArr, id, sizeof(id));
    std::memcpy(newArr + sizeof(id), array, sizeof(array));

    //add id to the back of the combined array
    std::memcpy(newArr + sizeof(id) + sizeof(array), id, sizeof(id));

    delete [] array;

    ReturnStruct result{newSize, newArr};
    return result;
}

bool arraysMatch(unsigned char* id, const unsigned char* expectedId, int size) 
{
    for (int i = 0; i < size; i++) 
    {
        if (id[i] != expectedId[i]) 
        {
            return false;
        }
    }
    return true;
}

ReturnStruct Controller::reduceArray(unsigned char* array, unsigned int currentSize, const unsigned char* expectedId, int idSize)
{
    unsigned int newSize;
    unsigned char* idFront = new unsigned char[idSize];
    unsigned char* idBack = new unsigned char[idSize];
    unsigned char* newArr;

    try
    {
        newSize = currentSize - (2 * idSize);
        if (newSize < 0)
        {
            throw ControllerException("size exception");
        }
        else
        {
            newArr = new unsigned char[newSize];
            std::memcpy(idFront, array, sizeof(idFront));
            std::memcpy(newArr, array + sizeof(idFront), sizeof(newArr));
            std::memcpy(idBack, array + sizeof(idFront) + sizeof(newArr), sizeof(idBack));

            if (!arraysMatch(idFront, expectedId, idSize) || !arraysMatch(idFront, expectedId, idSize))
            {
                throw ControllerException("id mismatch exception");
            }
            else
            {
                ReturnStruct result{newSize, newArr};
                delete [] array;
                return result;
            }
        } 
    }
    catch(ControllerException & e)
    {
        e.printMessage();
    }
}

void Controller::printArray(unsigned char* array, unsigned int size)
{
    std::cout << "[";
    for (unsigned int i = 0; i < size; i++)
    {
        if (i != size - 1)
        {
            std::cout << static_cast<char>(array[i])  << ",";
        }
        else
        {
            std::cout << static_cast<char>(array[i]) << "]" << std::endl;
        }
    }
}
