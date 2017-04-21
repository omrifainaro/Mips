#include <stdio.h>
#include "Instruction.h"

void pause();

int main() {
	INSTRUCTION* inst;
	inst = newInstruction(0x01384020);
	printInstruction(inst);
	inst = newInstruction(0x08002FFF);
	printInstruction(inst);
	inst = newInstruction(0x2149FFFF);
	printInstruction(inst);
	inst = newInstruction(0xc52A5A0);
	printInstruction(inst);
	free(inst);
	pause();
	return 0;
}

void pause() {
	printf("press any key to continue...");
	getchar();
}