#!/bin/env bash
# Converts a video file to the correct encoding and resolution

if [ -z $1 ]; then
    echo "Usage: $0 <infile>"
fi

ffmpeg -i "$1" -map 0:v -vf scale="240:160" -r 30 -c:v av1 output.mp4
