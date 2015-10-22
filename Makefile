all: encodeirz

MakeHex: MakeHex.cpp IRP.cpp
	g++ -o MakeHex $^

encodeirz: EncodeIR.cpp IRP.cpp
	g++ -o encodeirz $^
