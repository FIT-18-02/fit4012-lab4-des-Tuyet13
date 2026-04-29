#!/usr/bin/env bash
set -euo pipefail

mkdir -p logs

g++ -std=c++17 -Wall -Wextra -pedantic des.cpp -o des

echo "=== Run DES Program ===" > logs/run_log.txt
./des >> logs/run_log.txt

echo "" >> logs/run_log.txt
echo "=== Round-trip Test ===" >> logs/run_log.txt
echo "Input: hello" >> logs/run_log.txt
echo "Expected: decrypt(encrypt(x)) = x" >> logs/run_log.txt
