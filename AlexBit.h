/* AlexBit.h
*  Written 2013, Alex Noble.
*  A struct that lets you individually store and lookup individual bit values in a byte.
*  Usage Situation:
*  Keep 8 booleans in a 1 byte long chunk of memory, rather than 8 bytes.
*
*  Fixed logical fallacy that occurs in the version I have on pastebin at (https://pastebin.com/WvntvJDj)
*  Size: 1 byte
*  returnBit(int whatBit) returns value (1 or 0) of the bit number given in the parameter (0 to 7).
*  setBit(int whatBit) flips value of the bit number given in the parameter (0 to 7).
*  setAllBits(int bitValue) sets all bits to the given value in the parameter (0 or 1).
*  setChar(char Char) sets all bits to the same as the given char.
*  printByte() prints out the byte. (Goes from 7 to 0 to print out in correct order).
*  encryptByte(char key) encrypts the bits with xor encryption using the given key.
*  decryptByte(char key) -- See above --
*/
#ifndef ALEXBITH
struct AlexBit
{
        unsigned char container;
        int returnBit(int whatBit);
        void setBit(int whatBit);
        int setAllBits(int bitValue);
        int setChar(char Char);
        void printByte();
		// Not very reliable encryption but why not
        void encryptByte(char key);
        void decryptByte(char key);
};
void AlexBit::setBit(int whatBit)
{
        if(whatBit <= 7 && whatBit >= 0)
                container ^= 1 << whatBit;
}
int AlexBit::returnBit(int whatBit)
{
        if(whatBit <= 7 && whatBit >= 0)
                return (container & (1 << whatBit)) >> whatBit;
        return -1;
}
int AlexBit::setAllBits(int bitValue)
{
	if(bitValue == 1 || bitValue == 0)
	{
		for(int i = 0; i < 8; i++)
			if(returnBit(i) != bitValue)
				setBit(i);
		return 0;
	}
	return -1;
}
int AlexBit::setChar(char Char)
{
        container = Char;
        return 0;
}
void AlexBit::printByte()
{
        int i(8);
        while(i-- > 0) std::cout << returnBit(i);
}
void AlexBit::encryptByte(char key)
{
        container ^= key;
}
void AlexBit::decryptByte(char key)
{
        container ^= key;
}
#endif