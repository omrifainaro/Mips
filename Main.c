#include <stdio.h>
#include "Instruction.h"

void pause();

int main() {
	INSTRUCTION* inst;
	inst = newInstruction(0x014B4820);
	printInstruction(inst);
	inst = newInstruction(0x08002FFF);
	printInstruction(inst);
	inst = newInstruction(0x2149FFFF);
	printInstruction(inst);
	inst = newInstruction(0xc52A5A0);
	printInstruction(inst);
	pause();
	return 0;
}

void pause() {
	printf("press any key to continue...");
	getchar();
}