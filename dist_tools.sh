#!/bin/bash

rm -rf dist
mkdir dist
grep -f symbols.txt pokefirered_rev1.map > dist/offsets.txt
tools/inigen/inigen pokefirered_rev1.elf dist/custom_offsets.ini --code BPRE --name "FireRed Moveset Expansion"
