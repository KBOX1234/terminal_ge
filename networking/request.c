

//error codes:

#define CLIENT_FAILED_TO_INIT 1
#define FAILD_TO_BEGIN_CONNECTION 2
#define FAILED_TO_CONNECT 3
#define REQUEST_TIMED_OUT 4

int connect_to_server(const char* ip_adress, enet_uint16 port){
    client = enet_host_create(NULL /* create a client host */,
		1 /* only allow 1 outgoing connection */,
		CHANNELS /* allow up 2 channels to be used, 0 and 1 */,
		0 /* assume any amount of incoming bandwidth */,
		0 /* assume any amount of outgoing bandwidth */);

    if(client == NULL) {
        return CLIENT_FAILED_TO_INIT;
        printf_win(debug_win, 0x40, "Failed to initilize the client\n");
    }

    //adress

	ENetAddress address = {};
	enet_address_set_host(&address, ip_adress);
	address.port = port;

    server = enet_host_connect(client, &address, CHANNELS, 0);

    if(server == NULL){
        printf_win(debug_win, 0x40, "Failed to begin connection\n");
        return FAILD_TO_BEGIN_CONNECTION;
    }

    //actualy connect

    if (enet_host_service(client, &event, 5000) > 0 && event.type == ENET_EVENT_TYPE_CONNECT){
        printf_win(debug_win, 0x20, "Connected to server\n");
        return 0;
    }
    else{
        printf_win(debug_win, 0x40, "Failed to connect try checking your router :)=\n");
        return FAILED_TO_CONNECT;
    }
    
}

int receive_packet(int max_wait_time, struct packaged_packet* p){
    while (enet_host_service(client, &event, max_wait_time) > 0)
    {
        switch (event.type)
        {
        case ENET_EVENT_TYPE_CONNECT:
        break;

        case ENET_EVENT_TYPE_RECEIVE:
        printf("A packet of length %u containing %s was received on channel %u.\n",
            event.packet->dataLength,
            event.packet->data,
            event.channelID);
        /* Clean up the packet now that we're done using it. */

        p->data = malloc(event.packet->dataLength);

        memcpy(p->data, event.packet->data, event.packet->dataLength);

        p->size = event.packet->dataLength;
        enet_packet_destroy(event.packet);

        break;

        case ENET_EVENT_TYPE_DISCONNECT:
        
        return DISCONNECTED;
        break;
        }
    }
    return 0;
}