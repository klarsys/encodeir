///////////////////////////////////////////////////////////////////////////////
// MakeHex version 4  Copyright 2004 John S. Fine
//
// You may use, copy, modify and/or distribute this program for private or
// commercial use provided that:
//
// 1)  You do not hold me responsible for any damage or negative consequences
// resulting from those activities.
//
// 2)  You include this copyright notice and disclaimer in any copy of any part
// or all of this program.
//
// I do not provide any warranty of the correctness, safety, or suitibility of
// this program for any purpose.
//
// If you do not agree to these conditions, you have no permission to use, copy,
// modify or distribute this program.
///////////////////////////////////////////////////////////////////////////////

#include "StdAfx.h"
#include "IRP.h"

#pragma GCC diagnostic ignored "-Wwrite-strings"

struct protdef {
	const char *prot;
	const char *def;
	const int tgl;
};
#define count(ARRAY) (sizeof(ARRAY)/sizeof(*ARRAY))

struct protdef protdefs[] = {
	{ "aiwa",
		"Protocol=Aiwa\n"
		"Frequency=38000\n"
		"Time Base=550\n"
		"One=1,-3\n"
		"Zero=1,-1\n"
		"Prefix=16,-8\n"
		"Suffix=1,-42\n"
		"R-Prefix=16,-8\n"
		"R-Suffix=1,-165\n"
		"Form=*,D:8,S:5,~D:8,~S:5,F:8,~F:8,_;*,_\n"
	, 0 },
	{ "apple-I",
		"Protocol=Apple\n"
		"Frequency=38400\n"
		"Time Base=564\n"
		"One=1,-3\n"
		"Zero=1,-1\n"
		"Prefix=16,-8\n"
		"Suffix=1,-78\n"
		"R-Prefix=16,-4\n"
		"R-Suffix=1,-173\n"
		"Default S=~D\n"
		"Define C=1+(F:1)+(F:1:1)+(F:1:2)+(F:1:3)+(F:1:4)+(F:1:5)+(F:1:6)+(I:1)+(I:1:1)+(I:1:2)+(I:1:3)+(I:1:4)+(I:1:5)+(I:1:6)+(I:1:7)\n"
		"Form=*,D:8,S:8,C:1,F:7,I:8,_;*,_\n"
	, 0 },
	{ "async",
		"Protocol=Async\n"
		"Frequency=43600\n"
		"Time Base=833\n"
		"Zero=1\n"
		"One=-1\n"
		"Prefix=1,-9,1\n"
		"Suffix=-1,1,-9\n"
		"First Bit=LSB\n"
		"Form=*,1:8,1:2,D:8,1:2,F:8,1:2,F:8,1:2,1:8,_\n"
	, 0 },
	{ "blaupunkt",
		"Protocol=Blaupunkt\n"
		"Frequency=30500\n"
		"Time Base=500\n"
		"Zero=-1,1\n"
		"One=1,-1\n"
		"Prefix=1,-5\n"
		"Suffix=-27\n"
		"Form=*,1023:10,_;*,1:1,F:7,D:2,_\n"
	, 0 },
	{ "DAC4",
		"Frequency=38000\n"
		"Zero=500,-1000\n"
		"One=500,-500\n"
		"define X=(D+F)^1\n"
		"define Y=(1+D+F)^1\n"
		"First Bit=MSB\n"
		"Form=7000,-2800,0:1,D:8,F:8,X:8,500,-60m;7000,-2800,1:1,D:8,F:8,Y:8,500,-60m\n"
	, 0 },
	{ "Dell",
		"Define C=32796\n"
		"Frequency=36000\n"
		"Time Base=444\n"
		"Message Time=107m\n"
		"Zero=-1,1\n"
		"One=1,-1\n"
		"Prefix=6,-2,1,-1\n"
		"First Bit=MSB\n"
		"Form=;*,M:3,-2,2,C:16,T:1,D:7,F:8\n"
	, 1 },
	{ "Denon-K",
		"Frequency=37000\n"
		"Time Base=432\n"
		"Zero=1,-1\n"
		"One=1,-3\n"
		"Prefix=8,-4\n"
		"Default S=0\n"
		"Define C=(D*16)^S^(F*16)^(F:8:4)\n"
		"Suffix=1,-173\n"
		"Form=;*,84:8,50:8,0:4,D:4,S:4,F:12,C:8,_\n"
	, 0 },
	{ "denon",
		"Protocol=Denon\n"
		"Frequency=37917\n"
		"Time Base=264\n"
		"Zero=1,-3\n"
		"One=1,-7\n"
		"Suffix=1,-165\n"
		"Form=;D:5,F:8,0:2,_,D:5,~F:8,3:2,_\n"
	, 0 },
	{ "Dgtec",
		"Frequency=38000\n"
		"Time Base=560\n"
		"Zero=1,-1\n"
		"One=1,-3\n"
		"Form=;16,-8,D:8,F:8,~F:8,1,^108m\n"
	, 0 },
	{ "DishPlayer_Network",
		"Protocol=DishPlayer_Network\n"
		"Frequency=57600\n"
		"Time Base=410\n"
		"Zero=1,-7\n"
		"One=1,-4\n"
		"Suffix=1,-15\n"
		"Form=_;F:-6,S:5,D:5,_\n"
	, 0 },
	{ "Dreambox",
		"Define A=0\n"
		"Define B=3908\n"
		"Define G=0\n"
		"Define H=8\n"
		"Define J=0\n"
		"Frequency=38000\n"
		"First Bit=MSB\n"
		"0=210,-760\n"
		"1=210,-896\n"
		"2=210,-1032\n"
		"3=210,-1168\n"
		"4=210,-1304\n"
		"5=210,-1440\n"
		"6=210,-1576\n"
		"7=210,-1712\n"
		"8=210,-1848\n"
		"9=210,-1984\n"
		"10=210,-2120\n"
		"11=210,-2256\n"
		"12=210,-2392\n"
		"13=210,-2528\n"
		"14=210,-2664\n"
		"15=210,-2800\n"
		"Define C=0-A-S-B-(B:4:4)-(B:4:8)-D-(D:4:4)\n"
		"Define X=0-A-G-J-F-(F:4:4)-(F:4:8)-(F:4:12)\n"
		"Define Y=X+G-H\n"
		"Form=A:4,C:4,S:4,B:12,D:8,210,-13800,A:4,X:4,G:4,J:4,F:16,210,-80400;A:4,C:4,S:4,B:12,D:8,210,-13800,A:4,Y:4,H:4,J:4,F:16,210,-80400\n"
	, 0 },
	{ "emerson",
		"Protocol=EMERSON\n"
		"Frequency=36700\n"
		"Time Base=872\n"
		"Zero=1,-1\n"
		"One=1,-3\n"
		"Prefix=4,-4\n"
		"Suffix=1,-39\n"
		"Form=;*,D:6,F:6,~D:6,~F:6,_\n"
	, 0 },
	{ "f12",
		"Protocol=F12\n"
		"Frequency=38000\n"
		"Time Base=425\n"
		"Zero=1,-3\n"
		"One=3,-1\n"
		"Form=D:3,S:1,F:8,-80,D:3,S:1,F:8,-80\n"
	, 0 },
	{ "fujitsu",
		"Define E=0\n"
		"Define X=0\n"
		"Protocol= Fujitsu\n"
		"Frequency=38000\n"
		"Time Base=400\n"
		"Zero=1,-1\n"
		"One=1,-3\n"
		"Prefix=8,-4\n"
		"Suffix=1,-110\n"
		"Form=;*,20:8,99:8,X:4,E:4,D:8,S:8,F:8,_\n"
	, 0 },
	{ "Furby",
		"Protocol=Furby\n"
		"Frequency=40000\n"
		"Time Base=125\n"
		"Zero=1,-1,1,-5\n"
		"One=1,-1,1,-13\n"
		"Suffix=1,-1,1,-890\n"
		"Form=;D:5,F:8,_\n"
	, 0 },
	{ "GI4dtv",
		"Protocol=G.I.4dtv\n"
		"Frequency=37700\n"
		"Time Base=992\n"
		"Zero=1,-1\n"
		"One=1,-3\n"
		"Prefix=5,-2\n"
		"SUFFIX=1,-60\n"
		"Define B=D*64+F\n"
		"Define C=B^B*2^B*4^B*16^B*64^B*128^B*1024\n"
		"Form=;*,B:8,C:1:10,C:3:7,_\n"
	, 0 },
	{ "GI_cable",
		"Protocol=G.I.cable\n"
		"Frequency=38400\n"
		"Time Base=245\n"
		"Zero=2,-9\n"
		"One=2,-18\n"
		"Define C=-(D+(F:4)+(F:4:4))\n"
		"Form=36,-18,F:8,D:4,C:4,2,-120;36,-9,2,-356\n"
	, 0 },
	{ "imonpc",
		"Frequency=39700\n"
		"First Bit=MSB\n"
		"Define A=840\n"
		"Define B=300\n"
		"Message Time=200m\n"
		"0=(3*A-B),-(A+B)\n"
		"1=(2*A-B),-(2*A+B)\n"
		"2=(A-B),-(A+B),(A-B),-(A+B)\n"
		"3=(A-B),-(3*A+B)\n"
		"Form=;F:8,~F:8\n"
	, 0 },
	{ "iPod",
		"Protocol=NEC\n"
		"Frequency=38000\n"
		"Time Base=564\n"
		"One=1,-3\n"
		"Zero=1,-1\n"
		"Prefix=16,-8\n"
		"Suffix=1,-78\n"
		"R-Prefix=16,-4\n"
		"R-Suffix=1,-174\n"
		"Default S=~D\n"
		"Form=*,D:8,S:8,F:8,63:8,_;*,_\n"
	, 0 },
	{ "jvc",
		"Protocol=JVC\n"
		"Frequency=37900\n"
		"Time Base=527\n"
		"Zero=1,-1\n"
		"One=1,-3\n"
		"Prefix=16,-8\n"
		"Form=*;D:8,F:8,1,^88\n"
	, 0 },
	{ "jvc_two_frames",
		"Frequency=37900\n"
		"Time Base=527\n"
		"Zero=1,-1\n"
		"One=1,-3\n"
		"Prefix=16,-8\n"
		"Form=*,D:8,F:8,1,^88;D:8,F:8,1,^88\n"
	, 0 },
	{ "Kaseikyo",
		"define N=90\n"
		"define E=1\n"
		"Frequency=37000\n"
		"Time Base=432\n"
		"Zero=1,-1\n"
		"One=1,-3\n"
		"Prefix=8,-4\n"
		"Default S=0\n"
		"Define X=M^N^(M:4:4)^(N:4:4)\n"
		"Define C=D^S^F^E^(S:4:4)^(F:4:4)\n"
		"Suffix=1,-173\n"
		"Form=;*,M:8,N:8,X:4,D:4,S:8,F:8,E:4,C:4,_\n"
	, 0 },
	{ "Kramer",
		"Frequency=38462\n"
		"Zero=-1m,1m\n"
		"One=-1m,2m\n"
		"Form=4m,D:8,-2m,4500u,F:8,-33m\n"
	, 0 },
	{ "lumagen",
		"Frequency=38000\n"
		"Time Base=416\n"
		"First Bit=MSB\n"
		"Zero=1,-6\n"
		"One=1,-12\n"
		"define X=F^(F:4:4)\n"
		"define C=X^(X:1:1)^(X:1:2)^(X:1:3)\n"
		"Form=;D:4,~C:1,F:7,1,-26\n"
	, 0 },
	{ "mce",
		"Frequency=36000\n"
		"Time Base=444\n"
		"Message Time=106m\n"
		"Zero=-1,1\n"
		"One=1,-1\n"
		"First Bit=MSB\n"
		"Form=;6,-2,1:1,M:3,-2,2,128:8,S:8,T:1,D:7,F:8\n"
	, 1 },
	{ "Mitsubishi",
		"Protocol= Mitsubishi\n"
		"Frequency=32600\n"
		"Time Base=300\n"
		"Zero=1,-3\n"
		"One=1,-7\n"
		"Suffix=1,-80\n"
		"Form=;D:8,F:8,_\n"
	, 0 },
	{ "nec1",
		"Protocol=NEC\n"
		"Frequency=38000\n"
		"Time Base=564\n"
		"One=1,-3\n"
		"Zero=1,-1\n"
		"Prefix=16,-8\n"
		"Suffix=1,-78\n"
		"R-Prefix=16,-4\n"
		"R-Suffix=1,-174\n"
		"Default S=~D\n"
		"Form=*,D:8,S:8,F:8,~F:8,_;*,_\n"
	, 0 },
	{ "nec2",
		"Protocol=NEC2\n"
		"Frequency=38000\n"
		"Time Base=564\n"
		"One=1,-3\n"
		"Zero=1,-1\n"
		"Prefix=16,-8\n"
		"Suffix=1,-78\n"
		"Default S=~D\n"
		"Form=;*,D:8,S:8,F:8,~F:8,_\n"
	, 0 },
	{ "NECx1",
		"Protocol=NECx1\n"
		"Frequency=38000\n"
		"Time Base=564\n"
		"One=1,-3\n"
		"Zero=1,-1\n"
		"Prefix=8,-8\n"
		"Suffix=1,-78\n"
		"Default S=D\n"
		"R-Suffix=~D:1,1,-170\n"
		"Form=*,D:8,S:8,F:8,~F:8,_;*,_\n"
	, 0 },
	{ "NECx2",
		"Protocol=NECx2\n"
		"Frequency=38000\n"
		"Time Base=564\n"
		"One=1,-3\n"
		"Zero=1,-1\n"
		"Prefix=8,-8\n"
		"Suffix=1,-78\n"
		"Default S=D\n"
		"Form=;*,D:8,S:8,F:8,~F:8,_\n"
	, 0 },
	{ "Nokia32",
		"Define X=38\n"
		"Default S=0\n"
		"Protocol=Nokia32\n"
		"Frequency=36000\n"
		"First Bit=MSB\n"
		"Zero=164,-276\n"
		"One=164,-445\n"
		"TWO=164,-614\n"
		"THREE=164,-783\n"
		"Form=;412,-276,D:8,S:8,X:8,F:8,164,^100m\n"
	, 0 },
	{ "Nokia32single",
		"Define X=38\n"
		"Frequency=36000\n"
		"First Bit=MSB\n"
		"Zero=164,-276\n"
		"One=164,-445\n"
		"TWO=164,-614\n"
		"THREE=164,-783\n"
		"Form=412,-276,D:8,S:8,X:8,F:8,164,^100m,412,-276,D:8,S:8,(X+128):8,F:8,164,-10m\n"
	, 0 },
	{ "panasonic",
		"Protocol= Panasonic\n"
		"Frequency=37000\n"
		"Time Base=432\n"
		"Zero=1,-1\n"
		"One=1,-3\n"
		"Prefix=8,-4\n"
		"Default S=0\n"
		"Define C=D^S^F\n"
		"Suffix=1,-173\n"
		"Form=;*,2:8,32:8,D:8,S:8,F:8,C:8,_\n"
	, 0 },
	{ "panasonic2",
		"Define X=0\n"
		"Frequency=37000\n"
		"Time Base=432\n"
		"Zero=1,-1\n"
		"One=1,-3\n"
		"Prefix=8,-4\n"
		"Default S=0\n"
		"Define C=D^S^X^F\n"
		"Suffix=1,-173\n"
		"Form=;*,2:8,32:8,D:8,S:8,X:8,F:8,C:8,_\n"
	, 0 },
	{ "Panasonic_Old",
		"Protocol=Panasonic_Old\n"
		"Frequency=57600\n"
		"Time Base=833\n"
		"Message Time=100m\n"
		"Zero=1,-1\n"
		"One=1,-3\n"
		"Prefix=4,-4\n"
		"Suffix=1\n"
		"Form=;*,D:5,F:6,~D:5,~F:6,_\n"
	, 0 },
	{ "pioneer",
		"Protocol=Pioneer\n"
		"Frequency=40000\n"
		"Time Base=550\n"
		"One=1,-3\n"
		"Zero=1,-1\n"
		"Prefix=16,-8\n"
		"Suffix=1,-78\n"
		"Default S=~D\n"
		"Form=;*,D:8,S:8,F:8,~F:8,_\n"
	, 0 },
	{ "pioneer2",
		"Define P=86\n"
		"Protocol=Pioneer2\n"
		"Frequency=40000\n"
		"Time Base=550\n"
		"One=1,-3\n"
		"Zero=1,-1\n"
		"Prefix=16,-8\n"
		"Suffix=1,-78\n"
		"Form=;*,D:8,~D:8,P:8,~P:8,_,*,S:8,~S:8,F:8,~F:8,_\n"
	, 0 },
	{ "Polycom",
		"Protocol=Polycom\n"
		"Frequency=38740\n"
		"Zero=880,-1200\n"
		"One=580,-880\n"
		"Prefix=2600,-2600\n"
		"Suffix=580,-60000\n"
		"Form=*,D:-8,F:-6,0:2,_,*,D:-8,3:-8,_\n"
	, 0 },
	{ "Proton",
		"Protocol=Proton\n"
		"Frequency=38000\n"
		"Time Base=500\n"
		"Zero=1,-1\n"
		"One=1,-3\n"
		"Prefix=16,-8\n"
		"Suffix=1,-45\n"
		"Form=;*,D:8,1,-8,F:8,_\n"
	, 0 },
	{ "rc5-M-L",
		"Protocol=RC5\n"
		"Frequency=36000\n"
		"Time Base=889\n"
		"Message Time=128\n"
		"Zero=1,-1\n"
		"One=-1,1\n"
		"Prefix=1\n"
		"First Bit=MSB\n"
		"Form=;*,M:1,T:1,D:5,S:(L-16),F:8\n"
	, 1 },
	{ "rc5",
		"Protocol=RC5\n"
		"Frequency=36000\n"
		"Time Base=889\n"
		"Message Time=128\n"
		"Zero=1,-1\n"
		"One=-1,1\n"
		"Prefix=1\n"
		"First Bit=MSB\n"
		"Form=;*,~F:1:6,T:1,D:5,F:6\n"
	, 1 },
	{ "rc5odd",
		"Protocol=RC5\n"
		"Frequency=36000\n"
		"Time Base=889\n"
		"Message Time=128\n"
		"Zero=1,-1\n"
		"One=-1,1\n"
		"Prefix=1\n"
		"First Bit=MSB\n"
		"Form=;*,~F:1:6,1:1,D:5,F:6\n"
	, 0 },
	{ "rc5x",
		"Protocol=RC5x\n"
		"Frequency=36000\n"
		"Time Base=889\n"
		"Message Time=128\n"
		"Zero=1,-1\n"
		"One=-1,1\n"
		"First Bit=MSB\n"
		"Form=;1,~S:1:6,T:1,D:5,-4,S:6,F:6\n"
	, 1 },
	{ "rc6-M-L",
		"Protocol=RC6\n"
		"Frequency=36000\n"
		"Time Base=444\n"
		"Message Time=107m\n"
		"Zero=-1,1\n"
		"One=1,-1\n"
		"Prefix=6,-2,1,-1\n"
		"First Bit=MSB\n"
		"Default S=0\n"
		"Form=;*,M:3,(4*T-2),(2-4*T),D:8,S:(L-16),F:8\n"
	, 1 },
	{ "rc6",
		"Protocol=RC6\n"
		"Frequency=36000\n"
		"Time Base=444\n"
		"Message Time=107m\n"
		"Zero=-1,1\n"
		"One=1,-1\n"
		"Prefix=6,-2,1,-1\n"
		"First Bit=MSB\n"
		"Form=;*,M:3,(4*T-2),(2-4*T),D:8,F:8\n"
	, 1 },
	{ "RCA-38",
		"Protocol=RCA-38\n"
		"Frequency=38700\n"
		"Time Base=460\n"
		"Zero=1,-2\n"
		"One=1,-4\n"
		"Prefix=8,-8\n"
		"Suffix=1,-16\n"
		"First Bit=MSB\n"
		"Form=;*,D:4,F:8,~D:4,~F:8,_\n"
	, 0 },
	{ "rca",
		"Protocol=RCA\n"
		"Frequency=58000\n"
		"Time Base=460\n"
		"Zero=1,-2\n"
		"One=1,-4\n"
		"Prefix=8,-8\n"
		"Suffix=1,-16\n"
		"First Bit=MSB\n"
		"Form=;*,D:4,F:8,~D:4,~F:8,_\n"
	, 0 },
	{ "recs80_45",
		"Frequency=38000\n"
		"Zero=170,-4900\n"
		"One=170,-7425\n"
		"MESSAGETIME=121000\n"
		"First Bit=MSB\n"
		"Form=;1:1,T:1,D:3,F:6,170\n"
	, 1 },
	{ "recs80_68",
		"Frequency=36400\n"
		"Zero=170,-5580\n"
		"One=170,-8440\n"
		"MESSAGETIME=138000\n"
		"First Bit=MSB\n"
		"Form=;1:1,T:1,D:3,F:6,170\n"
	, 1 },
	{ "russound",
		"Frequency=38400\n"
		"Time Base=601\n"
		"Zero=1,-1\n"
		"One=1,-2\n"
		"Two=2,-1\n"
		"Three=2,-2\n"
		"First Bit=MSB\n"
		"Define C=7*(F:2:6)+5*(F:2:4)+3*(F:2:2)+(F:2)\n"
		"Form=10,-2,D:4,F:8,C:4,1,-50;5,-2,D:4,F:8,C:4,1,-50\n"
	, 0 },
	{ "sagem",
		"Frequency=56000\n"
		"Time Base=250\n"
		"Zero=-1,1\n"
		"One=1,-1\n"
		"First Bit=MSB\n"
		"Form=1:1,D:6,S:7,0:1,F:8,-350;1:1,D:6,S:7,1:1,F:8,-350\n"
	, 0 },
	{ "Samsung20",
		"Protocol=Samsung20\n"
		"Frequency=38400\n"
		"Time Base=564\n"
		"One=1,-3\n"
		"Zero=1,-1\n"
		"Default S=0\n"
		"Form=;8,-8,D:6,S:6,F:8,1,-44\n"
	, 0 },
	{ "Samsung36",
		"define E=1\n"
		"Frequency=38000\n"
		"One=498,-1498\n"
		"Zero=498,-498\n"
		"Form=;4488,-4492,d:8,s:8,498,-4498,e:4,f:8,-68,~f:8,498,-59154\n"
	, 0 },
	{ "sharp",
		"Protocol=SHARP\n"
		"Frequency=37917\n"
		"Time Base=264\n"
		"Zero=1,-3\n"
		"One=1,-7\n"
		"Suffix=1,-165\n"
		"Form=;D:5,F:8,1:2,_,D:5,~F:8,2:2,_\n"
	, 0 },
	{ "Sony12",
		"Protocol=Sony12\n"
		"Frequency=40000\n"
		"Time Base=600\n"
		"One=2,-1\n"
		"Zero=1,-1\n"
		"Prefix=4,-1\n"
		"Message Time=45m\n"
		"Form=;*,f:7,d:5\n"
	, 0 },
	{ "Sony15",
		"Protocol=Sony15\n"
		"Frequency=40000\n"
		"Time Base=600\n"
		"One=2,-1\n"
		"Zero=1,-1\n"
		"Prefix=4,-1\n"
		"Message Time=45m\n"
		"Form=;*,f:7,d:8\n"
	, 0 },
	{ "Sony20",
		"Protocol=Sony20\n"
		"Frequency=40000\n"
		"Time Base=600\n"
		"One=2,-1\n"
		"Zero=1,-1\n"
		"Prefix=4,-1\n"
		"Message Time=45m\n"
		"Form=;*,f:7,d:5,s:8\n"
	, 0 },
	{ "streamzap",
		"Frequency=59000\n"
		"Time Base=889\n"
		"Zero=1,-1\n"
		"One=-1,1\n"
		"Message Time=114\n"
		"First Bit=MSB\n"
		"Form=;1:1,~F:1:6,T:1,D:6,F:6\n"
	, 1 },
	{ "Teac-K",
		"define N=83\n"
		"Frequency=37900\n"
		"Time Base=432\n"
		"Zero=1,-1\n"
		"One=1,-3\n"
		"Default S=0\n"
		"Define X=M^N^(M:4:4)^(N:4:4)\n"
		"Form=8,-4,M:8,N:8,X:4,D:4,S:8,F:8,T:8,1,-100;8,-8,1,-100\n"
	, 1 },
	{ "Thomson",
		"Protocol=Thomson\n"
		"Frequency=33000\n"
		"Time Base=500\n"
		"Zero=1,-4\n"
		"One=1,-9\n"
		"Suffix=1\n"
		"Message Time=80m\n"
		"Form=;D:4,T:1,D:1:5,F:6,1\n"
	, 1 },
	{ "Tivo-Nec1",
		"define U=0\n"
		"Protocol=TivoNec\n"
		"Frequency=38000\n"
		"Time Base=564\n"
		"One=1,-3\n"
		"Zero=1,-1\n"
		"Prefix=16,-8\n"
		"Suffix=1,-78\n"
		"R-Prefix=16,-4\n"
		"R-Suffix=1,-174\n"
		"Default S=~D\n"
		"Form=*,D:8,S:8,F:8,U:4,~F:4:4,_;*,_\n"
	, 0 },
	{ "TViX",
		"Protocol=NEC\n"
		"Frequency=38000\n"
		"Time Base=564\n"
		"One=1,-3\n"
		"Zero=1,-1\n"
		"Prefix=16,-8\n"
		"Suffix=1,-78\n"
		"R-Prefix=16,-4\n"
		"R-Suffix=1,-174\n"
		"Default S=~D\n"
		"Form=*,D:8,F:8,0:8,0:8,_;*,_\n"
	, 0 },
	{ "x10ir",
		"Protocol=X10IR\n"
		"Frequency=40000\n"
		"Time Base=650\n"
		"One=7,-7\n"
		"Zero=2,-13\n"
		"Form=;*,F:5,~F:5,_\n"
		"Prefix=8,-8\n"
		"suffix=23,-8\n"
	, 0 },
	{ "XMP",
		"Define A=S:4:4\n"
		"Define B=3908\n"
		"Define G=0\n"
		"Define H=8\n"
		"Define J=S\n"
		"Frequency=38000\n"
		"First Bit=MSB\n"
		"0=210,-760\n"
		"1=210,-896\n"
		"2=210,-1032\n"
		"3=210,-1168\n"
		"4=210,-1304\n"
		"5=210,-1440\n"
		"6=210,-1576\n"
		"7=210,-1712\n"
		"8=210,-1848\n"
		"9=210,-1984\n"
		"10=210,-2120\n"
		"11=210,-2256\n"
		"12=210,-2392\n"
		"13=210,-2528\n"
		"14=210,-2664\n"
		"15=210,-2800\n"
		"Define C=0-A-S-B-(B:4:4)-(B:4:8)-D-(D:4:4)\n"
		"Define X=0-A-G-J-F-(F:4:4)-(F:4:8)-(F:4:12)\n"
		"Define Y=X+G-H\n"
		"Form=A:4,C:4,S:4,B:12,D:8,210,-13800,A:4,X:4,G:4,J:4,F:8,F:8:8,210,-80400;A:4,C:4,S:4,B:12,D:8,210,-13800,A:4,Y:4,H:4,J:4,F:8,F:8:8,210,-80400\n"
	, 0 }
};

int main(int argc, char** argv)
{
	if (argc != 5 && argc != 6)
	{
		printf("{\"error\":\"invalid arguments\"}\n");
		return 0;
	}

	char irp[1024] = "";

	// Handle D, S, F, T
	int D = atoi(argv[2]);
	int S = atoi(argv[3]);
	int F = atoi(argv[4]);
	int T = 0;
	if (argc == 6) T = atoi(argv[5]);
	if (S >= 0)
		sprintf(irp, "Device=%d.%d\nFunction=%d\nDefine T=%d\n", D, S, F, T);
	else
		sprintf(irp, "Device=%d\nFunction=%d\nDefine T=%d\n", D, F, T);

	// Search for protocol
	char *prot = argv[1];
	int p = -1;
	for (int i = 0; i < count(protdefs); i++)
		if (strcasecmp(prot, protdefs[i].prot) == 0) {
			p = i;
			break;
		}
	if (p < 0) {
		// Protocol not found, try for special protocols
		int M = 0, L = 0;
		int I = 0;
		for (int i = 0; i < strlen(prot); i++) {
			prot[i] = toupper(prot[i]);
			if (prot[i] == '{') {
				prot[i] = 0;
				break;
			}
		}
		if (sscanf(prot, "RC6-%d-%d", &M, &L) == 2 && M < 8 && L >= 16) {
			char temp[256];
			sprintf (temp, "Define M=%d\nDefine L=%d\n", M, L);
			strcat(irp, temp);
			prot = "rc6-M-L";
		}
		if (sscanf(prot, "RC5-%d-%d", &M, &L) == 2 && M < 2 && L >= 16) {
			char temp[256];
			sprintf (temp, "Define M=%d\nDefine L=%d\n", M, L);
			strcat(irp, temp);
			prot = "rc5-M-L";
		}
		else if (sscanf(prot, "APPLE-%d", &I) == 1) {
			char temp[256];
			sprintf (temp, "Define I=%d\n", I);
			strcat(irp, temp);
			prot = "apple-I";
		}
		else if (strcmp("NEC", prot) == 0)
			prot = "nec2";
		else if (strcmp("NECX", prot) == 0)
			prot = "NECx2";
		// Search again for protocol
		for (int i = 0; i < count(protdefs); i++)
			if (strcasecmp(prot, protdefs[i].prot) == 0) {
				p = i;
				break;
			}
		if (p < 0) {
			printf ("{\"error\":\"unknown protocol\"}\n");
			return 0;
		}
	}
	strcat(irp, protdefs[p].def);
	
	// Parse
	IRP Irp;
	if (!Irp.readIrpString(irp)) {
		printf ("{\"error\":\"invalid irp\"}\n");
		return 0;
	}

	// Encode
	int s, r;
	float seq[1024], prd;
	Irp.m_value['D' - 'A'] = D;
	Irp.m_value['S' - 'A'] = S;
	Irp.m_value['F' - 'A'] = F;
	Irp.m_value['N' - 'A'] = -1;
	Irp.generate(&s, &r, seq);

	// Output
	prd = 1000000. / Irp.m_frequency;
	printf("{\"frequency\":%g,\"n\":%d,\"repeat\":[0,%d,%d],\"seq\":[", Irp.m_frequency, 2*(s+r), 2*s, 2*(s+r));
	for (int i = 0; i < 2*(s + r); i+=2) {
		int v1 = floor(seq[i] / prd + 0.5);
		int v2 = floor((seq[i] + seq[i+1]) / prd + 0.5) - v1;
		printf ("%s%d,%d", i?",":"", v1, v2);
	}
	printf ("]}\n");
	
	return 0;
}
