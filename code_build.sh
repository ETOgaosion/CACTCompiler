#!/bin/bash

echo "Generating lexer and parser code..."
antlr4 -Dlanguage=Cpp grammar/CACT.g4
