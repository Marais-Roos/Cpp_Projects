#include "Controller.h"

using namespace std;

int main()
{
    string filename = "list.txt";

    Controller *c = new Controller(filename);

    string originalMessage;

    //get a message to encrypt from the user
    cout << "Enter message to encrypt: ";
    getline(cin, originalMessage);
    
    //convert the message to a dynamic unsigned char array
    unsigned int size = originalMessage.length();
    unsigned char *message = new unsigned char[size];

    for (unsigned i = 0; i < size; i++)
    {
        message[i] = (unsigned char)originalMessage[i];
    }

    ReturnStruct r;

    cout << "Original message (plain text):\t";
    cout << originalMessage << endl << endl;
    
    cout << "Encrypting original message... " << endl << endl;
    r = c->encrypt(message, size);

    cout << "Encrypted message: ";
    for (unsigned i = 0; i < r.arraySize; i++)
    {
        cout << r.returnArray[i] << endl;
    }
    cout << "Encrypted message size: " << r.arraySize << endl << endl;

    cout << "Decrypting cipher text... " << endl;
    c->decrypt(r.returnArray, r.arraySize);

    cout << "Decrypted message: ";
    for (unsigned i = 0; i < r.arraySize; i++)
    {
        cout << r.returnArray[i] << endl;
    }
    cout << "Decrypted message size: " << r.arraySize << endl << endl;

    cout << "Complete!" << endl;

    return 0;
}