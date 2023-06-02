#!/bin/bash
if [ $# -eq 0 ]; then
  echo "[Error]: No argument provided."
  exit 1
fi

IN="$1"
First=$(echo -n "$IN" | openssl dgst -sha256 | awk '{print $2}')
Second=$(echo -n "$First" | openssl dgst -sha256)
Final=$(echo "$Second" | awk '{print $2}')

echo "[FINAL]Double Hash for ($IN): $Final"
