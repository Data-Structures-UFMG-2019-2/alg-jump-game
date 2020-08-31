EXEC=$1
TMP_OUT=$2
INPUT_GENERATOR=$3

for i in {1..100..1}; do
    for j in {1..10..1}; do
        testname=$(printf "%02d_tmp" $i)
        $INPUT_GENERATOR $i $i 11 input/$testname.in timed
        $EXEC input/$testname.in timed > $TMP_OUT
    done
done
rm $TMP_OUT