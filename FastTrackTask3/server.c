#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <stdio.h>
#include <arpa/inet.h>
#include <net/if.h>
#include <netdb.h>
#include <stdlib.h>
#include "CodeDecode.h"


int main() {
    struct sockaddr_in addr = (struct sockaddr_in) {
        .sin_family = AF_INET,
        addr.sin_port = htons(3425),
        addr.sin_addr.s_addr = htonl(INADDR_ANY)
    };

    uint8_t buf[1024];
    int listener = socket(AF_INET, SOCK_STREAM, 0);
    if(listener < 0) {
        perror("socket");
        exit(1);
    }

    if(bind(listener, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("bind");
        exit(2);
    } 

    listen(listener, 1);

    int sock = accept(listener, NULL, NULL);
    if(sock < 0) {
        perror("accept");
        exit(3);
    }

    int bytes_read = recv(sock, buf, 1024, 0);
    printf("Received request\n Size: %d", bytes_read);

    if (bytes_read <= 0) {
        perror("bytes read < 0");
        exit(3);
    }

    struct Message m = {buf, bytes_read};
    RRCConnectionRequest_t* request = DecodeRequest(buf, bytes_read);
    Message setup = CreateConnectionSetup();

    printf("Send connection setup\n");
    send(sock, setup.ptr, setup.size, 0);

    bytes_read = recv(sock, buf, 1024, 0);
    printf("Received connection setup complete\n Size: %d\n", bytes_read);

    if (bytes_read <= 0) {
        perror("bytes read < 0");
        exit(3);
    }

    RRCConnectionSetupComplete_t* omplete = DecodeComplete(struct Message {buf, bytes_read});
    printf("Setup complete ID: %ld\n", complete->rrc_TransactionIdentifier);

    free(setup.ptr);
    ASN_STRUCT_FREE(asn_DEF_RRCConnectionSetupComplete, complete);
    ASN_STRUCT_FREE(asn_DEF_RRCConnectionRequest, request);
    close(sock);
}