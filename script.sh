make all
sudo avrdude -p m32 -c usbasp -e -U flash:w:deployer.hex
make clean
