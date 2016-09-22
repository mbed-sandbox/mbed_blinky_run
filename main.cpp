#include "mbed.h"

//test setting up an mbed pin as a class member initialized in the constructor
class flasher {
public:
	DigitalOut LED1;
	DigitalOut LED2;
	DigitalOut LED3;
	DigitalOut LED4;
	DigitalOut LED5;
	DigitalOut LED6;
	DigitalOut LED7;
	DigitalOut LED8;

	flasher() :
			LED1(P2_0), LED2(P2_1), LED3(P2_2), LED4(P2_3), LED5(P2_4), LED6(
					P2_5), LED7(P2_6), LED8(P2_7) {
	}

	void flash(void) {
		LED1 = 1;
		wait(0.05);
		LED1 = 0;
		wait(0.15);
		LED2 = 1;
		wait(0.05);
		LED2 = 0;
		wait(0.15);
		LED3 = 1;
		wait(0.05);
		LED3 = 0;
		wait(0.15);
		LED4 = 1;
		wait(0.05);
		LED4 = 0;
		wait(0.15);
		LED5 = 1;
		wait(0.05);
		LED5 = 0;
		wait(0.15);
		LED6 = 1;
		wait(0.05);
		LED6 = 0;
		wait(0.15);
		LED7 = 1;
		wait(0.05);
		LED7 = 0;
		wait(0.15);
		LED8 = 1;
		wait(0.05);
		LED8 = 0;
		wait(0.15);

	}
};

Serial serial(P0_2, P0_3); //RxD, TxD usb
int adc0Val;
double ch1, ch2;
int main() {
//    flasher ff;
	serial.baud(115200);
	serial.printf("Ready\r\n");

	AnalogIn CH1(P0_23);
	AnalogIn CH2(P0_24);
	AnalogIn CH3(P0_25);
	AnalogIn CH4(P0_26);
	AnalogIn CH5(P1_30);
	AnalogIn CH6(P1_31);

	DigitalOut RELAY1(P2_11);
	DigitalOut RELAY2(P2_12);
	DigitalOut RELAY3(P0_22);
	//DigitalOut RELAY4(P2_10);
	//DigitalOut RELAY5(P0_20);
	//DigitalOut RELAY6(P0_21);

	RELAY1 = 0;
	RELAY2 = 0;
	RELAY3 = 0;
//	RELAY4 = 0;
//	RELAY5 = 0;
//	RELAY6 = 0;

	while (1) {
//    	RELAY1 = 1;  wait(0.5);
//    	RELAY1 = 0;  wait(0.5);
//    	RELAY2 = 1;  wait(0.5);
//    	RELAY2 = 0;  wait(0.5);
//    	RELAY3 = 1;  wait(0.5);
//    	RELAY3 = 0;  wait(0.5);
//    	RELAY4 = 1;  wait(0.5);
//    	RELAY4 = 0;  wait(0.5);
//    	RELAY5 = 1;  wait(0.5);
//    	RELAY5 = 0;  wait(0.5);
//    	RELAY6 = 1;  wait(0.5);
//    	RELAY6 = 0;  wait(0.5);
//        adc0Val = CH2.read_u16();

//		for (int i = 0; i < 10; i++) {
			ch1 = CH1.read_u16();
			ch2 = CH2.read_u16();
//		}

		serial.printf("%.3f,%.3f\r\n", (ch1 - 50320)/735.577,
				(ch2 - 50370) /735.577 );

		ch1 = 0.0;
		ch2 = 0.0;

		wait(0.5);
//		for (int i = 0; i < 1000; i++) {
//			ch1 += CH1.read_u16();
//			ch2 += CH2.read_u16();
//		}
//
//		serial.printf("%.3f (%f), %.3f (%f) \r\n", (ch1 - 50320805)/735577,ch1,
//				(ch2 - 50370805) /735577 , ch2);

		//wait(0.5);
//        ff.flash();
		//wait(0.25);
	}

}
