#/bin/bash

NAME=$1
DATE=$(date "+%Y-%m-%d")


mkdir -p $NAME/src

cp .example_files/Makefile.example $NAME/Makefile
sed -i '' "s/<target>/$NAME/g" $NAME/Makefile

cp .example_files/main.c $NAME/src/$NAME.c
sed -i '' "s/<date>/$DATE/g" $NAME/src/$NAME.c
sed -i '' "s/<project_title>/$NAME/g" $NAME/src/$NAME.c
