#ifndef _CodeDecode_H
#define _CodeDecode_H

extern "C" {
    #include <RRCConnectionRequest.h>
    #include <RRCConnectionSetupComplete.h>
    #include <RRCConnectionSetup.h>
}

typedef struct Message{
    uint32_t *mem_for_msg;
    size_t size;
} Message;

Message CodeRequest();
RRCConnectionSetupComplete_t* DecodeRequest(Message m);

Message CodeSetup();
RRCConnectionSetup_t* DecodeSetup(Message m);

Message CodeComplete();
RRCConnectionSetupComplete_t* DecodeComplete(Message m);

#endif