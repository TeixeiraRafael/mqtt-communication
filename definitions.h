#ifndef DEFINITIONS_H
#define DEFINITIONS_H

#include <string.h>
#include <iostream>

#include "mqtt/async_client.h"
#include "mqtt/client.h"
#include "mqtt/connect_options.h"
#include "mqtt/delivery_token.h"
#include "mqtt/callback.h"
#include "mqtt/message.h"
#include "mqtt/token.h"

using namespace std;

const string DEFAULT_ADDRESS = {"tcp://10.228.255.162:1883"};
const string DEFAULT_CLIENT_ID = "client";
const int TIMEOUT = 20;
const int QOS = 1;


#endif // DEFINITIONS_H
