./makeCfile -D Date -a "A. N. Author" test.c
DIFF=$(diff test.c ../data/test.c)
if [ "$DIFF" == "" ]; then
    printf "Test(makeCfile)\tpass\n"
else
    printf "Test(makeCfile)\tfail\n"
    echo ${DIFF}
fi
rm -rf test.c
