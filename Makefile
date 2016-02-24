all: encodeirz

encodeirz: EncodeIR.cpp IRP.cpp
	g++ -o encodeirz $^
