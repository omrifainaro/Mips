#ifndef INSTRUCTION_H
#define INSTRUCTION_H
#include <stdlib.h>
#include "constants.h"
#include "Utils.h"

typedef enum {
	BNE = 0x5,
	BEQ = 0x4,
	SB = 0x28,
	SH = 0x29,
	SW = 0x2b,
	LB = 0x20,
	LBU = 0x24,
	LH = 0x21,
	LHU = 0x25,
	LW = 0x23,
	J = 0x2,
	JAL = 0x3,
	//JALR = 0x9,
	LHI = 0x19,
	ORI = 0xd,
	ADDI = 0x8,
	ADDIU = 0x9,
	ANDI = 0xc,
	XORI = 0xe,
	SLTI = 0xa,
	MFHI = 0x10,
	SLTIU = 0x9,
	MTHI = 0x11
} ij_operator;

typedef enum {
	ADD = 0x20,
	ADDU = 0x21,
	AND = 0x24,
	DIV = 0x1a,
	DIVU = 0x1b,
	MULT = 0x18,
	MULTU = 0x19,
	NOR = 0x27,
	OR = 0x25,
	SLL = 0x0,
	SLLV = 0x4,
	SRA = 0x3,
	SRAV = 0x7,
	SRL = 0x2,
	SRLV = 0x6,
	SUB = 0x22,
	SUBU = 0x23,
	XOR = 0x26,
	LLO = 0x18,
	SLT = 0x2a,
	SLTU = 0x29,
	BGTZ = 0x7,
	BLEZ = 0x6,
	MFLO = 0x12,
	MTLO = 0x13,
	TRAP = 0x1a,
	JR = 0x8,
}r_operator;

typedef enum {
	J_FORMAT, I_FORMAT, R_FORMAT
} format;

typedef struct {
	format type;
	union {
		r_operator rop;
		ij_operator ijop;
	} op;
	union {
		struct {
			unsigned char rs;
			unsigned char rt;
			unsigned char rd;
			unsigned char shift;
			unsigned char func;
		} R;
		struct {
			unsigned char rs;
			unsigned char rt;
			unsigned char imm;
		} I;
		struct {
			unsigned int addr;
		} J;
	} body;
} INSTRUCTION;

INSTRUCTION* newInstruction(unsigned int opcode);
void printInstruction(INSTRUCTION* inst);
char* getIJInstructionName(char op, format* f);
char* getRInsructionName(INSTRUCTION* inst);
#endif