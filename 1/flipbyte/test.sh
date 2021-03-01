#!/bin/bash

output=$(./cmake-build-debug/flipbyte 6)
if [ "$output" == 96 ]
then
    printf '+++ 6 96 test passed\n'
else
    printf '!!! 6 96 test failed\n'
fi

output=$(./cmake-build-debug/flipbyte 0)
if [ "$output" == 0 ]
then
    printf '+++ 0 0 test passed\n'
else
    printf '!!! 0 0 test failed\n'
fi

output=$(./cmake-build-debug/flipbyte 255)
if [ "$output" == 255 ]
then
    printf '+++ 255 255 test passed\n'
else
    printf '!!! 255 255 test failed\n'
fi

./cmake-build-debug/flipbyte 1235465 >/dev/null
if [ $? -eq 1 ]
then
    printf '+++ long test passed\n'
else
    printf '!!! long test failed\n'
fi

./cmake-build-debug/flipbyte 1235465 54698 >/dev/null
if [ $? -eq 1 ]
then
    printf '+++ long test passed\n'
else
    printf '!!! long test failed\n'
fi

./cmake-build-debug/flipbyte y >/dev/null
if [ $? -eq 1 ]
then
    printf '+++ y test passed\n'
else
    printf '!!! y test failed\n'
fi

read -n 1 -p "(нажмите любую клавишу для завершения)"