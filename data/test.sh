./PROGNAME > tmp.out
DIFF=$(diff tmp.out ../data/PROGNAME.out)
if [ "$DIFF" == "" ] 
then
    printf "Test(PROGNAME)\tpass\n"
else
    printf "Test(PROGNAME)\tfail\n"
    echo ${DIFF}
fi

rm tmp.out
