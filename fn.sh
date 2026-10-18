#!/bin/sh
# Print one function's retail disassembly. usage: ./fn.sh func_001173A0
cd "$(dirname "$0")"
awk -v f="$1" '$0=="glabel "f{p=1} p{print} p&&$0=="endlabel "f{exit}' asm/main.s
