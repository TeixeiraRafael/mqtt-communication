#include "communicator.h"

Communicator::Communicator()
{
    client_ptr = std::make_shared<mqtt::async_client>(DEFAULT_ADDRESS, DEFAULT_CLIENT_ID);
    client_ptr->set_callback(*this);

    connOpts.set_keep_alive_interval(20);
    connOpts.set_clean_session(false);
    connOpts.set_automatic_reconnect(true);

    cout << "Construced!" << endl;
}

void Communicator::connected(const string &cause){
    cout << "Connected:\t" << cause << endl;
}

void Communicator::connection_lost(const string &cause){
    cout << "Connection lost:\t" << cause << endl;
}

void Communicator::message_arrived(mqtt::const_message_ptr msg){
    cout << "Message arrived:\n" << msg->to_string() << endl;
}

void Communicator::delivery_complete(mqtt::delivery_token_ptr tok){
    cout << "Message delivered!" << endl;
}

void Communicator::connect(){
    try{
        this->client_ptr->connect(connOpts);
        is_connected = true;
    }catch(mqtt::exception e){
        is_connected = false;
        cout << "Error while trying to connect:\n" << e.what() << endl;
    }
}

void Communicator::disconnect(){
    try{
        this->client_ptr->disconnect();
        is_connected = false;
    } catch(mqtt::exception e){
        cout << "Error while trying to disconnect:\n" << e.what() <<endl;
    }

}

void Communicator::publish(string topic, string payload){
    try{
        if(is_connected){
            mqtt::message_ptr pubmsg = mqtt::make_message(topic, payload);
            pubmsg->set_qos(QOS);
            client_ptr->publish(pubmsg)->wait_for(TIMEOUT);
        }
    }catch(mqtt::exception e){
        cout << "Error while trying to publish the following message:\n\t" << payload << endl << e.what() << endl;
    }
}

void Communicator::subscribe(string topic){
    try{
        if(is_connected){
            client_ptr->subscribe(topic, QOS);
        }
    }catch(mqtt::exception e){
        cout << "Error while trying to subscribe to topic \"" << topic << "\"" << endl << e.what() << endl;
    }
}
