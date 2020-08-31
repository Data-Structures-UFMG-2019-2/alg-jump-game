EXEC=$1
TMP_OUT=$2

for i in {1..8..1}; do
    for j in {1..10..1}; do
        testname=$(printf "%02d" $i)
        $EXEC input/$testname.in timed > $TMP_OUT
    done
done
rm $TMP_OUT