#!/bin/bash

if [ "$1" == "-h" ]; then
  echo ""
  echo "./visulization.sh [InputFile] [OutputFile] [OutputFile2.png]"
  echo "-----------------------------------"
  echo "Example: ./visulization.sh input.txt output.txt output.png"
  echo "-----------------------------------"
  echo " - InputFile: a file with simple graph, including NumNode, NumEdge, Edges"
  echo " - OutputFile: a file with cooridnates"
  echo " - OutputFile: a png file with graph visulization"
  echo "-----------------------------------"
  exit 0
fi

if [ "$#" -ne 3 ]; then
    echo "You must input 3 arguments"
    exit 0
fi

make
echo "./visulation"
./visulization <$1 >$2
make clean
echo "python3 draw.py"
python3 draw.py $1 $2 $3
