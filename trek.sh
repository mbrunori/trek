#!/bin/bash
# trek.sh — wrapper for the C program 'trek'

# Run the compiled C program and capture the path
target_dir="$(/usr/local/bin/trek)"

# Check if the program returned a non-empty string
if [ -n "$target_dir" ]; then
    # Change the shell's current directory
    cd "$target_dir" || {
        echo "trek.sh: Failed to cd into '$target_dir'" >&2
        exit 1
    }
else
    echo "trek.sh: No directory returned by trek" >&2
    exit 1
fi