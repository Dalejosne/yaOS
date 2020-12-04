from capstone import *
import sys

def main():
    if len(sys.argv) != 2:
        print("Error : program just waited one file")
        raise(ValueError)
    else:
        file_name = sys.argv
    file = open(file_name[1], mode='rb')

    CODE = file.read()

    md = Cs(CS_ARCH_X86, CS_MODE_32)
    for i in md.disasm(CODE, 0x0):
        print("0x%x:\t%s\t%s" %(i.address, i.mnemonic, i.op_str))
if __name__ == "__main__":main()