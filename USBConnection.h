#ifndef USBCONNECTION_H
#define USBCONNECTION_H

#include <stack>

class USBConnection
{
private:
    int ID;
    static std::stack<int> ids;

    USBConnection(int id) : ID(id) {}

public:
    ~USBConnection()
    {
        ids.push(ID);
    }

    static USBConnection *CreateUsbConnection()
    {
        if (ids.empty())
        {
            return nullptr;
        }
        int id = ids.top();
        ids.pop();
        return new USBConnection(id);
    }

    int get_id() const
    {
        return ID;
    }
};

std::stack<int> USBConnection::ids({3, 2, 1});

#endif