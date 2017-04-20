#include "Instruction.h"
//http://www.mrc.uidaho.edu/mrc/people/jff/digital/MIPSir.html all instructions

INSTRUCTION* newInstruction(unsigned int opcode) {
	INSTRUCTION* inst;
	inst = (INSTRUCTION*)malloc(sizeof(INSTRUCTION));
	unsigned char op = opcode >> 26;
	inst->op.ijop = op;
	format f;
	getIJInstructionName(op, &f);
	inst->type = f;
	if (f == R_FORMAT) {
		inst->body.R.func = opcode & 0x3f;
		inst->body.R.shift = (opcode >> 6) & 0x1f;
		inst->body.R.rd = (opcode >> 11) & 0x1f;
		inst->body.R.rt = (opcode >> 16) & 0x1f;
		inst->body.R.rs= (opcode >> 21) & 0x1f;
	}
	else if (f == I_FORMAT){
		inst->body.I.imm = opcode & 0xffff;
		inst->body.I.rt = (opcode >> 16) & 0x1f;
		inst->body.I.rt = (opcode >> 21) & 0x1f;
	}
	else if (f == J_FORMAT) {
		inst->body.J.addr = opcode & 0x3ffffff;
	}
	return inst;
}

void printInstruction(INSTRUCTION* inst) {
	if (inst->type == R_FORMAT) {
		printf("%s %x, %x, %x\n", getRInsructionName(inst), inst->body.R.rs, inst->body.R.rt,
			inst->body.R.rd);
	}
	else if (inst->type == I_FORMAT) {
		printf("%s %x, %x, %x\n", getIJInstructionName(inst->op.ijop, &inst->type), inst->body.I.rs, inst->body.I.rt, inst->body.I.imm);
	}
	else if (inst->type == J_FORMAT) {
		printf("%s %x\n", getIJInstructionName(inst->op.ijop, &inst->type), inst->body.J.addr);
	}
}

char* getIJInstructionName(char op, format* f) {
	switch (absoluteVal(op))
	{
	case BNE:
		*f = I_FORMAT;
		return "BNE\0";
		break;
	case BEQ:
		*f = I_FORMAT;
		return "BEQ\0";
		break;
	case SB:
		*f = I_FORMAT;
		return "SB\0";
		break;
	case SH:
		*f = I_FORMAT;
		return "SH\0";
		break;
	case SW:
		*f = I_FORMAT;
		return "SW\0";
		break;
	case LB:
		*f = I_FORMAT;
		return "LB\0";
		break;
	case LBU:
		*f = I_FORMAT;
		return "LBU\0";
		break;
	case LH:
		*f = I_FORMAT;
		return "LH\0";
		break;
	case LHU:
		*f = I_FORMAT;
		return "LHU\0";
		break;
	case LW:
		*f = I_FORMAT;
		return "LW\0";
		break;
	case J:
		*f = J_FORMAT;
		return "J\0";
		break;
	case JAL:
		*f = J_FORMAT;
		return "JAL\0";
		break;
	//case JALR:
	//	break;
	case LHI:
		*f = I_FORMAT;
		return "LHI\0";
		break;
	case ORI:
		*f = I_FORMAT;
		return "ORI\0";
		break;
	case ADDI:
		*f = I_FORMAT;
		return "ADDI\0";
		break;
	case ADDIU:
		*f = I_FORMAT;
		return "ADDIU\0";
		break;
	case ANDI:
		*f = I_FORMAT;
		return "ANDI\0";
		break;
	case XORI:
		*f = I_FORMAT;
		return "XORI\0";
		break;
	case SLTI:
		*f = I_FORMAT;
		return "SLTI\0";
		break;
	case MFHI:
		*f = I_FORMAT;
		return "MFHI\0";
		break;
	//case SLTIU:
	//	break;
	case MTHI:
		*f = I_FORMAT;
		return "MTHI\0";
		break;
	default:
		*f = R_FORMAT;
		return "NULL\0";
		break;
	}
}

char* getRInsructionName(INSTRUCTION* inst) {
	switch (absoluteVal(inst->body.R.func)) {
	case ADD:
		return "ADD\0";
		break;
	case ADDU:
		return "ADDU\0";
		break;
	case AND:
		return "AND\0";
		break;
	case DIV:
		return "DIV\0";
		break;
	case DIVU:
		return "DIVU\0";
		break;
	case MULT:
		return "MULT\0";
		break;
	case MULTU:
		return "MULTU\0";
		break;
	case NOR:
		return "NOR\0";
		break;
	case OR:
		return "OR\0";
		break;
	case SLL:
		return "SLL\0";
		break;
	case SLLV:
		return "SLV\0";
		break;
	case SRA:
		return "SRA\0";
		break;
	case SRAV:
		return "SRAV\0";
		break;
	case SRL:
		return "SRL\0";
		break;
	case SRLV:
		return "SRLV\0";
		break;
	case SUB:
		return "SUB\0";
		break;
	case SUBU:
		return "SUBU\0";
		break;
	case XOR:
		return "XOR\0";
		break;
	//case LLO:
	//	break;
	case SLT:
		return "SLT\0";
		break;
	case SLTU:
		return "SLTU\0";
		break;
	//case BGTZ: dont know yet what to do
	//	break;   these instructions are real
	//case BLEZ:
	//	break;
	case MFLO:
		return "MFLO\0";
		break;
	case MTLO:
		return "MTLO\0";
		break;
	//case TRAP:
	//	break;
	case JR:
		return "JR\0";
		break;
	default:
		return "NULL\0";
		break;
	}
}