
#include "CodeDecode.h"

Message CodeRequest() {
    RRCConnectionSetup_t* connection_setup = (RRCConnectionSetup_t *)calloc(1, sizeof(RRCConnectionSetup_t));

    connection_setup->rrc_TransactionIdentifier = 1;
    connection_setup->criticalExtensions.present = RRCConnectionSetup__criticalExtensions_PR_criticalExtensionsFuture;

    uint8_t* mem_for_msg = (uint8_t *)calloc(128, 1);
    asn_enc_rval_t size_coded = asn_encode_to_buffer(0, ATS_BER, &asn_DEF_RRCConnectionSetup, connection_setup, mem_for_msg, 128);

    free(connection_setup);

    return (Message) {
        .msg = mem_for_msg,
        .size = static_cast<size_t>(size_coded.encoded)
    };
}

RRCConnectionSetup_t* DecodeConnectionSetup(Message m) {
    uint32_t* mem = m.mem_for_msg;
    size_t size = m.size;

    RRCConnectionSetup_t* setup = 0;
    asn_dec_rval_t rval = asn_decode(0, ATS_BER, &asn_DEF_RRCConnectionSetup, (void **)&setup, mem, size);

    asn_fprint(stdout, &asn_DEF_RRCConnectionSetup, setup);

    return setup;
}

Message CodeSetup() {
    RRCConnectionSetup_t* connection_setup = (RRCConnectionSetup_t *)calloc(1, sizeof(RRCConnectionSetup_t));

    connection_setup->rrc_TransactionIdentifier = 1;
    connection_setup->criticalExtensions.present = RRCConnectionSetup__criticalExtensions_PR_criticalExtensionsFuture;


    uint8_t* mem_for_msg = (uint8_t *)calloc(128, 1);
    asn_enc_rval_t er = asn_encode_to_buffer(0, ATS_BER, &asn_DEF_RRCConnectionSetup, connection_setup, mem_for_msg, 128);

    free(connection_setup);

    return (Message) {
        .mem_for_msg = mem_for_msg,
        .size = static_cast<size_t>(er.encoded)
    };
}

RRCConnectionSetup_t* DecodeSetup(Message m) {
    uint32_t* mem = m.mem_for_msg;
    size_t size = m.size;

    RRCConnectionSetup_t* setup = 0;
    asn_dec_rval_t rval = asn_decode(0, ATS_BER, &asn_DEF_RRCConnectionSetup, (void **)&setup, mem, size);

    asn_fprint(stdout, &asn_DEF_RRCConnectionSetup, setup);

    return setup;
}


Message CodeComplete() {
    RRCConnectionSetupComplete_t* connection_setup_complete = (RRCConnectionSetupComplete_t *)calloc(1, sizeof(RRCConnectionSetupComplete_t));

    connection_setup_complete->rrc_TransactionIdentifier = 1;
    connection_setup_complete->criticalExtensions.present = RRCConnectionSetupComplete__criticalExtensions_PR_criticalExtensionsFuture;

    uint8_t* mem_for_msg = (uint8_t *)calloc(128, 1);
    asn_enc_rval_t er = asn_encode_to_buffer(0, ATS_BER, &asn_DEF_RRCConnectionSetupComplete, connection_setup_complete, mem_for_msg, 128);

    free(connection_setup_complete);

    return (Message) {
        .mem_for_msg = mem_for_msg,
        .size = static_cast<size_t>(er.encoded)
    };
}

RRCConnectionSetupComplete_t* DecodeComplete(Message m) {
    uint32_t* mem = m.mem_for_msg;
    size_t size = m.size;

    RRCConnectionSetupComplete_t* setup_complete = 0;
    asn_dec_rval_t rval = asn_decode(0, ATS_BER, &asn_DEF_RRCConnectionSetupComplete, (void **)&setup_complete, mem, size);

    asn_fprint(stdout, &asn_DEF_RRCConnectionSetupComplete, setup_complete);

    return setup_complete;
}