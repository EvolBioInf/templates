./makeCfile -D Date -a "A. N. Author" test.c
DIFF=$(diff test.c ../data/test.c)
if [ "$DIFF" == "" ]; then
    printf "Test(makeCfile)\t\t\tpass\n"
else
    printf "Test(makeCfile)\t\t\tfail\n"
    echo ${DIFF}
fi
rm -rf test.c
