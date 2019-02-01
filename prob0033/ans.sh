#!/bin/bash

numprod=1
for num in `cut -d/ -f1 c.out`; do
	numprod=$(( $num * ${numprod} ))
done
denomprod=1
for denom in `cut -d/ -f2 c.out | cut "-d " -f1`; do
	denomprod=$(( $denom * ${denomprod} ))
done
echo "${numprod}/${denomprod}"
echo "${denomprod}"
