#include "communicator.h"

int main(int argc, char *argv[])
{
    int option = 0;
    Communicator c;
    c.connect();

    while(1){
        cin >> option;
        if (option)
            c.publish("ocelus", "teste");
        else if (option == 2)
            c.subscribe("ocelus");
        option = 0;
    }
}
