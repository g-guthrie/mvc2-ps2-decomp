#!/bin/sh
# scripts for run_pair.sh: naomi_fight.txt / port_fight.txt = menu + body
cd "$(dirname "$0")"
cat menu_naomi.txt body_fight.txt > naomi_fight.txt
cat menu_port.txt body_fight.txt > port_fight.txt
