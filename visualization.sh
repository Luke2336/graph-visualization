#!/bin/bash

if [ "$1" == "-h" ]; then
  echo ""
  echo "./visualization.sh [InputFile]"
  echo "-----------------------------------"
  echo "Example: ./visualization.sh input.txt"
  echo "-----------------------------------"
  echo " - InputFile: a file with simple graph, including NumNode, NumEdge, Edges"
  exit 0
fi

if [ "$#" -ne 1 ]; then
  echo "You must input InputFile"
  exit 0
fi

make
python3 draw.py <$1
make clean