#!/bin/bash

n=5

echo "Enter the number of Fibonacci numbers to generate: "
read n

fibo() {
    local a=0
    local b=1
    local count=0

    for ((i=1; i<=n; i++))
    do
        a=$((a+b))
        b=$((b+a))
        count=$((count+1))
        echo $a
    done
}

fibo