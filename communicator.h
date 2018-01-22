#ifndef COMMUNICATOR_H
#define COMMUNICATOR_H

#include "definitions.h"

class Communicator : public mqtt::callback
{

private:
    mqtt::async_client_ptr client_ptr;
    mqtt::connect_options connOpts;
    bool is_connected = false;

public:
    Communicator();

    void connect();
    void disconnect();
    void publish(string topic, string payload);
    void subscribe(string topic);

    //Callbacks
    virtual void connected(const string &cause) override;
    virtual void connection_lost(const string &cause) override;
    virtual void message_arrived(mqtt::const_message_ptr msg) override;
    virtual void delivery_complete(mqtt::delivery_token_ptr tok) override;

};

#endif // COMMUNICATOR_H
