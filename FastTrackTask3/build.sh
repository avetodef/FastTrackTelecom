rm -r src/*
rm -r build/*

mkdir -p build src

cd ./src

asn1c ../RRC.asn1 -gen-PER 

cd ..

gcc src/*.c -o build/ -I src/ -Wno-

g++ -Isrc -o build/client client.cpp CodeDecode.cpp -DASN_DISABLE_OER_SUPPORT -lsctp
g++ -Isrc -o build/server server.cpp CodeDecode.cpp -DASN_DISABLE_OER_SUPPORT -lsctp