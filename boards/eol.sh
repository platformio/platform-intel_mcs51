#!/bin/bash
for f in *; do
echo "Converting $f to Linux EOL"
sed -i -r 's/\r$//' $f
done
echo "End of script reached"
