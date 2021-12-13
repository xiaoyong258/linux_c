.PHONY: all

all: 
	make -C lcd
	make -C usb
	make -C media
	make -C app

clean:
	rm -rf app/player.o app/mp3
	rm -rf lcd/*.o
	rm -rf lcd/*.d
	rm -rf usb/*.o
	rm -rf usb/*.d
	rm -rf media/*.o
	rm -rf media/*.d
