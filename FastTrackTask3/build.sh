# rm -r src/*
# rm -r build/*


asn1c RRC.asn1 -D src -no-gen-OER -no-gen-example

gcc -Isrc -o build/client client.c CodeDecode.c src/*.c -DASN_DISABLE_OER_SUPPORT -lsctp
gcc -Isrc -o build/server server.c CodeDecode.c src/*.c -DASN_DISABLE_OER_SUPPORT -lsctp