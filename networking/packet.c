void send_data_tgl_ge(void *data, size_t s, ENetPeer *to){
	ENetPacket *packet = enet_packet_create(data, s, ENET_PACKET_FLAG_RELIABLE);

	enet_peer_send(to, 0, packet);

}

struct packaged_packet package_packet(void* packet, size_t size){
    struct packaged_packet returnV;

    returnV.data = malloc(size);

    memcpy(returnV.data, packet, size);

    returnV.size = size;

    return returnV;
}

int send_packet(struct packaged_packet p){
    send_data_tgl_ge(p.data, p.size, server);
}


void* unpackage_packet(struct packaged_packet p){
    return p.data;
}