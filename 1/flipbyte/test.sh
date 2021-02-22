#!/bin/bash

./cmake-build-debug/copyfile ./multiline.txt /tmp/output.txt
if cmp ./multiline.txt /tmp/output.txt;
then
    printf '+++multiline test passed\n'
else
    printf '!!!multiline test failed\n'
fi

./cmake-build-debug/copyfile ./empty.txt /tmp/output.txt
if cmp ./empty.txt /tmp/output.txt;
then
    printf '+++empty test passed\n'
else
    printf '!!!empty test failed\n'
fi

./cmake-build-debug/copyfile ./one-line.txt /tmp/output.txt
if cmp ./one-line.txt /tmp/output.txt;
then
    printf '+++one-line test passed\n'
else
    printf '!!!one-line test failed\n'
fi

./cmake-build-debug/copyfile /tmp/output.txt >/dev/null
if [ $? -eq 1 ] 
then
    printf '+++missing-arg test passed\n'
else
    printf '!!!missing-arg test failed\n'
fi