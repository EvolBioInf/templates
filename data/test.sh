./exe > tmp.out
DIFF=$(diff tmp.out ../data/exe.out)
if [ "$DIFF" == "" ] 
then
    printf "Test(exe)\tpass\n"
else
    printf "Test(exe)\tfail\n"
    echo ${DIFF}
fi

rm tmp.out
