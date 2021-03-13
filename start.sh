#!/bin/bash 

imageName="minishell:dev"
if [[ "$(docker images -q $imageName)" == "" ]]
then
    echo "Building $imageName"
    docker build -t $imageName .
else
    echo "Running $imageName"
    docker run --rm -it -v "$(pwd):/home/minishell" $imageName
fi
