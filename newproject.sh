#/bin/bash

NAME=$1
DATE=$(date -I)


mkdir -p $NAME/src
mkdir -p $NAME/include
touch $NAME/include/definitions.h

cp .example_files/Makefile.example $NAME/Makefile
sed -i "s/<target>/$NAME/g" $NAME/Makefile

cp .example_files/main.c $NAME/src/$NAME.c
sed -i "s/<date>/$DATE/g" $NAME/src/$NAME.c
sed -i "s/<project_title>/$NAME/g" $NAME/src/$NAME.c
