#!/usr/bin/env python

# thanks to Oleg Endo for his work at:
# https://github.com/shared-ptr/sh_insns
# http://www.shared-ptr.com/sh_insns.html

from enum import Enum, auto, unique

#------------------------------------------------------------------------------
# ENUMERATIONS
#------------------------------------------------------------------------------

@unique
class OP(Enum):
    ERROR = 0	
    ADD = auto()
    ADDC = auto()
    ADDV = auto()
    AND = auto()
    BF = auto()
    BRA = auto()
    BRAF = auto()
    BSR = auto()
    BSRF = auto()
    BT = auto()
    CLRMAC = auto()
    CLRS = auto()
    CLRT = auto()
    CMP = auto()
    DIV0S = auto()
    DIV0U = auto()
    DIV1 = auto()
    DMULS = auto()
    DMULU = auto()
    DT = auto()
    EXTS = auto()
    EXTU = auto()
    FABS = auto()
    FADD = auto()
    FCMP = auto()
    FCNVDS = auto()
    FCNVSD = auto()
    FDIV = auto()
    FIPR = auto()
    FLDI0 = auto()
    FLDI1 = auto()
    FLDS = auto()
    FLOAT = auto()
    FMAC = auto()
    FMOV = auto()
    FMUL = auto()
    FNEG = auto()
    FRCHG = auto()
    FSCA = auto()
    FSCHG = auto()
    FSQRT = auto()
    FSRRA = auto()
    FSTS = auto()
    FSUB = auto()
    FTRC = auto()
    FTRV = auto()
    JMP = auto()
    JSR = auto()
    LDC = auto()
    LDS = auto()
    LDTLB = auto()
    MAC = auto()
    MOV = auto()
    MOVA = auto()
    MOVCA = auto()
    MOVT = auto()
    MUL = auto()
    MULS = auto()
    MULU = auto()
    NEG = auto()
    NEGC = auto()
    NOP = auto()
    NOT = auto()
    OCBI = auto()
    OCBP = auto()
    OCBWB = auto()
    OR = auto()
    PREF = auto()
    ROTCL = auto()
    ROTCR = auto()
    ROTL = auto()
    ROTR = auto()
    RTE = auto()
    RTS = auto()
    SETS = auto()
    SETT = auto()
    SHAD = auto()
    SHAL = auto()
    SHAR = auto()
    SHLD = auto()
    SHLL16 = auto()
    SHLL2 = auto()
    SHLL8 = auto()
    SHLL = auto()
    SHLR16 = auto()
    SHLR2 = auto()
    SHLR8 = auto()
    SHLR = auto()
    SLEEP = auto()
    STC = auto()
    STS = auto()
    SUB = auto()
    SUBC = auto()
    SUBV = auto()
    SWAP = auto()
    TAS = auto()
    TRAPA = auto()
    TST = auto()
    XOR = auto()
    XTRCT = auto()

@unique
class OPER_TYPE(Enum):
    NONE = 0
    ADDRESS = auto()
    BANKREG = auto()
    CTRLREG = auto()
    DEREF_REG = auto()
    DEREF_REG_PRE_DECR = auto()
    DEREF_REG_POST_INCR = auto()
    DEREF_REG_IMM = auto()
    DEREF_REG_REG = auto()
    FPUREG = auto()
    GPREG = auto()
    IMMEDIATE = auto()
    SYSREG = auto()

@unique
class REG(Enum):
    NONE=0
    # gpr's
    R0 = auto()
    R1 = auto()
    R2 = auto()
    R3 = auto()
    R4 = auto()
    R5 = auto()
    R6 = auto()
    R7 = auto()
    R8 = auto()
    R9 = auto()
    R10 = auto()
    R11 = auto()
    R12 = auto()
    R13 = auto()
    R14 = auto()
    R15 = auto()
    # banks
    R0_BANK0 = auto()
    R1_BANK0 = auto()
    R2_BANK0 = auto()
    R3_BANK0 = auto()
    R4_BANK0 = auto()
    R5_BANK0 = auto()
    R6_BANK0 = auto()
    R7_BANK0 = auto()
    R0_BANK1 = auto()
    R1_BANK1 = auto()
    R2_BANK1 = auto()
    R3_BANK1 = auto()
    R4_BANK1 = auto()
    R5_BANK1 = auto()
    R6_BANK1 = auto()
    R7_BANK1 = auto()
    # control
    SR = auto()
    SSR = auto()
    SPC = auto()
    GBR = auto()
    VBR = auto()
    SGR = auto()
    DBR = auto()
    # system
    MACH = auto()
    MACL = auto()
    PR = auto()
    PC = auto()
    FPSCR = auto()
    FPUL = auto()
    # floating point
    FR0 = auto()
    FR1 = auto()
    FR2 = auto()
    FR3 = auto()
    FR4 = auto()
    FR5 = auto()
    FR6 = auto()
    FR7 = auto()
    FR8 = auto()
    FR9 = auto()
    FR10 = auto()
    FR11 = auto()
    FR12 = auto()
    FR13 = auto()
    FR14 = auto()
    FR15 = auto()
    XR0 = auto()
    XR1 = auto()
    XR2 = auto()
    XR3 = auto()
    XR4 = auto()
    XR5 = auto()
    XR6 = auto()
    XR7 = auto()
    XR8 = auto()
    XR9 = auto()
    XR10 = auto()
    XR11 = auto()
    XR12 = auto()
    XR13 = auto()
    XR14 = auto()
    XR15 = auto()
    DR0 = auto()
    DR1 = auto()
    DR2 = auto()
    DR3 = auto()
    DR4 = auto()
    DR5 = auto()
    DR6 = auto()
    DR7 = auto()
    DR8 = auto()
    DR9 = auto()
    DR10 = auto()
    DR11 = auto()
    DR12 = auto()
    DR13 = auto()
    DR14 = auto()
    DR15 = auto()
    FV0 = auto()
    FV1 = auto()
    FV2 = auto()
    FV3 = auto()
    FV4 = auto()
    FV5 = auto()
    FV6 = auto()
    FV7 = auto()
    FV8 = auto()
    FV9 = auto()
    FV10 = auto()
    FV11 = auto()
    FV12 = auto()
    FV13 = auto()
    FV14 = auto()
    FV15 = auto()
    # wtf
    XD0 = auto()
    XD1 = auto()
    XD2 = auto()
    XD3 = auto()
    XMTRX = auto()

@unique
class COND(Enum):
    NONE = 0
    EQ = auto()
    GE = auto()
    GT = auto()
    HI = auto()
    HS = auto()
    PL = auto()
    PZ = auto()
    STR = auto()

@unique
class SUFFIX(Enum):
    NONE = 0
    B = auto()
    W = auto()
    L = auto()

# ------------------------------------------------------------
# STRUCTS
# ------------------------------------------------------------
class Decoded():
    def __init__(self):
        self.op = OP.ERROR
        # list of (OPER_TYPE, VALUE)
        self.operands = []
        self.length_suffix = SUFFIX.NONE
        self.cond = COND.NONE
        self.delay_slot = False

    def __str__(self):
        result = ''

        result += '.op = %s' % (self.op)
        if self.operands:
            result += '\n'
        for i in range(len(self.operands)):
            result += '.operands[%d] = %s' % (i, self.operands[i])
            if i < len(self.operands)-1:
                result += '\n'

        return result

#------------------------------------------------------------------------------
# DECODING
#------------------------------------------------------------------------------

def int8(i):
    """ get 8-bit signed int """
    result = i
    if i & 0x80:
        result = -(128 - (i&0x7F))
    return result

def int12(i):
    """ get 12-bit signed int """
    result = i
    if i & 0x800:
        result = -(2048 - (i&0x7FF))
    return result

def displ2ea(scale, disp, base):
    """ displacement to effective address """
    #print('displ2ea(%d, %d, %X)' % (scale, disp, base))

    dest = (base+4) + scale*disp

    if dest < 0:
        dest = -dest
        dest = dest ^ 0xFFFFFFFFFFFFFFFF
        dest = dest + 1

    return dest

CR_TO_ID = [REG.SR, REG.GBR, REG.VBR, REG.SSR, REG.SPC]

# about 231 cases follow
# so worst case: 230 checks
# average case: 165 checks
# TODO: order these so most common opcodes near the top
def decode(insword, addr):
    """ decode instruction word at given address """

    result = Decoded()

    # 0111nnnniiiiiiii "add #imm,Rn"
    if (insword & 0xf000) == 0x7000:
        i = int8(insword & 0xff)
        n = (insword & 0xf00)>>8
        result.op = OP.ADD
        result.operands.append((OPER_TYPE.IMMEDIATE, i))
        result.operands.append((OPER_TYPE.GPREG, REG(REG.R0.value + n)))
        #return "add #%d,r%d" % (i,n)

    # 0011nnnnmmmm1100 "add Rm,Rn"
    elif (insword & 0xf00f) == 0x300c:
        m = (insword & 0xf0)>>4
        n = (insword & 0xf00)>>8
        result.op = OP.ADD
        result.operands.append((OPER_TYPE.GPREG, REG(REG.R0.value + m)))
        result.operands.append((OPER_TYPE.GPREG, REG(REG.R0.value + n)))
        #return "add r%d,r%d" % (m, n)

    # 0011nnnnmmmm1110 "addc Rm,Rn"
    elif (insword & 0xf00f) == 0x300e:
        m = (insword & 0xf0)>>4
        n = (insword & 0xf00)>>8
        result.op = OP.ADDC
        result.operands.append((OPER_TYPE.GPREG, REG(REG.R0.value + m)))
        result.operands.append((OPER_TYPE.GPREG, REG(REG.R0.value + n)))
        #return "addc r%d,r%d" % (m, n)

    # 0011nnnnmmmm1111 "addv Rm,Rn"
    elif (insword & 0xf00f) == 0x300f:
        m = (insword & 0xf0)>>4
        n = (insword & 0xf00)>>8
        result.op = OP.ADDV
        result.operands.append((OPER_TYPE.GPREG, REG(REG.R0.value + m)))
        result.operands.append((OPER_TYPE.GPREG, REG(REG.R0.value + n)))
        #return "addv r%d,r%d" % (m, n)

    # 11001001iiiiiiii "and #imm,r0"
    elif (insword & 0xff00) == 0xc900:
        i = int8(insword & 0xff)
        result.op = OP.AND
        result.operands.append((OPER_TYPE.IMMEDIATE, i))
        result.operands.append((OPER_TYPE.GPREG, REG.R0))
        #return "and #%d,r0" % (i)

    # 0010nnnnmmmm1001 "and Rm,Rn"
    elif (insword & 0xf00f) == 0x2009:
        m = (insword & 0xf0)>>4
        n = (insword & 0xf00)>>8
        result.op = OP.AND
        result.operands.append((OPER_TYPE.GPREG, REG(REG.R0.value + m)))
        result.operands.append((OPER_TYPE.GPREG, REG(REG.R0.value + n)))
        #return "and r%d,r%d" % (m, n)

    # 11001101iiiiiiii "and.b #imm,@(r0,gbr)"
    elif (insword & 0xff00) == 0xcd00:
        i = int8(insword & 0xff)
        result.op = OP.AND
        result.length_suffix = SUFFIX.B
        result.operands.append((OPER_TYPE.IMMEDIATE, i))
        result.operands.append((OPER_TYPE.DEREF_REG_REG, REG.R0, REG.GBR))
        #return "and.b #%d,@(r0,gbr)" % (i)

    # 10001011dddddddd "bf label"
    elif (insword & 0xff00) == 0x8b00:
        d = displ2ea(2, int8(insword & 0xff), addr)
        result.op = OP.BF
        result.operands.append((OPER_TYPE.ADDRESS, d))
        #return "bf 0x%016x" % d

    # 10001111dddddddd "bf/s label"
    elif (insword & 0xff00) == 0x8f00:
        d = displ2ea(2, int8(insword & 0xff), addr)
        result.op = OP.BF
        result.delay_slot = True
        result.operands.append((OPER_TYPE.ADDRESS, d))
        #return "bf.s 0x%016x" % d

    # 1010dddddddddddd "bra label"
    elif (insword & 0xf000) == 0xa000:
        d = displ2ea(2, int12(insword & 0xfff), addr)
        result.op = OP.BRA
        result.operands.append((OPER_TYPE.ADDRESS, d))
        #return "bra 0x%016x" % d

    # 0000mmmm00100011 "braf Rm"
    elif (insword & 0xf0ff) == 0x23:
        m = (insword & 0xf00)>>8
        result.op = OP.BRAF
        result.operands.append((OPER_TYPE.GPREG, REG(REG.R0.value + m)))
        #return "braf r%d" % (m)

    # 1011dddddddddddd "bsr label"
    elif (insword & 0xf000) == 0xb000:
        d = displ2ea(2, int12(insword & 0xfff), addr)
        result.op = OP.BSR
        result.operands.append((OPER_TYPE.ADDRESS, d))
        #return "bsr 0x%016x" % d

    # 0000mmmm00000011 "bsrf Rm"
    elif (insword & 0xf0ff) == 0x3:
        m = (insword & 0xf00)>>8
        result.op = OP.BSRF
        result.operands.append((OPER_TYPE.GPREG, REG(REG.R0.value + m)))
        #return "bsrf r%d" % (m)

    # 10001001dddddddd "bt label"
    elif (insword & 0xff00) == 0x8900:
        d = displ2ea(2, int8(insword & 0xff), addr)
        result.op = OP.BT
        result.operands.append((OPER_TYPE.ADDRESS, d))
        #return "bt 0x%016x" % d

    # 10001101dddddddd "bt/s label"
    elif (insword & 0xff00) == 0x8d00:
        d = displ2ea(2, int8(insword & 0xff), addr)
        result.op = OP.BT
        result.delay_slot = True
        result.operands.append((OPER_TYPE.ADDRESS, d))
        #return "bt.s 0x%016x" % d

    # 0000000000101000 "clrmac"
    elif insword == 0x28:
        result.op = OP.CLRMAC
        #return "clrmac"

    # 0000000001001000 "clrs"
    elif insword == 0x48:
        result.op = OP.CLRS
        #return "clrs"

    # 0000000000001000 "clrt"
    elif insword == 0x8:
        result.op = OP.CLRT
        #return "clrt"

    # 10001000iiiiiiii "cmp/eq #imm,r0"
    elif (insword & 0xff00) == 0x8800:
        i = int8(insword & 0xff)
        result.op = OP.CMP
        result.cond = COND.EQ
        result.operands.append((OPER_TYPE.IMMEDIATE, i))
        result.operands.append((OPER_TYPE.GPREG, REG.R0))
        #return "cmp/eq #%d,r0" % (i)

    # 0011nnnnmmmm0000 "cmp/eq Rm,Rn"
    elif (insword & 0xf00f) == 0x3000:
        m = (insword & 0xf0)>>4
        n = (insword & 0xf00)>>8
        result.op = OP.CMP
        result.cond = COND.EQ
        result.operands.append((OPER_TYPE.GPREG, REG(REG.R0.value + m)))
        result.operands.append((OPER_TYPE.GPREG, REG(REG.R0.value + n)))
        #return "cmp/eq r%d,r%d" % (m, n)

    # 0011nnnnmmmm0011 "cmp/ge Rm,Rn"
    elif (insword & 0xf00f) == 0x3003:
        m = (insword & 0xf0)>>4
        n = (insword & 0xf00)>>8
        result.op = OP.CMP
        result.cond = COND.GE
        result.operands.append((OPER_TYPE.GPREG, REG(REG.R0.value + m)))
        result.operands.append((OPER_TYPE.GPREG, REG(REG.R0.value + n)))
        #return "cmp/ge r%d,r%d" % (m, n)

    # 0011nnnnmmmm0111 "cmp/gt Rm,Rn"
    elif (insword & 0xf00f) == 0x3007:
        m = (insword & 0xf0)>>4
        n = (insword & 0xf00)>>8
        result.op = OP.CMP
        result.cond = COND.GT
        result.operands.append((OPER_TYPE.GPREG, REG(REG.R0.value + m)))
        result.operands.append((OPER_TYPE.GPREG, REG(REG.R0.value + n)))
        #return "cmp/gt r%d,r%d" % (m, n)

    # 0011nnnnmmmm0110 "cmp/hi Rm,Rn"
    elif (insword & 0xf00f) == 0x3006:
        m = (insword & 0xf0)>>4
        n = (insword & 0xf00)>>8
        result.op = OP.CMP
        result.cond = COND.HI
        result.operands.append((OPER_TYPE.GPREG, REG(REG.R0.value + m)))
        result.operands.append((OPER_TYPE.GPREG, REG(REG.R0.value + n)))
        #return "cmp/hi r%d,r%d" % (m, n)

    # 0011nnnnmmmm0010 "cmp/hs Rm,Rn"
    elif (insword & 0xf00f) == 0x3002:
        m = (insword & 0xf0)>>4
        n = (insword & 0xf00)>>8
        result.op = OP.CMP
        result.cond = COND.HS
        result.operands.append((OPER_TYPE.GPREG, REG(REG.R0.value + m)))
        result.operands.append((OPER_TYPE.GPREG, REG(REG.R0.value + n)))
        #return "cmp/hs r%d,r%d" % (m, n)

    # 0100nnnn00010101 "cmp/pl Rn"
    elif (insword & 0xf0ff) == 0x4015:
        n = (insword & 0xf00)>>8
        result.op = OP.CMP
        result.cond = COND.PL
        result.operands.append((OPER_TYPE.GPREG, REG(REG.R0.value + n)))
        #return "cmp/pl r%d" % (n)

    # 0100nnnn00010001 "cmp/pz Rn"
    elif (insword & 0xf0ff) == 0x4011:
        n = (insword & 0xf00)>>8
        result.op = OP.CMP
        result.cond = COND.PZ
        result.operands.append((OPER_TYPE.GPREG, REG(REG.R0.value + n)))
        #return "cmp/pz r%d" % (n)

    # 0010nnnnmmmm1100 "cmp/str Rm,Rn"
    elif (insword & 0xf00f) == 0x200c:
        m = (insword & 0xf0)>>4
        n = (insword & 0xf00)>>8
        result.op = OP.CMP
        result.cond = COND.STR
        result.operands.append((OPER_TYPE.GPREG, REG(REG.R0.value + m)))
        result.operands.append((OPER_TYPE.GPREG, REG(REG.R0.value + n)))
        #return "cmp/str r%d,r%d" % (m, n)

    # 0010nnnnmmmm0111 "div0s Rm,Rn"
    elif (insword & 0xf00f) == 0x2007:
        m = (insword & 0xf0)>>4
        n = (insword & 0xf00)>>8
        result.op = OP.DIV0S
        result.operands.append((OPER_TYPE.GPREG, REG(REG.R0.value + m)))
        result.operands.append((OPER_TYPE.GPREG, REG(REG.R0.value + n)))
        #return "div0s r%d,r%d" % (m, n)

    # 0000000000011001 "div0u"
    elif insword == 0x19:
        result.op = OP.DIV0U
        #return "div0u"

    # 0011nnnnmmmm0100 "div1 Rm,Rn"
    elif (insword & 0xf00f) == 0x3004:
        m = (insword & 0xf0)>>4
        n = (insword & 0xf00)>>8
        result.op = OP.DIV1
        result.operands.append((OPER_TYPE.GPREG, REG(REG.R0.value + m)))
        result.operands.append((OPER_TYPE.GPREG, REG(REG.R0.value + n)))
        #return "div1 r%d,r%d" % (m, n)

    # 0011nnnnmmmm1101 "dmuls.l Rm,Rn"
    elif (insword & 0xf00f) == 0x300d:
        m = (insword & 0xf0)>>4
        n = (insword & 0xf00)>>8
        result.op = OP.DMULS
        result.length_suffix = SUFFIX.L
        result.operands.append((OPER_TYPE.GPREG, REG(REG.R0.value + m)))
        result.operands.append((OPER_TYPE.GPREG, REG(REG.R0.value + n)))
        #return "dmuls.l r%d,r%d" % (m, n)

    # 0011nnnnmmmm0101 "dmulu.l Rm,Rn"
    elif (insword & 0xf00f) == 0x3005:
        m = (insword & 0xf0)>>4
        n = (insword & 0xf00)>>8
        result.op = OP.DMULU
        result.length_suffix = SUFFIX.L
        result.operands.append((OPER_TYPE.GPREG, REG(REG.R0.value + m)))
        result.operands.append((OPER_TYPE.GPREG, REG(REG.R0.value + n)))
        #return "dmulu.l r%d,r%d" % (m, n)

    # 0100nnnn00010000 "dt Rn"
    elif (insword & 0xf0ff) == 0x4010:
        n = (insword & 0xf00)>>8
        result.op = OP.DT
        result.operands.append((OPER_TYPE.GPREG, REG(REG.R0.value + n)))
        #return "dt r%d" % (n)

    # 0110nnnnmmmm1110 "exts.b Rm,Rn"
    elif (insword & 0xf00f) == 0x600e:
        m = (insword & 0xf0)>>4
        n = (insword & 0xf00)>>8
        result.op = OP.EXTS
        result.length_suffix = SUFFIX.B
        result.operands.append((OPER_TYPE.GPREG, REG(REG.R0.value + m)))
        result.operands.append((OPER_TYPE.GPREG, REG(REG.R0.value + n)))
        #return "exts.b r%d,r%d" % (m, n)

    # 0110nnnnmmmm1111 "exts.w Rm,Rn"
    elif (insword & 0xf00f) == 0x600f:
        m = (insword & 0xf0)>>4
        n = (insword & 0xf00)>>8
        result.op = OP.EXTS
        result.length_suffix = SUFFIX.W
        result.operands.append((OPER_TYPE.GPREG, REG(REG.R0.value + m)))
        result.operands.append((OPER_TYPE.GPREG, REG(REG.R0.value + n)))
        #return "exts.w r%d,r%d" % (m, n)

    # 0110nnnnmmmm1100 "extu.b Rm,Rn"
    elif (insword & 0xf00f) == 0x600c:
        m = (insword & 0xf0)>>4
        n = (insword & 0xf00)>>8
        result.op = OP.EXTU
        result.length_suffix = SUFFIX.B
        result.operands.append((OPER_TYPE.GPREG, REG(REG.R0.value + m)))
        result.operands.append((OPER_TYPE.GPREG, REG(REG.R0.value + n)))
        #return "extu.b r%d,r%d" % (m, n)

    # 0110nnnnmmmm1101 "extu.w Rm,Rn"
    elif (insword & 0xf00f) == 0x600d:
        m = (insword & 0xf0)>>4
        n = (insword & 0xf00)>>8
        result.op = OP.EXTU
        result.length_suffix = SUFFIX.W
        result.operands.append((OPER_TYPE.GPREG, REG(REG.R0.value + m)))
        result.operands.append((OPER_TYPE.GPREG, REG(REG.R0.value + n)))
        #return "extu.w r%d,r%d" % (m, n)

    # 1111nnn001011101 "fabs DRn"
    elif (insword & 0xf1ff) == 0xf05d:
        n = (insword & 0xf00)>>8
        result.op = OP.FABS
        result.operands.append((OPER_TYPE.FPUREG, REG(REG.FR0.value + n)))
        #return "fabs fr%d" % (n)

    # 1111nnnn01011101 "fabs FRn"
    elif (insword & 0xf0ff) == 0xf05d:
        n = (insword & 0xf00)>>8
        result.op = OP.FABS
        result.operands.append((OPER_TYPE.FPUREG, REG(REG.FR0.value + n)))
        #return "fabs fr%d" % (n)

    # 1111nnn0mmmm0000 "fadd DRm,DRn"
    elif (insword & 0xf10f) == 0xf000:
        m = (insword & 0xF0)>>4
        n = (insword & 0xf00)>>8
        result.op = OP.FADD
        result.operands.append((OPER_TYPE.FPUREG, REG(REG.FR0.value + m)))
        result.operands.append((OPER_TYPE.FPUREG, REG(REG.FR0.value + n)))
        #return "fadd fr%d,fr%d" % (m, n)

    # 1111nnnnmmmm0000 "fadd FRm,FRn"
    elif (insword & 0xf00f) == 0xf000:
        m = (insword & 0xf0)>>4
        n = (insword & 0xf00)>>8
        result.op = OP.FADD
        result.operands.append((OPER_TYPE.FPUREG, REG(REG.FR0.value + m)))
        result.operands.append((OPER_TYPE.FPUREG, REG(REG.FR0.value + n)))
        #return "fadd fr%d,fr%d" % (m, n)

    # 1111nnn0mmmm0100 "fcmp/eq DRm,DRn"
    elif (insword & 0xf11f) == 0xf004:
        m = (insword & 0xf0)>>4
        n = (insword & 0xf00)>>8
        result.op = OP.FCMP
        result.cond = COND.EQ
        result.operands.append((OPER_TYPE.FPUREG, REG(REG.FR0.value + m)))
        result.operands.append((OPER_TYPE.FPUREG, REG(REG.FR0.value + n)))
        #return "fcmp/eq fr%d,fr%d" % (m, n)

    # 1111nnnnmmmm0100 "fcmp/eq FRm,FRn"
    elif (insword & 0xf00f) == 0xf004:
        m = (insword & 0xf0)>>4
        n = (insword & 0xf00)>>8
        result.op = OP.FCMP
        result.cond = COND.EQ
        result.operands.append((OPER_TYPE.FPUREG, REG(REG.FR0.value + m)))
        result.operands.append((OPER_TYPE.FPUREG, REG(REG.FR0.value + n)))
        #return "fcmp/eq fr%d,fr%d" % (m, n)

    # 1111nnn0mmm00101 "fcmp/gt DRm,DRn"
    elif (insword & 0xf11f) == 0xf005:
        m = (insword & 0xf0)>>4
        n = (insword & 0xf00)>>8
        result.op = OP.FCMP
        result.cond = COND.GT
        result.operands.append((OPER_TYPE.FPUREG, REG(REG.FR0.value + m)))
        result.operands.append((OPER_TYPE.FPUREG, REG(REG.FR0.value + n)))
        #return "fcmp/gt fr%d,fr%d" % (m, n)

    # 1111nnnnmmmm0101 "fcmp/gt FRm,FRn"
    elif (insword & 0xf00f) == 0xf005:
        m = (insword & 0xf0)>>4
        n = (insword & 0xf00)>>8
        result.op = OP.FCMP
        result.cond = COND.GT
        result.operands.append((OPER_TYPE.FPUREG, REG(REG.FR0.value + m)))
        result.operands.append((OPER_TYPE.FPUREG, REG(REG.FR0.value + n)))
        #return "fcmp/gt fr%d,fr%d" % (m, n)

    # 1111mmm010111101 "fcnvds DRm,fpul"
    elif (insword & 0xf1ff) == 0xf0bd:
        m = (insword & 0xf00)>>8
        result.op = OP.FCNVDS
        result.operands.append((OPER_TYPE.FPUREG, REG(REG.DR0.value + m)))
        result.operands.append((OPER_TYPE.SYSREG, REG.FPUL))
        #return "fcnvds dr%d,fpul" % (m)

    # 1111nnn010101101 "fcnvsd fpul,DRn"
    elif (insword & 0xf1ff) == 0xf0ad:
        n = (insword & 0xf00)>>8
        result.op = OP.FCNVSD
        result.operands.append((OPER_TYPE.SYSREG, REG.FPUL))
        result.operands.append((OPER_TYPE.FPUREG, REG(REG.DR0.value + n)))
        #return "fcnvsd fpul,dr%d" % (n)

    # 1111nnn0mmmm0011 "fdiv DRm,DRn"
    elif (insword & 0xf10f) == 0xf003:
        m = (insword & 0xf0)>>4
        n = (insword & 0xf00)>>8
        result.op = OP.FDIV
        result.operands.append((OPER_TYPE.FPUREG, REG(REG.FR0.value + m)))
        result.operands.append((OPER_TYPE.FPUREG, REG(REG.FR0.value + n)))
        #return "fdiv fr%d,fr%d" % (m, n)

    # 1111nnnnmmmm0011 "fdiv FRm,FRn"
    elif (insword & 0xf00f) == 0xf003:
        m = (insword & 0xf0)>>4
        n = (insword & 0xf00)>>8
        result.op = OP.FDIV
        result.operands.append((OPER_TYPE.FPUREG, REG(REG.FR0.value + m)))
        result.operands.append((OPER_TYPE.FPUREG, REG(REG.FR0.value + n)))
        #return "fdiv fr%d,fr%d" % (m, n)

    # 1111nnmm11101101 "fipr fvm,fvn"
    elif (insword & 0xf0ff) == 0xf0ed:
        m = (insword & 0x300)>>8
        n = (insword & 0xc00)>>10
        result.op = OP.FIPR
        result.operands.append((OPER_TYPE.FPUREG, REG(REG.FV0.value + 4*m)))
        result.operands.append((OPER_TYPE.FPUREG, REG(REG.FV0.value + 4*n)))
        #return "fipr fv%d,fv%d" % (4*m,4*n)

    # 1111nnnn10001101 "fldi0 FRn"
    elif (insword & 0xf0ff) == 0xf08d:
        n = (insword & 0xf00)>>8
        result.op = OP.FLDI0
        result.operands.append((OPER_TYPE.FPUREG, REG(REG.FR0.value + n)))
        #return "fldi0 fr%d" % (n)

    # 1111nnnn10011101 "fldi1 FRn"
    elif (insword & 0xf0ff) == 0xf09d:
        n = (insword & 0xf00)>>8
        result.op = OP.FLDI1
        result.operands.append((OPER_TYPE.FPUREG, REG(REG.FR0.value + n)))
        #return "fldi1 fr%d" % (n)

    # 1111mmmm00011101 "flds FRm,fpul"
    elif (insword & 0xf0ff) == 0xf01d:
        m = (insword & 0xf00)>>8
        result.op = OP.FLDS
        result.operands.append((OPER_TYPE.FPUREG, REG(REG.FR0.value + m)))
        result.operands.append((OPER_TYPE.SYSREG, REG.FPUL))
        #return "flds fr%d,fpul" % (m)

    # 1111nnn000101101 "float fpul,DRn"
    elif (insword & 0xf1ff) == 0xf02d:
        n = (insword & 0xf00)>>8
        result.op = OP.FLOAT
        result.operands.append((OPER_TYPE.SYSREG, REG.FPUL))
        result.operands.append((OPER_TYPE.FPUREG, REG(REG.FR0.value + n)))
        #return "float fpul,fr%d" % (n)

    # 1111nnnn00101101 "float fpul,FRn"
    elif (insword & 0xf0ff) == 0xf02d:
        n = (insword & 0xf00)>>8
        result.op = OP.FLOAT
        result.operands.append((OPER_TYPE.SYSREG, REG.FPUL))
        result.operands.append((OPER_TYPE.FPUREG, REG(REG.FR0.value + n)))
        #return "float fpul,fr%d" % (n)

    # 1111nnnnmmmm1110 "fmac fr0,FRm,FRn"
    elif (insword & 0xf00f) == 0xf00e:
        m = (insword & 0xf0)>>4
        n = (insword & 0xf00)>>8
        result.op = OP.FMAC
        result.operands.append((OPER_TYPE.FPUREG, REG(REG.FR0.value)))
        result.operands.append((OPER_TYPE.FPUREG, REG(REG.FR0.value + m)))
        result.operands.append((OPER_TYPE.FPUREG, REG(REG.FR0.value + n)))
        #return "fmac fr0,fr%d,fr%d" % (m, n)

    # 1111nnn0mmm01100 "fmov DRm,DRn"
    elif (insword & 0xf11f) == 0xf00c:
        m = (insword & 0xf0)>>4
        n = (insword & 0xf00)>>8
        result.op = OP.FMOV
        result.operands.append((OPER_TYPE.FPUREG, REG(REG.FR0.value + m)))
        result.operands.append((OPER_TYPE.FPUREG, REG(REG.FR0.value + n)))
        #return "fmov fr%d,fr%d" % (m, n)

    # 1111nnn1mmm01100 "fmov DRm,XDn"
    elif (insword & 0xf11f) == 0xf10c:
        m = (insword & 0xf0)>>4
        n = (insword & 0xf00)>>8
        result.op = OP.FMOV
        result.operands.append((OPER_TYPE.FPUREG, REG(REG.FR0.value + m)))
        result.operands.append((OPER_TYPE.FPUREG, REG(REG.FR0.value + n)))
        #return "fmov fr%d,fr%d" % (m, n)

    # 1111nnnnmmmm1100 "fmov FRm,FRn"
    elif (insword & 0xf00f) == 0xf00c:
        m = (insword & 0xf0)>>4
        n = (insword & 0xf00)>>8
        result.op = OP.FMOV
        result.operands.append((OPER_TYPE.FPUREG, REG(REG.FR0.value + m)))
        result.operands.append((OPER_TYPE.FPUREG, REG(REG.FR0.value + n)))
        #return "fmov fr%d,fr%d" % (m, n)

    # 1111nnn0mmm11100 "fmov XDm,DRn"
    elif (insword & 0xf11f) == 0xf01c:
        m = (insword & 0xf0)>>4
        n = (insword & 0xf00)>>8
        result.op = OP.FMOV
        result.operands.append((OPER_TYPE.FPUREG, REG(REG.XD0.value + m)))
        result.operands.append((OPER_TYPE.FPUREG, REG(REG.FR0.value + n)))
        #return "fmov XD%d,fr%d" % (m, n)

    # 1111nnn1mmm11100 "fmov XDm,XDn"
    elif (insword & 0xf11f) == 0xf11c:
        m = (insword & 0xf0)>>4
        n = (insword & 0xf00)>>8
        result.op = OP.FMOV
        result.operands.append((OPER_TYPE.FPUREG, REG(REG.XD0.value + m)))
        result.operands.append((OPER_TYPE.FPUREG, REG(REG.FR0.value + n)))
        #return "fmov XD%d,fr%d" % (m, n)

    # 1111nnn0mmmm0110 "fmov @(r0,Rm),DRn"
    elif (insword & 0xf10f) == 0xf006:
        m = (insword & 0xf0)>>4
        n = (insword & 0xf00)>>8
        result.op = OP.FMOV
        result.operands.append((OPER_TYPE.DEREF_REG_REG, REG.R0, REG(REG.R0.value + m)))
        result.operands.append((OPER_TYPE.FPUREG, REG(REG.FR0.value + n)))
        #return "fmov @(r0,r%d),fr%d" % (m, n)

    # 1111nnnnmmmm0110 "fmov @(r0,Rm),XDn"
    elif (insword & 0xf10f) == 0xf106:
        m = (insword & 0xf0)>>4
        n = (insword & 0xf00)>>8
        result.op = OP.FMOV
        result.operands.append((OPER_TYPE.DEREF_REG_REG, REG.R0, REG(REG.R0.value + m)))
        result.operands.append((OPER_TYPE.FPUREG, REG(REG.FR0.value + n)))
        #return "fmov @(r0,r%d),fr%d" % (m, n)

    # 1111nnn0mmmm1001 "fmov @Rm+,DRn"
    elif (insword & 0xf10f) == 0xf009:
        m = (insword & 0xf0)>>4
        n = (insword & 0xf00)>>8
        result.op = OP.FMOV
        result.operands.append((OPER_TYPE.DEREF_REG_POST_INCR, REG(REG.R0.value + m)))
        result.operands.append((OPER_TYPE.FPUREG, REG(REG.FR0.value + n)))
        #return "fmov @r%d+,fr%d" % (m, n)

    # 1111nnnnmmmm1001 "fmov @Rm+,XDn"
    elif (insword & 0xf10f) == 0xf109:
        m = (insword & 0xf0)>>4
        n = (insword & 0xf00)>>8
        result.op = OP.FMOV
        result.operands.append((OPER_TYPE.DEREF_REG_POST_INCR, REG(REG.R0.value + m)))
        result.operands.append((OPER_TYPE.FPUREG, REG(REG.FR0.value + n)))
        #return "fmov @r%d+,fr%d" % (m, n)

    # 1111nnn0mmmm1000 "fmov @Rm,DRn"
    elif (insword & 0xf10f) == 0xf008:
        m = (insword & 0xf0)>>4
        n = (insword & 0xf00)>>8
        result.op = OP.FMOV
        result.operands.append((OPER_TYPE.DEREF_REG, REG(REG.R0.value + m)))
        result.operands.append((OPER_TYPE.FPUREG, REG(REG.FR0.value + n)))
        #return "fmov @r%d,fr%d" % (m, n)

    # 1111nnnnmmmm1000 "fmov @Rm,XDn"
    elif (insword & 0xf10f) == 0xf108:
        m = (insword & 0xf0)>>4
        n = (insword & 0xF00)>>8
        result.op = OP.FMOV
        result.operands.append((OPER_TYPE.DEREF_REG, REG(REG.R0.value + m)))
        result.operands.append((OPER_TYPE.FPUREG, REG(REG.FR0.value + n)))
        #return "fmov @r%d,fr%d" % (m, n)

    # 1111nnnnmmm00111 "fmov DRm,@(r0,Rn)"
    elif (insword & 0xf01f) == 0xf007:
        m = (insword & 0xf0)>>4
        n = (insword & 0xf00)>>8
        result.op = OP.FMOV
        result.operands.append((OPER_TYPE.FPUREG, REG(REG.FR0.value + m)))
        result.operands.append((OPER_TYPE.DEREF_REG_REG, REG.R0, REG(REG.R0.value + n)))
        #return "fmov fr%d,@(r0,r%d)" % (m, n)

    # 1111nnnnmmm01011 "fmov DRm,@-Rn"
    elif (insword & 0xf01f) == 0xf00b:
        m = (insword & 0xf0)>>4
        n = (insword & 0xf00)>>8
        result.op = OP.FMOV
        result.operands.append((OPER_TYPE.FPUREG, REG(REG.FR0.value + m)))
        result.operands.append((OPER_TYPE.DEREF_REG_PRE_DECR, REG(REG.R0.value + n)))
        #return "fmov fr%d,@-r%d" % (m, n)

    # 1111nnnnmmm01010 "fmov DRm,@Rn"
    elif (insword & 0xf01f) == 0xf00a:
        m = (insword & 0xf0)>>4
        n = (insword & 0xf00)>>8
        result.op = OP.FMOV
        result.operands.append((OPER_TYPE.FPUREG, REG(REG.FR0.value + m)))
        result.operands.append((OPER_TYPE.DEREF_REG, REG(REG.R0.value + n)))
        #return "fmov fr%d,@r%d" % (m, n)

    # 1111nnnnmmmm0111 "fmov XDm,@(r0,Rn)"
    elif (insword & 0xf00f) == 0xf007:
        m = (insword & 0xf0)>>4
        n = (insword & 0xf00)>>8
        result.op = OP.FMOV
        result.operands.append((OPER_TYPE.FPUREG, REG(REG.FR0.value + m)))
        result.operands.append((OPER_TYPE.DEREF_REG_REG, REG.R0, REG(REG.R0.value + n)))
        #return "fmov fr%d,@(r0,r%d)" % (m, n)

    # 1111nnnnmmm11011 "fmov XDm,@-Rn"
    elif (insword & 0xf00f) == 0xf00b:
        m = (insword & 0xf0)>>4
        n = (insword & 0xf00)>>8
        result.op = OP.FMOV
        result.operands.append((OPER_TYPE.FPUREG, REG(REG.FR0.value + m)))
        result.operands.append((OPER_TYPE.DEREF_REG_PRE_DECR, REG(REG.R0.value + n)))
        #return "fmov fr%d,@-r%d" % (m, n)

    # 1111nnnnmmmm1010 "fmov XDm,@Rn"
    elif (insword & 0xf00f) == 0xf00a:
        m = (insword & 0xf0)>>4
        n = (insword & 0xf00)>>8
        result.op = OP.FMOV
        result.operands.append((OPER_TYPE.FPUREG, REG(REG.FR0.value + m)))
        result.operands.append((OPER_TYPE.DEREF_REG, REG(REG.R0.value + n)))
        #return "fmov fr%d,@r%d" % (m, n)

    # 1111nnnnmmmm0110 "fmov.s @(r0,Rm),FRn"
    elif (insword & 0xf00f) == 0xf006:
        m = (insword & 0xf0)>>4
        n = (insword & 0xf00)>>8
        result.op = OP.FMOV
        result.delay_slot = True
        result.operands.append((OPER_TYPE.DEREF_REG_REG, REG.R0, REG(REG.R0.value + m)))
        result.operands.append((OPER_TYPE.FPUREG, REG(REG.FR0.value + n)))
        #return "fmov.s @(r0,r%d),fr%d" % (m, n)

    # 1111nnnnmmmm1001 "fmov.s @Rm+,FRn"
    elif (insword & 0xf00f) == 0xf009:
        m = (insword & 0xf0)>>4
        n = (insword & 0xf00)>>8
        result.op = OP.FMOV
        result.delay_slot = True
        result.operands.append((OPER_TYPE.DEREF_REG_POST_INCR, REG(REG.R0.value + m)))
        result.operands.append((OPER_TYPE.FPUREG, REG(REG.FR0.value + n)))
        #return "fmov.s @r%d+,fr%d" % (m, n)

    # 1111nnnnmmmm1000 "fmov.s @Rm,FRn"
    elif (insword & 0xf00f) == 0xf008:
        m = (insword & 0xf0)>>4
        n = (insword & 0xf00)>>8
        result.op = OP.FMOV
        result.delay_slot = True
        result.operands.append((OPER_TYPE.DEREF_REG, REG(REG.R0.value + m)))
        result.operands.append((OPER_TYPE.FPUREG, REG(REG.FR0.value + n)))
        #return "fmov.s @r%d,fr%d" % (m, n)

    # 1111nnnnmmmm0111 "fmov.s FRm,@(r0,Rn)"
    elif (insword & 0xf00f) == 0xf007:
        m = (insword & 0xf0)>>4
        n = (insword & 0xf00)>>8
        result.op = OP.FMOV
        result.delay_slot = True
        result.operands.append((OPER_TYPE.FPUREG, REG(REG.FR0.value + m)))
        result.operands.append((OPER_TYPE.DEREF_REG_REG, REG.R0, REG(REG.R0.value + n)))
        #return "fmov.s fr%d,@(r0,r%d)" % (m, n)

    # 1111nnnnmmmm1011 "fmov.s FRm,@-Rn"
    elif (insword & 0xf00f) == 0xf00b:
        m = (insword & 0xf0)>>4
        n = (insword & 0xf00)>>8
        result.op = OP.FMOV
        result.delay_slot = True
        result.operands.append((OPER_TYPE.FPUREG, REG(REG.FR0.value + m)))
        result.operands.append((OPER_TYPE.DEREF_REG_PRE_DECR, REG(REG.R0.value + n)))
        #return "fmov.s fr%d,@-r%d" % (m, n)

    # 1111nnnnmmmm1010 "fmov.s FRm,@Rn"
    elif (insword & 0xf00f) == 0xf00a:
        m = (insword & 0xf0)>>4
        n = (insword & 0xf00)>>8
        result.op = OP.FMOV
        result.delay_slot = True
        result.operands.append((OPER_TYPE.FPUREG, REG(REG.FR0.value + m)))
        result.operands.append((OPER_TYPE.DEREF_REG, REG(REG.R0.value + n)))
        #return "fmov.s fr%d,@r%d" % (m, n)

    # 1111nnn0mmmm0010 "fmul DRm,DRn"
    elif (insword & 0xf10f) == 0xf002:
        m = (insword & 0xF0)>>4
        n = (insword & 0xf00)>>8
        result.op = OP.FMUL
        result.operands.append((OPER_TYPE.FPUREG, REG(REG.FR0.value + m)))
        result.operands.append((OPER_TYPE.FPUREG, REG(REG.FR0.value + n)))
        #return "fmul fr%d,fr%d" % (m, n)

    # 1111nnnnmmmm0010 "fmul FRm,FRn"
    elif (insword & 0xf00f) == 0xf002:
        m = (insword & 0xf0)>>4
        n = (insword & 0xf00)>>8
        result.op = OP.FMUL
        result.operands.append((OPER_TYPE.FPUREG, REG(REG.FR0.value + m)))
        result.operands.append((OPER_TYPE.FPUREG, REG(REG.FR0.value + n)))
        #return "fmul fr%d,fr%d" % (m, n)

    # 1111nnn001001101 "fneg DRn"
    elif (insword & 0xf1ff) == 0xf04d:
        n = (insword & 0xf00)>>8
        result.op = OP.FNEG
        result.operands.append((OPER_TYPE.FPUREG, REG(REG.FR0.value + n)))
        #return "fneg fr%d" % (n)

    # 1111nnnn01001101 "fneg FRn"
    elif (insword & 0xf0ff) == 0xf04d:
        n = (insword & 0xf00)>>8
        result.op = OP.FNEG
        result.operands.append((OPER_TYPE.FPUREG, REG(REG.FR0.value + n)))
        #return "fneg fr%d" % (n)

    # 1111101111111101 "frchg"
    elif insword == 0xfbfd:
        result.op = OP.FRCHG
        #return "frchg"

    # 1111001111111101 "fschg"
    elif insword == 0xf3fd:
        result.op = OP.FSCHG
        #return "fschg"

    # 1111nnn001101101 "fsqrt DRn"
    elif (insword & 0xf1ff) == 0xf06d:
        n = (insword & 0xf00)>>8
        result.op = OP.FSQRT
        result.operands.append((OPER_TYPE.FPUREG, REG(REG.FR0.value + n)))
        #return "fsqrt fr%d" % (n)

    # 1111nnnn01101101 "fsqrt FRn"
    elif (insword & 0xf0ff) == 0xf06d:
        n = (insword & 0xf00)>>8
        result.op = OP.FSQRT
        result.operands.append((OPER_TYPE.FPUREG, REG(REG.FR0.value + n)))
        #return "fsqrt fr%d" % (n)

    # 1111nnnn00001101 "fsts fpul,FRn"
    elif (insword & 0xf0ff) == 0xf00d:
        n = (insword & 0xf00)>>8
        result.op = OP.FSTS
        result.operands.append((OPER_TYPE.SYSREG, REG.FPUL))
        result.operands.append((OPER_TYPE.FPUREG, REG(REG.FR0.value + n)))
        #return "fsts fpul,fr%d" % (n)

    # 1111nnn0mmmm0001 "fsub DRm,DRn"
    elif (insword & 0xf10f) == 0xf001:
        m = (insword & 0xF0)>>4
        n = (insword & 0xf00)>>8
        result.op = OP.FSUB
        result.operands.append((OPER_TYPE.FPUREG, REG(REG.FR0.value + m)))
        result.operands.append((OPER_TYPE.FPUREG, REG(REG.FR0.value + n)))
        #return "fsub fr%d,fr%d" % (m, n)

    # 1111nnnnmmmm0001 "fsub FRm,FRn"
    elif (insword & 0xf00f) == 0xf001:
        m = (insword & 0xf0)>>4
        n = (insword & 0xf00)>>8
        result.op = OP.FSUB
        result.operands.append((OPER_TYPE.FPUREG, REG(REG.FR0.value + m)))
        result.operands.append((OPER_TYPE.FPUREG, REG(REG.FR0.value + n)))
        #return "fsub fr%d,fr%d" % (m, n)

    # 1111mmm000111101 "ftrc DRm,fpul"
    elif (insword & 0xf1ff) == 0xf03d:
        m = (insword & 0xf00)>>8
        result.op = OP.FTRC
        result.operands.append((OPER_TYPE.FPUREG, REG(REG.FR0.value + m)))
        result.operands.append((OPER_TYPE.SYSREG, REG.FPUL))
        #return "ftrc fr%d,fpul" % (m)

    # 1111mmmm00111101 "ftrc FRm,fpul"
    elif (insword & 0xf0ff) == 0xf03d:
        m = (insword & 0xf00)>>8
        result.op = OP.FTRC
        result.operands.append((OPER_TYPE.FPUREG, REG(REG.FR0.value + m)))
        result.operands.append((OPER_TYPE.SYSREG, REG.FPUL))
        #return "ftrc fr%d,fpul" % (m)

    # 1111nn0111111101 "ftrv xmtrx,fvn"
    elif (insword & 0xf3ff) == 0xf1fd:
        n = (insword & 0xc00)>>10
        result.op = OP.FTRV
        result.operands.append((OPER_TYPE.FPUREG, REG.XMTRX))
        result.operands.append((OPER_TYPE.FPUREG, REG(REG.FV0.value + 4*n)))
        #return "ftrv xmtrx,fv%d" % (4*n)

    # 0100mmmm00101011 "jmp @Rm"
    elif (insword & 0xf0ff) == 0x402b:
        m = (insword & 0xf00)>>8
        result.op = OP.JMP
        result.operands.append((OPER_TYPE.DEREF_REG, REG(REG.R0.value + m)))
        #return "jmp @r%d" % (m)

    # 0100mmmm00001011 "jsr @Rm"
    elif (insword & 0xf0ff) == 0x400b:
        m = (insword & 0xf00)>>8
        result.op = OP.JSR
        result.operands.append((OPER_TYPE.DEREF_REG, REG(REG.R0.value + m)))
        #return "jsr @r%d" % (m)

    # 0100mmmm11110110 "ldc Rm,dbr"
    elif (insword & 0xf0ff) == 0x40f6:
        m = (insword & 0xf00)>>8
        result.op = OP.LDC
        result.length_suffix = SUFFIX.L
        result.operands.append((OPER_TYPE.DEREF_REG_POST_INCR, REG(REG.R0.value + m)))
        result.operands.append((OPER_TYPE.CTRLREG, REG.DBR))
        #return "ldc.l @r%d+,dbr" % (m)

    # MANUAL
    elif (insword & 0xf0ff) == 0x40fa:
        m = (insword & 0xf00)>>8
        result.op = OP.LDC
        result.operands.append((OPER_TYPE.GPREG, REG(REG.R0.value + m)))
        result.operands.append((OPER_TYPE.CTRLREG, REG.DBR))
        #return "ldc r%d,dbr" % (m)

    # 0100mmmm00011110 "ldc Rm,gbr"
    elif (insword & 0xf0ff) == 0x401e:
        m = (insword & 0xf00)>>8
        result.op = OP.LDC
        result.operands.append((OPER_TYPE.GPREG, REG(REG.R0.value + m)))
        result.operands.append((OPER_TYPE.CTRLREG, REG.GBR))
        #return "ldc r%d,gbr" % (m)

    # 0100mmmm1nnn1110 "ldc Rm,Rn_bank"
    elif (insword & 0xf08f) == 0x408e:
        m = (insword & 0xf00)>>8
        n = (insword & 0x70)>>4
        result.op = OP.LDC
        result.operands.append((OPER_TYPE.GPREG, REG(REG.R0.value + m)))
        result.operands.append((OPER_TYPE.BANKREG, REG(REG.R0_BANK0.value + n)))
        #return "ldc r%d,r%d_bank" % (m, n)

    # 0100mmmm01001110 "ldc Rm,spc"
    elif (insword & 0xf0ff) == 0x404e:
        m = (insword & 0xf00)>>8
        result.op = OP.LDC
        result.operands.append((OPER_TYPE.GPREG, REG(REG.R0.value + m)))
        result.operands.append((OPER_TYPE.CTRLREG, REG.SPC))
        #return "ldc r%d,spc" % (m)

    # 0100mmmm00001110 "ldc Rm,sr"
    elif (insword & 0xf0ff) == 0x400e:
        m = (insword & 0xf00)>>8
        result.op = OP.LDC
        result.operands.append((OPER_TYPE.GPREG, REG(REG.R0.value + m)))
        result.operands.append((OPER_TYPE.CTRLREG, REG.SR))
        #return "ldc r%d,sr" % (m)

    # 0100mmmm00111110 "ldc Rm,ssr"
    elif (insword & 0xf0ff) == 0x403e:
        m = (insword & 0xf00)>>8
        result.op = OP.LDC
        result.operands.append((OPER_TYPE.GPREG, REG(REG.R0.value + m)))
        result.operands.append((OPER_TYPE.CTRLREG, REG.SSR))
        #return "ldc r%d,ssr" % (m)

    # MANUAL
    # 0100mmmm00111010 "ldc Rm,sgr"
    elif (insword & 0xf0ff) == 0x403A:
        m = (insword & 0xf00)>>8
        result.op = OP.LDC
        result.operands.append((OPER_TYPE.GPREG, REG(REG.R0.value + m)))
        result.operands.append((OPER_TYPE.CTRLREG, REG.SGR))
        #return "ldc r%d,sgr" % (m)

    # 0100mmmm00101110 "ldc Rm,vbr"
    elif (insword & 0xf0ff) == 0x402e:
        m = (insword & 0xf00)>>8
        result.op = OP.LDC
        result.operands.append((OPER_TYPE.GPREG, REG(REG.R0.value + m)))
        result.operands.append((OPER_TYPE.CTRLREG, REG.VBR))
        #return "ldc r%d,vbr" % (m)

    # 0100mmmm11110110 "ldc.l @Rm+,dbr"
    elif (insword & 0xf0ff) == 0x40f6:
        m = (insword & 0xf00)>>8
        result.op = OP.LDC
        result.length_suffix = SUFFIX.L
        result.operands.append((OPER_TYPE.DEREF_REG_POST_INCR, REG(REG.R0.value + m)))
        result.operands.append((OPER_TYPE.CTRLREG, REG.DBR))
        #return "ldc.l @r%d+,dbr" % (m)

    # MANUAL
    # 0100mmmmnnnn1110
    elif (insword & 0xf00f) == 0x400E:
        m = (insword & 0xf00)>>8
        n = (insword & 0xf0)>>4
        result.op = OP.LDC
        if n < 5:
            result.operands.append((OPER_TYPE.GPREG, REG(REG.RO.value + m)))
            result.operands.append((OPER_TYPE.CTRLREG, REG(CR_TO_ID[n])))
        else:
            result.operands.append((OPER_TYPE.GPREG, REG(REG.R0.value + m)))
            result.operands.append((OPER_TYPE.BANKREG, REG(REG.R0_BANK0.value + n)))

    # 0100mmmm00010111 "ldc.l @Rm+,gbr"
    elif (insword & 0xf0ff) == 0x4017:
        m = (insword & 0xf00)>>8
        result.op = OP.LDC
        result.length_suffix = SUFFIX.L
        result.operands.append((OPER_TYPE.DEREF_REG_POST_INCR, REG(REG.R0.value + m)))
        result.operands.append((OPER_TYPE.CTRLREG, REG.GBR))
        #return "ldc.l @r%d+,gbr" % (m)

    # 0100mmmm1nnn0111 "ldc.l @Rm+,Rn_bank"
    elif (insword & 0xf08f) == 0x4087:
        m = (insword & 0xf00)>>8
        n = (insword & 0x70)>>4
        result.op = OP.LDC
        result.length_suffix = SUFFIX.L
        result.operands.append((OPER_TYPE.DEREF_REG_POST_INCR, REG(REG.R0.value + m)))
        result.operands.append((OPER_TYPE.BANKREG, REG(REG.R0_BANK0.value + n)))
        #return "ldc.l @r%d+,r%d_bank" % (m, n)

    # 0100mmmm01000111 "ldc.l @Rm+,spc"
    elif (insword & 0xf0ff) == 0x4047:
        m = (insword & 0xf00)>>8
        result.op = OP.LDC
        result.length_suffix = SUFFIX.L
        result.operands.append((OPER_TYPE.DEREF_REG_POST_INCR, REG(REG.R0.value + m)))
        result.operands.append((OPER_TYPE.CTRLREG, REG.SPC))
        #return "ldc.l @r%d+,spc" % (m)

    # 0100mmmm00000111 "ldc.l @Rm+,sr"
    elif (insword & 0xf0ff) == 0x4007:
        m = (insword & 0xf00)>>8
        result.op = OP.LDC
        result.length_suffix = SUFFIX.L
        result.operands.append((OPER_TYPE.DEREF_REG_POST_INCR, REG(REG.R0.value + m)))
        result.operands.append((OPER_TYPE.CTRLREG, REG.SR))
        #return "ldc.l @r%d+,sr" % (m)

    # 0100mmmm00110111 "ldc.l @Rm+,ssr"
    elif (insword & 0xf0ff) == 0x4037:
        m = (insword & 0xf00)>>8
        result.op = OP.LDC
        result.length_suffix = SUFFIX.L
        result.operands.append((OPER_TYPE.DEREF_REG_POST_INCR, REG(REG.R0.value + m)))
        result.operands.append((OPER_TYPE.CTRLREG, REG.SSR))
        #return "ldc.l @r%d+,ssr" % (m)

    # MANUAL
    # 0100mmmm00110110 "ldc.l @Rm+,sgr"
    elif (insword & 0xf0ff) == 0x4036:
        m = (insword & 0xf00)>>8
        result.op = OP.LDC
        result.length_suffix = SUFFIX.L
        result.operands.append((OPER_TYPE.DEREF_REG_POST_INCR, REG(REG.R0.value + m)))
        result.operands.append((OPER_TYPE.CTRLREG, REG.SGR))
        #return "ldc.l @r%d+,sgr" % (m)

    # 0100mmmm00100111 "ldc.l @Rm+,vbr"
    elif (insword & 0xf0ff) == 0x4027:
        m = (insword & 0xf00)>>8
        result.op = OP.LDC
        result.length_suffix = SUFFIX.L
        result.operands.append((OPER_TYPE.DEREF_REG_POST_INCR, REG(REG.R0.value + m)))
        result.operands.append((OPER_TYPE.CTRLREG, REG.VBR))
        #return "ldc.l @r%d+,vbr" % (m)

    # MANUAL
    # 0100mmmmnnnn0111 "ldc.l @Rm+,vbr"
    elif (insword & 0xf00f) == 0x4007:
        m = (insword & 0xf00)>>8
        n = (insword & 0xf0)>>4
        result.op = OP.LDC
        if n < 5:
            result.length_suffix = SUFFIX.L;
            result.operands.append((OPER_TYPE.DEREF_REG_POST_INCR, REG(REG.RO.value + m)))
            result.operands.append((OPER_TYPE.CTRLREG, REG(CR_TO_ID[n])))
        else:
            result.length_suffix = SUFFIX.L;
            result.operands.append((OPER_TYPE.DEREF_REG_POST_INCR, REG(REG.R0.value + m)))
            result.operands.append((OPER_TYPE.BANKREG, REG(REG.R0_BANK0.value + n)))

    # 0100mmmm01101010 "lds Rm,fpscr"
    elif (insword & 0xf0ff) == 0x406a:
        m = (insword & 0xf00)>>8
        result.op = OP.LDS
        result.operands.append((OPER_TYPE.GPREG, REG(REG.R0.value + m)))
        result.operands.append((OPER_TYPE.SYSREG, REG.FPSCR))
        #return "lds r%d,fpscr" % (m)

    # 0100mmmm01011010 "lds Rm,fpul"
    elif (insword & 0xf0ff) == 0x405a:
        m = (insword & 0xf00)>>8
        result.op = OP.LDS
        result.operands.append((OPER_TYPE.GPREG, REG(REG.R0.value + m)))
        result.operands.append((OPER_TYPE.SYSREG, REG.FPUL))
        #return "lds r%d,fpul" % (m)

    # 0100mmmm00001010 "lds Rm,mach"
    elif (insword & 0xf0ff) == 0x400a:
        m = (insword & 0xf00)>>8
        result.op = OP.LDS
        result.operands.append((OPER_TYPE.GPREG, REG(REG.R0.value + m)))
        result.operands.append((OPER_TYPE.SYSREG, REG.MACH))
        #return "lds r%d,mach" % (m)

    # 0100mmmm00011010 "lds Rm,macl"
    elif (insword & 0xf0ff) == 0x401a:
        m = (insword & 0xf00)>>8
        result.op = OP.LDS
        result.operands.append((OPER_TYPE.GPREG, REG(REG.R0.value + m)))
        result.operands.append((OPER_TYPE.SYSREG, REG.MACL))
        #return "lds r%d,macl" % (m)

    # 0100mmmm00101010 "lds Rm,pr"
    elif (insword & 0xf0ff) == 0x402a:
        m = (insword & 0xf00)>>8
        result.op = OP.LDS
        result.operands.append((OPER_TYPE.GPREG, REG(REG.R0.value + m)))
        result.operands.append((OPER_TYPE.SYSREG, REG.PR))
        #return "lds r%d,pr" % (m)

    # 0100mmmm01100110 "lds.l @Rm+,fpscr"
    elif (insword & 0xf0ff) == 0x4066:
        m = (insword & 0xf00)>>8
        result.op = OP.LDS
        result.length_suffix = SUFFIX.L
        result.operands.append((OPER_TYPE.DEREF_REG_POST_INCR, REG(REG.R0.value + m)))
        result.operands.append((OPER_TYPE.SYSREG, REG.FPSCR))
        #return "lds.l @r%d+,fpscr" % (m)

    # 0100mmmm01010110 "lds.l @Rm+,fpul"
    elif (insword & 0xf0ff) == 0x4056:
        m = (insword & 0xf00)>>8
        result.op = OP.LDS
        result.length_suffix = SUFFIX.L
        result.operands.append((OPER_TYPE.DEREF_REG_POST_INCR, REG(REG.R0.value + m)))
        result.operands.append((OPER_TYPE.SYSREG, REG.FPUL))
        #return "lds.l @r%d+,fpul" % (m)

    # 0100mmmm00000110 "lds.l @Rm+,mach"
    elif (insword & 0xf0ff) == 0x4006:
        m = (insword & 0xf00)>>8
        result.op = OP.LDS
        result.length_suffix = SUFFIX.L
        result.operands.append((OPER_TYPE.DEREF_REG_POST_INCR, REG(REG.R0.value + m)))
        result.operands.append((OPER_TYPE.SYSREG, REG.MACH))
        #return "lds.l @r%d+,mach" % (m)

    # 0100mmmm00010110 "lds.l @Rm+,macl"
    elif (insword & 0xf0ff) == 0x4016:
        m = (insword & 0xf00)>>8
        result.op = OP.LDS
        result.length_suffix = SUFFIX.L
        result.operands.append((OPER_TYPE.DEREF_REG_POST_INCR, REG(REG.R0.value + m)))
        result.operands.append((OPER_TYPE.SYSREG, REG.MACL))
        #return "lds.l @r%d+,macl" % (m)

    # 0100mmmm00100110 "lds.l @Rm+,pr"
    elif (insword & 0xf0ff) == 0x4026:
        m = (insword & 0xf00)>>8
        result.op = OP.LDS
        result.length_suffix = SUFFIX.L
        result.operands.append((OPER_TYPE.DEREF_REG_POST_INCR, REG(REG.R0.value + m)))
        result.operands.append((OPER_TYPE.SYSREG, REG.PR))
        #return "lds.l @r%d+,pr" % (m)

    # 0000000000111000 "ldtlb"
    elif insword == 0x38:
        result.op = OP.LDTLB
        #return "ldtlb"

    # 0000nnnnmmmm1111 "mac.l @Rm+,@Rn+"
    elif (insword & 0xf00f) == 0xf:
        m = (insword & 0xf0)>>4
        n = (insword & 0xf00)>>8
        result.op = OP.MAC
        result.length_suffix = SUFFIX.L
        result.operands.append((OPER_TYPE.DEREF_REG_POST_INCR, REG(REG.R0.value + m)))
        result.operands.append((OPER_TYPE.DEREF_REG_POST_INCR, REG(REG.R0.value + n)))
        #return "mac.l @r%d+,@r%d+" % (m, n)

    # 0100nnnnmmmm1111 "mac.w @Rm+,@Rn+"
    elif (insword & 0xf00f) == 0x400f:
        m = (insword & 0xf0)>>4
        n = (insword & 0xf00)>>8
        result.op = OP.MAC
        result.length_suffix = SUFFIX.W
        result.operands.append((OPER_TYPE.DEREF_REG_POST_INCR, REG(REG.R0.value + m)))
        result.operands.append((OPER_TYPE.DEREF_REG_POST_INCR, REG(REG.R0.value + n)))
        #return "mac.w @r%d+,@r%d+" % (m, n)

    # 1110nnnniiiiiiii "mov #imm,Rn"
    elif (insword & 0xf000) == 0xe000:
        i = int8(insword & 0xff)
        n = (insword & 0xf00)>>8
        result.op = OP.MOV
        result.operands.append((OPER_TYPE.IMMEDIATE, i))
        result.operands.append((OPER_TYPE.GPREG, REG(REG.R0.value + n)))
        #return "mov #%d,r%d" % (i,n)

    # 0110nnnnmmmm0011 "mov Rm,Rn"
    elif (insword & 0xf00f) == 0x6003:
        m = (insword & 0xf0)>>4
        n = (insword & 0xf00)>>8
        result.op = OP.MOV
        result.operands.append((OPER_TYPE.GPREG, REG(REG.R0.value + m)))
        result.operands.append((OPER_TYPE.GPREG, REG(REG.R0.value + n)))
        #return "mov r%d,r%d" % (m, n)

    # 0000nnnnmmmm1100 "mov.b @(r0,Rm),Rn"
    elif (insword & 0xf00f) == 0xc:
        m = (insword & 0xf0)>>4
        n = (insword & 0xf00)>>8
        result.op = OP.MOV
        result.length_suffix = SUFFIX.B
        result.operands.append((OPER_TYPE.DEREF_REG_REG, REG.R0, REG(REG.R0.value + m)))
        result.operands.append((OPER_TYPE.GPREG, REG(REG.R0.value + n)))
        #return "mov.b @(r0,r%d),r%d" % (m, n)

    # 11000100dddddddd "mov.b @(disp,gbr),r0"
    elif (insword & 0xff00) == 0xc400:
        d = insword & 0xff
        result.op = OP.MOV
        result.length_suffix = SUFFIX.B
        result.operands.append((OPER_TYPE.DEREF_REG_IMM, REG.GBR, d))
        result.operands.append((OPER_TYPE.GPREG, REG.R0))
        #return "mov.b @(%d,gbr),r0" % (d)

    # 10000100mmmmdddd "mov.b @(disp,Rm),r0"
    elif (insword & 0xff00) == 0x8400:
        d = insword & 0xf
        m = (insword & 0xf0)>>4
        result.op = OP.MOV
        result.length_suffix = SUFFIX.B
        result.operands.append((OPER_TYPE.DEREF_REG_IMM, REG(REG.R0.value + m), d))
        result.operands.append((OPER_TYPE.GPREG, REG.R0))
        #return "mov.b @(%d,r%d),r0" % (d,m)

    # 0110nnnnmmmm0100 "mov.b @Rm+,Rn"
    elif (insword & 0xf00f) == 0x6004:
        m = (insword & 0xf0)>>4
        n = (insword & 0xf00)>>8
        result.op = OP.MOV
        result.length_suffix = SUFFIX.B
        result.operands.append((OPER_TYPE.DEREF_REG_POST_INCR, REG(REG.R0.value + m)))
        result.operands.append((OPER_TYPE.GPREG, REG(REG.R0.value + n)))
        #return "mov.b @r%d+,r%d" % (m, n)

    # 0110nnnnmmmm0000 "mov.b @Rm,Rn"
    elif (insword & 0xf00f) == 0x6000:
        m = (insword & 0xf0)>>4
        n = (insword & 0xf00)>>8
        result.op = OP.MOV
        result.length_suffix = SUFFIX.B
        result.operands.append((OPER_TYPE.DEREF_REG, REG(REG.R0.value + m)))
        result.operands.append((OPER_TYPE.GPREG, REG(REG.R0.value + n)))
        #return "mov.b @r%d,r%d" % (m, n)

    # 11000000dddddddd "mov.b r0,@(disp,gbr)"
    elif (insword & 0xff00) == 0xc000:
        d = insword & 0xff
        result.op = OP.MOV
        result.length_suffix = SUFFIX.B
        result.operands.append((OPER_TYPE.GPREG, REG.R0))
        result.operands.append((OPER_TYPE.DEREF_REG_IMM, REG.GBR, d))
        #return "mov.b r0,@(%d,gbr)" % (d)

    # 10000000nnnndddd "mov.b r0,@(disp,Rn)"
    elif (insword & 0xff00) == 0x8000:
        d = insword & 0xf
        n = (insword & 0xf0)>>4
        result.op = OP.MOV
        result.length_suffix = SUFFIX.B
        result.operands.append((OPER_TYPE.GPREG, REG.R0))
        result.operands.append((OPER_TYPE.DEREF_REG_IMM, REG(REG.R0.value + n), d))
        #return "mov.b r0,@(%d,r%d)" % (d,n)

    # 0000nnnnmmmm0100 "mov.b Rm,@(r0,Rn)"
    elif (insword & 0xf00f) == 0x4:
        m = (insword & 0xf0)>>4
        n = (insword & 0xf00)>>8
        result.op = OP.MOV
        result.length_suffix = SUFFIX.B
        result.operands.append((OPER_TYPE.GPREG, REG(REG.R0.value + m)))
        result.operands.append((OPER_TYPE.DEREF_REG_REG, REG.R0, REG(REG.R0.value + n)))
        #return "mov.b r%d,@(r0,r%d)" % (m, n)

    # 0010nnnnmmmm0100 "mov.b Rm,@-Rn"
    elif (insword & 0xf00f) == 0x2004:
        m = (insword & 0xf0)>>4
        n = (insword & 0xf00)>>8
        result.op = OP.MOV
        result.length_suffix = SUFFIX.B
        result.operands.append((OPER_TYPE.GPREG, REG(REG.R0.value + m)))
        result.operands.append((OPER_TYPE.DEREF_REG_PRE_DECR, REG(REG.R0.value + n)))
        #return "mov.b r%d,@-r%d" % (m, n)

    # 0010nnnnmmmm0000 "mov.b Rm,@Rn"
    elif (insword & 0xf00f) == 0x2000:
        m = (insword & 0xf0)>>4
        n = (insword & 0xf00)>>8
        result.op = OP.MOV
        result.length_suffix = SUFFIX.B
        result.operands.append((OPER_TYPE.GPREG, REG(REG.R0.value + m)))
        result.operands.append((OPER_TYPE.DEREF_REG, REG(REG.R0.value + n)))
        #return "mov.b r%d,@r%d" % (m, n)

    # 0000nnnnmmmm1110 "mov.l @(r0,Rm),Rn"
    elif (insword & 0xf00f) == 0xe:
        m = (insword & 0xf0)>>4
        n = (insword & 0xf00)>>8
        result.op = OP.MOV
        result.length_suffix = SUFFIX.L
        result.operands.append((OPER_TYPE.DEREF_REG_REG, REG.R0, REG(REG.R0.value + m)))
        result.operands.append((OPER_TYPE.GPREG, REG(REG.R0.value + n)))
        #return "mov.l @(r0,r%d),r%d" % (m, n)

    # 11000110dddddddd "mov.l @(disp,gbr),r0"
    elif (insword & 0xff00) == 0xc600:
        d = insword & 0xff
        result.op = OP.MOV
        result.length_suffix = SUFFIX.L
        result.operands.append((OPER_TYPE.DEREF_REG_IMM, REG.GBR, 4*d))
        result.operands.append((OPER_TYPE.GPREG, REG.R0))
        #return "mov.l @(%d,gbr),r0" % (4*d)

    # 1101nnnndddddddd "mov.l @(disp,PC),Rn"
    elif (insword & 0xf000) == 0xd000:
        displ = insword & 0xff
        eaddr = ((addr >> 2)<<2) + 4 + 4*displ
        n = (insword & 0xf00)>>8
        result.op = OP.MOV
        result.length_suffix = SUFFIX.L
        result.operands.append((OPER_TYPE.ADDRESS, eaddr))
        result.operands.append((OPER_TYPE.GPREG, REG(REG.R0.value + n)))
        #return "mov.l 0x%016x,r%d" % (eaddr, n)

    # 0101nnnnmmmmdddd "mov.l @(disp,Rm),Rn"
    elif (insword & 0xf000) == 0x5000:
        d = insword & 0xf
        m = (insword & 0xf0)>>4
        n = (insword & 0xf00)>>8
        result.op = OP.MOV
        result.length_suffix = SUFFIX.L
        result.operands.append((OPER_TYPE.DEREF_REG_IMM, REG(REG.R0.value + m), 4*d))
        result.operands.append((OPER_TYPE.GPREG, REG(REG.R0.value + n)))
        #return "mov.l @(%d,r%d),r%d" % (4*d,m,n)

    # 0110nnnnmmmm0110 "mov.l @Rm+,Rn"
    elif (insword & 0xf00f) == 0x6006:
        m = (insword & 0xf0)>>4
        n = (insword & 0xf00)>>8
        result.op = OP.MOV
        result.length_suffix = SUFFIX.L
        result.operands.append((OPER_TYPE.DEREF_REG_POST_INCR, REG(REG.R0.value + m)))
        result.operands.append((OPER_TYPE.GPREG, REG(REG.R0.value + n)))
        #return "mov.l @r%d+,r%d" % (m, n)

    # 0110nnnnmmmm0010 "mov.l @Rm,Rn"
    elif (insword & 0xf00f) == 0x6002:
        m = (insword & 0xf0)>>4
        n = (insword & 0xf00)>>8
        result.op = OP.MOV
        result.length_suffix = SUFFIX.L
        result.operands.append((OPER_TYPE.DEREF_REG, REG(REG.R0.value + m)))
        result.operands.append((OPER_TYPE.GPREG, REG(REG.R0.value + n)))
        #return "mov.l @r%d,r%d" % (m, n)

    # 11000010dddddddd "mov.l r0,@(disp,gbr)"
    elif (insword & 0xff00) == 0xc200:
        d = insword & 0xff
        result.op = OP.MOV
        result.length_suffix = SUFFIX.L
        result.operands.append((OPER_TYPE.GPREG, REG.R0))
        result.operands.append((OPER_TYPE.DEREF_REG_IMM, REG.GBR, 4*d))
        #return "mov.l r0,@(%d,gbr)" % (4*d)

    # 0000nnnnmmmm0110 "mov.l Rm,@(r0,Rn)"
    elif (insword & 0xf00f) == 0x6:
        m = (insword & 0xf0)>>4
        n = (insword & 0xf00)>>8
        result.op = OP.MOV
        result.length_suffix = SUFFIX.L
        result.operands.append((OPER_TYPE.GPREG, REG(REG.R0.value + m)))
        result.operands.append((OPER_TYPE.DEREF_REG_REG, REG.R0, REG(REG.R0.value + n)))
        #return "mov.l r%d,@(r0,r%d)" % (m, n)

    # 0001nnnnmmmmdddd "mov.l Rm,@(disp,Rn)"
    elif (insword & 0xf000) == 0x1000:
        d = insword & 0xf
        m = (insword & 0xf0)>>4
        n = (insword & 0xf00)>>8
        result.op = OP.MOV
        result.length_suffix = SUFFIX.L
        result.operands.append((OPER_TYPE.GPREG, REG(REG.R0.value + m)))
        result.operands.append((OPER_TYPE.DEREF_REG_IMM, REG(REG.R0.value + n), 4*d))
        #return "mov.l r%d,@(%d,r%d)" % (m,4*d,n)

    # 0010nnnnmmmm0110 "mov.l Rm,@-Rn"
    elif (insword & 0xf00f) == 0x2006:
        m = (insword & 0xf0)>>4
        n = (insword & 0xf00)>>8
        result.op = OP.MOV
        result.length_suffix = SUFFIX.L
        result.operands.append((OPER_TYPE.GPREG, REG(REG.R0.value + m)))
        result.operands.append((OPER_TYPE.DEREF_REG_PRE_DECR, REG(REG.R0.value + n)))
        #return "mov.l r%d,@-r%d" % (m, n)

    # 0010nnnnmmmm0010 "mov.l Rm,@Rn"
    elif (insword & 0xf00f) == 0x2002:
        m = (insword & 0xf0)>>4
        n = (insword & 0xf00)>>8
        result.op = OP.MOV
        result.length_suffix = SUFFIX.L
        result.operands.append((OPER_TYPE.GPREG, REG(REG.R0.value + m)))
        result.operands.append((OPER_TYPE.DEREF_REG, REG(REG.R0.value + n)))
        #return "mov.l r%d,@r%d" % (m, n)

    # 0000nnnnmmmm1101 "mov.w @(r0,Rm),Rn"
    elif (insword & 0xf00f) == 0xd:
        m = (insword & 0xf0)>>4
        n = (insword & 0xf00)>>8
        result.op = OP.MOV
        result.length_suffix = SUFFIX.W
        result.operands.append((OPER_TYPE.DEREF_REG_REG, REG.R0, REG(REG.R0.value + m)))
        result.operands.append((OPER_TYPE.GPREG, REG(REG.R0.value + n)))
        #return "mov.w @(r0,r%d),r%d" % (m, n)

    # 11000101dddddddd "mov.w @(disp,gbr),r0"
    elif (insword & 0xff00) == 0xc500:
        d = insword & 0xff
        result.op = OP.MOV
        result.length_suffix = SUFFIX.W
        result.operands.append((OPER_TYPE.DEREF_REG_IMM, REG.GBR, 2*d))
        result.operands.append((OPER_TYPE.GPREG, REG.R0))
        #return "mov.w @(%d,gbr),r0" % (2*d)

    # 1001nnnndddddddd "mov.w @(disp,PC),Rn"
    elif (insword & 0xf000) == 0x9000:
        d = (addr+4) + 2*(insword & 0xff)
        n = (insword & 0xf00)>>8
        result.op = OP.MOV
        result.length_suffix = SUFFIX.W
        result.operands.append((OPER_TYPE.ADDRESS, d))
        result.operands.append((OPER_TYPE.GPREG, REG(REG.R0.value + n)))
        #return "mov.w 0x%016x,r%d" % (d,n)

    # 10000101mmmmdddd "mov.w @(disp,Rm),r0"
    elif (insword & 0xff00) == 0x8500:
        d = insword & 0xf
        m = (insword & 0xf0)>>4
        result.op = OP.MOV
        result.length_suffix = SUFFIX.W
        result.operands.append((OPER_TYPE.DEREF_REG_IMM, REG(REG.R0.value + m), 2*d))
        result.operands.append((OPER_TYPE.GPREG, REG.R0))
        #return "mov.w @(%d,r%d),r0" % (2*d,m)

    # 0110nnnnmmmm0101 "mov.w @Rm+,Rn"
    elif (insword & 0xf00f) == 0x6005:
        m = (insword & 0xf0)>>4
        n = (insword & 0xf00)>>8
        result.op = OP.MOV
        result.length_suffix = SUFFIX.W
        result.operands.append((OPER_TYPE.DEREF_REG_POST_INCR, REG(REG.R0.value + m)))
        result.operands.append((OPER_TYPE.GPREG, REG(REG.R0.value + n)))
        #return "mov.w @r%d+,r%d" % (m, n)

    # 0110nnnnmmmm0001 "mov.w @Rm,Rn"
    elif (insword & 0xf00f) == 0x6001:
        m = (insword & 0xf0)>>4
        n = (insword & 0xf00)>>8
        result.op = OP.MOV
        result.length_suffix = SUFFIX.W
        result.operands.append((OPER_TYPE.DEREF_REG, REG(REG.R0.value + m)))
        result.operands.append((OPER_TYPE.GPREG, REG(REG.R0.value + n)))
        #return "mov.w @r%d,r%d" % (m, n)

    # 11000001dddddddd "mov.w r0,@(disp,gbr)"
    elif (insword & 0xff00) == 0xc100:
        d = insword & 0xff
        result.op = OP.MOV
        result.length_suffix = SUFFIX.W
        result.operands.append((OPER_TYPE.GPREG, REG.R0))
        result.operands.append((OPER_TYPE.DEREF_REG_IMM, REG.GBR, 2*d))
        #return "mov.w r0,@(%d,gbr)" % (2*d)

    # 10000001nnnndddd "mov.w r0,@(disp,Rn)"
    elif (insword & 0xff00) == 0x8100:
        d = insword & 0xf
        n = (insword & 0xf0)>>4
        result.op = OP.MOV
        result.length_suffix = SUFFIX.W
        result.operands.append((OPER_TYPE.GPREG, REG.R0))
        result.operands.append((OPER_TYPE.DEREF_REG_IMM, REG(REG.R0.value + n), 2*d))
        #return "mov.w r0,@(%d,r%d)" % (2*d,n)

    # 0000nnnnmmmm0101 "mov.w Rm,@(r0,Rn)"
    elif (insword & 0xf00f) == 0x5:
        m = (insword & 0xf0)>>4
        n = (insword & 0xf00)>>8
        result.op = OP.MOV
        result.length_suffix = SUFFIX.W
        result.operands.append((OPER_TYPE.GPREG, REG(REG.R0.value + m)))
        result.operands.append((OPER_TYPE.DEREF_REG_REG, REG.R0, REG(REG.R0.value + n)))
        #return "mov.w r%d,@(r0,r%d)" % (m, n)

    # 0010nnnnmmmm0101 "mov.w Rm,@-Rn"
    elif (insword & 0xf00f) == 0x2005:
        m = (insword & 0xf0)>>4
        n = (insword & 0xf00)>>8
        result.op = OP.MOV
        result.length_suffix = SUFFIX.W
        result.operands.append((OPER_TYPE.GPREG, REG(REG.R0.value + m)))
        result.operands.append((OPER_TYPE.DEREF_REG_PRE_DECR, REG(REG.R0.value + n)))
        #return "mov.w r%d,@-r%d" % (m, n)

    # 0010nnnnmmmm0001 "mov.w Rm,@Rn"
    elif (insword & 0xf00f) == 0x2001:
        m = (insword & 0xf0)>>4
        n = (insword & 0xf00)>>8
        result.op = OP.MOV
        result.length_suffix = SUFFIX.W
        result.operands.append((OPER_TYPE.GPREG, REG(REG.R0.value + m)))
        result.operands.append((OPER_TYPE.DEREF_REG, REG(REG.R0.value + n)))
        #return "mov.w r%d,@r%d" % (m, n)

    # 11000111dddddddd "mova @(disp,PC),r0"
    elif (insword & 0xff00) == 0xc700:
        displ = insword & 0xff
        eaddr = ((addr >> 2)<<2) + 4 + 4*displ
        result.op = OP.MOVA
        result.operands.append((OPER_TYPE.ADDRESS, eaddr))
        result.operands.append((OPER_TYPE.GPREG, REG.R0))
        #return "mova 0x%016x,r0" % eaddr

    # 0000nnnn11000011 "movca.l r0,@Rn"
    elif (insword & 0xf0ff) == 0xc3:
        n = (insword & 0xf00)>>8
        result.op = OP.MOVCA
        result.length_suffix = SUFFIX.L
        result.operands.append((OPER_TYPE.GPREG, REG.R0))
        result.operands.append((OPER_TYPE.DEREF_REG, REG(REG.R0.value + n)))
        #return "movca.l r0,@r%d" % (n)

    # 0000nnnn00101001 "movt Rn"
    elif (insword & 0xf0ff) == 0x29:
        n = (insword & 0xf00)>>8
        result.op = OP.MOVT
        result.operands.append((OPER_TYPE.GPREG, REG(REG.R0.value + n)))
        #return "movt r%d" % (n)

    # 0000nnnnmmmm0111 "mul.l Rm,Rn"
    elif (insword & 0xf00f) == 0x7:
        m = (insword & 0xf0)>>4
        n = (insword & 0xf00)>>8
        result.op = OP.MUL
        result.length_suffix = SUFFIX.L
        result.operands.append((OPER_TYPE.GPREG, REG(REG.R0.value + m)))
        result.operands.append((OPER_TYPE.GPREG, REG(REG.R0.value + n)))
        #return "mul.l r%d,r%d" % (m, n)

    # 0010nnnnmmmm1111 "muls.w Rm,Rn"
    elif (insword & 0xf00f) == 0x200f:
        m = (insword & 0xf0)>>4
        n = (insword & 0xf00)>>8
        result.op = OP.MULS
        result.length_suffix = SUFFIX.W
        result.operands.append((OPER_TYPE.GPREG, REG(REG.R0.value + m)))
        result.operands.append((OPER_TYPE.GPREG, REG(REG.R0.value + n)))
        #return "muls.w r%d,r%d" % (m, n)

    # 0010nnnnmmmm1110 "mulu.w Rm,Rn"
    elif (insword & 0xf00f) == 0x200e:
        m = (insword & 0xf0)>>4
        n = (insword & 0xf00)>>8
        result.op = OP.MULU
        result.length_suffix = SUFFIX.W
        result.operands.append((OPER_TYPE.GPREG, REG(REG.R0.value + m)))
        result.operands.append((OPER_TYPE.GPREG, REG(REG.R0.value + n)))
        #return "mulu.w r%d,r%d" % (m, n)

    # 0110nnnnmmmm1011 "neg Rm,Rn"
    elif (insword & 0xf00f) == 0x600b:
        m = (insword & 0xf0)>>4
        n = (insword & 0xf00)>>8
        result.op = OP.NEG
        result.operands.append((OPER_TYPE.GPREG, REG(REG.R0.value + m)))
        result.operands.append((OPER_TYPE.GPREG, REG(REG.R0.value + n)))
        #return "neg r%d,r%d" % (m, n)

    # 0110nnnnmmmm1010 "negc Rm,Rn"
    elif (insword & 0xf00f) == 0x600a:
        m = (insword & 0xf0)>>4
        n = (insword & 0xf00)>>8
        result.op = OP.NEGC
        result.operands.append((OPER_TYPE.GPREG, REG(REG.R0.value + m)))
        result.operands.append((OPER_TYPE.GPREG, REG(REG.R0.value + n)))
        #return "negc r%d,r%d" % (m, n)

    # 0000000000001001 "nop"
    elif insword == 0x9:
        result.op = OP.NOP
        #return "nop"

    # 0110nnnnmmmm0111 "not Rm,Rn"
    elif (insword & 0xf00f) == 0x6007:
        m = (insword & 0xf0)>>4
        n = (insword & 0xf00)>>8
        result.op = OP.NOT
        result.operands.append((OPER_TYPE.GPREG, REG(REG.R0.value + m)))
        result.operands.append((OPER_TYPE.GPREG, REG(REG.R0.value + n)))
        #return "not r%d,r%d" % (m, n)

    # 0000nnnn10010011 "ocbi @Rn"
    elif (insword & 0xf0ff) == 0x93:
        n = (insword & 0xf00)>>8
        result.op = OP.OCBI
        result.operands.append((OPER_TYPE.DEREF_REG, REG(REG.R0.value + n)))
        #return "ocbi @r%d" % (n)

    # 0000nnnn10100011 "ocbp @Rn"
    elif (insword & 0xf0ff) == 0xa3:
        n = (insword & 0xf00)>>8
        result.op = OP.OCBP
        result.operands.append((OPER_TYPE.DEREF_REG, REG(REG.R0.value + n)))
        #return "ocbp @r%d" % (n)

    # 0000nnnn10110011 "ocbwb @Rn"
    elif (insword & 0xf0ff) == 0xb3:
        n = (insword & 0xf00)>>8
        result.op = OP.OCBWB
        result.operands.append((OPER_TYPE.DEREF_REG, REG(REG.R0.value + n)))
        #return "ocbwb @r%d" % (n)

    # 11001011iiiiiiii "or #imm,r0"
    elif (insword & 0xff00) == 0xcb00:
        i = int8(insword & 0xff)
        result.op = OP.OR
        result.operands.append((OPER_TYPE.IMMEDIATE, i))
        result.operands.append((OPER_TYPE.GPREG, REG.R0))
        #return "or #%d,r0" % (i)

    # 0010nnnnmmmm1011 "or Rm,Rn"
    elif (insword & 0xf00f) == 0x200b:
        m = (insword & 0xf0)>>4
        n = (insword & 0xf00)>>8
        result.op = OP.OR
        result.operands.append((OPER_TYPE.GPREG, REG(REG.R0.value + m)))
        result.operands.append((OPER_TYPE.GPREG, REG(REG.R0.value + n)))
        #return "or r%d,r%d" % (m, n)

    # 11001111iiiiiiii "or.b #imm,@(r0,gbr)"
    elif (insword & 0xff00) == 0xcf00:
        i = int8(insword & 0xff)
        result.op = OP.OR
        result.length_suffix = SUFFIX.B
        result.operands.append((OPER_TYPE.IMMEDIATE, i))
        result.operands.append((OPER_TYPE.DEREF_REG_REG, REG.R0, REG.GBR))
        #return "or.b #%d,@(r0,gbr)" % (i)

    # 0000nnnn10000011 "pref @Rn"
    elif (insword & 0xf0ff) == 0x83:
        n = (insword & 0xf00)>>8
        result.op = OP.PREF
        result.operands.append((OPER_TYPE.DEREF_REG, REG(REG.R0.value + n)))
        #return "pref @r%d" % (n)

    # 0100nnnn00100100 "rotcl Rn"
    elif (insword & 0xf0ff) == 0x4024:
        n = (insword & 0xf00)>>8
        result.op = OP.ROTCL
        result.operands.append((OPER_TYPE.GPREG, REG(REG.R0.value + n)))
        #return "rotcl r%d" % (n)

    # 0100nnnn00100101 "rotcr Rn"
    elif (insword & 0xf0ff) == 0x4025:
        n = (insword & 0xf00)>>8
        result.op = OP.ROTCR
        result.operands.append((OPER_TYPE.GPREG, REG(REG.R0.value + n)))
        #return "rotcr r%d" % (n)

    # 0100nnnn00000100 "rotl Rn"
    elif (insword & 0xf0ff) == 0x4004:
        n = (insword & 0xf00)>>8
        result.op = OP.ROTL
        result.operands.append((OPER_TYPE.GPREG, REG(REG.R0.value + n)))
        #return "rotl r%d" % (n)

    # 0100nnnn00000101 "rotr Rn"
    elif (insword & 0xf0ff) == 0x4005:
        n = (insword & 0xf00)>>8
        result.op = OP.ROTR
        result.operands.append((OPER_TYPE.GPREG, REG(REG.R0.value + n)))
        #return "rotr r%d" % (n)

    # 0000000000101011 "rte"
    elif insword == 0x2b:
        result.op = OP.RTE
        #return "rte"

    # 0000000000001011 "rts"
    elif insword == 0xb:
        result.op = OP.RTS
        #return "rts"

    # 0000000000011000 "sett"
    elif insword == 0x18:
        result.op = OP.SETT
        #return "sett"

    # 0000000001011000 "sets"
    elif insword == 0x58:
        result.op = OP.SETS
        #return "sets"

    # 0100nnnnmmmm1100 "shad Rm,Rn"
    elif (insword & 0xf00f) == 0x400c:
        m = (insword & 0xf0)>>4
        n = (insword & 0xf00)>>8
        result.op = OP.SHAD
        result.operands.append((OPER_TYPE.GPREG, REG(REG.R0.value + m)))
        result.operands.append((OPER_TYPE.GPREG, REG(REG.R0.value + n)))
        #return "shad r%d,r%d" % (m, n)

    # 0100nnnn00100000 "shal Rn"
    elif (insword & 0xf0ff) == 0x4020:
        n = (insword & 0xf00)>>8
        result.op = OP.SHAL
        result.operands.append((OPER_TYPE.GPREG, REG(REG.R0.value + n)))
        #return "shal r%d" % (n)

    # 0100nnnn00100001 "shar Rn"
    elif (insword & 0xf0ff) == 0x4021:
        n = (insword & 0xf00)>>8
        result.op = OP.SHAR
        result.operands.append((OPER_TYPE.GPREG, REG(REG.R0.value + n)))
        #return "shar r%d" % (n)

    # 0100nnnnmmmm1101 "shld Rm,Rn"
    elif (insword & 0xf00f) == 0x400d:
        m = (insword & 0xf0)>>4
        n = (insword & 0xf00)>>8
        result.op = OP.SHLD
        result.operands.append((OPER_TYPE.GPREG, REG(REG.R0.value + m)))
        result.operands.append((OPER_TYPE.GPREG, REG(REG.R0.value + n)))
        #return "shld r%d,r%d" % (m, n)

    # 0100nnnn00000000 "shll Rn"
    elif (insword & 0xf0ff) == 0x4000:
        n = (insword & 0xf00)>>8
        result.op = OP.SHLL
        result.operands.append((OPER_TYPE.GPREG, REG(REG.R0.value + n)))
        #return "shll r%d" % (n)

    # 0100nnnn00101000 "shll16 Rn"
    elif (insword & 0xf0ff) == 0x4028:
        n = (insword & 0xf00)>>8
        result.op = OP.SHLL16
        result.operands.append((OPER_TYPE.GPREG, REG(REG.R0.value + n)))
        #return "shll16 r%d" % (n)

    # 0100nnnn00001000 "shll2 Rn"
    elif (insword & 0xf0ff) == 0x4008:
        n = (insword & 0xf00)>>8
        result.op = OP.SHLL2
        result.operands.append((OPER_TYPE.GPREG, REG(REG.R0.value + n)))
        #return "shll2 r%d" % (n)

    # 0100nnnn00011000 "shll8 Rn"
    elif (insword & 0xf0ff) == 0x4018:
        n = (insword & 0xf00)>>8
        result.op = OP.SHLL8
        result.operands.append((OPER_TYPE.GPREG, REG(REG.R0.value + n)))
        #return "shll8 r%d" % (n)

    # 0100nnnn00000001 "shlr Rn"
    elif (insword & 0xf0ff) == 0x4001:
        n = (insword & 0xf00)>>8
        result.op = OP.SHLR
        result.operands.append((OPER_TYPE.GPREG, REG(REG.R0.value + n)))
        #return "shlr r%d" % (n)

    # 0100nnnn00101001 "shlr16 Rn"
    elif (insword & 0xf0ff) == 0x4029:
        n = (insword & 0xf00)>>8
        result.op = OP.SHLR16
        result.operands.append((OPER_TYPE.GPREG, REG(REG.R0.value + n)))
        #return "shlr16 r%d" % (n)

    # 0100nnnn00001001 "shlr2 Rn"
    elif (insword & 0xf0ff) == 0x4009:
        n = (insword & 0xf00)>>8
        result.op = OP.SHLR2
        result.operands.append((OPER_TYPE.GPREG, REG(REG.R0.value + n)))
        #return "shlr2 r%d" % (n)

    # 0100nnnn00011001 "shlr8 Rn"
    elif (insword & 0xf0ff) == 0x4019:
        n = (insword & 0xf00)>>8
        result.op = OP.SHLR8
        result.operands.append((OPER_TYPE.GPREG, REG(REG.R0.value + n)))
        #return "shlr8 r%d" % (n)

    # 0000000000011011 "sleep"
    elif insword == 0x1b:
        result.op = OP.SLEEP
        #return "sleep"

    # 0000nnnn1mmm0010 "stc Rn,Rm_bank"
    elif (insword & 0xF08F) == 0x0082:
        n = (insword & 0xf00)>>8
        m = (insword & 0x70)>>4
        result.op = OP.STC
        result.operands.append((OPER_TYPE.BANKREG, REG(REG.R0_BANK0.value + m)))
        result.operands.append((OPER_TYPE.GPREG, REG(REG.R0.value + n)))
        #return "stc r%d_bank,r%d" % (m, n)

    # 0000nnnn11111010 "stc dbr,Rn"
    elif (insword & 0xf0ff) == 0xfa:
        n = (insword & 0xf00)>>8
        result.op = OP.STC
        result.operands.append((OPER_TYPE.CTRLREG, REG.DBR))
        result.operands.append((OPER_TYPE.GPREG, REG(REG.R0.value + n)))
        #return "stc dbr,r%d" % (n)

    # 0000nnnn00010010 "stc gbr,Rn"
    elif (insword & 0xf0ff) == 0x12:
        n = (insword & 0xf00)>>8
        result.op = OP.STC
        result.operands.append((OPER_TYPE.CTRLREG, REG.GBR))
        result.operands.append((OPER_TYPE.GPREG, REG(REG.R0.value + n)))
        #return "stc gbr,r%d" % (n)

    # 0000nnnn00111010 "stc sgr,Rn"
    elif (insword & 0xf0ff) == 0x3a:
        n = (insword & 0xf00)>>8
        result.op = OP.STC
        result.operands.append((OPER_TYPE.CTRLREG, REG.SGR))
        result.operands.append((OPER_TYPE.GPREG, REG(REG.R0.value + n)))
        #return "stc sgr,r%d" % (n)

    # 0000nnnn01000010 "stc spc,Rn"
    elif (insword & 0xf0ff) == 0x42:
        n = (insword & 0xf00)>>8
        result.op = OP.STC
        result.operands.append((OPER_TYPE.CTRLREG, REG.SPC))
        result.operands.append((OPER_TYPE.GPREG, REG(REG.R0.value + n)))
        #return "stc spc,r%d" % (n)

    # 0000nnnn00000010 "stc sr,Rn"
    elif (insword & 0xf0ff) == 0x2:
        n = (insword & 0xf00)>>8
        result.op = OP.STC
        result.operands.append((OPER_TYPE.CTRLREG, REG.SR))
        result.operands.append((OPER_TYPE.GPREG, REG(REG.R0.value + n)))
        #return "stc sr,r%d" % (n)

    # 0000nnnn00110010 "stc ssr,Rn"
    elif (insword & 0xf0ff) == 0x32:
        n = (insword & 0xf00)>>8
        result.op = OP.STC
        result.operands.append((OPER_TYPE.CTRLREG, REG.SSR))
        result.operands.append((OPER_TYPE.GPREG, REG(REG.R0.value + n)))
        #return "stc ssr,r%d" % (n)

    # 0000nnnn00100010 "stc vbr,Rn"
    elif (insword & 0xf0ff) == 0x22:
        n = (insword & 0xf00)>>8
        result.op = OP.STC
        result.operands.append((OPER_TYPE.CTRLREG, REG.VBR))
        result.operands.append((OPER_TYPE.GPREG, REG(REG.R0.value + n)))
        #return "stc vbr,r%d" % (n)

    # MANUAL
    # 0000nnnn1mmm0010 "stc Rm_bank,Rn"
    elif (insword & 0xf08f) == 0x82:
        m = (insword & 0x70)>>4
        n = (insword & 0xf00)>>8
        result.op = OP.STC
        result.operands.append((OPER_TYPE.BANKREG, REG(REG.R0_BANK0.value + m)))
        result.operands.append((OPER_TYPE.GPREG, REG(REG.R0.value + n)))
        #return "stc r%d_bank,r%d" % (m, n)

    # MANUAL
    # 0000nnnn0mmm0010 "stc Rm_bank,Rn"
    elif (insword & 0xf08f) == 0x2:
        m = (insword & 0x70)>>4
        n = (insword & 0xf00)>>8
        result.op = OP.STC;
        if m < 5:
            result.operands.append((OPER_TYPE.GPREG, REG(REG.R0_BANK0.value + n)))
            result.operands.append((OPER_TYPE.GPREG, REG(REG.R0.value + m)))
            # return "stc %s,r%d" % (cr2str[m], n)
        else:
            result.operands.append((OPER_TYPE.BANKREG, REG(REG.R0_BANK0.value + m)))
            result.operands.append((OPER_TYPE.GPREG, REG(REG.R0.value + n)))
            # return "stc r%d_bank,r%d" % (m, n)

    # 0100nnnn11110010 "stc.l dbr,@-Rn"
    elif (insword & 0xf0ff) == 0x40f2:
        n = (insword & 0xf00)>>8
        result.op = OP.STC
        result.length_suffix = SUFFIX.L
        result.operands.append((OPER_TYPE.CTRLREG, REG.DBR))
        result.operands.append((OPER_TYPE.DEREF_REG_PRE_DECR, REG(REG.R0.value + n)))
        #return "stc.l dbr,@-r%d" % (n)

    # 0100nnnn00010011 "stc.l gbr,@-Rn"
    elif (insword & 0xf0ff) == 0x4013:
        n = (insword & 0xf00)>>8
        result.op = OP.STC
        result.length_suffix = SUFFIX.L
        result.operands.append((OPER_TYPE.CTRLREG, REG.GBR))
        result.operands.append((OPER_TYPE.DEREF_REG_PRE_DECR, REG(REG.R0.value + n)))
        #return "stc.l gbr,@-r%d" % (n)

    # 0100nnnn1mmm0011 "stc.l Rm_bank,@-Rn"
    elif (insword & 0xf08f) == 0x4083:
        m = (insword & 0x70)>>4
        n = (insword & 0xf00)>>8
        result.op = OP.STC
        result.length_suffix = SUFFIX.L
        result.operands.append((OPER_TYPE.BANKREG, REG(REG.R0_BANK0.value + m)))
        result.operands.append((OPER_TYPE.DEREF_REG_PRE_DECR, REG(REG.R0.value + n)))
        #return "stc.l r%d_bank,@-r%d" % (m, n)

    # MANUAL
    # 0100nnnn0mmm0011 "stc.l Rm_bank,@-Rn"
    elif (insword & 0xf08f) == 0x4003:
        m = (insword & 0x70)>>4
        n = (insword & 0xf00)>>8
        if m < 5:
            result.op = OP.STC;
            result.length_suffix = SUFFIX.L;
            result.operands.append((OPER_TYPE.CTRLREG, CR_TO_ID[m]))
            result.operands.append((OPER_TYPE.DEREF_REG_PRE_DECR, REG(REG.R0.value + n)))
            # return "stc.l %s,@-r%d" % (cr2str[m], n)
        else:
            result.op = OP.STC;
            result.length_suffix = SUFFIX.L;
            result.operands.append((OPER_TYPE.BANKREG, REG(REG.R0_BANK0.value + m)))
            result.operands.append((OPER_TYPE.DEREF_REG_PRE_DECR, REG(REG.R0.value + n)))
            # return "stc.l r%d_bank,@-r%d" % (m, n)

    # 0100nnnn00110010 "stc.l sgr,@-Rn"
    elif (insword & 0xf0ff) == 0x4032:
        n = (insword & 0xf00)>>8
        result.op = OP.STC
        result.length_suffix = SUFFIX.L
        result.operands.append((OPER_TYPE.CTRLREG, REG.SGR))
        result.operands.append((OPER_TYPE.DEREF_REG_PRE_DECR, REG(REG.R0.value + n)))
        #return "stc.l sgr,@-r%d" % (n)

    # 0100nnnn01000011 "stc.l spc,@-Rn"
    elif (insword & 0xf0ff) == 0x4043:
        n = (insword & 0xf00)>>8
        result.op = OP.STC
        result.length_suffix = SUFFIX.L
        result.operands.append((OPER_TYPE.CTRLREG, REG.SPC))
        result.operands.append((OPER_TYPE.DEREF_REG_PRE_DECR, REG(REG.R0.value + n)))
        #return "stc.l spc,@-r%d" % (n)

    # 0100nnnn00000011 "stc.l sr,@-Rn"
    elif (insword & 0xf0ff) == 0x4003:
        n = (insword & 0xf00)>>8
        result.op = OP.STC
        result.length_suffix = SUFFIX.L
        result.operands.append((OPER_TYPE.CTRLREG, REG.SR))
        result.operands.append((OPER_TYPE.DEREF_REG_PRE_DECR, REG(REG.R0.value + n)))
        #return "stc.l sr,@-r%d" % (n)

    # 0100nnnn00110011 "stc.l ssr,@-Rn"
    elif (insword & 0xf0ff) == 0x4033:
        n = (insword & 0xf00)>>8
        result.op = OP.STC
        result.length_suffix = SUFFIX.L
        result.operands.append((OPER_TYPE.CTRLREG, REG.SSR))
        result.operands.append((OPER_TYPE.DEREF_REG_PRE_DECR, REG(REG.R0.value + n)))
        #return "stc.l ssr,@-r%d" % (n)

    # 0100nnnn00100011 "stc.l vbr,@-Rn"
    elif (insword & 0xf0ff) == 0x4023:
        n = (insword & 0xf00)>>8
        result.op = OP.STC
        result.length_suffix = SUFFIX.L
        result.operands.append((OPER_TYPE.CTRLREG, REG.VBR))
        result.operands.append((OPER_TYPE.DEREF_REG_PRE_DECR, REG(REG.R0.value + n)))
        #return "stc.l vbr,@-r%d" % (n)

    # 0000nnnn01101010 "sts fpscr,Rn"
    elif (insword & 0xf0ff) == 0x6a:
        n = (insword & 0xf00)>>8
        result.op = OP.STS
        result.operands.append((OPER_TYPE.SYSREG, REG.FPSCR))
        result.operands.append((OPER_TYPE.GPREG, REG(REG.R0.value + n)))
        #return "sts fpscr,r%d" % (n)

    # 0000nnnn01011010 "sts fpul,Rn"
    elif (insword & 0xf0ff) == 0x5a:
        n = (insword & 0xf00)>>8
        result.op = OP.STS
        result.operands.append((OPER_TYPE.SYSREG, REG.FPUL))
        result.operands.append((OPER_TYPE.GPREG, REG(REG.R0.value + n)))
        #return "sts fpul,r%d" % (n)

    # 0000nnnn00001010 "sts mach,Rn"
    elif (insword & 0xf0ff) == 0xa:
        n = (insword & 0xf00)>>8
        result.op = OP.STS
        result.operands.append((OPER_TYPE.SYSREG, REG.MACH))
        result.operands.append((OPER_TYPE.GPREG, REG(REG.R0.value + n)))
        #return "sts mach,r%d" % (n)

    # 0000nnnn00011010 "sts macl,Rn"
    elif (insword & 0xf0ff) == 0x1a:
        n = (insword & 0xf00)>>8
        result.op = OP.STS
        result.operands.append((OPER_TYPE.SYSREG, REG.MACL))
        result.operands.append((OPER_TYPE.GPREG, REG(REG.R0.value + n)))
        #return "sts macl,r%d" % (n)

    # 0000nnnn00101010 "sts pr,Rn"
    elif (insword & 0xf0ff) == 0x2a:
        n = (insword & 0xf00)>>8
        result.op = OP.STS
        result.operands.append((OPER_TYPE.SYSREG, REG.PR))
        result.operands.append((OPER_TYPE.GPREG, REG(REG.R0.value + n)))
        #return "sts pr,r%d" % (n)

    # 0100nnnn01100010 "sts.l fpscr,@-Rn"
    elif (insword & 0xf0ff) == 0x4062:
        n = (insword & 0xf00)>>8
        result.op = OP.STS
        result.length_suffix = SUFFIX.L
        result.operands.append((OPER_TYPE.SYSREG, REG.FPSCR))
        result.operands.append((OPER_TYPE.DEREF_REG_PRE_DECR, REG(REG.R0.value + n)))
        #return "sts.l fpscr,@-r%d" % (n)

    # 0100nnnn01010010 "sts.l fpul,@-Rn"
    elif (insword & 0xf0ff) == 0x4052:
        n = (insword & 0xf00)>>8
        result.op = OP.STS
        result.length_suffix = SUFFIX.L
        result.operands.append((OPER_TYPE.SYSREG, REG.FPUL))
        result.operands.append((OPER_TYPE.DEREF_REG_PRE_DECR, REG(REG.R0.value + n)))
        #return "sts.l fpul,@-r%d" % (n)

    # 0100nnnn00000010 "sts.l mach,@-Rn"
    elif (insword & 0xf0ff) == 0x4002:
        n = (insword & 0xf00)>>8
        result.op = OP.STS
        result.length_suffix = SUFFIX.L
        result.operands.append((OPER_TYPE.SYSREG, REG.MACH))
        result.operands.append((OPER_TYPE.DEREF_REG_PRE_DECR, REG(REG.R0.value + n)))
        #return "sts.l mach,@-r%d" % (n)

    # 0100nnnn00010010 "sts.l macl,@-Rn"
    elif (insword & 0xf0ff) == 0x4012:
        n = (insword & 0xf00)>>8
        result.op = OP.STS
        result.length_suffix = SUFFIX.L
        result.operands.append((OPER_TYPE.SYSREG, REG.MACL))
        result.operands.append((OPER_TYPE.DEREF_REG_PRE_DECR, REG(REG.R0.value + n)))
        #return "sts.l macl,@-r%d" % (n)

    # 0100nnnn00100010 "sts.l pr,@-Rn"
    elif (insword & 0xf0ff) == 0x4022:
        n = (insword & 0xf00)>>8
        result.op = OP.STS
        result.length_suffix = SUFFIX.L
        result.operands.append((OPER_TYPE.SYSREG, REG.PR))
        result.operands.append((OPER_TYPE.DEREF_REG_PRE_DECR, REG(REG.R0.value + n)))
        #return "sts.l pr,@-r%d" % (n)

    # 0011nnnnmmmm1000 "sub Rm,Rn"
    elif (insword & 0xf00f) == 0x3008:
        m = (insword & 0xf0)>>4
        n = (insword & 0xf00)>>8
        result.op = OP.SUB
        result.operands.append((OPER_TYPE.GPREG, REG(REG.R0.value + m)))
        result.operands.append((OPER_TYPE.GPREG, REG(REG.R0.value + n)))
        #return "sub r%d,r%d" % (m, n)

    # 0011nnnnmmmm1010 "subc Rm,Rn"
    elif (insword & 0xf00f) == 0x300a:
        m = (insword & 0xf0)>>4
        n = (insword & 0xf00)>>8
        result.op = OP.SUBC
        result.operands.append((OPER_TYPE.GPREG, REG(REG.R0.value + m)))
        result.operands.append((OPER_TYPE.GPREG, REG(REG.R0.value + n)))
        #return "subc r%d,r%d" % (m, n)

    # 0011nnnnmmmm1011 "subv Rm,Rn"
    elif (insword & 0xf00f) == 0x300b:
        m = (insword & 0xf0)>>4
        n = (insword & 0xf00)>>8
        result.op = OP.SUBV
        result.operands.append((OPER_TYPE.GPREG, REG(REG.R0.value + m)))
        result.operands.append((OPER_TYPE.GPREG, REG(REG.R0.value + n)))
        #return "subv r%d,r%d" % (m, n)

    # 0110nnnnmmmm1000 "swap.b Rm,Rn"
    elif (insword & 0xf00f) == 0x6008:
        m = (insword & 0xf0)>>4
        n = (insword & 0xf00)>>8
        result.op = OP.SWAP
        result.length_suffix = SUFFIX.B
        result.operands.append((OPER_TYPE.GPREG, REG(REG.R0.value + m)))
        result.operands.append((OPER_TYPE.GPREG, REG(REG.R0.value + n)))
        #return "swap.b r%d,r%d" % (m, n)

    # 0110nnnnmmmm1001 "swap.w Rm,Rn"
    elif (insword & 0xf00f) == 0x6009:
        m = (insword & 0xf0)>>4
        n = (insword & 0xf00)>>8
        result.op = OP.SWAP
        result.length_suffix = SUFFIX.W
        result.operands.append((OPER_TYPE.GPREG, REG(REG.R0.value + m)))
        result.operands.append((OPER_TYPE.GPREG, REG(REG.R0.value + n)))
        #return "swap.w r%d,r%d" % (m, n)

    # 0100nnnn00011011 "tas.b @Rn"
    elif (insword & 0xf0ff) == 0x401b:
        n = (insword & 0xf00)>>8
        result.op = OP.TAS
        result.length_suffix = SUFFIX.B
        result.operands.append((OPER_TYPE.DEREF_REG, REG(REG.R0.value + n)))
        #return "tas.b @r%d" % (n)

    # 11000011iiiiiiii "trapa #imm"
    elif (insword & 0xff00) == 0xc300:
        i = int8(insword & 0xff)
        result.op = OP.TRAPA
        result.operands.append((OPER_TYPE.IMMEDIATE, i))
        #return "trapa #%d" % (i)

    # 11001000iiiiiiii "tst #imm,r0"
    elif (insword & 0xff00) == 0xc800:
        i = int8(insword & 0xff)
        result.op = OP.TST
        result.operands.append((OPER_TYPE.IMMEDIATE, i))
        result.operands.append((OPER_TYPE.GPREG, REG.R0))
        #return "tst #%d,r0" % (i)

    # 0010nnnnmmmm1000 "tst Rm,Rn"
    elif (insword & 0xf00f) == 0x2008:
        m = (insword & 0xf0)>>4
        n = (insword & 0xf00)>>8
        result.op = OP.TST
        result.operands.append((OPER_TYPE.GPREG, REG(REG.R0.value + m)))
        result.operands.append((OPER_TYPE.GPREG, REG(REG.R0.value + n)))
        #return "tst r%d,r%d" % (m, n)

    # 11001100iiiiiiii "tst.b #imm,@(r0,gbr)"
    elif (insword & 0xff00) == 0xcc00:
        i = int8(insword & 0xff)
        result.op = OP.TST
        result.length_suffix = SUFFIX.B
        result.operands.append((OPER_TYPE.IMMEDIATE, i))
        result.operands.append((OPER_TYPE.DEREF_REG_REG, REG.R0, REG.GBR))
        #return "tst.b #%d,@(r0,gbr)" % (i)

    # 11001010iiiiiiii "xor #imm,r0"
    elif (insword & 0xff00) == 0xca00:
        i = int8(insword & 0xff)
        result.op = OP.XOR
        result.operands.append((OPER_TYPE.IMMEDIATE, i))
        result.operands.append((OPER_TYPE.GPREG, REG.R0))
        #return "xor #%d,r0" % (i)

    # 0010nnnnmmmm1010 "xor Rm,Rn"
    elif (insword & 0xf00f) == 0x200a:
        m = (insword & 0xf0)>>4
        n = (insword & 0xf00)>>8
        result.op = OP.XOR
        result.operands.append((OPER_TYPE.GPREG, REG(REG.R0.value + m)))
        result.operands.append((OPER_TYPE.GPREG, REG(REG.R0.value + n)))
        #return "xor r%d,r%d" % (m, n)

    # 11001110iiiiiiii "xor.b #imm,@(r0,gbr)"
    elif (insword & 0xff00) == 0xce00:
        i = int8(insword & 0xff)
        result.op = OP.XOR
        result.length_suffix = SUFFIX.B
        result.operands.append((OPER_TYPE.IMMEDIATE, i))
        result.operands.append((OPER_TYPE.DEREF_REG_REG, REG.R0, REG.GBR))
        #return "xor.b #%d,@(r0,gbr)" % (i)

    # 0010nnnnmmmm1101 "xtrct Rm,Rn"
    elif (insword & 0xf00f) == 0x200d:
        m = (insword & 0xf0)>>4
        n = (insword & 0xf00)>>8
        result.op = OP.XTRCT
        result.operands.append((OPER_TYPE.GPREG, REG(REG.R0.value + m)))
        result.operands.append((OPER_TYPE.GPREG, REG(REG.R0.value + n)))
        #return "xtrct r%d,r%d" % (m, n)

    # 1111nnnn01111101 "fsrra Rn"
    elif (insword & 0xf0ff) == 0xf07d:
        m = (insword & 0xf00)>>8
        result.op = OP.FSRRA
        result.operands.append((OPER_TYPE.FPUREG, REG(REG.FR0.value + m)))
        #return "fsrra fr%d" % (m)

    # 1111nnn011111101 "fsca fpul, drn"
    elif (insword & 0xf1ff) == 0xf0fd:
        m = (insword & 0xE00)>>9
        result.op = OP.FSCA
        result.operands.append((OPER_TYPE.SYSREG, REG.FPUL))
        result.operands.append((OPER_TYPE.FPUREG, REG(REG.DR0.value + 2*m)))
        #return "fsca fpul,dr%d" % (2*m)

    # didn't disassemble!
    #return ".word 0x%04x" % insword

    return result

#------------------------------------------------------------------------------
# STRING MAKING
#------------------------------------------------------------------------------

def oper2str(oper):
    if oper[0] == OPER_TYPE.ADDRESS:
        return '0x%016x' % oper[1]
    if oper[0] in [OPER_TYPE.GPREG, OPER_TYPE.FPUREG, OPER_TYPE.CTRLREG, OPER_TYPE.SYSREG]:
        return oper[1].name.lower()
    if oper[0] == OPER_TYPE.BANKREG:
        return oper[1].name[:-1].lower()
    if oper[0] == OPER_TYPE.DEREF_REG:
        return '@%s' % oper[1].name.lower()
    if oper[0] == OPER_TYPE.DEREF_REG_POST_INCR:
        return '@%s+' % oper[1].name.lower()
    if oper[0] == OPER_TYPE.DEREF_REG_PRE_DECR:
        return '@-%s' % oper[1].name.lower()
    if oper[0] == OPER_TYPE.DEREF_REG_IMM:
        return '@(%d,%s)' % (oper[2], oper[1].name.lower())
    if oper[0] == OPER_TYPE.DEREF_REG_REG:
        return '@(%s,%s)' % (oper[1].name.lower(), oper[2].name.lower())
    if oper[0] == OPER_TYPE.IMMEDIATE:
        return '#%d' % oper[1]

def decoded2str(decoded):
    result = decoded.op.name.lower()
    if decoded.length_suffix == SUFFIX.L:
        result += '.l'
    if decoded.length_suffix == SUFFIX.B:
        result += '.b'
    if decoded.length_suffix == SUFFIX.W:
        result += '.w'
    if decoded.delay_slot:
        result += '.s'
    if decoded.cond != COND.NONE:
        result += ['', '/eq', '/ge', '/gt', '/hi', '/hs', '/pl', '/pz', '/str'][decoded.cond.value]
    if decoded.operands:
        result += ' '
        result += oper2str(decoded.operands[0])
        if len(decoded.operands) > 1:
            result += ','
            result += oper2str(decoded.operands[1])
            if len(decoded.operands) > 2: # eg: fmac fr0,fr0,fr0
                result += ','
                result += oper2str(decoded.operands[2])
    return result

def disasm(arg, pc = 0):
    if type(arg) == int:
        decoded = decode(arg, pc)
    else:
        decoded = arg

    #print(decoded)

    return decoded2str(decoded)
